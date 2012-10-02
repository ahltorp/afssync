/* Generated from fs.xg */
#ifndef _fs_
#define _fs_

#include "atypes.h"

#include "fs_errors.h"
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
struct afsUUID {
     uint32_t time_low;
     uint16_t time_mid;
     uint16_t time_hi_and_version;
     char clock_seq_hi_and_reserved;
     char clock_seq_low;
     char node[ 6 ];
};
typedef struct afsUUID afsUUID;

#define AFSUUID_SIZE 44
char *ydr_encode_afsUUID(const afsUUID *o, char *ptr, size_t *total_len);
const char *ydr_decode_afsUUID(afsUUID *o, const char *ptr, size_t *total_len);
void ydr_print_afsUUID(afsUUID *o);
void ydr_free_afsUUID(afsUUID *o);
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
#define FLUSHMAX 10

typedef struct {
unsigned len;
int32_t *val;
} ViceIds;

#define VICEIDS_MAX_SIZE 44
char *ydr_encode_ViceIds(const ViceIds *o, char *ptr, size_t *total_len);
const char *ydr_decode_ViceIds(ViceIds *o, const char *ptr, size_t *total_len);
void ydr_print_ViceIds(ViceIds *o);
void ydr_free_ViceIds(ViceIds *o);
typedef struct {
unsigned len;
int32_t *val;
} IPAddrs;

#define IPADDRS_MAX_SIZE 44
char *ydr_encode_IPAddrs(const IPAddrs *o, char *ptr, size_t *total_len);
const char *ydr_decode_IPAddrs(IPAddrs *o, const char *ptr, size_t *total_len);
void ydr_print_IPAddrs(IPAddrs *o);
void ydr_free_IPAddrs(IPAddrs *o);

#endif /* fs */
