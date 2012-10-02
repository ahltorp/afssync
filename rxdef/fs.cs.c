/* Generated from fs.xg */
#include "fs.h"

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
RCSID("fs.cs.c generated from fs.xg with $Id: fs.cs.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
#include "fs.cs.h"

int StartRXAFS_FetchData(
struct rx_call *call
, const struct AFSFid *a_fidToFetchP
, const int32_t a_offset
, const int32_t a_lenInBytes
)
{
{ uint32_t u;
u = htonl (130);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidToFetchP).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidToFetchP).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidToFetchP).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_offset);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_lenInBytes);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return 0;
fail:
return conv_to_arla_errno(rx_GetCallError(call));
}

int EndRXAFS_FetchData(
struct rx_call *call
, struct AFSFetchStatus *a_fidStatP
, struct AFSCallBack *a_callBackP
, struct AFSVolSync *a_volSyncP
)
{
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_callBackP).CallBackVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_callBackP).ExpirationTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_callBackP).CallBackType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare6 = ntohl (u);
}
return 0;
fail:
return conv_to_arla_errno(rx_GetCallError(call));
}

int RXAFS_FetchACL(
struct rx_connection *connection
, const struct AFSFid *a_dirFidP
, AFSOpaque *a_ACLP
, struct AFSFetchStatus *a_dirNewStatP
, struct AFSVolSync *a_volSyncP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (131);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_ACLP).len = ntohl (u);
}
if ((*a_ACLP).len > 1024) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*a_ACLP).len) goto fail;
}
(*a_ACLP).val = (char *)malloc(sizeof(char ) * (*a_ACLP).len);
if ((*a_ACLP).val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*a_ACLP).len % 4)) % 4;
if(rx_Read (call, (*a_ACLP).val, (*a_ACLP).len) != (*a_ACLP).len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_FetchStatus(
struct rx_connection *connection
, const struct AFSFid *a_fidToStatP
, struct AFSFetchStatus *a_currStatP
, struct AFSCallBack *a_callBackP
, struct AFSVolSync *a_volSyncP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (132);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidToStatP).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidToStatP).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidToStatP).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_currStatP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_callBackP).CallBackVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_callBackP).ExpirationTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_callBackP).CallBackType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int StartRXAFS_StoreData(
struct rx_call *call
, const struct AFSFid *a_fidToStoreP
, const struct AFSStoreStatus *a_fidStatusP
, const int32_t a_offset
, const int32_t a_lenInBytes
, const int32_t a_fileLenInBytes
)
{
{ uint32_t u;
u = htonl (133);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidToStoreP).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidToStoreP).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidToStoreP).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidStatusP).Mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidStatusP).ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidStatusP).Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidStatusP).Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidStatusP).UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidStatusP).SegSize);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_offset);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_lenInBytes);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fileLenInBytes);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return 0;
fail:
return conv_to_arla_errno(rx_GetCallError(call));
}

int EndRXAFS_StoreData(
struct rx_call *call
, struct AFSFetchStatus *a_fidStatP
, struct AFSVolSync *a_volSyncP
)
{
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_fidStatP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare6 = ntohl (u);
}
return 0;
fail:
return conv_to_arla_errno(rx_GetCallError(call));
}

