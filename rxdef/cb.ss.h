/* Generated from cb.xg */
#include "rx.h"
#include "cb.h"

int SRXAFSCB_CallBack(
struct rx_call *call
, const AFSCBFids *a_fidArrayP
, const AFSCBs *a_callBackArrayP
);

int SRXAFSCB_InitCallBackState(
struct rx_call *call
);

int SRXAFSCB_Probe(
struct rx_call *call
);

int SRXAFSCB_GetLock(
struct rx_call *call
, const int32_t index
, struct AFSDBLock *lock
);

int SRXAFSCB_GetCE(
struct rx_call *call
, const int32_t index
, struct AFSDBCacheEntry *cbentry
);

int SRXAFSCB_XStatsVersion(
struct rx_call *call
, int32_t *version
);

int SRXAFSCB_GetXStats(
struct rx_call *call
, const int32_t client_version_num
, const int32_t collection_number
, int32_t *server_version_number
, int32_t *time
, AFSCB_CollData *stats
);

int SRXAFSCB_InitCallBackState2(
struct rx_call *call
, struct interfaceAddr *addr
);

int SRXAFSCB_WhoAreYou(
struct rx_call *call
, struct interfaceAddr *addr
);

int SRXAFSCB_InitCallBackState3(
struct rx_call *call
, const struct afsUUID *serverUuid
);

int SRXAFSCB_ProbeUUID(
struct rx_call *call
, const struct afsUUID *uuid
);

int SRXAFSCB_GetCellServDB(
struct rx_call *call
, const int32_t cellIndex
, char *cellName
, serverList *cellHosts
);

int SRXAFSCB_GetLocalCell(
struct rx_call *call
, char *cellName
);

int SRXAFSCB_GetCacheConfig(
struct rx_call *call
, const uint32_t callerVersion
, uint32_t *serverVersion
, uint32_t *configCount
, cacheConfig *config
);

int SRXAFSCB_GetCellByNum(
struct rx_call *call
, const int32_t cellNumber
, char *cellName
, serverList *cellHosts
);

int SRXAFSCB_TellMeAboutYourself(
struct rx_call *call
, struct interfaceAddr *addr
, Capabilities *capabilities
);

int32_t RXAFSCB_ExecuteRequest(struct rx_call *call);
