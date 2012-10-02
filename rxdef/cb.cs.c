/* Generated from cb.xg */
#include "cb.h"

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
RCSID("cb.cs.c generated from cb.xg with $Id: cb.cs.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
#include "cb.cs.h"

int RXAFSCB_CallBack(
struct rx_connection *connection
, const AFSCBFids *a_fidArrayP
, const AFSCBs *a_callBackArrayP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (204);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidArrayP).len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSFid );
if (overI < (*a_fidArrayP).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*a_fidArrayP).len;++i0){
{ uint32_t u;
u = htonl ((*a_fidArrayP).val[i0].Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidArrayP).val[i0].Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidArrayP).val[i0].Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*a_callBackArrayP).len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSCallBack );
if (overI < (*a_callBackArrayP).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*a_callBackArrayP).len;++i0){
{ uint32_t u;
u = htonl ((*a_callBackArrayP).val[i0].CallBackVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_callBackArrayP).val[i0].ExpirationTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_callBackArrayP).val[i0].CallBackType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_InitCallBackState(
struct rx_connection *connection
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (205);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_Probe(
struct rx_connection *connection
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (206);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_GetLock(
struct rx_connection *connection
, const int32_t index
, struct AFSDBLock *lock
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (207);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (index);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 16;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*lock).name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*lock).lock.waitStates = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*lock).lock.exclLocked = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*lock).lock.readersReading = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*lock).lock.numWaiting = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*lock).lock.spare = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*lock).lock.pid_last_reader = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*lock).lock.pid_writer = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*lock).lock.src_indicator = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_GetCE(
struct rx_connection *connection
, const int32_t index
, struct AFSDBCacheEntry *cbentry
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (208);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (index);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).addr = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).cell = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).netFid.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).netFid.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).netFid.Unique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).lock.waitStates = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).lock.exclLocked = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).lock.readersReading = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).lock.numWaiting = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).lock.spare = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).lock.pid_last_reader = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).lock.pid_writer = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).lock.src_indicator = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).callback = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).cbExpires = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).refCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).opens = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).writers = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).mvstat = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*cbentry).states = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_XStatsVersion(
struct rx_connection *connection
, int32_t *version
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (209);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*version) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_GetXStats(
struct rx_connection *connection
, const int32_t client_version_num
, const int32_t collection_number
, int32_t *server_version_number
, int32_t *time
, AFSCB_CollData *stats
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (210);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (client_version_num);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (collection_number);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*server_version_number) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*time) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stats).len = ntohl (u);
}
if ((*stats).len > 2048) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*stats).len) goto fail;
}
(*stats).val = (int32_t *)malloc(sizeof(int32_t ) * (*stats).len);
if ((*stats).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*stats).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stats).val[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_InitCallBackState2(
struct rx_connection *connection
, struct interfaceAddr *addr
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (211);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).numberOfInterfaces = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.time_low = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.time_mid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.time_hi_and_version = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.clock_seq_hi_and_reserved = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.clock_seq_low = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.node[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).addr_in[i0] =  (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).subnetmask[i0] =  (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).mtu[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_WhoAreYou(
struct rx_connection *connection
, struct interfaceAddr *addr
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (212);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).numberOfInterfaces = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.time_low = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.time_mid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.time_hi_and_version = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.clock_seq_hi_and_reserved = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.clock_seq_low = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.node[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).addr_in[i0] =  (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).subnetmask[i0] =  (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).mtu[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_InitCallBackState3(
struct rx_connection *connection
, const struct afsUUID *serverUuid
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (213);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*serverUuid).time_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*serverUuid).time_mid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*serverUuid).time_hi_and_version);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*serverUuid).clock_seq_hi_and_reserved);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*serverUuid).clock_seq_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
u = htonl ((*serverUuid).node[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_ProbeUUID(
struct rx_connection *connection
, const struct afsUUID *uuid
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (214);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*uuid).time_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*uuid).time_mid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*uuid).time_hi_and_version);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*uuid).clock_seq_hi_and_reserved);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*uuid).clock_seq_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
u = htonl ((*uuid).node[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_GetCellServDB(
struct rx_connection *connection
, const int32_t cellIndex
, char *cellName
, serverList *cellHosts
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (216);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cellIndex);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
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
if(rx_Read(call, (cellName), len) != len)
goto fail;
(cellName)[len] = '\0';
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
(*cellHosts)[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_GetLocalCell(
struct rx_connection *connection
, char *cellName
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (217);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
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
if(rx_Read(call, (cellName), len) != len)
goto fail;
(cellName)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_GetCacheConfig(
struct rx_connection *connection
, const uint32_t callerVersion
, uint32_t *serverVersion
, uint32_t *configCount
, cacheConfig *config
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (218);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (callerVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*serverVersion) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*configCount) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*config).len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(uint32_t );
if (overI < (*config).len) goto fail;
}
(*config).val = (uint32_t *)malloc(sizeof(uint32_t ) * (*config).len);
if ((*config).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*config).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*config).val[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_GetCellByNum(
struct rx_connection *connection
, const int32_t cellNumber
, char *cellName
, serverList *cellHosts
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (65537);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cellNumber);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
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
if(rx_Read(call, (cellName), len) != len)
goto fail;
(cellName)[len] = '\0';
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
(*cellHosts)[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFSCB_TellMeAboutYourself(
struct rx_connection *connection
, struct interfaceAddr *addr
, Capabilities *capabilities
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (65538);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).numberOfInterfaces = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.time_low = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.time_mid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.time_hi_and_version = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.clock_seq_hi_and_reserved = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.clock_seq_low = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).uuid.node[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).addr_in[i0] =  (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).subnetmask[i0] =  (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*addr).mtu[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*capabilities).len = ntohl (u);
}
if ((*capabilities).len > 196) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*capabilities).len) goto fail;
}
(*capabilities).val = (int32_t *)malloc(sizeof(int32_t ) * (*capabilities).len);
if ((*capabilities).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*capabilities).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*capabilities).val[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
