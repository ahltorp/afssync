/* Generated from ka.xg */
#include <rx/rx.h>
#include "ka.h"

int KAA_Authenticate(
struct rx_connection *connection
, const kaname name
, const kaname instance
, const uint32_t start_time
, const uint32_t end_time
, const struct ka_CBS *request
, struct ka_BBS *answer
);

int KAA_ChangePassword(
struct rx_connection *connection
, const kaname name
, const kaname instance
, const struct ka_CBS arequest
, struct ka_BBS *oanswer
);

int KAM_SetPassword(
struct rx_connection *connection
, const kaname name
, const kaname instance
, const int32_t kvno
, const struct EncryptionKey password
);

int KAM_SetFields(
struct rx_connection *connection
, const kaname name
, const kaname instance
, const int32_t flags
, const uint32_t user_expiration
, const int32_t max_ticket_lifetime
, const int32_t maxAssociates
, const int32_t spare1
, const int32_t spare2
);

int KAM_CreateUser(
struct rx_connection *connection
, const kaname name
, const kaname instance
, const struct EncryptionKey password
);

int KAM_GetEntry(
struct rx_connection *connection
, const kaname name
, const kaname instance
, const int32_t major_version
, struct kaentryinfo *entry
);

int KAT_GetTicket_old(
struct rx_connection *connection
, const int32_t kvno
, const kaname auth_domain
, const struct ka_CBS *aticket
, const kaname name
, const kaname instance
, const struct ka_CBS *atimes
, struct ka_BBS *oanswer
);

int KAT_GetTicket(
struct rx_connection *connection
, const int32_t kvno
, const kaname auth_domain
, const struct ka_CBS *aticket
, const kaname name
, const kaname instance
, const struct ka_CBS *atimes
, struct ka_BBS *oanswer
);

