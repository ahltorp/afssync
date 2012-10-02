/* Generated from volumeserver.xg */
#include "volumeserver.h"

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
RCSID("volumeserver.cs.c generated from volumeserver.xg with $Id: volumeserver.cs.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
#include "volumeserver.cs.h"

int VOLSER_AFSVolCreateVolume(
struct rx_connection *connection
, const int32_t partition
, const char *name
, const int32_t type
, const int32_t parent
, int32_t *volid
, int32_t *trans
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (100);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (partition);
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
{ uint32_t u;
u = htonl (type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (parent);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volid));
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*volid) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*trans) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolDeleteVolume(
struct rx_connection *connection
, const int32_t trans
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (101);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (trans);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolNukeVolume(
struct rx_connection *connection
, const int32_t partID
, const int32_t volID
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (122);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (partID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (volID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int StartVOLSER_AFSVolDump(
struct rx_call *call
, const int32_t fromTrans
, const int32_t fromDate
)
{
{ uint32_t u;
u = htonl (109);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (fromTrans);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (fromDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return 0;
fail:
return conv_to_arla_errno(rx_GetCallError(call));
}

int EndVOLSER_AFSVolDump(
struct rx_call *call
)
{
return 0;
}

int VOLSER_AFSVolSignalRestore(
struct rx_connection *connection
, const char *name
, const int32_t type
, const int32_t pid
, const int32_t cloneid
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (114);
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
{ uint32_t u;
u = htonl (type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (pid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cloneid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int StartVOLSER_AFSVolRestore(
struct rx_call *call
, const int32_t toTrans
, const int32_t flags
, const struct restoreCookie *cookie
)
{
{ uint32_t u;
u = htonl (102);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (toTrans);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u = htonl ((*cookie).name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*cookie).type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*cookie).clone);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*cookie).parent);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return 0;
fail:
return conv_to_arla_errno(rx_GetCallError(call));
}

int EndVOLSER_AFSVolRestore(
struct rx_call *call
)
{
return 0;
}

int VOLSER_AFSVolForward(
struct rx_connection *connection
, const int32_t fromTrans
, const int32_t fromData
, const struct destServer *destination
, const int32_t destTrans
, const struct restoreCookie *cookie
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (103);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (fromTrans);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (fromData);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*destination).destHost);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*destination).destPort);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*destination).destSSID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (destTrans);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u = htonl ((*cookie).name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*cookie).type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*cookie).clone);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*cookie).parent);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolClone(
struct rx_connection *connection
, const int32_t trans
, const int32_t purgeVol
, const int32_t newType
, const char *newName
, int32_t *newVol
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (105);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (trans);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (purgeVol);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (newType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(newName);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, newName, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*newVol));
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*newVol) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolReClone(
struct rx_connection *connection
, const int32_t tid
, const int32_t cloneID
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (120);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (tid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cloneID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolSetForwarding(
struct rx_connection *connection
, const int32_t tid
, const int32_t newsite
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (111);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (tid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (newsite);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolTransCreate(
struct rx_connection *connection
, const int32_t volume
, const int32_t partition
, const int32_t flags
, int32_t *trans
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (108);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (partition);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*trans) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolEndTrans(
struct rx_connection *connection
, const int32_t trans
, int32_t *rcode
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (104);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (trans);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*rcode) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolGetFlags(
struct rx_connection *connection
, const int32_t trans
, int32_t *flags
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (107);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (trans);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*flags) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolSetFlags(
struct rx_connection *connection
, const int32_t trans
, const int32_t flags
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (106);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (trans);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolGetName(
struct rx_connection *connection
, const int32_t tid
, char *tname
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (112);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (tid);
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
if(rx_Read(call, (tname), len) != len)
goto fail;
(tname)[len] = '\0';
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
int VOLSER_AFSVolGetStatus(
struct rx_connection *connection
, const int32_t tid
, struct volser_status *status
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (113);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (tid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).volID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).nextUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).parentID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).cloneID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).backupID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).restoredFromID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).maxQuota = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).minQuota = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).creationDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).accessDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).updateDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).exprirationDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).backupDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*status).copyDate = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolSetIdsTypes(
struct rx_connection *connection
, const int32_t tId
, const char *name
, const int32_t type
, const int32_t pId
, const int32_t cloneId
, const int32_t backupId
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (117);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (tId);
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
{ uint32_t u;
u = htonl (type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (pId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (cloneId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (backupId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolSetDate(
struct rx_connection *connection
, const int32_t tid
, const int32_t newDate
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (123);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (tid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (newDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolListPartitions(
struct rx_connection *connection
, struct pIDs *partIDs
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (115);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 26;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*partIDs).partIds[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolPartitionInfo(
struct rx_connection *connection
, const char *name
, struct diskPartition *partition
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (119);
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
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*partition).name[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*partition).devName[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*partition).lock_fd = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*partition).totalUsable = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*partition).free = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*partition).minFree = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolListVolumes(
struct rx_connection *connection
, const int32_t partID
, const int32_t flags
, volEntries *resultEntries
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (116);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (partID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct volintInfo );
if (overI < (*resultEntries).len) goto fail;
}
(*resultEntries).val = (struct volintInfo *)malloc(sizeof(struct volintInfo ) * (*resultEntries).len);
if ((*resultEntries).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*resultEntries).len;++i0){
{
int i1;
for(i1 = 0; i1 < 32;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].name[i1] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].volid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].backupID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].parentID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].cloneID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].status = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].copyDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].inUse = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].needsSalvaged = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].destroyMe = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].creationDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].accessDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].updateDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].backupDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].dayUse = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].filecount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].maxquota = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].size = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].spare0 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].spare3 = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolListOneVolume(
struct rx_connection *connection
, const int32_t partID
, const int32_t volid
, volEntries *resultEntries
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (121);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (partID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct volintInfo );
if (overI < (*resultEntries).len) goto fail;
}
(*resultEntries).val = (struct volintInfo *)malloc(sizeof(struct volintInfo ) * (*resultEntries).len);
if ((*resultEntries).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*resultEntries).len;++i0){
{
int i1;
for(i1 = 0; i1 < 32;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].name[i1] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].volid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].backupID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].parentID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].cloneID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].status = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].copyDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].inUse = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].needsSalvaged = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].destroyMe = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].creationDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].accessDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].updateDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].backupDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].dayUse = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].filecount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].maxquota = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].size = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].spare0 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].spare3 = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolGetNthVolume(
struct rx_connection *connection
, const int32_t index
, int32_t *volume
, int32_t *partition
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (110);
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
(*volume) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*partition) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolMonitor(
struct rx_connection *connection
, transDebugEntries *result
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (118);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct transDebugInfo );
if (overI < (*result).len) goto fail;
}
(*result).val = (struct transDebugInfo *)malloc(sizeof(struct transDebugInfo ) * (*result).len);
if ((*result).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*result).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].tid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].time = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].creationTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].returnCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].volid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].partition = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].iflags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].vflags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].tflags = ntohl (u);
}
{
int i1;
for(i1 = 0; i1 < 30;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].lastProcName[i1] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].callValid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].readNext = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].transmitNext = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].lastSendTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*result).val[i0].lastReceiveTime = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolXListVolumes(
struct rx_connection *connection
, const int32_t partID
, const int32_t flags
, xvolEntries *resultEntries
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (124);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (partID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct xvolintInfo );
if (overI < (*resultEntries).len) goto fail;
}
(*resultEntries).val = (struct xvolintInfo *)malloc(sizeof(struct xvolintInfo ) * (*resultEntries).len);
if ((*resultEntries).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*resultEntries).len;++i0){
{
int i1;
for(i1 = 0; i1 < 32;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].name[i1] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].volid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].backupID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].parentID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].cloneID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].status = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].copyDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].inUse = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].creationDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].accessDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].updateDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].backupDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].dayUse = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].filecount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].maxquota = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].size = ntohl (u);
}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].stat_reads[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].stat_writes[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].stat_fileSameAuthor[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].stat_fileDiffAuthor[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].stat_dirSameAuthor[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].stat_dirDiffAuthor[i1] = ntohl (u);
}
}
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolXListOneVolume(
struct rx_connection *connection
, const int32_t partID
, const int32_t volid
, xvolEntries *resultEntries
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (125);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (partID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct xvolintInfo );
if (overI < (*resultEntries).len) goto fail;
}
(*resultEntries).val = (struct xvolintInfo *)malloc(sizeof(struct xvolintInfo ) * (*resultEntries).len);
if ((*resultEntries).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*resultEntries).len;++i0){
{
int i1;
for(i1 = 0; i1 < 32;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].name[i1] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].volid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].backupID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].parentID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].cloneID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].status = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].copyDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].inUse = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].creationDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].accessDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].updateDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].backupDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].dayUse = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].filecount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].maxquota = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].size = ntohl (u);
}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].stat_reads[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].stat_writes[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].stat_fileSameAuthor[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].stat_fileDiffAuthor[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].stat_dirSameAuthor[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*resultEntries).val[i0].stat_dirDiffAuthor[i1] = ntohl (u);
}
}
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolSetInfo(
struct rx_connection *connection
, const int32_t transid
, const struct volintInfo *volinfo
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (126);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (transid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u = htonl ((*volinfo).name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*volinfo).volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).backupID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).parentID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).cloneID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).status);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).copyDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).inUse);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).needsSalvaged);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).destroyMe);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).creationDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).accessDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).updateDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).backupDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).dayUse);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).filecount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).maxquota);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).size);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).spare0);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*volinfo).spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolXListPartitions(
struct rx_connection *connection
, part_entries *ent
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (127);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*ent).len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*ent).len) goto fail;
}
(*ent).val = (int32_t *)malloc(sizeof(int32_t ) * (*ent).len);
if ((*ent).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*ent).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*ent).val[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VOLSER_AFSVolForwardMultiple(
struct rx_connection *connection
, const int32_t fromTrans
, const int32_t fromData
, const manyDests *destinations
, const int32_t spare0
, const struct restoreCookie *cookie
, multi_results *results
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (128);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (fromTrans);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (fromData);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*destinations).len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct replica );
if (overI < (*destinations).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*destinations).len;++i0){
{ uint32_t u;
u = htonl ((*destinations).val[i0].trans_id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*destinations).val[i0].destserver.destHost);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*destinations).val[i0].destserver.destPort);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*destinations).val[i0].destserver.destSSID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (spare0);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u = htonl ((*cookie).name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*cookie).type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*cookie).clone);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*cookie).parent);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*results).len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*results).len) goto fail;
}
(*results).val = (int32_t *)malloc(sizeof(int32_t ) * (*results).len);
if ((*results).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*results).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*results).val[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
