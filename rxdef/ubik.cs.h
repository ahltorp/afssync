/* Generated from ubik.xg */
#include "rx.h"
#include "ubik.h"

int StartUbik_Beacon(
struct rx_call *call
, const int32_t state
, const int32_t voteStart
, const net_version *Version
, const struct net_tid *tid
);

int EndUbik_Beacon(
struct rx_call *call
);

int Ubik_Beacon(
struct rx_connection *connection
, const int32_t state
, const int32_t voteStart
, const net_version *Version
, const struct net_tid *tid
);

int Ubik_Debug(
struct rx_connection *connection
, struct ubik_debug *db
);

int Ubik_SDebug(
struct rx_connection *connection
, const int32_t which
, struct ubik_sdebug *db
);

int Ubik_GetSyncSite(
struct rx_connection *connection
, int32_t *site
);

