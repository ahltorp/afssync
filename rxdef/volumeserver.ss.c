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
RCSID("volumeserver.ss.c generated from volumeserver.xg with $Id: volumeserver.ss.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
#include "volumeserver.ss.h"

static int ydr_ps_VOLSER_AFSVolCreateVolume(
struct rx_call *call)
{
int32_t _result;
int32_t partition;
char *name;
int32_t type;
int32_t parent;
int32_t volid;
int32_t trans;
memset(&partition, 0, sizeof(partition));
memset(&name, 0, sizeof(name));
memset(&type, 0, sizeof(type));
memset(&parent, 0, sizeof(parent));
memset(&volid, 0, sizeof(volid));
memset(&trans, 0, sizeof(trans));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
partition = ntohl (u);
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len == (uint32_t) -1) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
(name) = malloc(len + 1);
if ((name) == NULL) {
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
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
parent = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volid = ntohl (u);
}
_result = SVOLSER_AFSVolCreateVolume(call, partition, name, type, parent, &volid, &trans);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (trans);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolDeleteVolume(
struct rx_call *call)
{
int32_t _result;
int32_t trans;
memset(&trans, 0, sizeof(trans));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
trans = ntohl (u);
}
_result = SVOLSER_AFSVolDeleteVolume(call, trans);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolNukeVolume(
struct rx_call *call)
{
int32_t _result;
int32_t partID;
int32_t volID;
memset(&partID, 0, sizeof(partID));
memset(&volID, 0, sizeof(volID));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
partID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volID = ntohl (u);
}
_result = SVOLSER_AFSVolNukeVolume(call, partID, volID);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolDump(
struct rx_call *call)
{
int32_t _result;
int32_t fromTrans;
int32_t fromDate;
memset(&fromTrans, 0, sizeof(fromTrans));
memset(&fromDate, 0, sizeof(fromDate));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
fromTrans = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
fromDate = ntohl (u);
}
_result = SVOLSER_AFSVolDump(call, fromTrans, fromDate);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolSignalRestore(
struct rx_call *call)
{
int32_t _result;
char *name;
int32_t type;
int32_t pid;
int32_t cloneid;
memset(&name, 0, sizeof(name));
memset(&type, 0, sizeof(type));
memset(&pid, 0, sizeof(pid));
memset(&cloneid, 0, sizeof(cloneid));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len == (uint32_t) -1) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
(name) = malloc(len + 1);
if ((name) == NULL) {
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
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
pid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cloneid = ntohl (u);
}
_result = SVOLSER_AFSVolSignalRestore(call, name, type, pid, cloneid);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolRestore(
struct rx_call *call)
{
int32_t _result;
int32_t toTrans;
int32_t flags;
struct restoreCookie cookie;
memset(&toTrans, 0, sizeof(toTrans));
memset(&flags, 0, sizeof(flags));
memset(&cookie, 0, sizeof(cookie));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
toTrans = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
flags = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cookie.name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cookie.type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cookie.clone = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cookie.parent = ntohl (u);
}
_result = SVOLSER_AFSVolRestore(call, toTrans, flags, &cookie);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolForward(
struct rx_call *call)
{
int32_t _result;
int32_t fromTrans;
int32_t fromData;
struct destServer destination;
int32_t destTrans;
struct restoreCookie cookie;
memset(&fromTrans, 0, sizeof(fromTrans));
memset(&fromData, 0, sizeof(fromData));
memset(&destination, 0, sizeof(destination));
memset(&destTrans, 0, sizeof(destTrans));
memset(&cookie, 0, sizeof(cookie));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
fromTrans = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
fromData = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
destination.destHost = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
destination.destPort = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
destination.destSSID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
destTrans = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cookie.name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cookie.type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cookie.clone = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cookie.parent = ntohl (u);
}
_result = SVOLSER_AFSVolForward(call, fromTrans, fromData, &destination, destTrans, &cookie);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolClone(
struct rx_call *call)
{
int32_t _result;
int32_t trans;
int32_t purgeVol;
int32_t newType;
char *newName;
int32_t newVol;
memset(&trans, 0, sizeof(trans));
memset(&purgeVol, 0, sizeof(purgeVol));
memset(&newType, 0, sizeof(newType));
memset(&newName, 0, sizeof(newName));
memset(&newVol, 0, sizeof(newVol));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
trans = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
purgeVol = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newType = ntohl (u);
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len == (uint32_t) -1) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
(newName) = malloc(len + 1);
if ((newName) == NULL) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (newName), len) != len)
goto fail;
(newName)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newVol = ntohl (u);
}
_result = SVOLSER_AFSVolClone(call, trans, purgeVol, newType, newName, &newVol);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (newVol);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolReClone(
struct rx_call *call)
{
int32_t _result;
int32_t tid;
int32_t cloneID;
memset(&tid, 0, sizeof(tid));
memset(&cloneID, 0, sizeof(cloneID));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
tid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cloneID = ntohl (u);
}
_result = SVOLSER_AFSVolReClone(call, tid, cloneID);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolSetForwarding(
struct rx_call *call)
{
int32_t _result;
int32_t tid;
int32_t newsite;
memset(&tid, 0, sizeof(tid));
memset(&newsite, 0, sizeof(newsite));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
tid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newsite = ntohl (u);
}
_result = SVOLSER_AFSVolSetForwarding(call, tid, newsite);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolTransCreate(
struct rx_call *call)
{
int32_t _result;
int32_t volume;
int32_t partition;
int32_t flags;
int32_t trans;
memset(&volume, 0, sizeof(volume));
memset(&partition, 0, sizeof(partition));
memset(&flags, 0, sizeof(flags));
memset(&trans, 0, sizeof(trans));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
partition = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
flags = ntohl (u);
}
_result = SVOLSER_AFSVolTransCreate(call, volume, partition, flags, &trans);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (trans);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolEndTrans(
struct rx_call *call)
{
int32_t _result;
int32_t trans;
int32_t rcode;
memset(&trans, 0, sizeof(trans));
memset(&rcode, 0, sizeof(rcode));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
trans = ntohl (u);
}
_result = SVOLSER_AFSVolEndTrans(call, trans, &rcode);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (rcode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolGetFlags(
struct rx_call *call)
{
int32_t _result;
int32_t trans;
int32_t flags;
memset(&trans, 0, sizeof(trans));
memset(&flags, 0, sizeof(flags));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
trans = ntohl (u);
}
_result = SVOLSER_AFSVolGetFlags(call, trans, &flags);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolSetFlags(
struct rx_call *call)
{
int32_t _result;
int32_t trans;
int32_t flags;
memset(&trans, 0, sizeof(trans));
memset(&flags, 0, sizeof(flags));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
trans = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
flags = ntohl (u);
}
_result = SVOLSER_AFSVolSetFlags(call, trans, flags);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolGetName(
struct rx_call *call)
{
int32_t _result;
int32_t tid;
char tname[256];
memset(&tid, 0, sizeof(tid));
memset(&tname, 0, sizeof(tname));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
tid = ntohl (u);
}
_result = SVOLSER_AFSVolGetName(call, tid, tname);
if (_result) goto funcfail;
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(tname);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, tname, len) != len)
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

