/* Generated from bos.xg */
#include <rx/rx.h>
#include "bos.h"

int SBOZO_CreateBnode(
struct rx_call *call
, const char *type
, const char *instance
, const char *p1
, const char *p2
, const char *p3
, const char *p4
, const char *p5
, const char *p6
);

int SBOZO_DeleteBnode(
struct rx_call *call
, const char *instance
);

int SBOZO_SetStatus(
struct rx_call *call
, const char *instance
, const int32_t status
);

int SBOZO_GetStatus(
struct rx_call *call
, const char *instance
, int32_t *inStat
, char *statdescr
);

int SBOZO_EnumerateInstance(
struct rx_call *call
, const int32_t instance
, char *iname
);

int SBOZO_GetInstanceInfo(
struct rx_call *call
, const char *instance
, char *type
, struct bozo_status *status
);

int SBOZO_GetInstanceParm(
struct rx_call *call
, const char *instance
, const int32_t num
, char *parm
);

int SBOZO_AddSUser(
struct rx_call *call
, const char *name
);

int SBOZO_DeleteSUser(
struct rx_call *call
, const char *name
);

int SBOZO_ListSUsers(
struct rx_call *call
, const int32_t an
, char *name
);

int SBOZO_ListKeys(
struct rx_call *call
, const int32_t an
, int32_t *kvno
, struct bozo_key *key
, struct bozo_keyInfo *keinfo
);

int SBOZO_AddKey(
struct rx_call *call
, const int32_t an
, const struct bozo_key *key
);

int SBOZO_DeleteKey(
struct rx_call *call
, const int32_t an
);

int SBOZO_SetCellName(
struct rx_call *call
, const char *name
);

int SBOZO_GetCellName(
struct rx_call *call
, char *name
);

int SBOZO_GetCellHost(
struct rx_call *call
, const int32_t awhich
, char *name
);

int SBOZO_AddCellHost(
struct rx_call *call
, const char *name
);

int SBOZO_DeleteCellHost(
struct rx_call *call
, const char *name
);

int SBOZO_SetTStatus(
struct rx_call *call
, const char *instance
, const int32_t status
);

int SBOZO_ShutdownAll(
struct rx_call *call
);

int SBOZO_RestartAll(
struct rx_call *call
);

int SBOZO_StartupAll(
struct rx_call *call
);

int SBOZO_SetNoAuthFlag(
struct rx_call *call
, const int32_t flag
);

int SBOZO_ReBozo(
struct rx_call *call
);

int SBOZO_Restart(
struct rx_call *call
, const char *instance
);

int SBOZO_Install(
struct rx_call *call
, const char *path
, const int32_t size
, const int32_t flags
, const int32_t date
);

int SBOZO_UnInstall(
struct rx_call *call
, const char *path
);

int SBOZO_GetDates(
struct rx_call *call
, const char *path
, int32_t *newtime
, int32_t *baktime
, int32_t *oldtime
);

int SBOZO_Exec(
struct rx_call *call
, const char *cmd
);

int SBOZO_Prune(
struct rx_call *call
, const int32_t flags
);

int SBOZO_SetRestartTime(
struct rx_call *call
, const int32_t type
, const struct bozo_netKTime *restartTime
);

int SBOZO_GetRestartTime(
struct rx_call *call
, const int32_t type
, struct bozo_netKTime *restartTime
);

int SBOZO_GetLog(
struct rx_call *call
, const char *name
);

int SBOZO_WaitAll(
struct rx_call *call
);

int SBOZO_GetInstanceStrings(
struct rx_call *call
, const char *instance
, char *errorname
, char *spare1
, char *spare2
, char *spare3
);

int32_t BOZO_ExecuteRequest(struct rx_call *call);
