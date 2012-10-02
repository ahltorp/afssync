/* Generated from fs.xg */
#include <rx/rx.h>
#include "fs.h"

int SRXAFS_FetchData(
struct rx_call *call
, const struct AFSFid *a_fidToFetchP
, const int32_t a_offset
, const int32_t a_lenInBytes
, struct AFSFetchStatus *a_fidStatP
, struct AFSCallBack *a_callBackP
, struct AFSVolSync *a_volSyncP
);

int SRXAFS_FetchACL(
struct rx_call *call
, const struct AFSFid *a_dirFidP
, AFSOpaque *a_ACLP
, struct AFSFetchStatus *a_dirNewStatP
, struct AFSVolSync *a_volSyncP
);

int SRXAFS_FetchStatus(
struct rx_call *call
, const struct AFSFid *a_fidToStatP
, struct AFSFetchStatus *a_currStatP
, struct AFSCallBack *a_callBackP
, struct AFSVolSync *a_volSyncP
);

int SRXAFS_StoreData(
struct rx_call *call
, const struct AFSFid *a_fidToStoreP
, const struct AFSStoreStatus *a_fidStatusP
, const int32_t a_offset
, const int32_t a_lenInBytes
, const int32_t a_fileLenInBytes
, struct AFSFetchStatus *a_fidStatP
, struct AFSVolSync *a_volSyncP
);

int SRXAFS_StoreACL(
struct rx_call *call
, const struct AFSFid *a_dirFidP
, const AFSOpaque *a_ACLToStoreP
, struct AFSFetchStatus *a_dirNewStatP
, struct AFSVolSync *a_volSyncP
);

int SRXAFS_StoreStatus(
struct rx_call *call
, const struct AFSFid *a_fidP
, const struct AFSStoreStatus *a_currStatusP
, struct AFSFetchStatus *a_srStatusP
, struct AFSVolSync *a_volSyncP
);

int SRXAFS_RemoveFile(
struct rx_call *call
, const struct AFSFid *a_dirFidP
, const char *a_name
, struct AFSFetchStatus *a_srvStatusP
, struct AFSVolSync *a_volSyncP
);

int SRXAFS_CreateFile(
struct rx_call *call
, const struct AFSFid *DirFid
, const char *Name
, const struct AFSStoreStatus *InStatus
, struct AFSFid *OutFid
, struct AFSFetchStatus *OutFidStatus
, struct AFSFetchStatus *OutDirStatus
, struct AFSCallBack *CallBack
, struct AFSVolSync *a_volSyncP
);

int SRXAFS_Rename(
struct rx_call *call
, const struct AFSFid *a_origDirFidP
, const char *a_origNameP
, const struct AFSFid *a_newDirFidP
, const char *a_newNameP
, struct AFSFetchStatus *a_origDirStatusP
, struct AFSFetchStatus *a_newDirStatusP
, struct AFSVolSync *a_volSyncP
);

int SRXAFS_Symlink(
struct rx_call *call
, const struct AFSFid *a_dirFidP
, const char *a_nameP
, const char *a_linkContentsP
, const struct AFSStoreStatus *a_origDirStatP
, struct AFSFid *a_newFidP
, struct AFSFetchStatus *a_newFidStatP
, struct AFSFetchStatus *a_newDirStatP
, struct AFSVolSync *a_volSyncP
);

int SRXAFS_Link(
struct rx_call *call
, const struct AFSFid *a_dirFidP
, const char *a_nameP
, const struct AFSFid *a_existingFidP
, struct AFSFetchStatus *a_newFidStatP
, struct AFSFetchStatus *a_newDirStatP
, struct AFSVolSync *a_volSyncP
);

int SRXAFS_MakeDir(
struct rx_call *call
, const struct AFSFid *a_parentDirFidP
, const char *a_newDirNameP
, const struct AFSStoreStatus *a_currStatP
, struct AFSFid *a_newDirFidP
, struct AFSFetchStatus *a_dirFidStatP
, struct AFSFetchStatus *a_parentDirStatP
, struct AFSCallBack *a_newDirCallBackP
, struct AFSVolSync *a_volSyncP
);

int SRXAFS_RemoveDir(
struct rx_call *call
, const struct AFSFid *a_parentDirStatP
, const char *a_dirNameP
, struct AFSFetchStatus *a_newParentDirStatP
, struct AFSVolSync *a_volSyncP
);

int SRXAFS_GiveUpCallBacks(
struct rx_call *call
, const AFSCBFids *a_fidArrayP
, const AFSCBs *a_callBackArrayP
);

int SRXAFS_GetVolumeStatus(
struct rx_call *call
, const int32_t a_volIDP
, struct AFSFetchVolumeStatus *a_volFetchStatP
, char *a_volNameP
, char *a_offLineMsgP
, char *a_motdP
);

int SRXAFS_SetVolumeStatus(
struct rx_call *call
, const int32_t a_volIDP
, const struct AFSStoreVolumeStatus *a_volStoreStatP
, const char *a_volNameP
, const char *a_offLineMsgP
, const char *a_motdP
);

int SRXAFS_GetRootVolume(
struct rx_call *call
, char *a_rootVolNameP
);

int SRXAFS_GetTime(
struct rx_call *call
, uint32_t *a_secondsP
, uint32_t *a_uSecondsP
);

int SRXAFS_NGetVolumeInfo(
struct rx_call *call
, const char *VolumeName
, struct AFSVolumeInfo *stuff
);

int SRXAFS_BulkStatus(
struct rx_call *call
, const AFSCBFids *FidsArray
, AFSBulkStats *StatArray
, AFSCBs *CBArray
, struct AFSVolSync *Sync
);

int SRXAFS_SetLock(
struct rx_call *call
, const struct AFSFid *Fid
, const ViceLockType Type
, struct AFSVolSync *Sync
);

int SRXAFS_ExtendLock(
struct rx_call *call
, const struct AFSFid *Fid
, struct AFSVolSync *Sync
);

int SRXAFS_ReleaseLock(
struct rx_call *call
, const struct AFSFid *Fid
, struct AFSVolSync *Sync
);

int SRXAFS_FlushCPS(
struct rx_call *call
, const ViceIds *IdsArray
, const IPAddrs *AddrsArray
, const int32_t spare1
, int32_t *spare2
, int32_t *spare3
);

int SRXAFS_FetchData64(
struct rx_call *call
, const struct AFSFid *Fid
, const int64_t Pos
, const int64_t Length
, struct AFSFetchStatus *OutStatus
, struct AFSCallBack *CallBack
, struct AFSVolSync *Sync
);

int SRXAFS_StoreData64(
struct rx_call *call
, const struct AFSFid *Fid
, const struct AFSStoreStatus *InStatus
, const uint64_t Pos
, const uint64_t Length
, const uint64_t FileLength
, struct AFSFetchStatus *OutStatus
, struct AFSVolSync *Sync
);

int SRXAFS_GiveUpAllCallBacks(
struct rx_call *call
);

int SRXAFS_GetCapabilities(
struct rx_call *call
, Capabilities *capabilities
);

int32_t RXAFS_ExecuteRequest(struct rx_call *call);
