/* Generated from bos.xg */
#include "bos.h"

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
RCSID("bos.ss.c generated from bos.xg with $Id: bos.ss.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
#include "bos.ss.h"

static int ydr_ps_BOZO_CreateBnode(
struct rx_call *call)
{
int32_t _result;
char type[256];
char instance[256];
char p1[256];
char p2[256];
char p3[256];
char p4[256];
char p5[256];
char p6[256];
memset(&type, 0, sizeof(type));
memset(&instance, 0, sizeof(instance));
memset(&p1, 0, sizeof(p1));
memset(&p2, 0, sizeof(p2));
memset(&p3, 0, sizeof(p3));
memset(&p4, 0, sizeof(p4));
memset(&p5, 0, sizeof(p5));
memset(&p6, 0, sizeof(p6));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (type), len) != len)
goto fail;
(type)[len] = '\0';
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
if (len >= 256) {
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
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (p1), len) != len)
goto fail;
(p1)[len] = '\0';
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
if (len >= 256) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (p2), len) != len)
goto fail;
(p2)[len] = '\0';
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
if (len >= 256) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (p3), len) != len)
goto fail;
(p3)[len] = '\0';
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
if (len >= 256) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (p4), len) != len)
goto fail;
(p4)[len] = '\0';
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
if (len >= 256) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (p5), len) != len)
goto fail;
(p5)[len] = '\0';
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
if (len >= 256) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (p6), len) != len)
goto fail;
(p6)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
_result = SBOZO_CreateBnode(call, type, instance, p1, p2, p3, p4, p5, p6);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_DeleteBnode(
struct rx_call *call)
{
int32_t _result;
char instance[256];
memset(&instance, 0, sizeof(instance));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
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
_result = SBOZO_DeleteBnode(call, instance);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_SetStatus(
struct rx_call *call)
{
int32_t _result;
char instance[256];
int32_t status;
memset(&instance, 0, sizeof(instance));
memset(&status, 0, sizeof(status));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
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
status = ntohl (u);
}
_result = SBOZO_SetStatus(call, instance, status);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_GetStatus(
struct rx_call *call)
{
int32_t _result;
char instance[256];
int32_t inStat;
char statdescr[256];
memset(&instance, 0, sizeof(instance));
memset(&inStat, 0, sizeof(inStat));
memset(&statdescr, 0, sizeof(statdescr));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
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
_result = SBOZO_GetStatus(call, instance, &inStat, statdescr);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (inStat);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(statdescr);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, statdescr, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_EnumerateInstance(
struct rx_call *call)
{
int32_t _result;
int32_t instance;
char iname[256];
memset(&instance, 0, sizeof(instance));
memset(&iname, 0, sizeof(iname));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
instance = ntohl (u);
}
_result = SBOZO_EnumerateInstance(call, instance, iname);
if (_result) goto funcfail;
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(iname);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, iname, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_GetInstanceInfo(
struct rx_call *call)
{
int32_t _result;
char instance[256];
char type[256];
struct bozo_status status;
memset(&instance, 0, sizeof(instance));
memset(&type, 0, sizeof(type));
memset(&status, 0, sizeof(status));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
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
_result = SBOZO_GetInstanceInfo(call, instance, type, &status);
if (_result) goto funcfail;
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(type);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, type, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl (status.goal);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.fileGoal);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.porcStartTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.procStarts);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.lastAnyExit);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.lastErrorExit);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.errorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.errorSignal);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (status.spare[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_GetInstanceParm(
struct rx_call *call)
{
int32_t _result;
char instance[256];
int32_t num;
char parm[256];
memset(&instance, 0, sizeof(instance));
memset(&num, 0, sizeof(num));
memset(&parm, 0, sizeof(parm));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
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
num = ntohl (u);
}
_result = SBOZO_GetInstanceParm(call, instance, num, parm);
if (_result) goto funcfail;
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(parm);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, parm, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_AddSUser(
struct rx_call *call)
{
int32_t _result;
char name[256];
memset(&name, 0, sizeof(name));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
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
_result = SBOZO_AddSUser(call, name);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_DeleteSUser(
struct rx_call *call)
{
int32_t _result;
char name[256];
memset(&name, 0, sizeof(name));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
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
_result = SBOZO_DeleteSUser(call, name);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_ListSUsers(
struct rx_call *call)
{
int32_t _result;
int32_t an;
char name[256];
memset(&an, 0, sizeof(an));
memset(&name, 0, sizeof(name));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
an = ntohl (u);
}
_result = SBOZO_ListSUsers(call, an, name);
if (_result) goto funcfail;
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
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_ListKeys(
struct rx_call *call)
{
int32_t _result;
int32_t an;
int32_t kvno;
struct bozo_key key;
struct bozo_keyInfo keinfo;
memset(&an, 0, sizeof(an));
memset(&kvno, 0, sizeof(kvno));
memset(&key, 0, sizeof(key));
memset(&keinfo, 0, sizeof(keinfo));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
an = ntohl (u);
}
_result = SBOZO_ListKeys(call, an, &kvno, &key, &keinfo);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (kvno);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (key.data[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (keinfo.mod_sec);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (keinfo.mod_usec);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (keinfo.keyCheckSum);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (keinfo.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_AddKey(
struct rx_call *call)
{
int32_t _result;
int32_t an;
struct bozo_key key;
memset(&an, 0, sizeof(an));
memset(&key, 0, sizeof(key));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
an = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
key.data[i0] = ntohl (u);
}
}
}
_result = SBOZO_AddKey(call, an, &key);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_DeleteKey(
struct rx_call *call)
{
int32_t _result;
int32_t an;
memset(&an, 0, sizeof(an));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
an = ntohl (u);
}
_result = SBOZO_DeleteKey(call, an);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_SetCellName(
struct rx_call *call)
{
int32_t _result;
char name[256];
memset(&name, 0, sizeof(name));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
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
_result = SBOZO_SetCellName(call, name);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_GetCellName(
struct rx_call *call)
{
int32_t _result;
char name[256];
memset(&name, 0, sizeof(name));

_result = SBOZO_GetCellName(call, name);
if (_result) goto funcfail;
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
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_GetCellHost(
struct rx_call *call)
{
int32_t _result;
int32_t awhich;
char name[256];
memset(&awhich, 0, sizeof(awhich));
memset(&name, 0, sizeof(name));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
awhich = ntohl (u);
}
_result = SBOZO_GetCellHost(call, awhich, name);
if (_result) goto funcfail;
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
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_AddCellHost(
struct rx_call *call)
{
int32_t _result;
char name[256];
memset(&name, 0, sizeof(name));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
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
_result = SBOZO_AddCellHost(call, name);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_DeleteCellHost(
struct rx_call *call)
{
int32_t _result;
char name[256];
memset(&name, 0, sizeof(name));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
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
_result = SBOZO_DeleteCellHost(call, name);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_SetTStatus(
struct rx_call *call)
{
int32_t _result;
char instance[256];
int32_t status;
memset(&instance, 0, sizeof(instance));
memset(&status, 0, sizeof(status));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
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
status = ntohl (u);
}
_result = SBOZO_SetTStatus(call, instance, status);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_ShutdownAll(
struct rx_call *call)
{
int32_t _result;

_result = SBOZO_ShutdownAll(call);
if (_result) goto funcfail;
return _result;
funcfail:
return _result;
}

static int ydr_ps_BOZO_RestartAll(
struct rx_call *call)
{
int32_t _result;

_result = SBOZO_RestartAll(call);
if (_result) goto funcfail;
return _result;
funcfail:
return _result;
}

static int ydr_ps_BOZO_StartupAll(
struct rx_call *call)
{
int32_t _result;

_result = SBOZO_StartupAll(call);
if (_result) goto funcfail;
return _result;
funcfail:
return _result;
}

static int ydr_ps_BOZO_SetNoAuthFlag(
struct rx_call *call)
{
int32_t _result;
int32_t flag;
memset(&flag, 0, sizeof(flag));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
flag = ntohl (u);
}
_result = SBOZO_SetNoAuthFlag(call, flag);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_ReBozo(
struct rx_call *call)
{
int32_t _result;

_result = SBOZO_ReBozo(call);
if (_result) goto funcfail;
return _result;
funcfail:
return _result;
}

static int ydr_ps_BOZO_Restart(
struct rx_call *call)
{
int32_t _result;
char instance[256];
memset(&instance, 0, sizeof(instance));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
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
_result = SBOZO_Restart(call, instance);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_Install(
struct rx_call *call)
{
int32_t _result;
char path[256];
int32_t size;
int32_t flags;
int32_t date;
memset(&path, 0, sizeof(path));
memset(&size, 0, sizeof(size));
memset(&flags, 0, sizeof(flags));
memset(&date, 0, sizeof(date));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (path), len) != len)
goto fail;
(path)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
size = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
date = ntohl (u);
}
_result = SBOZO_Install(call, path, size, flags, date);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_UnInstall(
struct rx_call *call)
{
int32_t _result;
char path[256];
memset(&path, 0, sizeof(path));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (path), len) != len)
goto fail;
(path)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
_result = SBOZO_UnInstall(call, path);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_GetDates(
struct rx_call *call)
{
int32_t _result;
char path[256];
int32_t newtime;
int32_t baktime;
int32_t oldtime;
memset(&path, 0, sizeof(path));
memset(&newtime, 0, sizeof(newtime));
memset(&baktime, 0, sizeof(baktime));
memset(&oldtime, 0, sizeof(oldtime));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (path), len) != len)
goto fail;
(path)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
_result = SBOZO_GetDates(call, path, &newtime, &baktime, &oldtime);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (newtime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (baktime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (oldtime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_Exec(
struct rx_call *call)
{
int32_t _result;
char cmd[256];
memset(&cmd, 0, sizeof(cmd));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (cmd), len) != len)
goto fail;
(cmd)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
_result = SBOZO_Exec(call, cmd);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_Prune(
struct rx_call *call)
{
int32_t _result;
int32_t flags;
memset(&flags, 0, sizeof(flags));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
flags = ntohl (u);
}
_result = SBOZO_Prune(call, flags);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_SetRestartTime(
struct rx_call *call)
{
int32_t _result;
int32_t type;
struct bozo_netKTime restartTime;
memset(&type, 0, sizeof(type));
memset(&restartTime, 0, sizeof(restartTime));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
restartTime.mask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
restartTime.hour = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
restartTime.min = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
restartTime.sec = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
restartTime.day = ntohl (u);
}
_result = SBOZO_SetRestartTime(call, type, &restartTime);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_GetRestartTime(
struct rx_call *call)
{
int32_t _result;
int32_t type;
struct bozo_netKTime restartTime;
memset(&type, 0, sizeof(type));
memset(&restartTime, 0, sizeof(restartTime));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
type = ntohl (u);
}
_result = SBOZO_GetRestartTime(call, type, &restartTime);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (restartTime.mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (restartTime.hour);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (restartTime.min);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (restartTime.sec);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (restartTime.day);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_GetLog(
struct rx_call *call)
{
int32_t _result;
char name[256];
memset(&name, 0, sizeof(name));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
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
_result = SBOZO_GetLog(call, name);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_BOZO_WaitAll(
struct rx_call *call)
{
int32_t _result;

_result = SBOZO_WaitAll(call);
if (_result) goto funcfail;
return _result;
funcfail:
return _result;
}

static int ydr_ps_BOZO_GetInstanceStrings(
struct rx_call *call)
{
int32_t _result;
char instance[256];
char errorname[256];
char spare1[256];
char spare2[256];
char spare3[256];
memset(&instance, 0, sizeof(instance));
memset(&errorname, 0, sizeof(errorname));
memset(&spare1, 0, sizeof(spare1));
memset(&spare2, 0, sizeof(spare2));
memset(&spare3, 0, sizeof(spare3));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 256) {
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
_result = SBOZO_GetInstanceStrings(call, instance, errorname, spare1, spare2, spare3);
if (_result) goto funcfail;
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(errorname);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, errorname, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(spare1);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, spare1, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(spare2);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, spare2, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(spare3);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, spare3, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

int32_t BOZO_ExecuteRequest(struct rx_call *call)
{
unsigned opcode;
int32_t _result;
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
opcode = ntohl (u);
}
switch(opcode) {
case 80: {
_result = ydr_ps_BOZO_CreateBnode(call);
break;
}
case 81: {
_result = ydr_ps_BOZO_DeleteBnode(call);
break;
}
case 82: {
_result = ydr_ps_BOZO_SetStatus(call);
break;
}
case 83: {
_result = ydr_ps_BOZO_GetStatus(call);
break;
}
case 84: {
_result = ydr_ps_BOZO_EnumerateInstance(call);
break;
}
case 85: {
_result = ydr_ps_BOZO_GetInstanceInfo(call);
break;
}
case 86: {
_result = ydr_ps_BOZO_GetInstanceParm(call);
break;
}
case 87: {
_result = ydr_ps_BOZO_AddSUser(call);
break;
}
case 88: {
_result = ydr_ps_BOZO_DeleteSUser(call);
break;
}
case 89: {
_result = ydr_ps_BOZO_ListSUsers(call);
break;
}
case 90: {
_result = ydr_ps_BOZO_ListKeys(call);
break;
}
case 91: {
_result = ydr_ps_BOZO_AddKey(call);
break;
}
case 92: {
_result = ydr_ps_BOZO_DeleteKey(call);
break;
}
case 93: {
_result = ydr_ps_BOZO_SetCellName(call);
break;
}
case 94: {
_result = ydr_ps_BOZO_GetCellName(call);
break;
}
case 95: {
_result = ydr_ps_BOZO_GetCellHost(call);
break;
}
case 96: {
_result = ydr_ps_BOZO_AddCellHost(call);
break;
}
case 97: {
_result = ydr_ps_BOZO_DeleteCellHost(call);
break;
}
case 98: {
_result = ydr_ps_BOZO_SetTStatus(call);
break;
}
case 99: {
_result = ydr_ps_BOZO_ShutdownAll(call);
break;
}
case 100: {
_result = ydr_ps_BOZO_RestartAll(call);
break;
}
case 101: {
_result = ydr_ps_BOZO_StartupAll(call);
break;
}
case 102: {
_result = ydr_ps_BOZO_SetNoAuthFlag(call);
break;
}
case 103: {
_result = ydr_ps_BOZO_ReBozo(call);
break;
}
case 104: {
_result = ydr_ps_BOZO_Restart(call);
break;
}
case 105: {
_result = ydr_ps_BOZO_Install(call);
break;
}
case 106: {
_result = ydr_ps_BOZO_UnInstall(call);
break;
}
case 107: {
_result = ydr_ps_BOZO_GetDates(call);
break;
}
case 108: {
_result = ydr_ps_BOZO_Exec(call);
break;
}
case 109: {
_result = ydr_ps_BOZO_Prune(call);
break;
}
case 110: {
_result = ydr_ps_BOZO_SetRestartTime(call);
break;
}
case 111: {
_result = ydr_ps_BOZO_GetRestartTime(call);
break;
}
case 112: {
_result = ydr_ps_BOZO_GetLog(call);
break;
}
case 113: {
_result = ydr_ps_BOZO_WaitAll(call);
break;
}
case 114: {
_result = ydr_ps_BOZO_GetInstanceStrings(call);
break;
}
default:
_result = RXGEN_OPCODE;
}
return _result;
fail:
return rx_GetCallError(call);
}

