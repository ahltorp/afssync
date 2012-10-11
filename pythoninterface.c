#include <Python.h>

#include "plwp.h"
#include "cb.ss.h"
#include "ko.h"
#include "err.h"
#include "service.h"
#include "rx.h"
#include "rx_null.h"
#include "fs.cs.h"
#include "vldb.cs.h"
#include "arlalib.h"
#include "fdir.h"

static void
cmcb_init()
{
    static struct rx_securityClass *nullSecObjP;
    static struct rx_securityClass *(securityObjects[1]);
    
    nullSecObjP = rxnull_NewClientSecurityObject ();
    if (nullSecObjP == NULL) {
        printf("Cannot create null security object.\n");
        return;
    }
    
    securityObjects[0] = nullSecObjP;
    
    if (rx_NewService (0, CM_SERVICE_ID, "cm", securityObjects,
                       sizeof(securityObjects) / sizeof(*securityObjects),
                       RXAFSCB_ExecuteRequest) == NULL ) {
        printf("Cannot install service.\n");
        return;
    }
    rx_StartServer (0);    
}

static PyObject *
arla_sleep(PyObject *self, PyObject *args)
{
    IOMGR_Sleep(1);

    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
arla_init(PyObject *self, PyObject *args)
{

    PROCESS pid;
  
    LWP_InitializeProcessSupport (LWP_NORMAL_PRIORITY, &pid);
  
    int error = rx_Init (htons(7001));
    if (error) {
        return PyErr_Format(PyExc_TypeError, "Error initializing rx: %s", koerr_gettext(error));
    }
    cmcb_init();
#if 0
    NSString *rootcell = @"kth.se";
  
    VL *vl = [[VL alloc] initWithCell: rootcell];
    vldbservers = [[NSMutableDictionary alloc] init];
    [vldbservers setObject: vl forKey: rootcell];
    rootvldbentry = [[vl lookupVolume: @"root.afs"] retain];
    fileservers = [[NSMutableDictionary alloc] init];
#endif

#if 0
    if (!PyArg_ParseTuple(args, "s#(iiiiiiii)(iiiiiiii)", &samples, &nsamples,
                          &w[0], &w[1], &w[2], &w[3],
                          &w[4], &w[5], &w[6], &w[7],
                          &cos_k[0], &cos_k[1], &cos_k[2], &cos_k[3],
                          &cos_k[4], &cos_k[5], &cos_k[6], &cos_k[7]))
        return NULL;
#endif

    Log_method *method;
    
    method = log_open (getprogname(), "/dev/stderr");
    if (method == NULL)
        errx (1, "log_open failed");

    cell_init(0, method);

    Py_INCREF(Py_None);
    return Py_None;

    // return Py_BuildValue("s", keys[row-1][col-1]);

}

static PyObject *
arla_dbservers(PyObject *self, PyObject *args)
{
    const char *cellname;

    if (!PyArg_ParseTuple(args, "s", &cellname)) {
        return NULL;
    }

    cell_entry *ce = cell_get_by_name(cellname);

    int num_db_servers;
    const cell_db_entry *dbservers = cell_dbservers_by_id(ce->id, &num_db_servers);
    
    PyObject *list = PyList_New(num_db_servers);
    for (int i = 0; i < num_db_servers; i++) {
        PyList_SetItem(list, i, Py_BuildValue("I", ntohl(dbservers[i].addr.s_addr)));
    }

    return list;
}

typedef struct {
    PyObject_HEAD
    struct rx_connection *conn;
} rxconn_object;

static void
rxconn_dealloc(rxconn_object *conn)
{

}

static PyTypeObject rxconn_type = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "arla.rxconn",             /*tp_name*/
    sizeof(rxconn_object), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)rxconn_dealloc,/*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,        /*tp_flags*/
    "Rx connection",           /* tp_doc */
};