static int ydr_ps_VOLSER_AFSVolGetStatus(
struct rx_call *call)
{
int32_t _result;
int32_t tid;
struct volser_status status;
memset(&tid, 0, sizeof(tid));
memset(&status, 0, sizeof(status));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
tid = ntohl (u);
}
_result = SVOLSER_AFSVolGetStatus(call, tid, &status);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (status.volID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.nextUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.parentID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.cloneID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.backupID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.restoredFromID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.maxQuota);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.minQuota);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.creationDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.accessDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.updateDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.exprirationDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.backupDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (status.copyDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolSetIdsTypes(
struct rx_call *call)
{
int32_t _result;
int32_t tId;
char *name;
int32_t type;
int32_t pId;
int32_t cloneId;
int32_t backupId;
memset(&tId, 0, sizeof(tId));
memset(&name, 0, sizeof(name));
memset(&type, 0, sizeof(type));
memset(&pId, 0, sizeof(pId));
memset(&cloneId, 0, sizeof(cloneId));
memset(&backupId, 0, sizeof(backupId));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
tId = ntohl (u);
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len == (uint32_t) -1) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
(name) = malloc(len + 1);
if ((name) == NULL) {
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
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
pId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cloneId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
backupId = ntohl (u);
}
_result = SVOLSER_AFSVolSetIdsTypes(call, tId, name, type, pId, cloneId, backupId);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolSetDate(
struct rx_call *call)
{
int32_t _result;
int32_t tid;
int32_t newDate;
memset(&tid, 0, sizeof(tid));
memset(&newDate, 0, sizeof(newDate));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
tid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newDate = ntohl (u);
}
_result = SVOLSER_AFSVolSetDate(call, tid, newDate);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolListPartitions(
struct rx_call *call)
{
int32_t _result;
struct pIDs partIDs;
memset(&partIDs, 0, sizeof(partIDs));

_result = SVOLSER_AFSVolListPartitions(call, &partIDs);
if (_result) goto funcfail;
{
int i0;
for(i0 = 0; i0 < 26;++i0){
{ uint32_t u;
u = htonl (partIDs.partIds[i0]);
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

static int ydr_ps_VOLSER_AFSVolPartitionInfo(
struct rx_call *call)
{
int32_t _result;
char *name;
struct diskPartition partition;
memset(&name, 0, sizeof(name));
memset(&partition, 0, sizeof(partition));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len == (uint32_t) -1) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
(name) = malloc(len + 1);
if ((name) == NULL) {
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
_result = SVOLSER_AFSVolPartitionInfo(call, name, &partition);
if (_result) goto funcfail;
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u = htonl (partition.name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
u = htonl (partition.devName[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (partition.lock_fd);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (partition.totalUsable);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (partition.free);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (partition.minFree);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolListVolumes(
struct rx_call *call)
{
int32_t _result;
int32_t partID;
int32_t flags;
volEntries resultEntries;
memset(&partID, 0, sizeof(partID));
memset(&flags, 0, sizeof(flags));
memset(&resultEntries, 0, sizeof(resultEntries));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
partID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
flags = ntohl (u);
}
_result = SVOLSER_AFSVolListVolumes(call, partID, flags, &resultEntries);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (resultEntries.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct volintInfo );
if (overI < resultEntries.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < resultEntries.len;++i0){
{
int i1;
for(i1 = 0; i1 < 32;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].name[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].backupID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].parentID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].cloneID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].status);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].copyDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].inUse);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].needsSalvaged);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].destroyMe);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].creationDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].accessDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].updateDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].backupDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].dayUse);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].filecount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].maxquota);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].size);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].spare0);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
free(resultEntries.val);
return _result;
fail:
free(resultEntries.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolListOneVolume(
struct rx_call *call)
{
int32_t _result;
int32_t partID;
int32_t volid;
volEntries resultEntries;
memset(&partID, 0, sizeof(partID));
memset(&volid, 0, sizeof(volid));
memset(&resultEntries, 0, sizeof(resultEntries));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
partID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volid = ntohl (u);
}
_result = SVOLSER_AFSVolListOneVolume(call, partID, volid, &resultEntries);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (resultEntries.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct volintInfo );
if (overI < resultEntries.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < resultEntries.len;++i0){
{
int i1;
for(i1 = 0; i1 < 32;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].name[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].backupID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].parentID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].cloneID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].status);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].copyDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].inUse);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].needsSalvaged);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].destroyMe);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].creationDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].accessDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].updateDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].backupDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].dayUse);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].filecount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].maxquota);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].size);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].spare0);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
free(resultEntries.val);
return _result;
fail:
free(resultEntries.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolGetNthVolume(
struct rx_call *call)
{
int32_t _result;
int32_t index;
int32_t volume;
int32_t partition;
memset(&index, 0, sizeof(index));
memset(&volume, 0, sizeof(volume));
memset(&partition, 0, sizeof(partition));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
index = ntohl (u);
}
_result = SVOLSER_AFSVolGetNthVolume(call, index, &volume, &partition);
if (_result) goto funcfail;
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
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolMonitor(
struct rx_call *call)
{
int32_t _result;
transDebugEntries result;
memset(&result, 0, sizeof(result));

_result = SVOLSER_AFSVolMonitor(call, &result);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (result.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct transDebugInfo );
if (overI < result.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < result.len;++i0){
{ uint32_t u;
u = htonl (result.val[i0].tid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (result.val[i0].time);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (result.val[i0].creationTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (result.val[i0].returnCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (result.val[i0].volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (result.val[i0].partition);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (result.val[i0].iflags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (result.val[i0].vflags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (result.val[i0].tflags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i1;
for(i1 = 0; i1 < 30;++i1){
{ uint32_t u;
u = htonl (result.val[i0].lastProcName[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (result.val[i0].callValid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (result.val[i0].readNext);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (result.val[i0].transmitNext);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (result.val[i0].lastSendTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (result.val[i0].lastReceiveTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
free(result.val);
return _result;
fail:
free(result.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolXListVolumes(
struct rx_call *call)
{
int32_t _result;
int32_t partID;
int32_t flags;
xvolEntries resultEntries;
memset(&partID, 0, sizeof(partID));
memset(&flags, 0, sizeof(flags));
memset(&resultEntries, 0, sizeof(resultEntries));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
partID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
flags = ntohl (u);
}
_result = SVOLSER_AFSVolXListVolumes(call, partID, flags, &resultEntries);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (resultEntries.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct xvolintInfo );
if (overI < resultEntries.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < resultEntries.len;++i0){
{
int i1;
for(i1 = 0; i1 < 32;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].name[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].backupID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].parentID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].cloneID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].status);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].copyDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].inUse);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].creationDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].accessDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].updateDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].backupDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].dayUse);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].filecount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].maxquota);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].size);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].stat_reads[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].stat_writes[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].stat_fileSameAuthor[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].stat_fileDiffAuthor[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].stat_dirSameAuthor[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].stat_dirDiffAuthor[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
}
}
free(resultEntries.val);
return _result;
fail:
free(resultEntries.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolXListOneVolume(
struct rx_call *call)
{
int32_t _result;
int32_t partID;
int32_t volid;
xvolEntries resultEntries;
memset(&partID, 0, sizeof(partID));
memset(&volid, 0, sizeof(volid));
memset(&resultEntries, 0, sizeof(resultEntries));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
partID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volid = ntohl (u);
}
_result = SVOLSER_AFSVolXListOneVolume(call, partID, volid, &resultEntries);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (resultEntries.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct xvolintInfo );
if (overI < resultEntries.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < resultEntries.len;++i0){
{
int i1;
for(i1 = 0; i1 < 32;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].name[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].backupID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].parentID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].cloneID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].status);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].copyDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].inUse);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].creationDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].accessDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].updateDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].backupDate);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].dayUse);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].filecount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].maxquota);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (resultEntries.val[i0].size);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].stat_reads[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].stat_writes[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].stat_fileSameAuthor[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].stat_fileDiffAuthor[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].stat_dirSameAuthor[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ uint32_t u;
u = htonl (resultEntries.val[i0].stat_dirDiffAuthor[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
}
}
free(resultEntries.val);
return _result;
fail:
free(resultEntries.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolSetInfo(
struct rx_call *call)
{
int32_t _result;
int32_t transid;
struct volintInfo volinfo;
memset(&transid, 0, sizeof(transid));
memset(&volinfo, 0, sizeof(volinfo));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
transid = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.volid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.backupID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.parentID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.cloneID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.status = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.copyDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.inUse = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.needsSalvaged = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.destroyMe = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.creationDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.accessDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.updateDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.backupDate = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.dayUse = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.filecount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.maxquota = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.size = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.spare0 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volinfo.spare3 = ntohl (u);
}
_result = SVOLSER_AFSVolSetInfo(call, transid, &volinfo);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolXListPartitions(
struct rx_call *call)
{
int32_t _result;
part_entries ent;
memset(&ent, 0, sizeof(ent));

_result = SVOLSER_AFSVolXListPartitions(call, &ent);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (ent.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < ent.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < ent.len;++i0){
{ uint32_t u;
u = htonl (ent.val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
free(ent.val);
return _result;
fail:
free(ent.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VOLSER_AFSVolForwardMultiple(
struct rx_call *call)
{
int32_t _result;
int32_t fromTrans;
int32_t fromData;
manyDests destinations;
int32_t spare0;
struct restoreCookie cookie;
multi_results results;
memset(&fromTrans, 0, sizeof(fromTrans));
memset(&fromData, 0, sizeof(fromData));
memset(&destinations, 0, sizeof(destinations));
memset(&spare0, 0, sizeof(spare0));
memset(&cookie, 0, sizeof(cookie));
memset(&results, 0, sizeof(results));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
fromTrans = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
fromData = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
destinations.len = ntohl (u);
}
if (destinations.len > 255) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct replica );
if (overI < destinations.len) goto fail;
}
destinations.val = (struct replica *)malloc(sizeof(struct replica ) * destinations.len);
if (destinations.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < destinations.len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
destinations.val[i0].trans_id = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
destinations.val[i0].destserver.destHost = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
destinations.val[i0].destserver.destPort = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
destinations.val[i0].destserver.destSSID = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
spare0 = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cookie.name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cookie.type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cookie.clone = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
cookie.parent = ntohl (u);
}
_result = SVOLSER_AFSVolForwardMultiple(call, fromTrans, fromData, &destinations, spare0, &cookie, &results);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (results.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < results.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < results.len;++i0){
{ uint32_t u;
u = htonl (results.val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
free(destinations.val);
free(results.val);
return _result;
fail:
free(destinations.val);
free(results.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

int32_t VOLSER_ExecuteRequest(struct rx_call *call)
{
unsigned opcode;
int32_t _result;
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
opcode = ntohl (u);
}
switch(opcode) {
case 100: {
_result = ydr_ps_VOLSER_AFSVolCreateVolume(call);
break;
}
case 101: {
_result = ydr_ps_VOLSER_AFSVolDeleteVolume(call);
break;
}
case 122: {
_result = ydr_ps_VOLSER_AFSVolNukeVolume(call);
break;
}
case 109: {
_result = ydr_ps_VOLSER_AFSVolDump(call);
break;
}
case 114: {
_result = ydr_ps_VOLSER_AFSVolSignalRestore(call);
break;
}
case 102: {
_result = ydr_ps_VOLSER_AFSVolRestore(call);
break;
}
case 103: {
_result = ydr_ps_VOLSER_AFSVolForward(call);
break;
}
case 105: {
_result = ydr_ps_VOLSER_AFSVolClone(call);
break;
}
case 120: {
_result = ydr_ps_VOLSER_AFSVolReClone(call);
break;
}
case 111: {
_result = ydr_ps_VOLSER_AFSVolSetForwarding(call);
break;
}
case 108: {
_result = ydr_ps_VOLSER_AFSVolTransCreate(call);
break;
}
case 104: {
_result = ydr_ps_VOLSER_AFSVolEndTrans(call);
break;
}
case 107: {
_result = ydr_ps_VOLSER_AFSVolGetFlags(call);
break;
}
case 106: {
_result = ydr_ps_VOLSER_AFSVolSetFlags(call);
break;
}
case 112: {
_result = ydr_ps_VOLSER_AFSVolGetName(call);
break;
}
case 113: {
_result = ydr_ps_VOLSER_AFSVolGetStatus(call);
break;
}
case 117: {
_result = ydr_ps_VOLSER_AFSVolSetIdsTypes(call);
break;
}
case 123: {
_result = ydr_ps_VOLSER_AFSVolSetDate(call);
break;
}
case 115: {
_result = ydr_ps_VOLSER_AFSVolListPartitions(call);
break;
}
case 119: {
_result = ydr_ps_VOLSER_AFSVolPartitionInfo(call);
break;
}
case 116: {
_result = ydr_ps_VOLSER_AFSVolListVolumes(call);
break;
}
case 121: {
_result = ydr_ps_VOLSER_AFSVolListOneVolume(call);
break;
}
case 110: {
_result = ydr_ps_VOLSER_AFSVolGetNthVolume(call);
break;
}
case 118: {
_result = ydr_ps_VOLSER_AFSVolMonitor(call);
break;
}
case 124: {
_result = ydr_ps_VOLSER_AFSVolXListVolumes(call);
break;
}
case 125: {
_result = ydr_ps_VOLSER_AFSVolXListOneVolume(call);
break;
}
case 126: {
_result = ydr_ps_VOLSER_AFSVolSetInfo(call);
break;
}
case 127: {
_result = ydr_ps_VOLSER_AFSVolXListPartitions(call);
break;
}
case 128: {
_result = ydr_ps_VOLSER_AFSVolForwardMultiple(call);
break;
}
default:
_result = RXGEN_OPCODE;
}
return _result;
fail:
return rx_GetCallError(call);
}

