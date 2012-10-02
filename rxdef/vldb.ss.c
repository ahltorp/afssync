/* Generated from vldb.xg */
#include "vldb.h"

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
RCSID("vldb.ss.c generated from vldb.xg with $Id: vldb.ss.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
#include "vldb.ss.h"

static int ydr_ps_VL_CreateEntry(
struct rx_call *call)
{
int32_t _result;
struct vldbentry newentry;
memset(&newentry, 0, sizeof(newentry));

{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.volumeType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.nServers = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.serverNumber[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.serverPartition[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.serverFlags[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.volumeId[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.cloneId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.flags = ntohl (u);
}
_result = SVL_CreateEntry(call, &newentry);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_DeleteEntry(
struct rx_call *call)
{
int32_t _result;
int32_t Volid;
int32_t voltype;
memset(&Volid, 0, sizeof(Volid));
memset(&voltype, 0, sizeof(voltype));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Volid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
voltype = ntohl (u);
}
_result = SVL_DeleteEntry(call, Volid, voltype);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_GetEntryByID(
struct rx_call *call)
{
int32_t _result;
int32_t Volid;
int32_t voltype;
struct vldbentry entry;
memset(&Volid, 0, sizeof(Volid));
memset(&voltype, 0, sizeof(voltype));
memset(&entry, 0, sizeof(entry));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Volid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
voltype = ntohl (u);
}
_result = SVL_GetEntryByID(call, Volid, voltype, &entry);
if (_result) goto funcfail;
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
u = htonl (entry.name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.volumeType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.nServers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (entry.serverNumber[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (entry.serverPartition[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (entry.serverFlags[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
u = htonl (entry.volumeId[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.cloneId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_GetEntryByName(
struct rx_call *call)
{
int32_t _result;
char volumename[65];
struct vldbentry entry;
memset(&volumename, 0, sizeof(volumename));
memset(&entry, 0, sizeof(entry));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 65) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (volumename), len) != len)
goto fail;
(volumename)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
_result = SVL_GetEntryByName(call, volumename, &entry);
if (_result) goto funcfail;
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
u = htonl (entry.name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.volumeType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.nServers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (entry.serverNumber[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (entry.serverPartition[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (entry.serverFlags[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
u = htonl (entry.volumeId[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.cloneId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_GetNewVolumeId(
struct rx_call *call)
{
int32_t _result;
int32_t bumpcount;
int32_t newvolumid;
memset(&bumpcount, 0, sizeof(bumpcount));
memset(&newvolumid, 0, sizeof(newvolumid));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
bumpcount = ntohl (u);
}
_result = SVL_GetNewVolumeId(call, bumpcount, &newvolumid);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (newvolumid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_ReplaceEntry(
struct rx_call *call)
{
int32_t _result;
int32_t Volid;
int32_t voltype;
struct vldbentry newentry;
int32_t ReleaseType;
memset(&Volid, 0, sizeof(Volid));
memset(&voltype, 0, sizeof(voltype));
memset(&newentry, 0, sizeof(newentry));
memset(&ReleaseType, 0, sizeof(ReleaseType));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Volid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
voltype = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.volumeType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.nServers = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.serverNumber[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.serverPartition[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.serverFlags[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.volumeId[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.cloneId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
ReleaseType = ntohl (u);
}
_result = SVL_ReplaceEntry(call, Volid, voltype, &newentry, ReleaseType);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_UpdateEntry(
struct rx_call *call)
{
int32_t _result;
int32_t Volid;
int32_t voltype;
struct VldbUpdateEntry UpdateEntry;
int32_t ReleaseType;
memset(&Volid, 0, sizeof(Volid));
memset(&voltype, 0, sizeof(voltype));
memset(&UpdateEntry, 0, sizeof(UpdateEntry));
memset(&ReleaseType, 0, sizeof(ReleaseType));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Volid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
voltype = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.Mask = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.volumeType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.ReadOnlyId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.BackupId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.cloneid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.nModifiedRepsites = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.RepsitesMask[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.RepsitesTargetServer[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.RepsitesTargetPart[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.RepsitesNewServer[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.RepsitesNewPart[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.RepsitesNewFlags[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
ReleaseType = ntohl (u);
}
_result = SVL_UpdateEntry(call, Volid, voltype, &UpdateEntry, ReleaseType);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_SetLock(
struct rx_call *call)
{
int32_t _result;
int32_t Volid;
int32_t voltype;
int32_t voloper;
memset(&Volid, 0, sizeof(Volid));
memset(&voltype, 0, sizeof(voltype));
memset(&voloper, 0, sizeof(voloper));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Volid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
voltype = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
voloper = ntohl (u);
}
_result = SVL_SetLock(call, Volid, voltype, voloper);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_ReleaseLock(
struct rx_call *call)
{
int32_t _result;
int32_t volid;
int32_t voltype;
int32_t ReleaseType;
memset(&volid, 0, sizeof(volid));
memset(&voltype, 0, sizeof(voltype));
memset(&ReleaseType, 0, sizeof(ReleaseType));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
volid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
voltype = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
ReleaseType = ntohl (u);
}
_result = SVL_ReleaseLock(call, volid, voltype, ReleaseType);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_ListEntry(
struct rx_call *call)
{
int32_t _result;
int32_t previous_index;
int32_t count;
int32_t next_index;
struct vldbentry entry;
memset(&previous_index, 0, sizeof(previous_index));
memset(&count, 0, sizeof(count));
memset(&next_index, 0, sizeof(next_index));
memset(&entry, 0, sizeof(entry));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
previous_index = ntohl (u);
}
_result = SVL_ListEntry(call, previous_index, &count, &next_index, &entry);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (count);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (next_index);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
u = htonl (entry.name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.volumeType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.nServers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (entry.serverNumber[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (entry.serverPartition[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl (entry.serverFlags[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
u = htonl (entry.volumeId[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.cloneId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_ListAttributes(
struct rx_call *call)
{
int32_t _result;
struct VldbListByAttributes attributes;
int32_t nentries;
bulkentries blkentries;
memset(&attributes, 0, sizeof(attributes));
memset(&nentries, 0, sizeof(nentries));
memset(&blkentries, 0, sizeof(blkentries));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.Mask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.server = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.partition = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.volumetype = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.volumeid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.flag = ntohl (u);
}
_result = SVL_ListAttributes(call, &attributes, &nentries, &blkentries);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (nentries);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct vldbentry );
if (overI < blkentries.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < blkentries.len;++i0){
{
int i1;
for(i1 = 0; i1 < 65;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].name[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (blkentries.val[i0].volumeType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].nServers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].serverNumber[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].serverPartition[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].serverFlags[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].volumeId[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (blkentries.val[i0].cloneId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
free(blkentries.val);
return _result;
fail:
free(blkentries.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_GetStats(
struct rx_call *call)
{
int32_t _result;
struct vldstats stats;
struct vital_vlheader vital_header;
memset(&stats, 0, sizeof(stats));
memset(&vital_header, 0, sizeof(vital_header));

_result = SVL_GetStats(call, &stats, &vital_header);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (stats.start_time);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
{ uint32_t u;
u = htonl (stats.requests[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
{ uint32_t u;
u = htonl (stats.aborts[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ uint32_t u;
u = htonl (stats.reserved[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (vital_header.vldbversion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (vital_header.headersize);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (vital_header.freePtr);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (vital_header.eofPtr);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (vital_header.allocs);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (vital_header.frees);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (vital_header.MaxVolumeId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
u = htonl (vital_header.totalEntries[i0]);
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

static int ydr_ps_VL_Probe(
struct rx_call *call)
{
int32_t _result;

_result = SVL_Probe(call);
if (_result) goto funcfail;
return _result;
funcfail:
return _result;
}

static int ydr_ps_VL_GetAddrs(
struct rx_call *call)
{
int32_t _result;
int32_t handle;
int32_t spare;
struct VL_Callback spare3;
int32_t nentries;
bulkaddrs blkaddr;
memset(&handle, 0, sizeof(handle));
memset(&spare, 0, sizeof(spare));
memset(&spare3, 0, sizeof(spare3));
memset(&nentries, 0, sizeof(nentries));
memset(&blkaddr, 0, sizeof(blkaddr));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
handle = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
spare = ntohl (u);
}
_result = SVL_GetAddrs(call, handle, spare, &spare3, &nentries, &blkaddr);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (spare3.version);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (spare3.expiration_time);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (spare3.time);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (spare3.handle);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (nentries);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkaddr.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < blkaddr.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < blkaddr.len;++i0){
{ uint32_t u;
u = htonl (blkaddr.val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
free(blkaddr.val);
return _result;
fail:
free(blkaddr.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_ChangeAddrs(
struct rx_call *call)
{
int32_t _result;
int32_t old_ip;
int32_t new_ip;
memset(&old_ip, 0, sizeof(old_ip));
memset(&new_ip, 0, sizeof(new_ip));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
old_ip = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
new_ip = ntohl (u);
}
_result = SVL_ChangeAddrs(call, old_ip, new_ip);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_CreateEntryN(
struct rx_call *call)
{
int32_t _result;
struct nvldbentry newentry;
memset(&newentry, 0, sizeof(newentry));

{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.nServers = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.serverNumber[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.serverPartition[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.serverFlags[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.volumeId[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.cloneId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.matchindex = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares6 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares7 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares8 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares9 = ntohl (u);
}
_result = SVL_CreateEntryN(call, &newentry);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_GetEntryByIDN(
struct rx_call *call)
{
int32_t _result;
int32_t Volid;
int32_t voltype;
struct nvldbentry entry;
memset(&Volid, 0, sizeof(Volid));
memset(&voltype, 0, sizeof(voltype));
memset(&entry, 0, sizeof(entry));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Volid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
voltype = ntohl (u);
}
_result = SVL_GetEntryByIDN(call, Volid, voltype, &entry);
if (_result) goto funcfail;
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
u = htonl (entry.name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.nServers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl (entry.serverNumber[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl (entry.serverPartition[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl (entry.serverFlags[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
u = htonl (entry.volumeId[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.cloneId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.matchindex);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares7);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares8);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares9);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_GetEntryByNameN(
struct rx_call *call)
{
int32_t _result;
char volumename[65];
struct nvldbentry entry;
memset(&volumename, 0, sizeof(volumename));
memset(&entry, 0, sizeof(entry));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 65) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (volumename), len) != len)
goto fail;
(volumename)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
_result = SVL_GetEntryByNameN(call, volumename, &entry);
if (_result) goto funcfail;
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
u = htonl (entry.name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.nServers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl (entry.serverNumber[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl (entry.serverPartition[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl (entry.serverFlags[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
u = htonl (entry.volumeId[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.cloneId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.matchindex);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares7);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares8);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares9);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_ReplaceEntryN(
struct rx_call *call)
{
int32_t _result;
int32_t Volid;
int32_t voltype;
struct nvldbentry newentry;
int32_t ReleaseType;
memset(&Volid, 0, sizeof(Volid));
memset(&voltype, 0, sizeof(voltype));
memset(&newentry, 0, sizeof(newentry));
memset(&ReleaseType, 0, sizeof(ReleaseType));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Volid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
voltype = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.nServers = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.serverNumber[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.serverPartition[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.serverFlags[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.volumeId[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.cloneId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.matchindex = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares6 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares7 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares8 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newentry.spares9 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
ReleaseType = ntohl (u);
}
_result = SVL_ReplaceEntryN(call, Volid, voltype, &newentry, ReleaseType);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_ListEntryN(
struct rx_call *call)
{
int32_t _result;
int32_t previous_index;
int32_t count;
int32_t next_index;
struct nvldbentry entry;
memset(&previous_index, 0, sizeof(previous_index));
memset(&count, 0, sizeof(count));
memset(&next_index, 0, sizeof(next_index));
memset(&entry, 0, sizeof(entry));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
previous_index = ntohl (u);
}
_result = SVL_ListEntryN(call, previous_index, &count, &next_index, &entry);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (count);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (next_index);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
u = htonl (entry.name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.nServers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl (entry.serverNumber[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl (entry.serverPartition[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl (entry.serverFlags[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
u = htonl (entry.volumeId[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.cloneId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.matchindex);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares7);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares8);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.spares9);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_ListAttributesN(
struct rx_call *call)
{
int32_t _result;
struct VldbListByAttributes attributes;
int32_t nentries;
nbulkentries blkentries;
memset(&attributes, 0, sizeof(attributes));
memset(&nentries, 0, sizeof(nentries));
memset(&blkentries, 0, sizeof(blkentries));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.Mask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.server = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.partition = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.volumetype = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.volumeid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.flag = ntohl (u);
}
_result = SVL_ListAttributesN(call, &attributes, &nentries, &blkentries);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (nentries);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct nvldbentry );
if (overI < blkentries.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < blkentries.len;++i0){
{
int i1;
for(i1 = 0; i1 < 65;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].name[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (blkentries.val[i0].nServers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].serverNumber[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].serverPartition[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].serverFlags[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].volumeId[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (blkentries.val[i0].cloneId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].matchindex);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares7);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares8);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares9);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
free(blkentries.val);
return _result;
fail:
free(blkentries.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_UpdateEntryByName(
struct rx_call *call)
{
int32_t _result;
char volname[65];
struct VldbUpdateEntry UpdateEntry;
int32_t ReleaseType;
memset(&volname, 0, sizeof(volname));
memset(&UpdateEntry, 0, sizeof(UpdateEntry));
memset(&ReleaseType, 0, sizeof(ReleaseType));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 65) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (volname), len) != len)
goto fail;
(volname)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.Mask = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.volumeType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.ReadOnlyId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.BackupId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.cloneid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.nModifiedRepsites = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.RepsitesMask[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.RepsitesTargetServer[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.RepsitesTargetPart[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.RepsitesNewServer[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.RepsitesNewPart[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
UpdateEntry.RepsitesNewFlags[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
ReleaseType = ntohl (u);
}
_result = SVL_UpdateEntryByName(call, volname, &UpdateEntry, ReleaseType);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_GetAddrsU(
struct rx_call *call)
{
int32_t _result;
struct ListAddrByAttributes inaddr;
struct afsUUID uuidp1;
int32_t uniquifier;
int32_t nentries;
bulkaddrs blkaddrs;
memset(&inaddr, 0, sizeof(inaddr));
memset(&uuidp1, 0, sizeof(uuidp1));
memset(&uniquifier, 0, sizeof(uniquifier));
memset(&nentries, 0, sizeof(nentries));
memset(&blkaddrs, 0, sizeof(blkaddrs));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
inaddr.Mask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
inaddr.ipaddr = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
inaddr.index = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
inaddr.spare = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
inaddr.uuid.time_low = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
inaddr.uuid.time_mid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
inaddr.uuid.time_hi_and_version = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
inaddr.uuid.clock_seq_hi_and_reserved = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
inaddr.uuid.clock_seq_low = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
inaddr.uuid.node[i0] = ntohl (u);
}
}
}
_result = SVL_GetAddrsU(call, &inaddr, &uuidp1, &uniquifier, &nentries, &blkaddrs);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (uuidp1.time_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (uuidp1.time_mid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (uuidp1.time_hi_and_version);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (uuidp1.clock_seq_hi_and_reserved);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (uuidp1.clock_seq_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
u = htonl (uuidp1.node[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (uniquifier);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (nentries);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkaddrs.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < blkaddrs.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < blkaddrs.len;++i0){
{ uint32_t u;
u = htonl (blkaddrs.val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
free(blkaddrs.val);
return _result;
fail:
free(blkaddrs.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_RegisterAddrs(
struct rx_call *call)
{
int32_t _result;
struct afsUUID uid;
int32_t spare;
bulkaddrs addrs;
memset(&uid, 0, sizeof(uid));
memset(&spare, 0, sizeof(spare));
memset(&addrs, 0, sizeof(addrs));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uid.time_low = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uid.time_mid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uid.time_hi_and_version = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uid.clock_seq_hi_and_reserved = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uid.clock_seq_low = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uid.node[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
spare = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
addrs.len = ntohl (u);
}
if (addrs.len > 1024) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < addrs.len) goto fail;
}
addrs.val = (int32_t *)malloc(sizeof(int32_t ) * addrs.len);
if (addrs.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < addrs.len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
addrs.val[i0] = ntohl (u);
}
}
}
_result = SVL_RegisterAddrs(call, &uid, spare, &addrs);
if (_result) goto funcfail;
free(addrs.val);
return _result;
fail:
free(addrs.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_VL_ListAttributesN2(
struct rx_call *call)
{
int32_t _result;
struct VldbListByAttributes attributes;
char volumename[65];
int32_t startindex;
int32_t nentries;
nbulkentries blkentries;
int32_t nextstartindex;
memset(&attributes, 0, sizeof(attributes));
memset(&volumename, 0, sizeof(volumename));
memset(&startindex, 0, sizeof(startindex));
memset(&nentries, 0, sizeof(nentries));
memset(&blkentries, 0, sizeof(blkentries));
memset(&nextstartindex, 0, sizeof(nextstartindex));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.Mask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.server = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.partition = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.volumetype = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.volumeid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
attributes.flag = ntohl (u);
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 65) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (volumename), len) != len)
goto fail;
(volumename)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
startindex = ntohl (u);
}
_result = SVL_ListAttributesN2(call, &attributes, volumename, startindex, &nentries, &blkentries, &nextstartindex);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (nentries);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct nvldbentry );
if (overI < blkentries.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < blkentries.len;++i0){
{
int i1;
for(i1 = 0; i1 < 65;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].name[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (blkentries.val[i0].nServers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].serverNumber[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].serverPartition[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].serverFlags[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
{ uint32_t u;
u = htonl (blkentries.val[i0].volumeId[i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (blkentries.val[i0].cloneId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].matchindex);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares7);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares8);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (blkentries.val[i0].spares9);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (nextstartindex);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
free(blkentries.val);
return _result;
fail:
free(blkentries.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

int32_t VL_ExecuteRequest(struct rx_call *call)
{
unsigned opcode;
int32_t _result;
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
opcode = ntohl (u);
}
switch(opcode) {
case 501: {
_result = ydr_ps_VL_CreateEntry(call);
break;
}
case 502: {
_result = ydr_ps_VL_DeleteEntry(call);
break;
}
case 503: {
_result = ydr_ps_VL_GetEntryByID(call);
break;
}
case 504: {
_result = ydr_ps_VL_GetEntryByName(call);
break;
}
case 505: {
_result = ydr_ps_VL_GetNewVolumeId(call);
break;
}
case 506: {
_result = ydr_ps_VL_ReplaceEntry(call);
break;
}
case 507: {
_result = ydr_ps_VL_UpdateEntry(call);
break;
}
case 508: {
_result = ydr_ps_VL_SetLock(call);
break;
}
case 509: {
_result = ydr_ps_VL_ReleaseLock(call);
break;
}
case 510: {
_result = ydr_ps_VL_ListEntry(call);
break;
}
case 511: {
_result = ydr_ps_VL_ListAttributes(call);
break;
}
case 513: {
_result = ydr_ps_VL_GetStats(call);
break;
}
case 514: {
_result = ydr_ps_VL_Probe(call);
break;
}
case 515: {
_result = ydr_ps_VL_GetAddrs(call);
break;
}
case 516: {
_result = ydr_ps_VL_ChangeAddrs(call);
break;
}
case 517: {
_result = ydr_ps_VL_CreateEntryN(call);
break;
}
case 518: {
_result = ydr_ps_VL_GetEntryByIDN(call);
break;
}
case 519: {
_result = ydr_ps_VL_GetEntryByNameN(call);
break;
}
case 520: {
_result = ydr_ps_VL_ReplaceEntryN(call);
break;
}
case 521: {
_result = ydr_ps_VL_ListEntryN(call);
break;
}
case 522: {
_result = ydr_ps_VL_ListAttributesN(call);
break;
}
case 524: {
_result = ydr_ps_VL_UpdateEntryByName(call);
break;
}
case 533: {
_result = ydr_ps_VL_GetAddrsU(call);
break;
}
case 532: {
_result = ydr_ps_VL_RegisterAddrs(call);
break;
}
case 534: {
_result = ydr_ps_VL_ListAttributesN2(call);
break;
}
default:
_result = RXGEN_OPCODE;
}
return _result;
fail:
return rx_GetCallError(call);
}

