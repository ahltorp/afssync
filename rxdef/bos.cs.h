/* Generated from bos.xg */
#include <rx/rx.h>
#include "bos.h"

int BOZO_CreateBnode(
struct rx_connection *connection
, const char *type
, const char *instance
, const char *p1
, const char *p2
, const char *p3
, const char *p4
, const char *p5
, const char *p6
);

int BOZO_DeleteBnode(
struct rx_connection *connection
, const char *instance
);

int BOZO_SetStatus(
struct rx_connection *connection
, const char *instance
, const int32_t status
);

int BOZO_GetStatus(
struct rx_connection *connection
, const char *instance
, int32_t *inStat
, char *statdescr
);

int BOZO_EnumerateInstance(
struct rx_connection *connection
, const int32_t instance
, char *iname
);

int BOZO_GetInstanceInfo(
struct rx_connection *connection
, const char *instance
, char *type
, struct bozo_status *status
);

int BOZO_GetInstanceParm(
struct rx_connection *connection
, const char *instance
, const int32_t num
, char *parm
);

int BOZO_AddSUser(
struct rx_connection *connection
, const char *name
);

int BOZO_DeleteSUser(
struct rx_connection *connection
, const char *name
);

int BOZO_ListSUsers(
struct rx_connection *connection
, const int32_t an
, char *name
);

int BOZO_ListKeys(
struct rx_connection *connection
, const int32_t an
, int32_t *kvno
, struct bozo_key *key
, struct bozo_keyInfo *keinfo
);

int BOZO_AddKey(
struct rx_connection *connection
, const int32_t an
, const struct bozo_key *key
);

int BOZO_DeleteKey(
struct rx_connection *connection
, const int32_t an
);

int BOZO_SetCellName(
struct rx_connection *connection
, const char *name
);

int BOZO_GetCellName(
struct rx_connection *connection
, char *name
);

int BOZO_GetCellHost(
struct rx_connection *connection
, const int32_t awhich
, char *name
);

int BOZO_AddCellHost(
struct rx_connection *connection
, const char *name
);

int BOZO_DeleteCellHost(
struct rx_connection *connection
, const char *name
);

int BOZO_SetTStatus(
struct rx_connection *connection
, const char *instance
, const int32_t status
);

int BOZO_ShutdownAll(
struct rx_connection *connection
);

int BOZO_RestartAll(
struct rx_connection *connection
);

int BOZO_StartupAll(
struct rx_connection *connection
);

int BOZO_SetNoAuthFlag(
struct rx_connection *connection
, const int32_t flag
);

int BOZO_ReBozo(
struct rx_connection *connection
);

int BOZO_Restart(
struct rx_connection *connection
, const char *instance
);

int StartBOZO_Install(
struct rx_call *call
, const char *path
, const int32_t size
, const int32_t flags
, const int32_t date
);

int EndBOZO_Install(
struct rx_call *call
);

int BOZO_UnInstall(
struct rx_connection *connection
, const char *path
);

int BOZO_GetDates(
struct rx_connection *connection
, const char *path
, int32_t *newtime
, int32_t *baktime
, int32_t *oldtime
);

int BOZO_Exec(
struct rx_connection *connection
, const char *cmd
);

int BOZO_Prune(
struct rx_connection *connection
, const int32_t flags
);

int BOZO_SetRestartTime(
struct rx_connection *connection
, const int32_t type
, const struct bozo_netKTime *restartTime
);

int BOZO_GetRestartTime(
struct rx_connection *connection
, const int32_t type
, struct bozo_netKTime *restartTime
);

int StartBOZO_GetLog(
struct rx_call *call
, const char *name
);

int EndBOZO_GetLog(
struct rx_call *call
);

int BOZO_WaitAll(
struct rx_connection *connection
);

int BOZO_GetInstanceStrings(
struct rx_connection *connection
, const char *instance
, char *errorname
, char *spare1
, char *spare2
, char *spare3
);