int RXAFS_StoreACL(
struct rx_connection *connection
, const struct AFSFid *a_dirFidP
, const AFSOpaque *a_ACLToStoreP
, struct AFSFetchStatus *a_dirNewStatP
, struct AFSVolSync *a_volSyncP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (134);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_ACLToStoreP).len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*a_ACLToStoreP).len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - ((*a_ACLToStoreP).len % 4)) % 4;
if(rx_Write (call, (*a_ACLToStoreP).val, (*a_ACLToStoreP).len) != (*a_ACLToStoreP).len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirNewStatP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_StoreStatus(
struct rx_connection *connection
, const struct AFSFid *a_fidP
, const struct AFSStoreStatus *a_currStatusP
, struct AFSFetchStatus *a_srStatusP
, struct AFSVolSync *a_volSyncP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (135);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidP).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidP).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_fidP).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_currStatusP).Mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_currStatusP).ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_currStatusP).Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_currStatusP).Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_currStatusP).UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_currStatusP).SegSize);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srStatusP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_RemoveFile(
struct rx_connection *connection
, const struct AFSFid *a_dirFidP
, const char *a_name
, struct AFSFetchStatus *a_srvStatusP
, struct AFSVolSync *a_volSyncP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (136);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(a_name);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, a_name, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_srvStatusP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_CreateFile(
struct rx_connection *connection
, const struct AFSFid *DirFid
, const char *Name
, const struct AFSStoreStatus *InStatus
, struct AFSFid *OutFid
, struct AFSFetchStatus *OutFidStatus
, struct AFSFetchStatus *OutDirStatus
, struct AFSCallBack *CallBack
, struct AFSVolSync *a_volSyncP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (137);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*DirFid).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*DirFid).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*DirFid).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(Name);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, Name, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*InStatus).Mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*InStatus).ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*InStatus).Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*InStatus).Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*InStatus).UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*InStatus).SegSize);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFid).Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFid).Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFid).Unique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutFidStatus).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutDirStatus).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*CallBack).CallBackVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*CallBack).ExpirationTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*CallBack).CallBackType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_Rename(
struct rx_connection *connection
, const struct AFSFid *a_origDirFidP
, const char *a_origNameP
, const struct AFSFid *a_newDirFidP
, const char *a_newNameP
, struct AFSFetchStatus *a_origDirStatusP
, struct AFSFetchStatus *a_newDirStatusP
, struct AFSVolSync *a_volSyncP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (138);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_origDirFidP).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_origDirFidP).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_origDirFidP).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(a_origNameP);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, a_origNameP, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*a_newDirFidP).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_newDirFidP).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_newDirFidP).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(a_newNameP);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, a_newNameP, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_origDirStatusP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatusP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_Symlink(
struct rx_connection *connection
, const struct AFSFid *a_dirFidP
, const char *a_nameP
, const char *a_linkContentsP
, const struct AFSStoreStatus *a_origDirStatP
, struct AFSFid *a_newFidP
, struct AFSFetchStatus *a_newFidStatP
, struct AFSFetchStatus *a_newDirStatP
, struct AFSVolSync *a_volSyncP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (139);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(a_nameP);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, a_nameP, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(a_linkContentsP);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, a_linkContentsP, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*a_origDirStatP).Mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_origDirStatP).ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_origDirStatP).Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_origDirStatP).Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_origDirStatP).UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_origDirStatP).SegSize);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidP).Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidP).Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidP).Unique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_Link(
struct rx_connection *connection
, const struct AFSFid *a_dirFidP
, const char *a_nameP
, const struct AFSFid *a_existingFidP
, struct AFSFetchStatus *a_newFidStatP
, struct AFSFetchStatus *a_newDirStatP
, struct AFSVolSync *a_volSyncP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (140);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_dirFidP).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(a_nameP);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, a_nameP, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*a_existingFidP).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_existingFidP).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_existingFidP).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newFidStatP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirStatP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_MakeDir(
struct rx_connection *connection
, const struct AFSFid *a_parentDirFidP
, const char *a_newDirNameP
, const struct AFSStoreStatus *a_currStatP
, struct AFSFid *a_newDirFidP
, struct AFSFetchStatus *a_dirFidStatP
, struct AFSFetchStatus *a_parentDirStatP
, struct AFSCallBack *a_newDirCallBackP
, struct AFSVolSync *a_volSyncP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (141);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_parentDirFidP).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_parentDirFidP).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_parentDirFidP).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(a_newDirNameP);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, a_newDirNameP, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl ((*a_currStatP).Mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_currStatP).ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_currStatP).Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_currStatP).Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_currStatP).UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_currStatP).SegSize);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirFidP).Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirFidP).Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirFidP).Unique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_dirFidStatP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_parentDirStatP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirCallBackP).CallBackVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirCallBackP).ExpirationTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newDirCallBackP).CallBackType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_RemoveDir(
struct rx_connection *connection
, const struct AFSFid *a_parentDirStatP
, const char *a_dirNameP
, struct AFSFetchStatus *a_newParentDirStatP
, struct AFSVolSync *a_volSyncP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (142);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_parentDirStatP).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_parentDirStatP).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_parentDirStatP).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(a_dirNameP);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, a_dirNameP, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_newParentDirStatP).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volSyncP).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_GiveUpCallBacks(
struct rx_connection *connection
, const AFSCBFids *a_fidArrayP
, const AFSCBs *a_callBackArrayP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (147);
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
int RXAFS_GetVolumeStatus(
struct rx_connection *connection
, const int32_t a_volIDP
, struct AFSFetchVolumeStatus *a_volFetchStatP
, char *a_volNameP
, char *a_offLineMsgP
, char *a_motdP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (149);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volIDP);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volFetchStatP).Vid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volFetchStatP).ParentId = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volFetchStatP).Online = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volFetchStatP).InService = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volFetchStatP).Blessed = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volFetchStatP).NeedsSalvage = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volFetchStatP).Type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volFetchStatP).MinQuota = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volFetchStatP).MaxQuota = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volFetchStatP).BlocksInUse = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volFetchStatP).PartBlocksAvail = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_volFetchStatP).PartMaxBlocks = ntohl (u);
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
if(rx_Read(call, (a_volNameP), len) != len)
goto fail;
(a_volNameP)[len] = '\0';
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
if (len >= 1024) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (a_offLineMsgP), len) != len)
goto fail;
(a_offLineMsgP)[len] = '\0';
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
if (len >= 1024) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (a_motdP), len) != len)
goto fail;
(a_motdP)[len] = '\0';
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
int RXAFS_SetVolumeStatus(
struct rx_connection *connection
, const int32_t a_volIDP
, const struct AFSStoreVolumeStatus *a_volStoreStatP
, const char *a_volNameP
, const char *a_offLineMsgP
, const char *a_motdP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (150);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volIDP);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_volStoreStatP).Mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_volStoreStatP).MinQuota);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*a_volStoreStatP).MaxQuota);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(a_volNameP);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, a_volNameP, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(a_offLineMsgP);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, a_offLineMsgP, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(a_motdP);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, a_motdP, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_GetRootVolume(
struct rx_connection *connection
, char *a_rootVolNameP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (151);
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
if(rx_Read(call, (a_rootVolNameP), len) != len)
goto fail;
(a_rootVolNameP)[len] = '\0';
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
int RXAFS_GetTime(
struct rx_connection *connection
, uint32_t *a_secondsP
, uint32_t *a_uSecondsP
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (153);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_secondsP) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*a_uSecondsP) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_NGetVolumeInfo(
struct rx_connection *connection
, const char *VolumeName
, struct AFSVolumeInfo *stuff
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (154);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(VolumeName);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, VolumeName, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Vid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Type = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Type0 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Type1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Type2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Type3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Type4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).ServerCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Server0 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Server1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Server2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Server3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Server4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Server5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Server6 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Server7 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Port0 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Port1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Port2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Port3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Port4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Port5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Port6 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*stuff).Port7 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_BulkStatus(
struct rx_connection *connection
, const AFSCBFids *FidsArray
, AFSBulkStats *StatArray
, AFSCBs *CBArray
, struct AFSVolSync *Sync
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (155);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*FidsArray).len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSFid );
if (overI < (*FidsArray).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*FidsArray).len;++i0){
{ uint32_t u;
u = htonl ((*FidsArray).val[i0].Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*FidsArray).val[i0].Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*FidsArray).val[i0].Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).len = ntohl (u);
}
if ((*StatArray).len > 50) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSFetchStatus );
if (overI < (*StatArray).len) goto fail;
}
(*StatArray).val = (struct AFSFetchStatus *)malloc(sizeof(struct AFSFetchStatus ) * (*StatArray).len);
if ((*StatArray).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*StatArray).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*StatArray).val[i0].ErrorCode = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*CBArray).len = ntohl (u);
}
if ((*CBArray).len > 50) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSCallBack );
if (overI < (*CBArray).len) goto fail;
}
(*CBArray).val = (struct AFSCallBack *)malloc(sizeof(struct AFSCallBack ) * (*CBArray).len);
if ((*CBArray).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*CBArray).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*CBArray).val[i0].CallBackVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*CBArray).val[i0].ExpirationTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*CBArray).val[i0].CallBackType = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_SetLock(
struct rx_connection *connection
, const struct AFSFid *Fid
, const ViceLockType Type
, struct AFSVolSync *Sync
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (156);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_ExtendLock(
struct rx_connection *connection
, const struct AFSFid *Fid
, struct AFSVolSync *Sync
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (157);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_ReleaseLock(
struct rx_connection *connection
, const struct AFSFid *Fid
, struct AFSVolSync *Sync
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (158);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare6 = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_FlushCPS(
struct rx_connection *connection
, const ViceIds *IdsArray
, const IPAddrs *AddrsArray
, const int32_t spare1
, int32_t *spare2
, int32_t *spare3
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (162);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*IdsArray).len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*IdsArray).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*IdsArray).len;++i0){
{ uint32_t u;
u = htonl ((*IdsArray).val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl ((*AddrsArray).len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*AddrsArray).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*AddrsArray).len;++i0){
{ uint32_t u;
u = htonl ((*AddrsArray).val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*spare2) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*spare3) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int StartRXAFS_FetchData64(
struct rx_call *call
, const struct AFSFid *Fid
, const int64_t Pos
, const int64_t Length
)
{
{ uint32_t u;
u = htonl (65537);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint64_t u;
u = htobe64 (Pos);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint64_t u;
u = htobe64 (Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return 0;
fail:
return conv_to_arla_errno(rx_GetCallError(call));
}

int EndRXAFS_FetchData64(
struct rx_call *call
, struct AFSFetchStatus *OutStatus
, struct AFSCallBack *CallBack
, struct AFSVolSync *Sync
)
{
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*CallBack).CallBackVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*CallBack).ExpirationTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*CallBack).CallBackType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare6 = ntohl (u);
}
return 0;
fail:
return conv_to_arla_errno(rx_GetCallError(call));
}

