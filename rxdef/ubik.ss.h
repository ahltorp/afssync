/* Generated from ubik.xg */
#include <rx/rx.h>
#include "ubik.h"

int SUbik_Beacon(
struct rx_call *call
, const int32_t state
, const int32_t voteStart
, const net_version *Version
, const struct net_tid *tid
);

int SUbik_Debug(
struct rx_call *call
, struct ubik_debug *db
);

int SUbik_SDebug(
struct rx_call *call
, const int32_t which
, struct ubik_sdebug *db
);

int SUbik_GetSyncSite(
struct rx_call *call
, int32_t *site
);

int32_t Ubik_ExecuteRequest(struct rx_call *call);
