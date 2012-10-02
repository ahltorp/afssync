/* Generated from ka.xg */
#include <rx/rx.h>
#include "ka.h"

int SKAA_Authenticate(
struct rx_call *call
, const kaname name
, const kaname instance
, const uint32_t start_time
, const uint32_t end_time
, const struct ka_CBS *request
, struct ka_BBS *answer
);

int SKAA_ChangePassword(
struct rx_call *call
, const kaname name
, const kaname instance
, const struct ka_CBS arequest
, struct ka_BBS *oanswer
);

int SKAM_SetPassword(
struct rx_call *call
, const kaname name
, const kaname instance
, const int32_t kvno
, const struct EncryptionKey password
);

int SKAM_SetFields(
struct rx_call *call
, const kaname name
, const kaname instance
, const int32_t flags
, const uint32_t user_expiration
, const int32_t max_ticket_lifetime
, const int32_t maxAssociates
, const int32_t spare1
, const int32_t spare2
);

int SKAM_CreateUser(
struct rx_call *call
, const kaname name
, const kaname instance
, const struct EncryptionKey password
);

int SKAM_GetEntry(
struct rx_call *call
, const kaname name
, const kaname instance
, const int32_t major_version
, struct kaentryinfo *entry
);

int SKAT_GetTicket_old(
struct rx_call *call
, const int32_t kvno
, const kaname auth_domain
, const struct ka_CBS *aticket
, const kaname name
, const kaname instance
, const struct ka_CBS *atimes
, struct ka_BBS *oanswer
);

int SKAT_GetTicket(
struct rx_call *call
, const int32_t kvno
, const kaname auth_domain
, const struct ka_CBS *aticket
, const kaname name
, const kaname instance
, const struct ka_CBS *atimes
, struct ka_BBS *oanswer
);

int32_t KAA_ExecuteRequest(struct rx_call *call);
int32_t KAM_ExecuteRequest(struct rx_call *call);
int32_t KAT_ExecuteRequest(struct rx_call *call);
