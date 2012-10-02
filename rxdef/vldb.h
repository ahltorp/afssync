/* Generated from vldb.xg */
#ifndef _vldb_
#define _vldb_

#include "atypes.h"

#include "fs_errors.h"
#include "fs.h"
#ifndef _COMMON_
#define _COMMON_
#define LockRead 0

#define LockWrite 1

#define LockExtend 2

#define LockRelease 3

#define AFSNAMEMAX 256

#define RWVOL 0

#define ROVOL 1

#define BACKVOL 2

struct AFSFid {
     uint32_t Volume;
     uint32_t Vnode;
     uint32_t Unique;
};
typedef struct AFSFid AFSFid;

#define AFSFID_SIZE 12
char *ydr_encode_AFSFid(const AFSFid *o, char *ptr, size_t *total_len);
const char *ydr_decode_AFSFid(AFSFid *o, const char *ptr, size_t *total_len);
void ydr_print_AFSFid(AFSFid *o);
void ydr_free_AFSFid(AFSFid *o);
struct VenusFid {
     int32_t Cell;
     struct AFSFid fid;
};
typedef struct VenusFid VenusFid;

#define VENUSFID_SIZE 16
char *ydr_encode_VenusFid(const VenusFid *o, char *ptr, size_t *total_len);
const char *ydr_decode_VenusFid(VenusFid *o, const char *ptr, size_t *total_len);
void ydr_print_VenusFid(VenusFid *o);
void ydr_free_VenusFid(VenusFid *o);
struct AFSCallBack {
     uint32_t CallBackVersion;
     uint32_t ExpirationTime;
     uint32_t CallBackType;
};
typedef struct AFSCallBack AFSCallBack;

#define AFSCALLBACK_SIZE 12
char *ydr_encode_AFSCallBack(const AFSCallBack *o, char *ptr, size_t *total_len);
const char *ydr_decode_AFSCallBack(AFSCallBack *o, const char *ptr, size_t *total_len);
void ydr_print_AFSCallBack(AFSCallBack *o);
void ydr_free_AFSCallBack(AFSCallBack *o);
enum CallBackType {
     CBEXCLUSIVE = 1,
     CBSHARED = 2,
     CBDROPPED = 3
};
typedef enum CallBackType CallBackType;

#define CALLBACKTYPE_SIZE 4
char *ydr_encode_CallBackType(const CallBackType *o, char *ptr, size_t *total_len);
const char *ydr_decode_CallBackType(CallBackType *o, const char *ptr, size_t *total_len);
void ydr_print_CallBackType(CallBackType *o);
void ydr_free_CallBackType(CallBackType *o);
#define CALLBACK_VERSION 1

struct AFSVolSync {
     uint32_t spare1;
     uint32_t spare2;
     uint32_t spare3;
     uint32_t spare4;
     uint32_t spare5;
     uint32_t spare6;
};
typedef struct AFSVolSync AFSVolSync;

#define AFSVOLSYNC_SIZE 24
char *ydr_encode_AFSVolSync(const AFSVolSync *o, char *ptr, size_t *total_len);
const char *ydr_decode_AFSVolSync(AFSVolSync *o, const char *ptr, size_t *total_len);
void ydr_print_AFSVolSync(AFSVolSync *o);
void ydr_free_AFSVolSync(AFSVolSync *o);
#define TYPE_FILE 1

#define TYPE_DIR 2

#define TYPE_LINK 3

struct AFSFetchStatus {
     uint32_t InterfaceVersion;
     uint32_t FileType;
     uint32_t LinkCount;
     uint32_t Length;
     uint32_t DataVersion;
     uint32_t Author;
     uint32_t Owner;
     uint32_t CallerAccess;
     uint32_t AnonymousAccess;
     uint32_t UnixModeBits;
     uint32_t ParentVnode;
     uint32_t ParentUnique;
     uint32_t ResidencyMask;
     uint32_t ClientModTime;
     uint32_t ServerModTime;
     uint32_t Group;
     uint32_t SyncCounter;
     uint32_t DataVersionHigh;
     uint32_t LockCount;
     uint32_t LengthHigh;
     uint32_t ErrorCode;
};
typedef struct AFSFetchStatus AFSFetchStatus;

