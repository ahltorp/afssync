/* Generated from volumeserver.xg */
#include <rx/rx.h>
#include "volumeserver.h"

int SVOLSER_AFSVolCreateVolume(
struct rx_call *call
, const int32_t partition
, const char *name
, const int32_t type
, const int32_t parent
, int32_t *volid
, int32_t *trans
);

int SVOLSER_AFSVolDeleteVolume(
struct rx_call *call
, const int32_t trans
);

int SVOLSER_AFSVolNukeVolume(
struct rx_call *call
, const int32_t partID
, const int32_t volID
);

int SVOLSER_AFSVolDump(
struct rx_call *call
, const int32_t fromTrans
, const int32_t fromDate
);

int SVOLSER_AFSVolSignalRestore(
struct rx_call *call
, const char *name
, const int32_t type
, const int32_t pid
, const int32_t cloneid
);

int SVOLSER_AFSVolRestore(
struct rx_call *call
, const int32_t toTrans
, const int32_t flags
, const struct restoreCookie *cookie
);

int SVOLSER_AFSVolForward(
struct rx_call *call
, const int32_t fromTrans
, const int32_t fromData
, const struct destServer *destination
, const int32_t destTrans
, const struct restoreCookie *cookie
);

int SVOLSER_AFSVolClone(
struct rx_call *call
, const int32_t trans
, const int32_t purgeVol
, const int32_t newType
, const char *newName
, int32_t *newVol
);

int SVOLSER_AFSVolReClone(
struct rx_call *call
, const int32_t tid
, const int32_t cloneID
);

int SVOLSER_AFSVolSetForwarding(
struct rx_call *call
, const int32_t tid
, const int32_t newsite
);

int SVOLSER_AFSVolTransCreate(
struct rx_call *call
, const int32_t volume
, const int32_t partition
, const int32_t flags
, int32_t *trans
);

int SVOLSER_AFSVolEndTrans(
struct rx_call *call
, const int32_t trans
, int32_t *rcode
);

int SVOLSER_AFSVolGetFlags(
struct rx_call *call
, const int32_t trans
, int32_t *flags
);

int SVOLSER_AFSVolSetFlags(
struct rx_call *call
, const int32_t trans
, const int32_t flags
);

int SVOLSER_AFSVolGetName(
struct rx_call *call
, const int32_t tid
, char *tname
);

int SVOLSER_AFSVolGetStatus(
struct rx_call *call
, const int32_t tid
, struct volser_status *status
);

int SVOLSER_AFSVolSetIdsTypes(
struct rx_call *call
, const int32_t tId
, const char *name
, const int32_t type
, const int32_t pId
, const int32_t cloneId
, const int32_t backupId
);

int SVOLSER_AFSVolSetDate(
struct rx_call *call
, const int32_t tid
, const int32_t newDate
);

int SVOLSER_AFSVolListPartitions(
struct rx_call *call
, struct pIDs *partIDs
);

int SVOLSER_AFSVolPartitionInfo(
struct rx_call *call
, const char *name
, struct diskPartition *partition
);

int SVOLSER_AFSVolListVolumes(
struct rx_call *call
, const int32_t partID
, const int32_t flags
, volEntries *resultEntries
);

int SVOLSER_AFSVolListOneVolume(
struct rx_call *call
, const int32_t partID
, const int32_t volid
, volEntries *resultEntries
);

int SVOLSER_AFSVolGetNthVolume(
struct rx_call *call
, const int32_t index
, int32_t *volume
, int32_t *partition
);

int SVOLSER_AFSVolMonitor(
struct rx_call *call
, transDebugEntries *result
);

int SVOLSER_AFSVolXListVolumes(
struct rx_call *call
, const int32_t partID
, const int32_t flags
, xvolEntries *resultEntries
);

int SVOLSER_AFSVolXListOneVolume(
struct rx_call *call
, const int32_t partID
, const int32_t volid
, xvolEntries *resultEntries
);

int SVOLSER_AFSVolSetInfo(
struct rx_call *call
, const int32_t transid
, const struct volintInfo *volinfo
);

int SVOLSER_AFSVolXListPartitions(
struct rx_call *call
, part_entries *ent
);

int SVOLSER_AFSVolForwardMultiple(
struct rx_call *call
, const int32_t fromTrans
, const int32_t fromData
, const manyDests *destinations
, const int32_t spare0
, const struct restoreCookie *cookie
, multi_results *results
);

int32_t VOLSER_ExecuteRequest(struct rx_call *call);
