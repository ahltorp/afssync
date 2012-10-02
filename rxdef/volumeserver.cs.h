/* Generated from volumeserver.xg */
#include "rx.h"
#include "volumeserver.h"

int VOLSER_AFSVolCreateVolume(
struct rx_connection *connection
, const int32_t partition
, const char *name
, const int32_t type
, const int32_t parent
, int32_t *volid
, int32_t *trans
);

int VOLSER_AFSVolDeleteVolume(
struct rx_connection *connection
, const int32_t trans
);

int VOLSER_AFSVolNukeVolume(
struct rx_connection *connection
, const int32_t partID
, const int32_t volID
);

int StartVOLSER_AFSVolDump(
struct rx_call *call
, const int32_t fromTrans
, const int32_t fromDate
);

int EndVOLSER_AFSVolDump(
struct rx_call *call
);

int VOLSER_AFSVolSignalRestore(
struct rx_connection *connection
, const char *name
, const int32_t type
, const int32_t pid
, const int32_t cloneid
);

int StartVOLSER_AFSVolRestore(
struct rx_call *call
, const int32_t toTrans
, const int32_t flags
, const struct restoreCookie *cookie
);

int EndVOLSER_AFSVolRestore(
struct rx_call *call
);

int VOLSER_AFSVolForward(
struct rx_connection *connection
, const int32_t fromTrans
, const int32_t fromData
, const struct destServer *destination
, const int32_t destTrans
, const struct restoreCookie *cookie
);

int VOLSER_AFSVolClone(
struct rx_connection *connection
, const int32_t trans
, const int32_t purgeVol
, const int32_t newType
, const char *newName
, int32_t *newVol
);

int VOLSER_AFSVolReClone(
struct rx_connection *connection
, const int32_t tid
, const int32_t cloneID
);

int VOLSER_AFSVolSetForwarding(
struct rx_connection *connection
, const int32_t tid
, const int32_t newsite
);

int VOLSER_AFSVolTransCreate(
struct rx_connection *connection
, const int32_t volume
, const int32_t partition
, const int32_t flags
, int32_t *trans
);

int VOLSER_AFSVolEndTrans(
struct rx_connection *connection
, const int32_t trans
, int32_t *rcode
);

int VOLSER_AFSVolGetFlags(
struct rx_connection *connection
, const int32_t trans
, int32_t *flags
);

int VOLSER_AFSVolSetFlags(
struct rx_connection *connection
, const int32_t trans
, const int32_t flags
);

int VOLSER_AFSVolGetName(
struct rx_connection *connection
, const int32_t tid
, char *tname
);

int VOLSER_AFSVolGetStatus(
struct rx_connection *connection
, const int32_t tid
, struct volser_status *status
);

int VOLSER_AFSVolSetIdsTypes(
struct rx_connection *connection
, const int32_t tId
, const char *name
, const int32_t type
, const int32_t pId
, const int32_t cloneId
, const int32_t backupId
);

int VOLSER_AFSVolSetDate(
struct rx_connection *connection
, const int32_t tid
, const int32_t newDate
);

int VOLSER_AFSVolListPartitions(
struct rx_connection *connection
, struct pIDs *partIDs
);

int VOLSER_AFSVolPartitionInfo(
struct rx_connection *connection
, const char *name
, struct diskPartition *partition
);

int VOLSER_AFSVolListVolumes(
struct rx_connection *connection
, const int32_t partID
, const int32_t flags
, volEntries *resultEntries
);

int VOLSER_AFSVolListOneVolume(
struct rx_connection *connection
, const int32_t partID
, const int32_t volid
, volEntries *resultEntries
);

int VOLSER_AFSVolGetNthVolume(
struct rx_connection *connection
, const int32_t index
, int32_t *volume
, int32_t *partition
);

int VOLSER_AFSVolMonitor(
struct rx_connection *connection
, transDebugEntries *result
);

int VOLSER_AFSVolXListVolumes(
struct rx_connection *connection
, const int32_t partID
, const int32_t flags
, xvolEntries *resultEntries
);

int VOLSER_AFSVolXListOneVolume(
struct rx_connection *connection
, const int32_t partID
, const int32_t volid
, xvolEntries *resultEntries
);

int VOLSER_AFSVolSetInfo(
struct rx_connection *connection
, const int32_t transid
, const struct volintInfo *volinfo
);

int VOLSER_AFSVolXListPartitions(
struct rx_connection *connection
, part_entries *ent
);

int VOLSER_AFSVolForwardMultiple(
struct rx_connection *connection
, const int32_t fromTrans
, const int32_t fromData
, const manyDests *destinations
, const int32_t spare0
, const struct restoreCookie *cookie
, multi_results *results
);

