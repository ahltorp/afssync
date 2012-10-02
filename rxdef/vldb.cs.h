/* Generated from vldb.xg */
#include "rx.h"
#include "vldb.h"

int VL_CreateEntry(
struct rx_connection *connection
, const struct vldbentry *newentry
);

int VL_DeleteEntry(
struct rx_connection *connection
, const int32_t Volid
, const int32_t voltype
);

int VL_GetEntryByID(
struct rx_connection *connection
, const int32_t Volid
, const int32_t voltype
, struct vldbentry *entry
);

int VL_GetEntryByName(
struct rx_connection *connection
, const char *volumename
, struct vldbentry *entry
);

int VL_GetNewVolumeId(
struct rx_connection *connection
, const int32_t bumpcount
, int32_t *newvolumid
);

int VL_ReplaceEntry(
struct rx_connection *connection
, const int32_t Volid
, const int32_t voltype
, const struct vldbentry *newentry
, const int32_t ReleaseType
);

int VL_UpdateEntry(
struct rx_connection *connection
, const int32_t Volid
, const int32_t voltype
, const struct VldbUpdateEntry *UpdateEntry
, const int32_t ReleaseType
);

int VL_SetLock(
struct rx_connection *connection
, const int32_t Volid
, const int32_t voltype
, const int32_t voloper
);

int VL_ReleaseLock(
struct rx_connection *connection
, const int32_t volid
, const int32_t voltype
, const int32_t ReleaseType
);

int VL_ListEntry(
struct rx_connection *connection
, const int32_t previous_index
, int32_t *count
, int32_t *next_index
, struct vldbentry *entry
);

int VL_ListAttributes(
struct rx_connection *connection
, const struct VldbListByAttributes *attributes
, int32_t *nentries
, bulkentries *blkentries
);

int VL_GetStats(
struct rx_connection *connection
, struct vldstats *stats
, struct vital_vlheader *vital_header
);

int VL_Probe(
struct rx_connection *connection
);

int VL_GetAddrs(
struct rx_connection *connection
, const int32_t handle
, const int32_t spare
, struct VL_Callback *spare3
, int32_t *nentries
, bulkaddrs *blkaddr
);

int VL_ChangeAddrs(
struct rx_connection *connection
, const int32_t old_ip
, const int32_t new_ip
);

int VL_CreateEntryN(
struct rx_connection *connection
, const struct nvldbentry *newentry
);

int VL_GetEntryByIDN(
struct rx_connection *connection
, const int32_t Volid
, const int32_t voltype
, struct nvldbentry *entry
);

int VL_GetEntryByNameN(
struct rx_connection *connection
, const char *volumename
, struct nvldbentry *entry
);

int VL_ReplaceEntryN(
struct rx_connection *connection
, const int32_t Volid
, const int32_t voltype
, const struct nvldbentry *newentry
, const int32_t ReleaseType
);

int VL_ListEntryN(
struct rx_connection *connection
, const int32_t previous_index
, int32_t *count
, int32_t *next_index
, struct nvldbentry *entry
);

int VL_ListAttributesN(
struct rx_connection *connection
, const struct VldbListByAttributes *attributes
, int32_t *nentries
, nbulkentries *blkentries
);

int VL_UpdateEntryByName(
struct rx_connection *connection
, const char *volname
, const struct VldbUpdateEntry *UpdateEntry
, const int32_t ReleaseType
);

int VL_GetAddrsU(
struct rx_connection *connection
, const struct ListAddrByAttributes *inaddr
, struct afsUUID *uuidp1
, int32_t *uniquifier
, int32_t *nentries
, bulkaddrs *blkaddrs
);

int VL_RegisterAddrs(
struct rx_connection *connection
, const struct afsUUID *uid
, const int32_t spare
, const bulkaddrs *addrs
);

int VL_ListAttributesN2(
struct rx_connection *connection
, const struct VldbListByAttributes *attributes
, const char *volumename
, const int32_t startindex
, int32_t *nentries
, nbulkentries *blkentries
, int32_t *nextstartindex
);

