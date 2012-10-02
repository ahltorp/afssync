/* Generated from ka.xg */
#include "ka.h"

#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif /* _GNU_SOURCE */
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <errno.h>
#ifdef RCSID
RCSID("ka.cs.c generated from ka.xg with $Id: ka.cs.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
#endif

/* crap for operationssystem that doesn't provide us 64 bit ops */
#ifndef be64toh
#if BYTE_ORDER == LITTLE_ENDIAN
static inline uint64_t
ydr_swap64(uint64_t x)
{
#define LT(n) n##ULL
   return 
      ((LT(0x00000000000000ff) & x) << 56) | 
      ((LT(0x000000000000ff00) & x) << 40) | 
      ((LT(0x0000000000ff0000) & x) << 24) | 
      ((LT(0x00000000ff000000) & x) << 8) | 
      ((LT(0x000000ff00000000) & x) >> 8) | 
      ((LT(0x0000ff0000000000) & x) >> 24) | 
      ((LT(0x00ff000000000000) & x) >> 40) | 
      ((LT(0xff00000000000000) & x) >> 56) ; 
#undef LT
}

#define be64toh(x) ydr_swap64((x))
#define htobe64(x) ydr_swap64((x))
#endif /* BYTE_ORDER */
#if BYTE_ORDER == BIG_ENDIAN
#define be64toh(x) (x)
#define htobe64(x) (x)
#endif /* BYTE_ORDER */
#endif /* be64toh */
#include "ka.cs.h"

int KAA_Authenticate(
struct rx_connection *connection
, const kaname name
, const kaname instance
, const uint32_t start_time
, const uint32_t end_time
, const struct ka_CBS *request
, struct ka_BBS *answer
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (21);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(name);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, name, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(instance);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, instance, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl (start_time);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (end_time);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*request).Seq.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*request).Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*request).Seq.len % 4)) % 4;
if(rx_Write (call, (*request).Seq.val, (*request).Seq.len) != (*request).Seq.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*answer).MaxSeqLen);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*answer).Seq.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*answer).Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*answer).Seq.len % 4)) % 4;
if(rx_Write (call, (*answer).Seq.val, (*answer).Seq.len) != (*answer).Seq.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*answer).MaxSeqLen = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*answer).Seq.len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*answer).Seq.len) goto fail;
}
(*answer).Seq.val = (char *)malloc(sizeof(char ) * (*answer).Seq.len);
if ((*answer).Seq.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*answer).Seq.len % 4)) % 4;
if(rx_Read (call, (*answer).Seq.val, (*answer).Seq.len) != (*answer).Seq.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
return (rx_EndCall (call,0));
fail:
ret = (rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int KAA_ChangePassword(
struct rx_connection *connection
, const kaname name
, const kaname instance
, const struct ka_CBS arequest
, struct ka_BBS *oanswer
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(name);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, name, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(instance);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, instance, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl (arequest.Seq.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < arequest.Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (arequest.Seq.len % 4)) % 4;
if(rx_Write (call, arequest.Seq.val, arequest.Seq.len) != arequest.Seq.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*oanswer).MaxSeqLen);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*oanswer).Seq.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*oanswer).Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*oanswer).Seq.len % 4)) % 4;
if(rx_Write (call, (*oanswer).Seq.val, (*oanswer).Seq.len) != (*oanswer).Seq.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*oanswer).MaxSeqLen = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*oanswer).Seq.len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*oanswer).Seq.len) goto fail;
}
(*oanswer).Seq.val = (char *)malloc(sizeof(char ) * (*oanswer).Seq.len);
if ((*oanswer).Seq.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*oanswer).Seq.len % 4)) % 4;
if(rx_Read (call, (*oanswer).Seq.val, (*oanswer).Seq.len) != (*oanswer).Seq.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
return (rx_EndCall (call,0));
fail:
ret = (rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int KAM_SetPassword(
struct rx_connection *connection
, const kaname name
, const kaname instance
, const int32_t kvno
, const struct EncryptionKey password
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(name);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, name, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(instance);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, instance, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl (kvno);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (password.key[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
return (rx_EndCall (call,0));
fail:
ret = (rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
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
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(name);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, name, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(instance);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, instance, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl (flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (user_expiration);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (max_ticket_lifetime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (maxAssociates);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return (rx_EndCall (call,0));
fail:
ret = (rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int KAM_CreateUser(
struct rx_connection *connection
, const kaname name
, const kaname instance
, const struct EncryptionKey password
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(name);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, name, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(instance);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, instance, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (password.key[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
return (rx_EndCall (call,0));
fail:
ret = (rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int KAM_GetEntry(
struct rx_connection *connection
, const kaname name
, const kaname instance
, const int32_t major_version
, struct kaentryinfo *entry
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (8);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(name);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, name, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(instance);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, instance, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl (major_version);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).minor_version = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).user_expiration = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).modification_time = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).modification_user.name[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).modification_user.instance[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).change_password_time = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).max_ticket_lifetime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).key_version = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).key.key[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).keyCheckSym = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).reserved2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).reserved3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).reserved4 = ntohl (u);
}
return (rx_EndCall (call,0));
fail:
ret = (rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int KAT_GetTicket_old(
struct rx_connection *connection
, const int32_t kvno
, const kaname auth_domain
, const struct ka_CBS *aticket
, const kaname name
, const kaname instance
, const struct ka_CBS *atimes
, struct ka_BBS *oanswer
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (kvno);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(auth_domain);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, auth_domain, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*aticket).Seq.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*aticket).Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*aticket).Seq.len % 4)) % 4;
if(rx_Write (call, (*aticket).Seq.val, (*aticket).Seq.len) != (*aticket).Seq.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(name);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, name, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(instance);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, instance, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*atimes).Seq.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*atimes).Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*atimes).Seq.len % 4)) % 4;
if(rx_Write (call, (*atimes).Seq.val, (*atimes).Seq.len) != (*atimes).Seq.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*oanswer).MaxSeqLen);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*oanswer).Seq.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*oanswer).Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*oanswer).Seq.len % 4)) % 4;
if(rx_Write (call, (*oanswer).Seq.val, (*oanswer).Seq.len) != (*oanswer).Seq.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*oanswer).MaxSeqLen = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*oanswer).Seq.len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*oanswer).Seq.len) goto fail;
}
(*oanswer).Seq.val = (char *)malloc(sizeof(char ) * (*oanswer).Seq.len);
if ((*oanswer).Seq.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*oanswer).Seq.len % 4)) % 4;
if(rx_Read (call, (*oanswer).Seq.val, (*oanswer).Seq.len) != (*oanswer).Seq.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
return (rx_EndCall (call,0));
fail:
ret = (rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int KAT_GetTicket(
struct rx_connection *connection
, const int32_t kvno
, const kaname auth_domain
, const struct ka_CBS *aticket
, const kaname name
, const kaname instance
, const struct ka_CBS *atimes
, struct ka_BBS *oanswer
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (23);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (kvno);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(auth_domain);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, auth_domain, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*aticket).Seq.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*aticket).Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*aticket).Seq.len % 4)) % 4;
if(rx_Write (call, (*aticket).Seq.val, (*aticket).Seq.len) != (*aticket).Seq.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(name);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, name, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(instance);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, instance, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*atimes).Seq.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*atimes).Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*atimes).Seq.len % 4)) % 4;
if(rx_Write (call, (*atimes).Seq.val, (*atimes).Seq.len) != (*atimes).Seq.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*oanswer).MaxSeqLen);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*oanswer).Seq.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*oanswer).Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*oanswer).Seq.len % 4)) % 4;
if(rx_Write (call, (*oanswer).Seq.val, (*oanswer).Seq.len) != (*oanswer).Seq.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*oanswer).MaxSeqLen = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*oanswer).Seq.len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*oanswer).Seq.len) goto fail;
}
(*oanswer).Seq.val = (char *)malloc(sizeof(char ) * (*oanswer).Seq.len);
if ((*oanswer).Seq.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*oanswer).Seq.len % 4)) % 4;
if(rx_Read (call, (*oanswer).Seq.val, (*oanswer).Seq.len) != (*oanswer).Seq.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
return (rx_EndCall (call,0));
fail:
ret = (rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