#define AFSFETCHSTATUS_SIZE 84
char *ydr_encode_AFSFetchStatus(const AFSFetchStatus *o, char *ptr, size_t *total_len);
const char *ydr_decode_AFSFetchStatus(AFSFetchStatus *o, const char *ptr, size_t *total_len);
void ydr_print_AFSFetchStatus(AFSFetchStatus *o);
void ydr_free_AFSFetchStatus(AFSFetchStatus *o);
#define SS_MODTIME 1

#define SS_OWNER 2

#define SS_GROUP 4

#define SS_MODEBITS 8

#define SS_SEGSIZE 16

#define SS_FSYNC 1024

struct AFSStoreStatus {
     uint32_t Mask;
     uint32_t ClientModTime;
     uint32_t Owner;
     uint32_t Group;
     uint32_t UnixModeBits;
     uint32_t SegSize;
};
typedef struct AFSStoreStatus AFSStoreStatus;

#define AFSSTORESTATUS_SIZE 24
char *ydr_encode_AFSStoreStatus(const AFSStoreStatus *o, char *ptr, size_t *total_len);
const char *ydr_decode_AFSStoreStatus(AFSStoreStatus *o, const char *ptr, size_t *total_len);
void ydr_print_AFSStoreStatus(AFSStoreStatus *o);
void ydr_free_AFSStoreStatus(AFSStoreStatus *o);
struct AFSFetchVolumeStatus {
     int32_t Vid;
     int32_t ParentId;
     char Online;
     char InService;
     char Blessed;
     char NeedsSalvage;
     int32_t Type;
     int32_t MinQuota;
     int32_t MaxQuota;
     int32_t BlocksInUse;
     int32_t PartBlocksAvail;
     int32_t PartMaxBlocks;
};
typedef struct AFSFetchVolumeStatus AFSFetchVolumeStatus;

#define AFSFETCHVOLUMESTATUS_SIZE 48
char *ydr_encode_AFSFetchVolumeStatus(const AFSFetchVolumeStatus *o, char *ptr, size_t *total_len);
const char *ydr_decode_AFSFetchVolumeStatus(AFSFetchVolumeStatus *o, const char *ptr, size_t *total_len);
void ydr_print_AFSFetchVolumeStatus(AFSFetchVolumeStatus *o);
void ydr_free_AFSFetchVolumeStatus(AFSFetchVolumeStatus *o);
struct AFSStoreVolumeStatus {
     int32_t Mask;
     int32_t MinQuota;
     int32_t MaxQuota;
};
typedef struct AFSStoreVolumeStatus AFSStoreVolumeStatus;

#define AFSSTOREVOLUMESTATUS_SIZE 12
char *ydr_encode_AFSStoreVolumeStatus(const AFSStoreVolumeStatus *o, char *ptr, size_t *total_len);
const char *ydr_decode_AFSStoreVolumeStatus(AFSStoreVolumeStatus *o, const char *ptr, size_t *total_len);
void ydr_print_AFSStoreVolumeStatus(AFSStoreVolumeStatus *o);
void ydr_free_AFSStoreVolumeStatus(AFSStoreVolumeStatus *o);
#define AFS_SETMINQUOTA 1

#define AFS_SETMAXQUOTA 2

#define AFSOPAQUEMAX 1024

typedef struct {
unsigned len;
char *val;
} AFSOpaque;

#define AFSOPAQUE_MAX_SIZE 1028
char *ydr_encode_AFSOpaque(const AFSOpaque *o, char *ptr, size_t *total_len);
const char *ydr_decode_AFSOpaque(AFSOpaque *o, const char *ptr, size_t *total_len);
void ydr_print_AFSOpaque(AFSOpaque *o);
void ydr_free_AFSOpaque(AFSOpaque *o);
typedef int32_t ViceLockType;

#define VICELOCKTYPE_SIZE 4
char *ydr_encode_ViceLockType(const ViceLockType *o, char *ptr, size_t *total_len);
const char *ydr_decode_ViceLockType(ViceLockType *o, const char *ptr, size_t *total_len);
void ydr_print_ViceLockType(ViceLockType *o);
void ydr_free_ViceLockType(ViceLockType *o);
#define AFSCBMAX 50

