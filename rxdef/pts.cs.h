/* Generated from pts.xg */
#include "rx.h"
#include "pts.h"

int PR_NameToID(
struct rx_connection *connection
, const namelist *nlist
, idlist *ilist
);

int PR_IDToName(
struct rx_connection *connection
, const idlist *ilist
, namelist *nlist
);

int PR_NewEntry(
struct rx_connection *connection
, const char *name
, const int32_t flag
, const int32_t oid
, int32_t *id
);

int PR_INewEntry(
struct rx_connection *connection
, const char *name
, const int32_t id
, const int32_t oid
);

int PR_ListEntry(
struct rx_connection *connection
, const int32_t id
, struct prcheckentry *entry
);

int PR_DumpEntry(
struct rx_connection *connection
, const int32_t pos
, struct prdebugentry *entry
);

int PR_ChangeEntry(
struct rx_connection *connection
, const int32_t id
, const char *name
, const int32_t oid
, const int32_t newid
);

int PR_SetFieldsEntry(
struct rx_connection *connection
, const int32_t id
, const int32_t mask
, const int32_t flags
, const int32_t ngroups
, const int32_t nusers
, const int32_t spare1
, const int32_t spare2
);

int PR_Delete(
struct rx_connection *connection
, const int32_t id
);

int PR_WhereIsIt(
struct rx_connection *connection
, const int32_t id
, int32_t *ps
);

int PR_AddToGroup(
struct rx_connection *connection
, const int32_t uid
, const int32_t gid
);

int PR_RemoveFromGroup(
struct rx_connection *connection
, const int32_t id
, const int32_t gid
);

int PR_ListMax(
struct rx_connection *connection
, int32_t *uid
, int32_t *gid
);

int PR_SetMax(
struct rx_connection *connection
, const int32_t uid
, const int32_t gflag
);

int PR_ListElements(
struct rx_connection *connection
, const int32_t id
, prlist *elist
, int32_t *over
);

int PR_GetCPS(
struct rx_connection *connection
, const int32_t id
, prlist *elist
, int32_t *over
);

int PR_ListOwned(
struct rx_connection *connection
, const int32_t id
, prlist *elist
, int32_t *over
);

int PR_IsAMemberOf(
struct rx_connection *connection
, const int32_t uid
, const int32_t gid
, int32_t *flag
);

int PR_GetCPS2(
struct rx_connection *connection
, const int32_t id
, const int32_t host
, prlist *elist
, int32_t *over
);

int PR_GetHostCPS(
struct rx_connection *connection
, const int32_t host
, prlist *elist
, int32_t *over
);

