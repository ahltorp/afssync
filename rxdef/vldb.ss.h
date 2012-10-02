/* Generated from vldb.xg */
#include <rx/rx.h>
#include "vldb.h"

int SVL_CreateEntry(
struct rx_call *call
, const struct vldbentry *newentry
);

int SVL_DeleteEntry(
struct rx_call *call
, const int32_t Volid
, const int32_t voltype
);

int SVL_GetEntryByID(
struct rx_call *call
, const int32_t Volid
, const int32_t voltype
, struct vldbentry *entry
);

int SVL_GetEntryByName(
struct rx_call *call
, const char *volumename
, struct vldbentry *entry
);

int SVL_GetNewVolumeId(
struct rx_call *call
, const int32_t bumpcount
, int32_t *newvolumid
);

int SVL_ReplaceEntry(
struct rx_call *call
, const int32_t Volid
, const int32_t voltype
, const struct vldbentry *newentry
, const int32_t ReleaseType
);

int SVL_UpdateEntry(
struct rx_call *call
, const int32_t Volid
, const int32_t voltype
, const struct VldbUpdateEntry *UpdateEntry
, const int32_t ReleaseType
);

int SVL_SetLock(
struct rx_call *call
, const int32_t Volid
, const int32_t voltype
, const int32_t voloper
);

int SVL_ReleaseLock(
struct rx_call *call
, const int32_t volid
, const int32_t voltype
, const int32_t ReleaseType
);

int SVL_ListEntry(
struct rx_call *call
, const int32_t previous_index
, int32_t *count
, int32_t *next_index
, struct vldbentry *entry
);

int SVL_ListAttributes(
struct rx_call *call
, const struct VldbListByAttributes *attributes
, int32_t *nentries
, bulkentries *blkentries
);

int SVL_GetStats(
struct rx_call *call
, struct vldstats *stats
, struct vital_vlheader *vital_header
);

int SVL_Probe(
struct rx_call *call
);

int SVL_GetAddrs(
struct rx_call *call
, const int32_t handle
, const int32_t spare
, struct VL_Callback *spare3
, int32_t *nentries
, bulkaddrs *blkaddr
);

int SVL_ChangeAddrs(
struct rx_call *call
, const int32_t old_ip
, const int32_t new_ip
);

int SVL_CreateEntryN(
struct rx_call *call
, const struct nvldbentry *newentry
);

int SVL_GetEntryByIDN(
struct rx_call *call
, const int32_t Volid
, const int32_t voltype
, struct nvldbentry *entry
);

int SVL_GetEntryByNameN(
struct rx_call *call
, const char *volumename
, struct nvldbentry *entry
);

int SVL_ReplaceEntryN(
struct rx_call *call
, const int32_t Volid
, const int32_t voltype
, const struct nvldbentry *newentry
, const int32_t ReleaseType
);

int SVL_ListEntryN(
struct rx_call *call
, const int32_t previous_index
, int32_t *count
, int32_t *next_index
, struct nvldbentry *entry
);

int SVL_ListAttributesN(
struct rx_call *call
, const struct VldbListByAttributes *attributes
, int32_t *nentries
, nbulkentries *blkentries
);

int SVL_UpdateEntryByName(
struct rx_call *call
, const char *volname
, const struct VldbUpdateEntry *UpdateEntry
, const int32_t ReleaseType
);

int SVL_GetAddrsU(
struct rx_call *call
, const struct ListAddrByAttributes *inaddr
, struct afsUUID *uuidp1
, int32_t *uniquifier
, int32_t *nentries
, bulkaddrs *blkaddrs
);

int SVL_RegisterAddrs(
struct rx_call *call
, const struct afsUUID *uid
, const int32_t spare
, const bulkaddrs *addrs
);

int SVL_ListAttributesN2(
struct rx_call *call
, const struct VldbListByAttributes *attributes
, const char *volumename
, const int32_t startindex
, int32_t *nentries
, nbulkentries *blkentries
, int32_t *nextstartindex
);

int32_t VL_ExecuteRequest(struct rx_call *call);
