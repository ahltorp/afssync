import os
import stat
from util import *
from afsutil import *

def synconefile(basepath, name, localfile, serverfile, basefile, parentfid):
    localchecksum = checksumfile(basepath + "/" + name) if localfile and stat.S_ISREG(localfile["mode"]) else None
    places = (localfile != None, basefile != None, serverfile != None)
    
    if places == (False, False, True):
        print name, "new on server"
        fetchfileandupdate(basepath, name, serverfile)
        readbasefiles()
#    elif places == (False, True, False):
#        pass
    elif places == (False, True, True):
        if basefile["filetype"] == 1:
            arlalow.remove(fs.fsconn, serverfile["parent"], serverfile["name"])
            cursor.execute('delete from files where path = ?', (name,))
            conn.commit()
            readbasefiles()
        elif basefile["filetype"] == 2:
            def removedir():
                arlalow.rmdir(fs.fsconn, serverfile["parent"], serverfile["name"])
                cursor.execute('delete from files where path = ?', (name,))
                conn.commit()
                readbasefiles()
            return (lambda curpath: not curpath.startswith(name), removedir)
        else:
            raise Exception("Cannot handle symlinks yet")
    elif places == (True, False, False):
        print name, "created on client"
        sendfileandupdate(basepath, name, localfile, parentfid)
        readbasefiles()
    elif places == (True, False, True):
        print name, "created on server and client"
        conflictresolution(basepath, name, localfile, serverfile)
    elif places == (True, True, False):
        print name, "removed from server"
        basefiletype = basefile["filetype"]
        if basefiletype == 1:
            os.rename(basepath + "/" + name, basepath+"/.afssync/trash/%d-%d" % (basefile["vnode"], basefile["uniq"]))
            cursor.execute("update files set deleted = 1 where path = ?", (name, ))
            conn.commit()
            readbasefiles()
        elif basefiletype == 2:
            def removedir():
                os.rmdir(basepath + "/" + name)
                cursor.execute("delete from files where path = ?", (name, ))
                conn.commit()
                readbasefiles()
            return (lambda curpath: not curpath.startswith(name), removedir)
        else:
            raise Exception("Cannot handle symlinks yet")
    elif places == (True, True, True):
        if basefile["filetype"] != serverfile["status"]["type"] or basefile["filetype"] != mode_to_filetype(localfile["mode"]):
            raise Exception(name + ": Cannot handle changed filetypes yet")
        if basefile["filetype"] == 1:
            changes = (localchecksum != basefile["checksum"],
                       (basefile["vnode"], basefile["uniq"], basefile["dataversion"]) != (serverfile["fid"][1], serverfile["fid"][2], serverfile["status"]["dataversion"]))
            if changes == (False, False):
                pass
            elif changes == (False, True):
                fetchfileandupdate(basepath, name, serverfile)
                readbasefiles()
            elif changes == (True, False):
                sendfileandupdate(basepath, name, localfile, parentfid, serverfile=serverfile)
                readbasefiles()
            else:
                raise Exception(name + ": Unhandled changes state " + str(changes))
        elif basefile["filetype"] == 2:
            # only care about changed mode
            # XXX implement mode changing
            pass
        else:
            raise Exception("Cannot handle symlinks yet")
    else:
        raise Exception("Unhandled places state " + str(places))

def dosync(allfiles, fs, localfilesdict, serverfilesdict, basefilesdict, basepath):
    delayedtasks = []
    for f in allfiles:
        for delayedtask in delayedtasks:
            (predicate, action) = delayedtask
            if predicate(f):
                action()
                delayedtasks.remove(delayedtask)
        if f == "/":
            continue
        parentpath = os.path.dirname(os.path.normpath(f))
        if parentpath == "/":
            parentfid = fs.rootfid
        else:
            parentbasefile = basefilesdict[parentpath + "/"]
            parentfid = (fs.rootfid[0], parentbasefile["vnode"], parentbasefile["uniq"])
        # print f, parentpath, parentfid
        localfile = localfilesdict.get(f)
        serverfile = serverfilesdict.get(f)
        basefile = basefilesdict.get(f)
        # if localfile:
        #    print "local mtime", localfile["mtime"], "mode %o" % (localfile["mode"]&0777), "size", localfile["size"]
        # if basefile:
        #    print "base mtime", basefile["localmodtime"], "mode %o" % basefile["mode"], "size", localfile["length"]
        # if serverfile:
        #    serverstat = status[serverfile["fid"]]
        #    print "server mtime", serverstat["modtime"], "mode %o" % serverstat["mode"], "size", serverstat["length"]
    
        delayedtask = synconefile(basepath, f, localfile, serverfile, basefile, parentfid)
        if delayedtask:
            delayedtasks[0:0] = [delayedtask]
        #    break
        #    print
    for (predicate, action) in delayedtasks:
        action()