typedef struct {
unsigned len;
struct AFSCallBack *val;
} AFSCBs;

#define AFSCBS_MAX_SIZE 604
char *ydr_encode_AFSCBs(const AFSCBs *o, char *ptr, size_t *total_len);
const char *ydr_decode_AFSCBs(AFSCBs *o, const char *ptr, size_t *total_len);
void ydr_print_AFSCBs(AFSCBs *o);
void ydr_free_AFSCBs(AFSCBs *o);
typedef struct {
unsigned len;
struct AFSFetchStatus *val;
} AFSBulkStats;

#define AFSBULKSTATS_MAX_SIZE 4204
char *ydr_encode_AFSBulkStats(const AFSBulkStats *o, char *ptr, size_t *total_len);
const char *ydr_decode_AFSBulkStats(AFSBulkStats *o, const char *ptr, size_t *total_len);
void ydr_print_AFSBulkStats(AFSBulkStats *o);
void ydr_free_AFSBulkStats(AFSBulkStats *o);
typedef struct {
unsigned len;
struct AFSFid *val;
} AFSCBFids;

#define AFSCBFIDS_MAX_SIZE 604
char *ydr_encode_AFSCBFids(const AFSCBFids *o, char *ptr, size_t *total_len);
const char *ydr_decode_AFSCBFids(AFSCBFids *o, const char *ptr, size_t *total_len);
void ydr_print_AFSCBFids(AFSCBFids *o);
void ydr_free_AFSCBFids(AFSCBFids *o);
#define PRSFS_READ 1

#define PRSFS_WRITE 2

#define PRSFS_INSERT 4

#define PRSFS_LOOKUP 8

#define PRSFS_DELETE 16

#define PRSFS_LOCK 32

#define PRSFS_ADMINISTER 64

struct AFSVolumeInfo {
     uint32_t Vid;
     int32_t Type;
     uint32_t Type0;
     uint32_t Type1;
     uint32_t Type2;
     uint32_t Type3;
     uint32_t Type4;
     uint32_t ServerCount;
     uint32_t Server0;
     uint32_t Server1;
     uint32_t Server2;
     uint32_t Server3;
     uint32_t Server4;
     uint32_t Server5;
     uint32_t Server6;
     uint32_t Server7;
     uint16_t Port0;
     uint16_t Port1;
     uint16_t Port2;
     uint16_t Port3;
     uint16_t Port4;
     uint16_t Port5;
     uint16_t Port6;
     uint16_t Port7;
};
typedef struct AFSVolumeInfo AFSVolumeInfo;

#define AFSVOLUMEINFO_SIZE 96
char *ydr_encode_AFSVolumeInfo(const AFSVolumeInfo *o, char *ptr, size_t *total_len);
const char *ydr_decode_AFSVolumeInfo(AFSVolumeInfo *o, const char *ptr, size_t *total_len);
void ydr_print_AFSVolumeInfo(AFSVolumeInfo *o);
void ydr_free_AFSVolumeInfo(AFSVolumeInfo *o);
#ifndef _AFSUUID_COMMON_
#define _AFSUUID_COMMON_
#endif 
#define AFSCAPABILITIESMAX 196

typedef struct {
unsigned len;
int32_t *val;
} Capabilities;

#define CAPABILITIES_MAX_SIZE 788
char *ydr_encode_Capabilities(const Capabilities *o, char *ptr, size_t *total_len);
const char *ydr_decode_Capabilities(Capabilities *o, const char *ptr, size_t *total_len);
void ydr_print_Capabilities(Capabilities *o);
void ydr_free_Capabilities(Capabilities *o);
#endif 
#define VLDB_MAXNAMELEN 65

#define MAXNSERVERS 8

#define NMAXNSERVERS 13

#define MAX_NUMBER_OPCODES 30

#define MAXTYPES 3

#define MAXSERVERID 30

#define HASHSIZE 8191

#define DEFAULTBULK 10000

typedef struct {
unsigned len;
char *val;
} bulk;