int StartRXAFS_StoreData64(
struct rx_call *call
, const struct AFSFid *Fid
, const struct AFSStoreStatus *InStatus
, const uint64_t Pos
, const uint64_t Length
, const uint64_t FileLength
)
{
{ uint32_t u;
u = htonl (65538);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*Fid).Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*InStatus).Mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*InStatus).ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*InStatus).Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*InStatus).Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*InStatus).UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*InStatus).SegSize);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint64_t u;
u = htobe64 (Pos);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint64_t u;
u = htobe64 (Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint64_t u;
u = htobe64 (FileLength);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return 0;
fail:
return conv_to_arla_errno(rx_GetCallError(call));
}

int EndRXAFS_StoreData64(
struct rx_call *call
, struct AFSFetchStatus *OutStatus
, struct AFSVolSync *Sync
)
{
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).InterfaceVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).FileType = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).LinkCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).Length = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).DataVersion = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).Author = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).CallerAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).AnonymousAccess = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).ParentVnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).ParentUnique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).ResidencyMask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).ServerModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).SyncCounter = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).DataVersionHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).LockCount = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).LengthHigh = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*OutStatus).ErrorCode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare2 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare3 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare4 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare5 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*Sync).spare6 = ntohl (u);
}
return 0;
fail:
return conv_to_arla_errno(rx_GetCallError(call));
}

int RXAFS_GiveUpAllCallBacks(
struct rx_connection *connection
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (65539);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int RXAFS_GetCapabilities(
struct rx_connection *connection
, Capabilities *capabilities
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (65540);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
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
