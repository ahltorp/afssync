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
RCSID("cb.ss.c generated from cb.xg with $Id: cb.ss.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
#include "cb.ss.h"

static int ydr_ps_RXAFSCB_CallBack(
struct rx_call *call)
{
int32_t _result;
AFSCBFids a_fidArrayP;
AFSCBs a_callBackArrayP;
memset(&a_fidArrayP, 0, sizeof(a_fidArrayP));
memset(&a_callBackArrayP, 0, sizeof(a_callBackArrayP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidArrayP.len = ntohl (u);
}
if (a_fidArrayP.len > 50) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSFid );
if (overI < a_fidArrayP.len) goto fail;
}
a_fidArrayP.val = (struct AFSFid *)malloc(sizeof(struct AFSFid ) * a_fidArrayP.len);
if (a_fidArrayP.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < a_fidArrayP.len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidArrayP.val[i0].Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidArrayP.val[i0].Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidArrayP.val[i0].Unique = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_callBackArrayP.len = ntohl (u);
}
if (a_callBackArrayP.len > 50) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSCallBack );
if (overI < a_callBackArrayP.len) goto fail;
}
a_callBackArrayP.val = (struct AFSCallBack *)malloc(sizeof(struct AFSCallBack ) * a_callBackArrayP.len);
if (a_callBackArrayP.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < a_callBackArrayP.len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_callBackArrayP.val[i0].CallBackVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_callBackArrayP.val[i0].ExpirationTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_callBackArrayP.val[i0].CallBackType = ntohl (u);
}
}
}
_result = SRXAFSCB_CallBack(call, &a_fidArrayP, &a_callBackArrayP);
if (_result) goto funcfail;
free(a_fidArrayP.val);
free(a_callBackArrayP.val);
return _result;
fail:
free(a_fidArrayP.val);
free(a_callBackArrayP.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFSCB_InitCallBackState(
struct rx_call *call)
{
int32_t _result;

_result = SRXAFSCB_InitCallBackState(call);
if (_result) goto funcfail;
return _result;
funcfail:
return _result;
}

static int ydr_ps_RXAFSCB_Probe(
struct rx_call *call)
{
int32_t _result;

_result = SRXAFSCB_Probe(call);
if (_result) goto funcfail;
return _result;
funcfail:
return _result;
}

static int ydr_ps_RXAFSCB_GetLock(
struct rx_call *call)
{
int32_t _result;
int32_t index;
struct AFSDBLock lock;
memset(&index, 0, sizeof(index));
memset(&lock, 0, sizeof(lock));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
index = ntohl (u);
}
_result = SRXAFSCB_GetLock(call, index, &lock);
if (_result) goto funcfail;
{
int i0;
for(i0 = 0; i0 < 16;++i0){
{ uint32_t u;
u = htonl (lock.name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (lock.lock.waitStates);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (lock.lock.exclLocked);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (lock.lock.readersReading);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (lock.lock.numWaiting);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (lock.lock.spare);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (lock.lock.pid_last_reader);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (lock.lock.pid_writer);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (lock.lock.src_indicator);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFSCB_GetCE(
struct rx_call *call)
{
int32_t _result;
int32_t index;
struct AFSDBCacheEntry cbentry;
memset(&index, 0, sizeof(index));
memset(&cbentry, 0, sizeof(cbentry));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
index = ntohl (u);
}
_result = SRXAFSCB_GetCE(call, index, &cbentry);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (cbentry.addr);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.cell);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.netFid.Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.netFid.Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.netFid.Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.lock.waitStates);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.lock.exclLocked);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.lock.readersReading);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.lock.numWaiting);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.lock.spare);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.lock.pid_last_reader);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.lock.pid_writer);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.lock.src_indicator);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.callback);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.cbExpires);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.refCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.opens);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.writers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.mvstat);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cbentry.states);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFSCB_XStatsVersion(
struct rx_call *call)
{
int32_t _result;
int32_t version;
memset(&version, 0, sizeof(version));

_result = SRXAFSCB_XStatsVersion(call, &version);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (version);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFSCB_GetXStats(
struct rx_call *call)
{
int32_t _result;
int32_t client_version_num;
int32_t collection_number;
int32_t server_version_number;
int32_t time;
AFSCB_CollData stats;
memset(&client_version_num, 0, sizeof(client_version_num));
memset(&collection_number, 0, sizeof(collection_number));
memset(&server_version_number, 0, sizeof(server_version_number));
memset(&time, 0, sizeof(time));
memset(&stats, 0, sizeof(stats));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
client_version_num = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
collection_number = ntohl (u);
}
_result = SRXAFSCB_GetXStats(call, client_version_num, collection_number, &server_version_number, &time, &stats);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (server_version_number);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (time);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stats.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < stats.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < stats.len;++i0){
{ uint32_t u;
u = htonl (stats.val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
free(stats.val);
return _result;
fail:
free(stats.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFSCB_InitCallBackState2(
struct rx_call *call)
{
int32_t _result;
struct interfaceAddr addr;
memset(&addr, 0, sizeof(addr));

_result = SRXAFSCB_InitCallBackState2(call, &addr);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (addr.numberOfInterfaces);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.time_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.time_mid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.time_hi_and_version);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.clock_seq_hi_and_reserved);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.clock_seq_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
u = htonl (addr.uuid.node[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u =  (addr.addr_in[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u =  (addr.subnetmask[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u = htonl (addr.mtu[i0]);
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

static int ydr_ps_RXAFSCB_WhoAreYou(
struct rx_call *call)
{
int32_t _result;
struct interfaceAddr addr;
memset(&addr, 0, sizeof(addr));

_result = SRXAFSCB_WhoAreYou(call, &addr);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (addr.numberOfInterfaces);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.time_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.time_mid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.time_hi_and_version);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.clock_seq_hi_and_reserved);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.clock_seq_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
u = htonl (addr.uuid.node[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u =  (addr.addr_in[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u =  (addr.subnetmask[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u = htonl (addr.mtu[i0]);
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

static int ydr_ps_RXAFSCB_InitCallBackState3(
struct rx_call *call)
{
int32_t _result;
struct afsUUID serverUuid;
memset(&serverUuid, 0, sizeof(serverUuid));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
serverUuid.time_low = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
serverUuid.time_mid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
serverUuid.time_hi_and_version = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
serverUuid.clock_seq_hi_and_reserved = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
serverUuid.clock_seq_low = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
serverUuid.node[i0] = ntohl (u);
}
}
}
_result = SRXAFSCB_InitCallBackState3(call, &serverUuid);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFSCB_ProbeUUID(
struct rx_call *call)
{
int32_t _result;
struct afsUUID uuid;
memset(&uuid, 0, sizeof(uuid));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uuid.time_low = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uuid.time_mid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uuid.time_hi_and_version = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uuid.clock_seq_hi_and_reserved = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uuid.clock_seq_low = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uuid.node[i0] = ntohl (u);
}
}
}
_result = SRXAFSCB_ProbeUUID(call, &uuid);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFSCB_GetCellServDB(
struct rx_call *call)
{
int32_t _result;
int32_t cellIndex;
char cellName[256];
serverList cellHosts;
memset(&cellIndex, 0, sizeof(cellIndex));
memset(&cellName, 0, sizeof(cellName));
memset(&cellHosts, 0, sizeof(cellHosts));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cellIndex = ntohl (u);
}
_result = SRXAFSCB_GetCellServDB(call, cellIndex, cellName, &cellHosts);
if (_result) goto funcfail;
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(cellName);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, cellName, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (cellHosts[i0]);
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

static int ydr_ps_RXAFSCB_GetLocalCell(
struct rx_call *call)
{
int32_t _result;
char cellName[256];
memset(&cellName, 0, sizeof(cellName));

_result = SRXAFSCB_GetLocalCell(call, cellName);
if (_result) goto funcfail;
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(cellName);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, cellName, len) != len)
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

static int ydr_ps_RXAFSCB_GetCacheConfig(
struct rx_call *call)
{
int32_t _result;
uint32_t callerVersion;
uint32_t serverVersion;
uint32_t configCount;
cacheConfig config;
memset(&callerVersion, 0, sizeof(callerVersion));
memset(&serverVersion, 0, sizeof(serverVersion));
memset(&configCount, 0, sizeof(configCount));
memset(&config, 0, sizeof(config));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
callerVersion = ntohl (u);
}
_result = SRXAFSCB_GetCacheConfig(call, callerVersion, &serverVersion, &configCount, &config);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (serverVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (configCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (config.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(uint32_t );
if (overI < config.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < config.len;++i0){
{ uint32_t u;
u = htonl (config.val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
free(config.val);
return _result;
fail:
free(config.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFSCB_GetCellByNum(
struct rx_call *call)
{
int32_t _result;
int32_t cellNumber;
char cellName[256];
serverList cellHosts;
memset(&cellNumber, 0, sizeof(cellNumber));
memset(&cellName, 0, sizeof(cellName));
memset(&cellHosts, 0, sizeof(cellHosts));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cellNumber = ntohl (u);
}
_result = SRXAFSCB_GetCellByNum(call, cellNumber, cellName, &cellHosts);
if (_result) goto funcfail;
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(cellName);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, cellName, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (cellHosts[i0]);
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

static int ydr_ps_RXAFSCB_TellMeAboutYourself(
struct rx_call *call)
{
int32_t _result;
struct interfaceAddr addr;
Capabilities capabilities;
memset(&addr, 0, sizeof(addr));
memset(&capabilities, 0, sizeof(capabilities));

_result = SRXAFSCB_TellMeAboutYourself(call, &addr, &capabilities);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (addr.numberOfInterfaces);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.time_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.time_mid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.time_hi_and_version);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.clock_seq_hi_and_reserved);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (addr.uuid.clock_seq_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
u = htonl (addr.uuid.node[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u =  (addr.addr_in[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u =  (addr.subnetmask[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u = htonl (addr.mtu[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (capabilities.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < capabilities.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < capabilities.len;++i0){
{ uint32_t u;
u = htonl (capabilities.val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
free(capabilities.val);
return _result;
fail:
free(capabilities.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

int32_t RXAFSCB_ExecuteRequest(struct rx_call *call)
{
unsigned opcode;
int32_t _result;
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
opcode = ntohl (u);
}
switch(opcode) {
case 204: {
_result = ydr_ps_RXAFSCB_CallBack(call);
break;
}
case 205: {
_result = ydr_ps_RXAFSCB_InitCallBackState(call);
break;
}
case 206: {
_result = ydr_ps_RXAFSCB_Probe(call);
break;
}
case 207: {
_result = ydr_ps_RXAFSCB_GetLock(call);
break;
}
case 208: {
_result = ydr_ps_RXAFSCB_GetCE(call);
break;
}
case 209: {
_result = ydr_ps_RXAFSCB_XStatsVersion(call);
break;
}
case 210: {
_result = ydr_ps_RXAFSCB_GetXStats(call);
break;
}
case 211: {
_result = ydr_ps_RXAFSCB_InitCallBackState2(call);
break;
}
case 212: {
_result = ydr_ps_RXAFSCB_WhoAreYou(call);
break;
}
case 213: {
_result = ydr_ps_RXAFSCB_InitCallBackState3(call);
break;
}
case 214: {
_result = ydr_ps_RXAFSCB_ProbeUUID(call);
break;
}
case 216: {
_result = ydr_ps_RXAFSCB_GetCellServDB(call);
break;
}
case 217: {
_result = ydr_ps_RXAFSCB_GetLocalCell(call);
break;
}
case 218: {
_result = ydr_ps_RXAFSCB_GetCacheConfig(call);
break;
}
case 65537: {
_result = ydr_ps_RXAFSCB_GetCellByNum(call);
break;
}
case 65538: {
_result = ydr_ps_RXAFSCB_TellMeAboutYourself(call);
break;
}
default:
_result = RXGEN_OPCODE;
}
return _result;
fail:
return rx_GetCallError(call);
}