#define BULK_MAX_SIZE 10004
char *ydr_encode_bulk(const bulk *o, char *ptr, size_t *total_len);
const char *ydr_decode_bulk(bulk *o, const char *ptr, size_t *total_len);
void ydr_print_bulk(bulk *o);
void ydr_free_bulk(bulk *o);
#define VLSF_NEWREPSITE 1

#define VLSF_ROVOL 2

#define VLSF_RWVOL 4

#define VLSF_BACKVOL 8

#define VLSF_UUID 16

#define VLSF_DONTUSE 32

#define VLFREE 1

#define VLDELETED 2

#define VLLOCKED 4

#define VLOP_MOVE 16

#define VLOP_RELEASE 32

#define VLOP_BACKUP 64

#define VLOP_DELETE 128

#define VLOP_DUMP 256

#define VLOP_ALLOPERS ( VLOP_MOVE | VLOP_RELEASE | VLOP_BACKUP | VLOP_DELETE | VLOP_DUMP)
#define VLF_RWEXISTS 4096

#define VLF_ROEXISTS 8192

#define VLF_BOEXISTS 16384

#define VLF_BACKEXISTS 16384

#define VLF_DFSFILESET 32768

#define VL_IDEXIST 363520

#define VL_IO 363521

#define VL_NAMEEXIST 363522

#define VL_CREATEFAIL 363523

#define VL_NOENT 363524

#define VL_EMPTY 363525

#define VL_ENTDELETED 363526

#define VL_BADNAME 363527

#define VL_BADINDEX 363528

#define VL_BADVOLTYPE 363529

#define VL_BADPARTITION 363530

#define VL_BADSERVER 363531

#define VL_REPSFULL 363532

#define VL_NOREPSERVER 363533

#define VL_DUPREPSERVER 363534

#define VL_RWNOTFOUND 363535

#define VL_BADREFCOUNT 363536

#define VL_SIZEEXCEEDED 363537

#define VL_BADENTRY 363538

#define VL_BADVOLIDBUMP 363539

#define VL_IDALREADHASED 363540

#define VL_ENTRYLOCKED 363541

#define VL_BADVOLOPER 363542

#define VL_BADRELLOCKTYPE 363543

#define VL_RERELEASE 363544

#define VL_BADSERVERFLAG 363545

#define VL_PERM 363546

#define VL_NOMEM 363547

#define VL_BADVERSION 363548

#define VL_INDEXERANGE 363549

#define VL_MULTIPADDR 363550

#define VL_BADMASK 363551

#define VLCREATEENTRY 501

#define VLDELETEENTRY 502

#define VLGETENTRYBYID 503

#define VLGETENTRYBYNAME 504

#define VLGETNEWVOLUMEID 505

#define VLREPLACEENTRY 506

#define VLUPDATEENTRY 507

#define VLSETLOCK 508

#define VLRELEASELOCK 509

#define VLLISTENTRY 510

#define VLLISTATTRIBUTES 511

#define VLLINKEDLIST 512

#define VLGETSTATS 513

#define VLPROBE 514

#define VLGETADDRS 515

#define VLCHANGEADDR 516

#define VLCREATEENTRYN 517

#define VLGETENTRYBYIDN 518

#define VLGETENTRYBYNAMEN 519

#define VLREPLACEENTRYN 520

#define VLLISTENTRYN 521

#define VLLISTATTRIBUTESN 522

#define VLLINKEDLISTN 523

#define VLUPDATEENTRYBYNAME 524

#define VLCREATEENTRYU 525

#define VLGETENTRYBYIDU 526

#define VLGETENTRYBYNAMEU 527

#define VLREPLACEENTRYU 528

#define VLLISTENTRYU 529

#define VLLISTATTRIBUTESU 530

#define VLLINKEDLISTU 531

#define VLREGADDR 532

#define VLGETADDRSU 533

#define VLLISTATTRIBUTESN2 534

#define LOCKREL_TIMESTAMP 1

#define LOCKREL_OPCODE 2

#define LOCKREL_AFSID 4