static PyObject *
arla_rxconn(PyObject *self, PyObject *args)
{
    unsigned int hostorder_addr;
    int port;
    int serviceid;

    if (!PyArg_ParseTuple(args, "Iii", &hostorder_addr, &port, &serviceid)) {
        return NULL;
    }

    struct rx_securityClass *secureobj;
    int secureindex;
    secureobj = rxnull_NewClientSecurityObject();
    secureindex = 0;
    
    struct rx_connection *conn;
    conn = rx_NewConnection(htonl(hostorder_addr), 
                            htons(port), 
                            serviceid,
                            secureobj,
                            secureindex);

    rxconn_object *ret = PyObject_New(rxconn_object, &rxconn_type);
    ret->conn = conn;
    return (PyObject*)ret;
}

static PyObject *
arla_VL_GetEntryByNameN(PyObject *self, PyObject *args)
{
    rxconn_object *conn;
    const char *volumename;

    if (!PyArg_ParseTuple(args, "O!s", &rxconn_type, &conn, &volumename)) {
        return NULL;
    }

    struct nvldbentry nvldbentry;
    int error;
    error = VL_GetEntryByNameN(conn->conn, volumename, &nvldbentry);

    PyObject *pyDictionary = PyDict_New();
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("firstServer"), PyInt_FromLong(nvldbentry.serverNumber[0]));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("firstServerPartition"), PyInt_FromLong(nvldbentry.serverPartition[0]));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("roexists"), PyBool_FromLong(nvldbentry.flags & VLF_ROEXISTS));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("ROVolumeId"), PyInt_FromLong(nvldbentry.volumeId[ROVOL]));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("RWVolumeId"), PyInt_FromLong(nvldbentry.volumeId[RWVOL]));
    return pyDictionary;
}

static PyObject *
arla_arlalib_getconnbyaddr(PyObject *self, PyObject *args)
{
    const char *cell;
    int32_t hostorder_addr;
    int port;
    int serviceid;

    if (!PyArg_ParseTuple(args, "siii", &cell, &hostorder_addr, &port, &serviceid)) {
        return NULL;
    }

    struct rx_securityClass *secureobj;
    int secureindex;
    secureobj = rxnull_NewClientSecurityObject();
    secureindex = 0;
    
    struct rx_connection *conn;

    conn = arlalib_getconnbyaddr(cell,
                                 htonl(hostorder_addr),
                                 NULL,
                                 port,
                                 serviceid,
                                 AUTHFLAGS_ANY);

    rxconn_object *ret = PyObject_New(rxconn_object, &rxconn_type);
    ret->conn = conn;
    return (PyObject*)ret;
}

static PyObject *
encode_status(AFSFetchStatus status)
{
    PyObject *pyDictionary = PyDict_New();
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("mountpoint"), PyBool_FromLong(status.FileType == TYPE_LINK && status.UnixModeBits == 0644));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("type"), PyInt_FromLong(status.FileType));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("length"), PyInt_FromLong(status.Length));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("dataversion"), PyInt_FromLong(status.DataVersion));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("mode"), PyInt_FromLong(status.UnixModeBits));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("modtime"), PyInt_FromLong(status.ClientModTime));
    return pyDictionary;
}

