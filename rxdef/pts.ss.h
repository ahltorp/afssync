/* Generated from pts.xg */
#include <rx/rx.h>
#include "pts.h"

int SPR_NameToID(
struct rx_call *call
, const namelist *nlist
, idlist *ilist
);

int SPR_IDToName(
struct rx_call *call
, const idlist *ilist
, namelist *nlist
);

int SPR_NewEntry(
struct rx_call *call
, const char *name
, const int32_t flag
, const int32_t oid
, int32_t *id
);

int SPR_INewEntry(
struct rx_call *call
, const char *name
, const int32_t id
, const int32_t oid
);

int SPR_ListEntry(
struct rx_call *call
, const int32_t id
, struct prcheckentry *entry
);

int SPR_DumpEntry(
struct rx_call *call
, const int32_t pos
, struct prdebugentry *entry
);

int SPR_ChangeEntry(
struct rx_call *call
, const int32_t id
, const char *name
, const int32_t oid
, const int32_t newid
);

int SPR_SetFieldsEntry(
struct rx_call *call
, const int32_t id
, const int32_t mask
, const int32_t flags
, const int32_t ngroups
, const int32_t nusers
, const int32_t spare1
, const int32_t spare2
);

int SPR_Delete(
struct rx_call *call
, const int32_t id
);

int SPR_WhereIsIt(
struct rx_call *call
, const int32_t id
, int32_t *ps
);

int SPR_AddToGroup(
struct rx_call *call
, const int32_t uid
, const int32_t gid
);

int SPR_RemoveFromGroup(
struct rx_call *call
, const int32_t id
, const int32_t gid
);

int SPR_ListMax(
struct rx_call *call
, int32_t *uid
, int32_t *gid
);

int SPR_SetMax(
struct rx_call *call
, const int32_t uid
, const int32_t gflag
);

int SPR_ListElements(
struct rx_call *call
, const int32_t id
, prlist *elist
, int32_t *over
);

int SPR_GetCPS(
struct rx_call *call
, const int32_t id
, prlist *elist
, int32_t *over
);

int SPR_ListOwned(
struct rx_call *call
, const int32_t id
, prlist *elist
, int32_t *over
);

int SPR_IsAMemberOf(
struct rx_call *call
, const int32_t uid
, const int32_t gid
, int32_t *flag
);

int SPR_GetCPS2(
struct rx_call *call
, const int32_t id
, const int32_t host
, prlist *elist
, int32_t *over
);

int SPR_GetHostCPS(
struct rx_call *call
, const int32_t host
, prlist *elist
, int32_t *over
);

int32_t PR_ExecuteRequest(struct rx_call *call);