struct vldbentry {
     char name[ 65 ];
     int32_t volumeType;
     int32_t nServers;
     int32_t serverNumber[ 8 ];
     int32_t serverPartition[ 8 ];
     int32_t serverFlags[ 8 ];
     uint32_t volumeId[ 3 ];
     int32_t cloneId;
     int32_t flags;
};
typedef struct vldbentry vldbentry;

#define VLDBENTRY_SIZE 384
char *ydr_encode_vldbentry(const vldbentry *o, char *ptr, size_t *total_len);
const char *ydr_decode_vldbentry(vldbentry *o, const char *ptr, size_t *total_len);
void ydr_print_vldbentry(vldbentry *o);
void ydr_free_vldbentry(vldbentry *o);
struct nvldbentry {
     char name[ 65 ];
     int32_t nServers;
     int32_t serverNumber[ 13 ];
     int32_t serverPartition[ 13 ];
     int32_t serverFlags[ 13 ];
     uint32_t volumeId[ 3 ];
     int32_t cloneId;
     int32_t flags;
     int32_t matchindex;
     int32_t spares2;
     int32_t spares3;
     int32_t spares4;
     int32_t spares5;
     int32_t spares6;
     int32_t spares7;
     int32_t spares8;
     int32_t spares9;
};
typedef struct nvldbentry nvldbentry;

#define NVLDBENTRY_SIZE 476
char *ydr_encode_nvldbentry(const nvldbentry *o, char *ptr, size_t *total_len);
const char *ydr_decode_nvldbentry(nvldbentry *o, const char *ptr, size_t *total_len);
void ydr_print_nvldbentry(nvldbentry *o);
void ydr_free_nvldbentry(nvldbentry *o);
struct vlentry {
     uint32_t volumeId[ 3 ];
     int32_t flags;
     int32_t LockAfsId;
     int32_t LockTimestamp;
     int32_t cloneId;
     int32_t AssociatedChain;
     int32_t nextIdHash[ 3 ];
     int32_t nextNameHash;
     int32_t spares1[ 2 ];
     char name[ 65 ];
     unsigned char volumeType;
     unsigned char serverNumber[ 8 ];
     unsigned char serverPartition[ 8 ];
     unsigned char serverFlags[ 8 ];
     unsigned char RefCount;
     char spares2[ 1 ];
};
typedef struct vlentry vlentry;

#define VLENTRY_SIZE 424
char *ydr_encode_vlentry(const vlentry *o, char *ptr, size_t *total_len);
const char *ydr_decode_vlentry(vlentry *o, const char *ptr, size_t *total_len);
void ydr_print_vlentry(vlentry *o);
void ydr_free_vlentry(vlentry *o);
struct disk_vlentry {
     uint32_t volumeId[ 3 ];
     int32_t flags;
     int32_t cloneId;
     char *name;
     struct {
unsigned len;
int32_t *val;
} serverNumber;
     struct {
unsigned len;
int32_t *val;
} serverPartition;
     struct {
unsigned len;
int32_t *val;
} serverFlags;
};
typedef struct disk_vlentry disk_vlentry;

char *ydr_encode_disk_vlentry(const disk_vlentry *o, char *ptr, size_t *total_len);
const char *ydr_decode_disk_vlentry(disk_vlentry *o, const char *ptr, size_t *total_len);
void ydr_print_disk_vlentry(disk_vlentry *o);
void ydr_free_disk_vlentry(disk_vlentry *o);
struct vital_vlheader {
     int32_t vldbversion;
     int32_t headersize;
     int32_t freePtr;
     int32_t eofPtr;
     int32_t allocs;
     int32_t frees;
     int32_t MaxVolumeId;
     int32_t totalEntries[ 3 ];
};
typedef struct vital_vlheader vital_vlheader;

#define VITAL_VLHEADER_SIZE 40
char *ydr_encode_vital_vlheader(const vital_vlheader *o, char *ptr, size_t *total_len);
const char *ydr_decode_vital_vlheader(vital_vlheader *o, const char *ptr, size_t *total_len);
void ydr_print_vital_vlheader(vital_vlheader *o);
void ydr_free_vital_vlheader(vital_vlheader *o);
typedef int32_t longarray[ 3 ];

