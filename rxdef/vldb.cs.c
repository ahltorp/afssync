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
RCSID("vldb.cs.c generated from vldb.xg with $Id: vldb.cs.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
#include "vldb.cs.h"

int VL_CreateEntry(
struct rx_connection *connection
, const struct vldbentry *newentry
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (501);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
u = htonl ((*newentry).name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*newentry).volumeType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).nServers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*newentry).serverNumber[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*newentry).serverPartition[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*newentry).serverFlags[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
u = htonl ((*newentry).volumeId[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*newentry).cloneId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_DeleteEntry(
struct rx_connection *connection
, const int32_t Volid
, const int32_t voltype
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (502);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (voltype);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_GetEntryByID(
struct rx_connection *connection
, const int32_t Volid
, const int32_t voltype
, struct vldbentry *entry
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (503);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (voltype);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).volumeType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).nServers = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverNumber[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverPartition[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverFlags[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).volumeId[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).cloneId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).flags = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_GetEntryByName(
struct rx_connection *connection
, const char *volumename
, struct vldbentry *entry
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (504);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(volumename);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, volumename, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).volumeType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).nServers = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverNumber[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverPartition[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverFlags[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).volumeId[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).cloneId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).flags = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_GetNewVolumeId(
struct rx_connection *connection
, const int32_t bumpcount
, int32_t *newvolumid
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (505);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (bumpcount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*newvolumid) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_ReplaceEntry(
struct rx_connection *connection
, const int32_t Volid
, const int32_t voltype
, const struct vldbentry *newentry
, const int32_t ReleaseType
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (506);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (voltype);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
u = htonl ((*newentry).name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*newentry).volumeType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).nServers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*newentry).serverNumber[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*newentry).serverPartition[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*newentry).serverFlags[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
u = htonl ((*newentry).volumeId[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*newentry).cloneId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (ReleaseType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_UpdateEntry(
struct rx_connection *connection
, const int32_t Volid
, const int32_t voltype
, const struct VldbUpdateEntry *UpdateEntry
, const int32_t ReleaseType
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (507);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (voltype);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*UpdateEntry).Mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
u = htonl ((*UpdateEntry).name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*UpdateEntry).volumeType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*UpdateEntry).flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*UpdateEntry).ReadOnlyId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*UpdateEntry).BackupId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*UpdateEntry).cloneid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*UpdateEntry).nModifiedRepsites);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*UpdateEntry).RepsitesMask[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*UpdateEntry).RepsitesTargetServer[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*UpdateEntry).RepsitesTargetPart[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*UpdateEntry).RepsitesNewServer[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*UpdateEntry).RepsitesNewPart[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*UpdateEntry).RepsitesNewFlags[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (ReleaseType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_SetLock(
struct rx_connection *connection
, const int32_t Volid
, const int32_t voltype
, const int32_t voloper
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (508);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (voltype);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (voloper);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_ReleaseLock(
struct rx_connection *connection
, const int32_t volid
, const int32_t voltype
, const int32_t ReleaseType
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (509);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (voltype);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (ReleaseType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_ListEntry(
struct rx_connection *connection
, const int32_t previous_index
, int32_t *count
, int32_t *next_index
, struct vldbentry *entry
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (510);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (previous_index);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*count) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*next_index) = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).volumeType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).nServers = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverNumber[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverPartition[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverFlags[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).volumeId[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).cloneId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).flags = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_ListAttributes(
struct rx_connection *connection
, const struct VldbListByAttributes *attributes
, int32_t *nentries
, bulkentries *blkentries
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (511);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).Mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).server);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).partition);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).volumetype);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).volumeid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).flag);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*nentries) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct vldbentry );
if (overI < (*blkentries).len) goto fail;
}
(*blkentries).val = (struct vldbentry *)malloc(sizeof(struct vldbentry ) * (*blkentries).len);
if ((*blkentries).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*blkentries).len;++i0){
{
int i1;
for(i1 = 0; i1 < 65;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].name[i1] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].volumeType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].nServers = ntohl (u);
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].serverNumber[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].serverPartition[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].serverFlags[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].volumeId[i1] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].cloneId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].flags = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_GetStats(
struct rx_connection *connection
, struct vldstats *stats
, struct vital_vlheader *vital_header
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (513);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stats).start_time = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stats).requests[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stats).aborts[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stats).reserved[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*vital_header).vldbversion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*vital_header).headersize = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*vital_header).freePtr = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*vital_header).eofPtr = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*vital_header).allocs = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*vital_header).frees = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*vital_header).MaxVolumeId = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*vital_header).totalEntries[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_Probe(
struct rx_connection *connection
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (514);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_GetAddrs(
struct rx_connection *connection
, const int32_t handle
, const int32_t spare
, struct VL_Callback *spare3
, int32_t *nentries
, bulkaddrs *blkaddr
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (515);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (handle);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (spare);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*spare3).version = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*spare3).expiration_time = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*spare3).time = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*spare3).handle = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*nentries) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkaddr).len = ntohl (u);
}
if ((*blkaddr).len > 1024) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*blkaddr).len) goto fail;
}
(*blkaddr).val = (int32_t *)malloc(sizeof(int32_t ) * (*blkaddr).len);
if ((*blkaddr).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*blkaddr).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkaddr).val[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_ChangeAddrs(
struct rx_connection *connection
, const int32_t old_ip
, const int32_t new_ip
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (516);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (old_ip);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (new_ip);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_CreateEntryN(
struct rx_connection *connection
, const struct nvldbentry *newentry
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (517);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
u = htonl ((*newentry).name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*newentry).nServers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl ((*newentry).serverNumber[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl ((*newentry).serverPartition[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl ((*newentry).serverFlags[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
u = htonl ((*newentry).volumeId[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*newentry).cloneId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).matchindex);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares7);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares8);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares9);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_GetEntryByIDN(
struct rx_connection *connection
, const int32_t Volid
, const int32_t voltype
, struct nvldbentry *entry
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (518);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (voltype);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).nServers = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverNumber[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverPartition[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverFlags[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).volumeId[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).cloneId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).matchindex = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares6 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares7 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares8 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares9 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_GetEntryByNameN(
struct rx_connection *connection
, const char *volumename
, struct nvldbentry *entry
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (519);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(volumename);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, volumename, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).nServers = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverNumber[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverPartition[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverFlags[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).volumeId[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).cloneId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).matchindex = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares6 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares7 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares8 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares9 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_ReplaceEntryN(
struct rx_connection *connection
, const int32_t Volid
, const int32_t voltype
, const struct nvldbentry *newentry
, const int32_t ReleaseType
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (520);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Volid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (voltype);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
u = htonl ((*newentry).name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*newentry).nServers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl ((*newentry).serverNumber[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl ((*newentry).serverPartition[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
u = htonl ((*newentry).serverFlags[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
u = htonl ((*newentry).volumeId[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*newentry).cloneId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).matchindex);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares7);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares8);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*newentry).spares9);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (ReleaseType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_ListEntryN(
struct rx_connection *connection
, const int32_t previous_index
, int32_t *count
, int32_t *next_index
, struct nvldbentry *entry
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (521);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (previous_index);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*count) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*next_index) = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).name[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).nServers = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverNumber[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverPartition[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).serverFlags[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).volumeId[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).cloneId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).matchindex = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares6 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares7 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares8 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).spares9 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_ListAttributesN(
struct rx_connection *connection
, const struct VldbListByAttributes *attributes
, int32_t *nentries
, nbulkentries *blkentries
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (522);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).Mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).server);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).partition);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).volumetype);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).volumeid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).flag);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*nentries) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct nvldbentry );
if (overI < (*blkentries).len) goto fail;
}
(*blkentries).val = (struct nvldbentry *)malloc(sizeof(struct nvldbentry ) * (*blkentries).len);
if ((*blkentries).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*blkentries).len;++i0){
{
int i1;
for(i1 = 0; i1 < 65;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].name[i1] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].nServers = ntohl (u);
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].serverNumber[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].serverPartition[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].serverFlags[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].volumeId[i1] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].cloneId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].matchindex = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares6 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares7 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares8 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares9 = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_UpdateEntryByName(
struct rx_connection *connection
, const char *volname
, const struct VldbUpdateEntry *UpdateEntry
, const int32_t ReleaseType
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (524);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(volname);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, volname, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*UpdateEntry).Mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ uint32_t u;
u = htonl ((*UpdateEntry).name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*UpdateEntry).volumeType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*UpdateEntry).flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*UpdateEntry).ReadOnlyId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*UpdateEntry).BackupId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*UpdateEntry).cloneid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*UpdateEntry).nModifiedRepsites);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*UpdateEntry).RepsitesMask[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*UpdateEntry).RepsitesTargetServer[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*UpdateEntry).RepsitesTargetPart[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*UpdateEntry).RepsitesNewServer[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*UpdateEntry).RepsitesNewPart[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ uint32_t u;
u = htonl ((*UpdateEntry).RepsitesNewFlags[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (ReleaseType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_GetAddrsU(
struct rx_connection *connection
, const struct ListAddrByAttributes *inaddr
, struct afsUUID *uuidp1
, int32_t *uniquifier
, int32_t *nentries
, bulkaddrs *blkaddrs
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (533);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*inaddr).Mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*inaddr).ipaddr);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*inaddr).index);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*inaddr).spare);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*inaddr).uuid.time_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*inaddr).uuid.time_mid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*inaddr).uuid.time_hi_and_version);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*inaddr).uuid.clock_seq_hi_and_reserved);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*inaddr).uuid.clock_seq_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
u = htonl ((*inaddr).uuid.node[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*uuidp1).time_low = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*uuidp1).time_mid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*uuidp1).time_hi_and_version = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*uuidp1).clock_seq_hi_and_reserved = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*uuidp1).clock_seq_low = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*uuidp1).node[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*uniquifier) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*nentries) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkaddrs).len = ntohl (u);
}
if ((*blkaddrs).len > 1024) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*blkaddrs).len) goto fail;
}
(*blkaddrs).val = (int32_t *)malloc(sizeof(int32_t ) * (*blkaddrs).len);
if ((*blkaddrs).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*blkaddrs).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkaddrs).val[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int VL_RegisterAddrs(
struct rx_connection *connection
, const struct afsUUID *uid
, const int32_t spare
, const bulkaddrs *addrs
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (532);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*uid).time_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*uid).time_mid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*uid).time_hi_and_version);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*uid).clock_seq_hi_and_reserved);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*uid).clock_seq_low);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ uint32_t u;
u = htonl ((*uid).node[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (spare);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*addrs).len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*addrs).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*addrs).len;++i0){
{ uint32_t u;
u = htonl ((*addrs).val[i0]);
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
int VL_ListAttributesN2(
struct rx_connection *connection
, const struct VldbListByAttributes *attributes
, const char *volumename
, const int32_t startindex
, int32_t *nentries
, nbulkentries *blkentries
, int32_t *nextstartindex
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (534);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).Mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).server);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).partition);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).volumetype);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).volumeid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*attributes).flag);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(volumename);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, volumename, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl (startindex);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*nentries) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).len = ntohl (u);
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct nvldbentry );
if (overI < (*blkentries).len) goto fail;
}
(*blkentries).val = (struct nvldbentry *)malloc(sizeof(struct nvldbentry ) * (*blkentries).len);
if ((*blkentries).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*blkentries).len;++i0){
{
int i1;
for(i1 = 0; i1 < 65;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].name[i1] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].nServers = ntohl (u);
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].serverNumber[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].serverPartition[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].serverFlags[i1] = ntohl (u);
}
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].volumeId[i1] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].cloneId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].matchindex = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares6 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares7 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares8 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*blkentries).val[i0].spares9 = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*nextstartindex) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
