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
RCSID("ka.ss.c generated from ka.xg with $Id: ka.ss.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
#include "ka.ss.h"

static int ydr_ps_KAA_Authenticate(
struct rx_call *call)
{
int32_t _result;
kaname name;
kaname instance;
uint32_t start_time;
uint32_t end_time;
struct ka_CBS request;
struct ka_BBS answer;
memset(&name, 0, sizeof(name));
memset(&instance, 0, sizeof(instance));
memset(&start_time, 0, sizeof(start_time));
memset(&end_time, 0, sizeof(end_time));
memset(&request, 0, sizeof(request));
memset(&answer, 0, sizeof(answer));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (name), len) != len)
goto fail;
(name)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (instance), len) != len)
goto fail;
(instance)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
start_time = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
end_time = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
request.Seq.len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < request.Seq.len) goto fail;
}
request.Seq.val = (char *)malloc(sizeof(char ) * request.Seq.len);
if (request.Seq.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (request.Seq.len % 4)) % 4;
if(rx_Read (call, request.Seq.val, request.Seq.len) != request.Seq.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
answer.MaxSeqLen = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
answer.Seq.len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < answer.Seq.len) goto fail;
}
answer.Seq.val = (char *)malloc(sizeof(char ) * answer.Seq.len);
if (answer.Seq.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (answer.Seq.len % 4)) % 4;
if(rx_Read (call, answer.Seq.val, answer.Seq.len) != answer.Seq.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
_result = SKAA_Authenticate(call, name, instance, start_time, end_time, &request, &answer);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (answer.MaxSeqLen);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (answer.Seq.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < answer.Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (answer.Seq.len % 4)) % 4;
if(rx_Write (call, answer.Seq.val, answer.Seq.len) != answer.Seq.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_KAA_ChangePassword(
struct rx_call *call)
{
int32_t _result;
kaname name;
kaname instance;
struct ka_CBS arequest;
struct ka_BBS oanswer;
memset(&name, 0, sizeof(name));
memset(&instance, 0, sizeof(instance));
memset(&arequest, 0, sizeof(arequest));
memset(&oanswer, 0, sizeof(oanswer));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (name), len) != len)
goto fail;
(name)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (instance), len) != len)
goto fail;
(instance)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
arequest.Seq.len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < arequest.Seq.len) goto fail;
}
arequest.Seq.val = (char *)malloc(sizeof(char ) * arequest.Seq.len);
if (arequest.Seq.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (arequest.Seq.len % 4)) % 4;
if(rx_Read (call, arequest.Seq.val, arequest.Seq.len) != arequest.Seq.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
oanswer.MaxSeqLen = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
oanswer.Seq.len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < oanswer.Seq.len) goto fail;
}
oanswer.Seq.val = (char *)malloc(sizeof(char ) * oanswer.Seq.len);
if (oanswer.Seq.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (oanswer.Seq.len % 4)) % 4;
if(rx_Read (call, oanswer.Seq.val, oanswer.Seq.len) != oanswer.Seq.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
_result = SKAA_ChangePassword(call, name, instance, arequest, &oanswer);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (oanswer.MaxSeqLen);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (oanswer.Seq.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < oanswer.Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (oanswer.Seq.len % 4)) % 4;
if(rx_Write (call, oanswer.Seq.val, oanswer.Seq.len) != oanswer.Seq.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_KAM_SetPassword(
struct rx_call *call)
{
int32_t _result;
kaname name;
kaname instance;
int32_t kvno;
struct EncryptionKey password;
memset(&name, 0, sizeof(name));
memset(&instance, 0, sizeof(instance));
memset(&kvno, 0, sizeof(kvno));
memset(&password, 0, sizeof(password));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (name), len) != len)
goto fail;
(name)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (instance), len) != len)
goto fail;
(instance)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
kvno = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
password.key[i0] = ntohl (u);
}
}
}
_result = SKAM_SetPassword(call, name, instance, kvno, password);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_KAM_SetFields(
struct rx_call *call)
{
int32_t _result;
kaname name;
kaname instance;
int32_t flags;
uint32_t user_expiration;
int32_t max_ticket_lifetime;
int32_t maxAssociates;
int32_t spare1;
int32_t spare2;
memset(&name, 0, sizeof(name));
memset(&instance, 0, sizeof(instance));
memset(&flags, 0, sizeof(flags));
memset(&user_expiration, 0, sizeof(user_expiration));
memset(&max_ticket_lifetime, 0, sizeof(max_ticket_lifetime));
memset(&maxAssociates, 0, sizeof(maxAssociates));
memset(&spare1, 0, sizeof(spare1));
memset(&spare2, 0, sizeof(spare2));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (name), len) != len)
goto fail;
(name)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (instance), len) != len)
goto fail;
(instance)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
user_expiration = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
max_ticket_lifetime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
maxAssociates = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
spare2 = ntohl (u);
}
_result = SKAM_SetFields(call, name, instance, flags, user_expiration, max_ticket_lifetime, maxAssociates, spare1, spare2);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_KAM_CreateUser(
struct rx_call *call)
{
int32_t _result;
kaname name;
kaname instance;
struct EncryptionKey password;
memset(&name, 0, sizeof(name));
memset(&instance, 0, sizeof(instance));
memset(&password, 0, sizeof(password));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (name), len) != len)
goto fail;
(name)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (instance), len) != len)
goto fail;
(instance)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
password.key[i0] = ntohl (u);
}
}
}
_result = SKAM_CreateUser(call, name, instance, password);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_KAM_GetEntry(
struct rx_call *call)
{
int32_t _result;
kaname name;
kaname instance;
int32_t major_version;
struct kaentryinfo entry;
memset(&name, 0, sizeof(name));
memset(&instance, 0, sizeof(instance));
memset(&major_version, 0, sizeof(major_version));
memset(&entry, 0, sizeof(entry));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (name), len) != len)
goto fail;
(name)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (instance), len) != len)
goto fail;
(instance)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
major_version = ntohl (u);
}
_result = SKAM_GetEntry(call, name, instance, major_version, &entry);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (entry.minor_version);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.user_expiration);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.modification_time);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ uint32_t u;
u = htonl (entry.modification_user.name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ uint32_t u;
u = htonl (entry.modification_user.instance[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.change_password_time);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.max_ticket_lifetime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.key_version);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (entry.key.key[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.keyCheckSym);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.reserved2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.reserved3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.reserved4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_KAT_GetTicket_old(
struct rx_call *call)
{
int32_t _result;
int32_t kvno;
kaname auth_domain;
struct ka_CBS aticket;
kaname name;
kaname instance;
struct ka_CBS atimes;
struct ka_BBS oanswer;
memset(&kvno, 0, sizeof(kvno));
memset(&auth_domain, 0, sizeof(auth_domain));
memset(&aticket, 0, sizeof(aticket));
memset(&name, 0, sizeof(name));
memset(&instance, 0, sizeof(instance));
memset(&atimes, 0, sizeof(atimes));
memset(&oanswer, 0, sizeof(oanswer));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
kvno = ntohl (u);
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (auth_domain), len) != len)
goto fail;
(auth_domain)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
aticket.Seq.len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < aticket.Seq.len) goto fail;
}
aticket.Seq.val = (char *)malloc(sizeof(char ) * aticket.Seq.len);
if (aticket.Seq.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (aticket.Seq.len % 4)) % 4;
if(rx_Read (call, aticket.Seq.val, aticket.Seq.len) != aticket.Seq.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (name), len) != len)
goto fail;
(name)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (instance), len) != len)
goto fail;
(instance)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
atimes.Seq.len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < atimes.Seq.len) goto fail;
}
atimes.Seq.val = (char *)malloc(sizeof(char ) * atimes.Seq.len);
if (atimes.Seq.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (atimes.Seq.len % 4)) % 4;
if(rx_Read (call, atimes.Seq.val, atimes.Seq.len) != atimes.Seq.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
oanswer.MaxSeqLen = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
oanswer.Seq.len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < oanswer.Seq.len) goto fail;
}
oanswer.Seq.val = (char *)malloc(sizeof(char ) * oanswer.Seq.len);
if (oanswer.Seq.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (oanswer.Seq.len % 4)) % 4;
if(rx_Read (call, oanswer.Seq.val, oanswer.Seq.len) != oanswer.Seq.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
_result = SKAT_GetTicket_old(call, kvno, auth_domain, &aticket, name, instance, &atimes, &oanswer);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (oanswer.MaxSeqLen);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (oanswer.Seq.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < oanswer.Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (oanswer.Seq.len % 4)) % 4;
if(rx_Write (call, oanswer.Seq.val, oanswer.Seq.len) != oanswer.Seq.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_KAT_GetTicket(
struct rx_call *call)
{
int32_t _result;
int32_t kvno;
kaname auth_domain;
struct ka_CBS aticket;
kaname name;
kaname instance;
struct ka_CBS atimes;
struct ka_BBS oanswer;
memset(&kvno, 0, sizeof(kvno));
memset(&auth_domain, 0, sizeof(auth_domain));
memset(&aticket, 0, sizeof(aticket));
memset(&name, 0, sizeof(name));
memset(&instance, 0, sizeof(instance));
memset(&atimes, 0, sizeof(atimes));
memset(&oanswer, 0, sizeof(oanswer));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
kvno = ntohl (u);
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (auth_domain), len) != len)
goto fail;
(auth_domain)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
aticket.Seq.len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < aticket.Seq.len) goto fail;
}
aticket.Seq.val = (char *)malloc(sizeof(char ) * aticket.Seq.len);
if (aticket.Seq.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (aticket.Seq.len % 4)) % 4;
if(rx_Read (call, aticket.Seq.val, aticket.Seq.len) != aticket.Seq.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (name), len) != len)
goto fail;
(name)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (instance), len) != len)
goto fail;
(instance)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
atimes.Seq.len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < atimes.Seq.len) goto fail;
}
atimes.Seq.val = (char *)malloc(sizeof(char ) * atimes.Seq.len);
if (atimes.Seq.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (atimes.Seq.len % 4)) % 4;
if(rx_Read (call, atimes.Seq.val, atimes.Seq.len) != atimes.Seq.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
oanswer.MaxSeqLen = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
oanswer.Seq.len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < oanswer.Seq.len) goto fail;
}
oanswer.Seq.val = (char *)malloc(sizeof(char ) * oanswer.Seq.len);
if (oanswer.Seq.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (oanswer.Seq.len % 4)) % 4;
if(rx_Read (call, oanswer.Seq.val, oanswer.Seq.len) != oanswer.Seq.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
_result = SKAT_GetTicket(call, kvno, auth_domain, &aticket, name, instance, &atimes, &oanswer);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (oanswer.MaxSeqLen);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (oanswer.Seq.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < oanswer.Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (oanswer.Seq.len % 4)) % 4;
if(rx_Write (call, oanswer.Seq.val, oanswer.Seq.len) != oanswer.Seq.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

int32_t KAA_ExecuteRequest(struct rx_call *call)
{
unsigned opcode;
int32_t _result;
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
opcode = ntohl (u);
}
switch(opcode) {
case 21: {
_result = ydr_ps_KAA_Authenticate(call);
break;
}
case 2: {
_result = ydr_ps_KAA_ChangePassword(call);
break;
}
default:
_result = RXGEN_OPCODE;
}
return _result;
fail:
return rx_GetCallError(call);
}

int32_t KAM_ExecuteRequest(struct rx_call *call)
{
unsigned opcode;
int32_t _result;
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
opcode = ntohl (u);
}
switch(opcode) {
case 4: {
_result = ydr_ps_KAM_SetPassword(call);
break;
}
case 5: {
_result = ydr_ps_KAM_SetFields(call);
break;
}
case 6: {
_result = ydr_ps_KAM_CreateUser(call);
break;
}
case 8: {
_result = ydr_ps_KAM_GetEntry(call);
break;
}
default:
_result = RXGEN_OPCODE;
}
return _result;
fail:
return rx_GetCallError(call);
}

int32_t KAT_ExecuteRequest(struct rx_call *call)
{
unsigned opcode;
int32_t _result;
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
opcode = ntohl (u);
}
switch(opcode) {
case 3: {
_result = ydr_ps_KAT_GetTicket_old(call);
break;
}
case 23: {
_result = ydr_ps_KAT_GetTicket(call);
break;
}
default:
_result = RXGEN_OPCODE;
}
return _result;
fail:
return rx_GetCallError(call);
}