#define LONGARRAY_SIZE 12
char *ydr_encode_longarray(const longarray *o, char *ptr, size_t *total_len);
const char *ydr_decode_longarray(longarray *o, const char *ptr, size_t *total_len);
void ydr_print_longarray(longarray *o);
void ydr_free_longarray(longarray *o);
struct vlheader {
     struct vital_vlheader vital_header;
     uint32_t IpMappedAddr[ 30 ];
     int32_t VolnameHash[ 8191 ];
     longarray VolidHash[ 8191 ];
};
typedef struct vlheader vlheader;

#define VLHEADER_SIZE 131216
char *ydr_encode_vlheader(const vlheader *o, char *ptr, size_t *total_len);
const char *ydr_decode_vlheader(vlheader *o, const char *ptr, size_t *total_len);
void ydr_print_vlheader(vlheader *o);
void ydr_free_vlheader(vlheader *o);
#define VLUPDATE_VOLUMENAME 1

#define VLUPDATE_FLAGS 4

#define VLUPDATE_READONLYID 8

#define VLUPDATE_BACKUPID 16

#define VLUPDATE_REPSITES 32

#define VLUPDATE_CLONEID 128

#define VLUPDATE_VOLNAMEHASH 256

#define VLUPDATE_RWID 512

#define VLUPDATE_REPS_DELETE 256

#define VLUPDATE_REPS_ADD 512

#define VLUPDATE_REPS_MODSERV 1024

#define VLUPDATE_REPS_MODPART 2048

#define VLUPDATE_REPS_MODFLAG 4096

struct VldbUpdateEntry {
     uint32_t Mask;
     char name[ 65 ];
     int32_t volumeType;
     int32_t flags;
     uint32_t ReadOnlyId;
     uint32_t BackupId;
     int32_t cloneid;
     int32_t nModifiedRepsites;
     uint32_t RepsitesMask[ 8 ];
     int32_t RepsitesTargetServer[ 8 ];
     int32_t RepsitesTargetPart[ 8 ];
     int32_t RepsitesNewServer[ 8 ];
     int32_t RepsitesNewPart[ 8 ];
     int32_t RepsitesNewFlags[ 8 ];
};
typedef struct VldbUpdateEntry VldbUpdateEntry;

#define VLDBUPDATEENTRY_SIZE 480
char *ydr_encode_VldbUpdateEntry(const VldbUpdateEntry *o, char *ptr, size_t *total_len);
const char *ydr_decode_VldbUpdateEntry(VldbUpdateEntry *o, const char *ptr, size_t *total_len);
void ydr_print_VldbUpdateEntry(VldbUpdateEntry *o);
void ydr_free_VldbUpdateEntry(VldbUpdateEntry *o);
#define VLLIST_SERVER 1

#define VLLIST_PARTITION 2

#define VLLIST_VOLUMEID 8

#define VLLIST_FLAG 16

struct VldbListByAttributes {
     uint32_t Mask;
     int32_t server;
     int32_t partition;
     int32_t volumetype;
     int32_t volumeid;
     int32_t flag;
};
typedef struct VldbListByAttributes VldbListByAttributes;

#define VLDBLISTBYATTRIBUTES_SIZE 24
char *ydr_encode_VldbListByAttributes(const VldbListByAttributes *o, char *ptr, size_t *total_len);
const char *ydr_decode_VldbListByAttributes(VldbListByAttributes *o, const char *ptr, size_t *total_len);
void ydr_print_VldbListByAttributes(VldbListByAttributes *o);
void ydr_free_VldbListByAttributes(VldbListByAttributes *o);
struct uvldbentry {
     char name[ 65 ];
     int32_t nServers;
     struct afsUUID serverNumber[ 13 ];
     int32_t serverUnique[ 13 ];
     int32_t serverPartition[ 13 ];
     int32_t serverFlags[ 13 ];
     uint32_t volumeId[ 3 ];
     int32_t cloneId;
     int32_t flags;
     int32_t spares1;
     int32_t spares2;
     int32_t spares3;
     int32_t spares4;
     int32_t spares5;
     int32_t spares6;
     int32_t spares7;
     int32_t spares8;
     int32_t spares9;
};
typedef struct uvldbentry uvldbentry;