static PyObject *
fetchfile(PyObject *self, PyObject *args)
{
    rxconn_object *conn_object;
    AFSFid fid;
    uint32_t offset;
    uint32_t size;

    if (!PyArg_ParseTuple(args, "O!(III)II", &rxconn_type, &conn_object, &fid.Volume, &fid.Vnode, &fid.Unique, &offset, &size)) {
        return NULL;
    }

    struct rx_connection *conn = conn_object->conn;

    AFSFetchStatus status;
    AFSCallBack callback;
    AFSVolSync volsync;
    
    struct rx_call *call = rx_NewCall (conn);
    int ret;
    
    ret = StartRXAFS_FetchData (call,
                                &fid,
                                offset,
                                size);

    if (ret) {
        ret = rx_EndCall(call,ret);
        return PyErr_Format(PyExc_TypeError, "FileServer getFileWithFid(%d.%d.%d): start error %d(%s)", fid.Volume, fid.Vnode, fid.Unique, ret, koerr_gettext(ret));
    }
    
    uint32_t sizefs;
    
    ret = rx_Read (call, &sizefs, sizeof(sizefs));

#if 0
    fprintf(stderr, "FileServer getFileWithFid: read %d bytes", ret);
#endif
    if (ret != sizeof(sizefs)) {
        ret = rx_GetCallError(call);
        return PyErr_Format(PyExc_TypeError, "FileServer getFileWithFid(%d.%d.%d): sizefs error %d(%s)", fid.Volume, fid.Vnode, fid.Unique, ret, koerr_gettext(ret));
    }
    
    sizefs = ntohl(sizefs);
    
    char *buffer = malloc(sizefs);
    
    ret = rx_Read (call, buffer, sizefs);
    
    if (ret != sizefs) {
        int sizefetched = ret;
        ret = rx_EndCall(call,ret);
        PyErr_Format(PyExc_TypeError, "FileServer getFileWithFid(%d.%d.%d): content error %d(%s), size fetched %d", fid.Volume, fid.Vnode, fid.Unique, ret, koerr_gettext(ret), sizefetched);
        free(buffer);
        return NULL;
    }
    
    ret = EndRXAFS_FetchData (call,
                              &status,
                              &callback,
                              &volsync);
    
    if (ret) {
        ret = rx_EndCall(call,ret);
        PyErr_Format(PyExc_TypeError, "FileServer getFileWithFid(%d.%d.%d): end error %d(%s)", fid.Volume, fid.Vnode, fid.Unique, ret, koerr_gettext(ret));
        free(buffer);
        return NULL;
    }

    rx_EndCall(call,ret);

    PyObject *contents = PyByteArray_FromStringAndSize(buffer, sizefs);
    free(buffer);
    PyObject *pyDictionary = PyDict_New();
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("contents"), contents);
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("status"), encode_status(status));
    return pyDictionary;
}



static PyObject *pack_fid(AFSFid fid)
{
    return PyTuple_Pack(3, PyInt_FromLong(fid.Volume), PyInt_FromLong(fid.Vnode), PyInt_FromLong(fid.Unique));
}

static PyObject *
fetchbulkstatus(PyObject *self, PyObject *args)
{
    rxconn_object *conn_object;
    PyObject *fids_object;
    AFSFid fid;

    if (!PyArg_ParseTuple(args, "O!O!", &rxconn_type, &conn_object, &PyList_Type, &fids_object)) {
        return NULL;
    }

    Py_ssize_t nfids = PyList_Size(fids_object);
    AFSCBFids afsfids;
    afsfids.val = malloc(sizeof(AFSFid) * nfids);
    afsfids.len = nfids;

    for (int i = 0; i < nfids; i++) {
        PyObject *fid_object = PyList_GetItem(fids_object, i);

        AFSFid fid;
        fid.Volume = PyInt_AsLong(PyTuple_GetItem(fid_object, 0));
        fid.Vnode = PyInt_AsLong(PyTuple_GetItem(fid_object, 1));
        fid.Unique = PyInt_AsLong(PyTuple_GetItem(fid_object, 2));

        afsfids.val[i] = fid;
    }

    struct rx_connection *conn = conn_object->conn;

    AFSBulkStats stats;
    AFSCBs cbs;
    AFSVolSync volsync;
    
    int ret;

    stats.val = NULL;
    cbs.val = NULL;
    stats.len = cbs.len = 0;
    
    ret = RXAFS_BulkStatus(conn, &afsfids, &stats, &cbs, &volsync);

    if (ret && ret != ARLA_VNOVNODE) {
        PyErr_Format(PyExc_TypeError, "FileServer BulkStatus: error %d(%s)", ret, koerr_gettext(ret));
        free(afsfids.val);
        return NULL;
    }

    PyObject *entries = PyList_New(0);

    for (int i = 0; i < afsfids.len; i++) {
        PyObject *fileStatus;
        if (ret == 0) {
            fileStatus = encode_status(stats.val[i]);
        } else {
            PyErr_Format(PyExc_TypeError, "FileServer BulkStatus: NOVNODE recovery not implemented");
            free(afsfids.val);
            return NULL;
        }
        PyObject *pyDictionary = PyDict_New();
        PyDict_SetItem(pyDictionary, PyUnicode_FromString("status"), fileStatus);
        PyDict_SetItem(pyDictionary, PyUnicode_FromString("fid"), pack_fid(afsfids.val[i]));
        PyList_Append(entries, pyDictionary);
    }

    free(afsfids.val);

    return entries;
}

