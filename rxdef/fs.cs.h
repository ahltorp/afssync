/* Generated from fs.xg */
#include "rx.h"
#include "fs.h"

int StartRXAFS_FetchData(
struct rx_call *call
, const struct AFSFid *a_fidToFetchP
, const int32_t a_offset
, const int32_t a_lenInBytes
);

int EndRXAFS_FetchData(
struct rx_call *call
, struct AFSFetchStatus *a_fidStatP
, struct AFSCallBack *a_callBackP
, struct AFSVolSync *a_volSyncP
);

int RXAFS_FetchACL(
struct rx_connection *connection
, const struct AFSFid *a_dirFidP
, AFSOpaque *a_ACLP
, struct AFSFetchStatus *a_dirNewStatP
, struct AFSVolSync *a_volSyncP
);

int RXAFS_FetchStatus(
struct rx_connection *connection
, const struct AFSFid *a_fidToStatP
, struct AFSFetchStatus *a_currStatP
, struct AFSCallBack *a_callBackP
, struct AFSVolSync *a_volSyncP
);

int StartRXAFS_StoreData(
struct rx_call *call
, const struct AFSFid *a_fidToStoreP
, const struct AFSStoreStatus *a_fidStatusP
, const int32_t a_offset
, const int32_t a_lenInBytes
, const int32_t a_fileLenInBytes
);

int EndRXAFS_StoreData(
struct rx_call *call
, struct AFSFetchStatus *a_fidStatP
, struct AFSVolSync *a_volSyncP
);

int RXAFS_StoreACL(
struct rx_connection *connection
, const struct AFSFid *a_dirFidP
, const AFSOpaque *a_ACLToStoreP
, struct AFSFetchStatus *a_dirNewStatP
, struct AFSVolSync *a_volSyncP
);

int RXAFS_StoreStatus(
struct rx_connection *connection
, const struct AFSFid *a_fidP
, const struct AFSStoreStatus *a_currStatusP
, struct AFSFetchStatus *a_srStatusP
, struct AFSVolSync *a_volSyncP
);

int RXAFS_RemoveFile(
struct rx_connection *connection
, const struct AFSFid *a_dirFidP
, const char *a_name
, struct AFSFetchStatus *a_srvStatusP
, struct AFSVolSync *a_volSyncP
);

int RXAFS_CreateFile(
struct rx_connection *connection
, const struct AFSFid *DirFid
, const char *Name
, const struct AFSStoreStatus *InStatus
, struct AFSFid *OutFid
, struct AFSFetchStatus *OutFidStatus
, struct AFSFetchStatus *OutDirStatus
, struct AFSCallBack *CallBack
, struct AFSVolSync *a_volSyncP
);

int RXAFS_Rename(
struct rx_connection *connection
, const struct AFSFid *a_origDirFidP
, const char *a_origNameP
, const struct AFSFid *a_newDirFidP
, const char *a_newNameP
, struct AFSFetchStatus *a_origDirStatusP
, struct AFSFetchStatus *a_newDirStatusP
, struct AFSVolSync *a_volSyncP
);

int RXAFS_Symlink(
struct rx_connection *connection
, const struct AFSFid *a_dirFidP
, const char *a_nameP
, const char *a_linkContentsP
, const struct AFSStoreStatus *a_origDirStatP
, struct AFSFid *a_newFidP
, struct AFSFetchStatus *a_newFidStatP
, struct AFSFetchStatus *a_newDirStatP
, struct AFSVolSync *a_volSyncP
);

int RXAFS_Link(
struct rx_connection *connection
, const struct AFSFid *a_dirFidP
, const char *a_nameP
, const struct AFSFid *a_existingFidP
, struct AFSFetchStatus *a_newFidStatP
, struct AFSFetchStatus *a_newDirStatP
, struct AFSVolSync *a_volSyncP
);

int RXAFS_MakeDir(
struct rx_connection *connection
, const struct AFSFid *a_parentDirFidP
, const char *a_newDirNameP
, const struct AFSStoreStatus *a_currStatP
, struct AFSFid *a_newDirFidP
, struct AFSFetchStatus *a_dirFidStatP
, struct AFSFetchStatus *a_parentDirStatP
, struct AFSCallBack *a_newDirCallBackP
, struct AFSVolSync *a_volSyncP
);

int RXAFS_RemoveDir(
struct rx_connection *connection
, const struct AFSFid *a_parentDirStatP
, const char *a_dirNameP
, struct AFSFetchStatus *a_newParentDirStatP
, struct AFSVolSync *a_volSyncP
);

int RXAFS_GiveUpCallBacks(
struct rx_connection *connection
, const AFSCBFids *a_fidArrayP
, const AFSCBs *a_callBackArrayP
);

int RXAFS_GetVolumeStatus(
struct rx_connection *connection
, const int32_t a_volIDP
, struct AFSFetchVolumeStatus *a_volFetchStatP
, char *a_volNameP
, char *a_offLineMsgP
, char *a_motdP
);

int RXAFS_SetVolumeStatus(
struct rx_connection *connection
, const int32_t a_volIDP
, const struct AFSStoreVolumeStatus *a_volStoreStatP
, const char *a_volNameP
, const char *a_offLineMsgP
, const char *a_motdP
);

int RXAFS_GetRootVolume(
struct rx_connection *connection
, char *a_rootVolNameP
);

int RXAFS_GetTime(
struct rx_connection *connection
, uint32_t *a_secondsP
, uint32_t *a_uSecondsP
);

int RXAFS_NGetVolumeInfo(
struct rx_connection *connection
, const char *VolumeName
, struct AFSVolumeInfo *stuff
);

int RXAFS_BulkStatus(
struct rx_connection *connection
, const AFSCBFids *FidsArray
, AFSBulkStats *StatArray
, AFSCBs *CBArray
, struct AFSVolSync *Sync
);

int RXAFS_SetLock(
struct rx_connection *connection
, const struct AFSFid *Fid
, const ViceLockType Type
, struct AFSVolSync *Sync
);

int RXAFS_ExtendLock(
struct rx_connection *connection
, const struct AFSFid *Fid
, struct AFSVolSync *Sync
);

int RXAFS_ReleaseLock(
struct rx_connection *connection
, const struct AFSFid *Fid
, struct AFSVolSync *Sync
);

int RXAFS_FlushCPS(
struct rx_connection *connection
, const ViceIds *IdsArray
, const IPAddrs *AddrsArray
, const int32_t spare1
, int32_t *spare2
, int32_t *spare3
);

int StartRXAFS_FetchData64(
struct rx_call *call
, const struct AFSFid *Fid
, const int64_t Pos
, const int64_t Length
);

int EndRXAFS_FetchData64(
struct rx_call *call
, struct AFSFetchStatus *OutStatus
, struct AFSCallBack *CallBack
, struct AFSVolSync *Sync
);

int StartRXAFS_StoreData64(
struct rx_call *call
, const struct AFSFid *Fid
, const struct AFSStoreStatus *InStatus
, const uint64_t Pos
, const uint64_t Length
, const uint64_t FileLength
);

int EndRXAFS_StoreData64(
struct rx_call *call
, struct AFSFetchStatus *OutStatus
, struct AFSVolSync *Sync
);

int RXAFS_GiveUpAllCallBacks(
struct rx_connection *connection
);

int RXAFS_GetCapabilities(
struct rx_connection *connection
, Capabilities *capabilities
);