#define UVLDBENTRY_SIZE 1048
char *ydr_encode_uvldbentry(const uvldbentry *o, char *ptr, size_t *total_len);
const char *ydr_decode_uvldbentry(uvldbentry *o, const char *ptr, size_t *total_len);
void ydr_print_uvldbentry(uvldbentry *o);
void ydr_free_uvldbentry(uvldbentry *o);
struct vldstats {
     uint32_t start_time;
     int32_t requests[ 30 ];
     int32_t aborts[ 30 ];
     int32_t reserved[ 5 ];
};
typedef struct vldstats vldstats;

#define VLDSTATS_SIZE 264
char *ydr_encode_vldstats(const vldstats *o, char *ptr, size_t *total_len);
const char *ydr_decode_vldstats(vldstats *o, const char *ptr, size_t *total_len);
void ydr_print_vldstats(vldstats *o);
void ydr_free_vldstats(vldstats *o);
#define VL_MAX_BULK_ADDRS 1024

typedef struct {
unsigned len;
struct vldbentry *val;
} bulkentries;

char *ydr_encode_bulkentries(const bulkentries *o, char *ptr, size_t *total_len);
const char *ydr_decode_bulkentries(bulkentries *o, const char *ptr, size_t *total_len);
void ydr_print_bulkentries(bulkentries *o);
void ydr_free_bulkentries(bulkentries *o);
typedef struct {
unsigned len;
struct nvldbentry *val;
} nbulkentries;

char *ydr_encode_nbulkentries(const nbulkentries *o, char *ptr, size_t *total_len);
const char *ydr_decode_nbulkentries(nbulkentries *o, const char *ptr, size_t *total_len);
void ydr_print_nbulkentries(nbulkentries *o);
void ydr_free_nbulkentries(nbulkentries *o);
typedef struct {
unsigned len;
struct uvldbentry *val;
} ubulkentries;

char *ydr_encode_ubulkentries(const ubulkentries *o, char *ptr, size_t *total_len);
const char *ydr_decode_ubulkentries(ubulkentries *o, const char *ptr, size_t *total_len);
void ydr_print_ubulkentries(ubulkentries *o);
void ydr_free_ubulkentries(ubulkentries *o);
typedef struct {
unsigned len;
int32_t *val;
} bulkaddrs;

#define BULKADDRS_MAX_SIZE 4100
char *ydr_encode_bulkaddrs(const bulkaddrs *o, char *ptr, size_t *total_len);
const char *ydr_decode_bulkaddrs(bulkaddrs *o, const char *ptr, size_t *total_len);
void ydr_print_bulkaddrs(bulkaddrs *o);
void ydr_free_bulkaddrs(bulkaddrs *o);
#define VLADDR_IPADDR 1

#define VLADDR_INDEX 2

#define VLADDR_UUID 4

struct ListAddrByAttributes {
     int32_t Mask;
     uint32_t ipaddr;
     int32_t index;
     int32_t spare;
     struct afsUUID uuid;
};
typedef struct ListAddrByAttributes ListAddrByAttributes;

#define LISTADDRBYATTRIBUTES_SIZE 60
char *ydr_encode_ListAddrByAttributes(const ListAddrByAttributes *o, char *ptr, size_t *total_len);
const char *ydr_decode_ListAddrByAttributes(ListAddrByAttributes *o, const char *ptr, size_t *total_len);
void ydr_print_ListAddrByAttributes(ListAddrByAttributes *o);
void ydr_free_ListAddrByAttributes(ListAddrByAttributes *o);
struct VL_Callback {
     uint32_t version;
     uint32_t expiration_time;
     uint32_t time;
     uint32_t handle;
};
typedef struct VL_Callback VL_Callback;

#define VL_CALLBACK_SIZE 16
char *ydr_encode_VL_Callback(const VL_Callback *o, char *ptr, size_t *total_len);
const char *ydr_decode_VL_Callback(VL_Callback *o, const char *ptr, size_t *total_len);
void ydr_print_VL_Callback(VL_Callback *o);
void ydr_free_VL_Callback(VL_Callback *o);

#endif /* vldb */