static PyObject *
arla_rename(PyObject *self, PyObject *args)
{
    rxconn_object *conn_object;
    AFSFid olddir_fid;
    AFSFid newdir_fid;
    const char *oldname;
    const char *newname;

    if (!PyArg_ParseTuple(args, "O!(III)s(III)s", &rxconn_type, &conn_object,
                          &olddir_fid.Volume, &olddir_fid.Vnode, &olddir_fid.Unique,
                          &oldname,
                          &newdir_fid.Volume, &newdir_fid.Vnode, &newdir_fid.Unique,
                          &newname)) {
        return NULL;
    }

    struct rx_connection *conn = conn_object->conn;

    AFSFetchStatus orig_status, new_status;
    AFSVolSync volsync;
    
    int ret;

    ret = RXAFS_Rename (conn,
                        &olddir_fid,
                        oldname,
                        &newdir_fid,
                        newname,
                        &orig_status,
                        &new_status,
                        &volsync);

    if (ret) {
        PyErr_Format(PyExc_TypeError, "FileServer Rename: error %d(%s)", ret, koerr_gettext(ret));
        return NULL;
    }

    PyObject *pyDictionary = PyDict_New();
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("newstatus"), encode_status(new_status));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("origstatus"), encode_status(orig_status));

    return pyDictionary;
}

static PyObject *
arla_create(PyObject *self, PyObject *args)
{
    rxconn_object *conn_object;
    AFSFid dir_fid;
    AFSStoreStatus storestatus;
    const char *name;

    if (!PyArg_ParseTuple(args, "O!(III)sII", &rxconn_type, &conn_object,
                          &dir_fid.Volume, &dir_fid.Vnode, &dir_fid.Unique,
                          &name,
                          &storestatus.UnixModeBits, &storestatus.ClientModTime)) {
        return NULL;
    }

    storestatus.Mask = SS_MODEBITS | SS_MODTIME;

    struct rx_connection *conn = conn_object->conn;

    AFSFetchStatus status;
    AFSFetchStatus dirstatus;
    AFSVolSync volsync;
    AFSCallBack callback;
    AFSFid new_fid;
    
    int ret;

    ret = RXAFS_CreateFile (conn,
                            &dir_fid,
                            name,
                            &storestatus,
                            &new_fid,
                            &status,
                            &dirstatus,
                            &callback,
                            &volsync);

    if (ret) {
        PyErr_Format(PyExc_TypeError, "FileServer CreateFile: error %d(%s)", ret, koerr_gettext(ret));
        return NULL;
    }

    PyObject *pyDictionary = PyDict_New();
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("status"), encode_status(status));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("dirstatus"), encode_status(dirstatus));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("fid"), pack_fid(new_fid));

    return pyDictionary;
}

static PyObject *
arla_mkdir(PyObject *self, PyObject *args)
{
    rxconn_object *conn_object;
    AFSFid dir_fid;
    AFSStoreStatus storestatus;
    const char *name;

    if (!PyArg_ParseTuple(args, "O!(III)sII", &rxconn_type, &conn_object,
                          &dir_fid.Volume, &dir_fid.Vnode, &dir_fid.Unique,
                          &name,
                          &storestatus.UnixModeBits, &storestatus.ClientModTime)) {
        return NULL;
    }

    storestatus.Mask = SS_MODEBITS | SS_MODTIME;

    struct rx_connection *conn = conn_object->conn;

    AFSFetchStatus status;
    AFSFetchStatus dirstatus;
    AFSVolSync volsync;
    AFSCallBack callback;
    AFSFid new_fid;
    
    int ret;

    ret = RXAFS_MakeDir (conn,
                         &dir_fid,
                         name,
                         &storestatus,
                         &new_fid,
                         &status,
                         &dirstatus,
                         &callback,
                         &volsync);

    if (ret) {
        PyErr_Format(PyExc_TypeError, "FileServer MakeDir: error %d(%s)", ret, koerr_gettext(ret));
        return NULL;
    }

    PyObject *pyDictionary = PyDict_New();
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("status"), encode_status(status));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("dirstatus"), encode_status(dirstatus));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("fid"), pack_fid(new_fid));

    return pyDictionary;
}

