/* Generated from cb.xg */
#include <rx/rx.h>
#include "cb.h"

int RXAFSCB_CallBack(
struct rx_connection *connection
, const AFSCBFids *a_fidArrayP
, const AFSCBs *a_callBackArrayP
);

int RXAFSCB_InitCallBackState(
struct rx_connection *connection
);

int RXAFSCB_Probe(
struct rx_connection *connection
);

int RXAFSCB_GetLock(
struct rx_connection *connection
, const int32_t index
, struct AFSDBLock *lock
);

int RXAFSCB_GetCE(
struct rx_connection *connection
, const int32_t index
, struct AFSDBCacheEntry *cbentry
);

int RXAFSCB_XStatsVersion(
struct rx_connection *connection
, int32_t *version
);

int RXAFSCB_GetXStats(
struct rx_connection *connection
, const int32_t client_version_num
, const int32_t collection_number
, int32_t *server_version_number
, int32_t *time
, AFSCB_CollData *stats
);

int RXAFSCB_InitCallBackState2(
struct rx_connection *connection
, struct interfaceAddr *addr
);

int RXAFSCB_WhoAreYou(
struct rx_connection *connection
, struct interfaceAddr *addr
);

int RXAFSCB_InitCallBackState3(
struct rx_connection *connection
, const struct afsUUID *serverUuid
);

int RXAFSCB_ProbeUUID(
struct rx_connection *connection
, const struct afsUUID *uuid
);

int RXAFSCB_GetCellServDB(
struct rx_connection *connection
, const int32_t cellIndex
, char *cellName
, serverList *cellHosts
);

int RXAFSCB_GetLocalCell(
struct rx_connection *connection
, char *cellName
);

int RXAFSCB_GetCacheConfig(
struct rx_connection *connection
, const uint32_t callerVersion
, uint32_t *serverVersion
, uint32_t *configCount
, cacheConfig *config
);

int RXAFSCB_GetCellByNum(
struct rx_connection *connection
, const int32_t cellNumber
, char *cellName
, serverList *cellHosts
);

int RXAFSCB_TellMeAboutYourself(
struct rx_connection *connection
, struct interfaceAddr *addr
, Capabilities *capabilities
);