static PyObject *
arla_remove(PyObject *self, PyObject *args)
{
    rxconn_object *conn_object;
    AFSFid dir_fid;
    const char *name;

    if (!PyArg_ParseTuple(args, "O!(III)s", &rxconn_type, &conn_object,
                          &dir_fid.Volume, &dir_fid.Vnode, &dir_fid.Unique,
                          &name)) {
        return NULL;
    }

    struct rx_connection *conn = conn_object->conn;

    AFSFetchStatus dirstatus;
    AFSVolSync volsync;
    
    int ret;

    ret = RXAFS_RemoveFile (conn,
                            &dir_fid,
                            name,
                            &dirstatus,
                            &volsync);

    if (ret) {
        PyErr_Format(PyExc_TypeError, "FileServer RemoveFile: error %d(%s)", ret, koerr_gettext(ret));
        return NULL;
    }

    return encode_status(dirstatus);
}

static PyObject *
arla_rmdir(PyObject *self, PyObject *args)
{
    rxconn_object *conn_object;
    AFSFid dir_fid;
    const char *name;

    if (!PyArg_ParseTuple(args, "O!(III)s", &rxconn_type, &conn_object,
                          &dir_fid.Volume, &dir_fid.Vnode, &dir_fid.Unique,
                          &name)) {
        return NULL;
    }

    struct rx_connection *conn = conn_object->conn;

    AFSFetchStatus dirstatus;
    AFSVolSync volsync;
    
    int ret;

    ret = RXAFS_RemoveDir (conn,
                           &dir_fid,
                           name,
                           &dirstatus,
                           &volsync);

    if (ret) {
        PyErr_Format(PyExc_TypeError, "FileServer RemoveDir: error %d(%s)", ret, koerr_gettext(ret));
        return NULL;
    }

    return encode_status(dirstatus);
}

static PyObject *
storewholefile(PyObject *self, PyObject *args)
{
    rxconn_object *conn_object;
    AFSFid fid;
    PyObject *contents_object;
    AFSStoreStatus storestatus;


    if (!PyArg_ParseTuple(args, "O!(III)O!II", &rxconn_type, &conn_object, &fid.Volume, &fid.Vnode, &fid.Unique, &PyByteArray_Type, &contents_object, &storestatus.UnixModeBits, &storestatus.ClientModTime)) {
        return NULL;
    }

    storestatus.Mask = SS_MODEBITS | SS_MODTIME;

    uint32_t size = PyByteArray_Size(contents_object);
    char *contents = PyByteArray_AsString(contents_object);

    struct rx_connection *conn = conn_object->conn;

    AFSFetchStatus status;
    AFSCallBack callback;
    AFSVolSync volsync;
    
    struct rx_call *call = rx_NewCall (conn);
    int ret;

    ret = StartRXAFS_StoreData64(call, &fid,
                                 &storestatus,
                                 0,
                                 size,
                                 size);
    
    if (ret) {
        ret = rx_EndCall(call,ret);
        return PyErr_Format(PyExc_TypeError, "FileServer StoreData(%d.%d.%d): start error %d(%s)", fid.Volume, fid.Vnode, fid.Unique, ret, koerr_gettext(ret));
    }

    ret = rx_Write (call, contents, size);
    
    if (ret != size) {
        ret = rx_EndCall(call,ret);
        return PyErr_Format(PyExc_TypeError, "FileServer StoreData(%d.%d.%d): content error %d(%s)", fid.Volume, fid.Vnode, fid.Unique, ret, koerr_gettext(ret));
    }
    

    ret = EndRXAFS_StoreData64(call, &status, &volsync);
    
    if (ret) {
        ret = rx_EndCall(call,ret);
        PyErr_Format(PyExc_TypeError, "FileServer StoreData(%d.%d.%d): end error %d(%s)", fid.Volume, fid.Vnode, fid.Unique, ret, koerr_gettext(ret));
        return NULL;
    }

    rx_EndCall(call,ret);

    return encode_status(status);
}

static int dir_fill_array(VenusFid * fid, const char *name, void *arg) {
    PyObject *array = arg;

    PyObject *fid_object = pack_fid(fid->fid);
    PyObject *pyDictionary = PyDict_New();
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("name"), PyString_FromString(name));
    PyDict_SetItem(pyDictionary, PyUnicode_FromString("fid"), fid_object);

    PyList_Append(array, pyDictionary);

#if 0
    NSMutableArray *array = arg;
    ViceFid *vicefid = [[ViceFid alloc] initWithCell: @"" AFSFid: fid->fid];
    NSString *name2 = [[[NSString alloc] initWithCString:name encoding: NSISOLatin1StringEncoding] autorelease];
    DirectoryEntry *entry = [[[DirectoryEntry alloc] initWithFid: vicefid name: name2] autorelease];
    [array addObject:entry];
#endif
#if 0
    printf("name %s\n", name);
#endif
    return 0;
}


static PyObject *
parsedirectory(PyObject *self, PyObject *args)
{
    PyObject *fetchedfile;
    PyObject *contents;
    rxconn_object *conn_object;
    AFSFid fid;
    uint32_t offset;
    uint32_t size;

    if (!PyArg_ParseTuple(args, "O!(III)", &PyDict_Type, &fetchedfile, &fid.Volume, &fid.Vnode, &fid.Unique)) {
        return NULL;
    }

    contents = PyDict_GetItemString(fetchedfile, "contents");

    fbuf dir;
    
    dir.len = PyByteArray_Size(contents);
    dir.buf = PyByteArray_AsString(contents);
    
    VenusFid vfid;
    
    vfid.Cell = 0;
    vfid.fid = fid;

    PyObject *entries = PyList_New(0);
    fdir_readdir(&dir, dir_fill_array, entries, vfid, NULL);

    return entries;
}

static PyObject *
giveupallcallbacks(PyObject *self, PyObject *args)
{
    rxconn_object *conn_object;

    if (!PyArg_ParseTuple(args, "O!", &rxconn_type, &conn_object)) {
        return NULL;
    }

    struct rx_connection *conn = conn_object->conn;

    int ret;

    ret = RXAFS_GiveUpAllCallBacks (conn);

    if (ret) {
        PyErr_Format(PyExc_TypeError, "FileServer GiveUpAllCallBacks: error %d(%s)", ret, koerr_gettext(ret));
        return NULL;
    }

    Py_INCREF(Py_None);
    return Py_None;
}

static PyMethodDef ArlaMethods[] = {
  {"init", arla_init, METH_VARARGS},
  {"dbservers", arla_dbservers, METH_VARARGS},
  {"rxconn", arla_rxconn, METH_VARARGS},
  {"VL_GetEntryByNameN", arla_VL_GetEntryByNameN, METH_VARARGS},
  {"getconnbyaddr", arla_arlalib_getconnbyaddr, METH_VARARGS},
  {"fetchfile", fetchfile, METH_VARARGS},
  {"fetchbulkstatus", fetchbulkstatus, METH_VARARGS},
  {"parsedirectory", parsedirectory, METH_VARARGS},
  {"rename", arla_rename, METH_VARARGS},
  {"create", arla_create, METH_VARARGS},
  {"mkdir", arla_mkdir, METH_VARARGS},
  {"remove", arla_remove, METH_VARARGS},
  {"rmdir", arla_rmdir, METH_VARARGS},
  {"storewholefile", storewholefile, METH_VARARGS},
  {"giveupallcallbacks", giveupallcallbacks, METH_VARARGS},
  {"sleep", arla_sleep, METH_VARARGS},
  {NULL, NULL}
};

void
initarlalow()
{
    (void) Py_InitModule("arlalow", ArlaMethods);
}
