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
RCSID("fs.ss.c generated from fs.xg with $Id: fs.ss.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
#include "fs.ss.h"

static int ydr_ps_RXAFS_FetchData(
struct rx_call *call)
{
int32_t _result;
struct AFSFid a_fidToFetchP;
int32_t a_offset;
int32_t a_lenInBytes;
struct AFSFetchStatus a_fidStatP;
struct AFSCallBack a_callBackP;
struct AFSVolSync a_volSyncP;
memset(&a_fidToFetchP, 0, sizeof(a_fidToFetchP));
memset(&a_offset, 0, sizeof(a_offset));
memset(&a_lenInBytes, 0, sizeof(a_lenInBytes));
memset(&a_fidStatP, 0, sizeof(a_fidStatP));
memset(&a_callBackP, 0, sizeof(a_callBackP));
memset(&a_volSyncP, 0, sizeof(a_volSyncP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidToFetchP.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidToFetchP.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidToFetchP.Unique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_offset = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_lenInBytes = ntohl (u);
}
_result = SRXAFS_FetchData(call, &a_fidToFetchP, a_offset, a_lenInBytes, &a_fidStatP, &a_callBackP, &a_volSyncP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (a_fidStatP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_callBackP.CallBackVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_callBackP.ExpirationTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_callBackP.CallBackType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_FetchACL(
struct rx_call *call)
{
int32_t _result;
struct AFSFid a_dirFidP;
AFSOpaque a_ACLP;
struct AFSFetchStatus a_dirNewStatP;
struct AFSVolSync a_volSyncP;
memset(&a_dirFidP, 0, sizeof(a_dirFidP));
memset(&a_ACLP, 0, sizeof(a_ACLP));
memset(&a_dirNewStatP, 0, sizeof(a_dirNewStatP));
memset(&a_volSyncP, 0, sizeof(a_volSyncP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Unique = ntohl (u);
}
_result = SRXAFS_FetchACL(call, &a_dirFidP, &a_ACLP, &a_dirNewStatP, &a_volSyncP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (a_ACLP.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < a_ACLP.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (a_ACLP.len % 4)) % 4;
if(rx_Write (call, a_ACLP.val, a_ACLP.len) != a_ACLP.len)
goto fail;
if(rx_Write (call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
free(a_ACLP.val);
return _result;
fail:
free(a_ACLP.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_FetchStatus(
struct rx_call *call)
{
int32_t _result;
struct AFSFid a_fidToStatP;
struct AFSFetchStatus a_currStatP;
struct AFSCallBack a_callBackP;
struct AFSVolSync a_volSyncP;
memset(&a_fidToStatP, 0, sizeof(a_fidToStatP));
memset(&a_currStatP, 0, sizeof(a_currStatP));
memset(&a_callBackP, 0, sizeof(a_callBackP));
memset(&a_volSyncP, 0, sizeof(a_volSyncP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidToStatP.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidToStatP.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidToStatP.Unique = ntohl (u);
}
_result = SRXAFS_FetchStatus(call, &a_fidToStatP, &a_currStatP, &a_callBackP, &a_volSyncP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (a_currStatP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_currStatP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_callBackP.CallBackVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_callBackP.ExpirationTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_callBackP.CallBackType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_StoreData(
struct rx_call *call)
{
int32_t _result;
struct AFSFid a_fidToStoreP;
struct AFSStoreStatus a_fidStatusP;
int32_t a_offset;
int32_t a_lenInBytes;
int32_t a_fileLenInBytes;
struct AFSFetchStatus a_fidStatP;
struct AFSVolSync a_volSyncP;
memset(&a_fidToStoreP, 0, sizeof(a_fidToStoreP));
memset(&a_fidStatusP, 0, sizeof(a_fidStatusP));
memset(&a_offset, 0, sizeof(a_offset));
memset(&a_lenInBytes, 0, sizeof(a_lenInBytes));
memset(&a_fileLenInBytes, 0, sizeof(a_fileLenInBytes));
memset(&a_fidStatP, 0, sizeof(a_fidStatP));
memset(&a_volSyncP, 0, sizeof(a_volSyncP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidToStoreP.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidToStoreP.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidToStoreP.Unique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidStatusP.Mask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidStatusP.ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidStatusP.Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidStatusP.Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidStatusP.UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidStatusP.SegSize = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_offset = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_lenInBytes = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fileLenInBytes = ntohl (u);
}
_result = SRXAFS_StoreData(call, &a_fidToStoreP, &a_fidStatusP, a_offset, a_lenInBytes, a_fileLenInBytes, &a_fidStatP, &a_volSyncP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (a_fidStatP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_fidStatP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_StoreACL(
struct rx_call *call)
{
int32_t _result;
struct AFSFid a_dirFidP;
AFSOpaque a_ACLToStoreP;
struct AFSFetchStatus a_dirNewStatP;
struct AFSVolSync a_volSyncP;
memset(&a_dirFidP, 0, sizeof(a_dirFidP));
memset(&a_ACLToStoreP, 0, sizeof(a_ACLToStoreP));
memset(&a_dirNewStatP, 0, sizeof(a_dirNewStatP));
memset(&a_volSyncP, 0, sizeof(a_volSyncP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Unique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_ACLToStoreP.len = ntohl (u);
}
if (a_ACLToStoreP.len > 1024) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < a_ACLToStoreP.len) goto fail;
}
a_ACLToStoreP.val = (char *)malloc(sizeof(char ) * a_ACLToStoreP.len);
if (a_ACLToStoreP.val == NULL) goto fail;
{
char zero[4] = {0, 0, 0, 0};
unsigned padlen = (4 - (a_ACLToStoreP.len % 4)) % 4;
if(rx_Read (call, a_ACLToStoreP.val, a_ACLToStoreP.len) != a_ACLToStoreP.len)
goto fail;
if(rx_Read (call, zero, padlen) != padlen)
goto fail;
}
_result = SRXAFS_StoreACL(call, &a_dirFidP, &a_ACLToStoreP, &a_dirNewStatP, &a_volSyncP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (a_dirNewStatP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirNewStatP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
free(a_ACLToStoreP.val);
return _result;
fail:
free(a_ACLToStoreP.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_StoreStatus(
struct rx_call *call)
{
int32_t _result;
struct AFSFid a_fidP;
struct AFSStoreStatus a_currStatusP;
struct AFSFetchStatus a_srStatusP;
struct AFSVolSync a_volSyncP;
memset(&a_fidP, 0, sizeof(a_fidP));
memset(&a_currStatusP, 0, sizeof(a_currStatusP));
memset(&a_srStatusP, 0, sizeof(a_srStatusP));
memset(&a_volSyncP, 0, sizeof(a_volSyncP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidP.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidP.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_fidP.Unique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_currStatusP.Mask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_currStatusP.ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_currStatusP.Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_currStatusP.Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_currStatusP.UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_currStatusP.SegSize = ntohl (u);
}
_result = SRXAFS_StoreStatus(call, &a_fidP, &a_currStatusP, &a_srStatusP, &a_volSyncP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (a_srStatusP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srStatusP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_RemoveFile(
struct rx_call *call)
{
int32_t _result;
struct AFSFid a_dirFidP;
char a_name[256];
struct AFSFetchStatus a_srvStatusP;
struct AFSVolSync a_volSyncP;
memset(&a_dirFidP, 0, sizeof(a_dirFidP));
memset(&a_name, 0, sizeof(a_name));
memset(&a_srvStatusP, 0, sizeof(a_srvStatusP));
memset(&a_volSyncP, 0, sizeof(a_volSyncP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Unique = ntohl (u);
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
if(rx_Read(call, (a_name), len) != len)
goto fail;
(a_name)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
_result = SRXAFS_RemoveFile(call, &a_dirFidP, a_name, &a_srvStatusP, &a_volSyncP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (a_srvStatusP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_srvStatusP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_CreateFile(
struct rx_call *call)
{
int32_t _result;
struct AFSFid DirFid;
char Name[256];
struct AFSStoreStatus InStatus;
struct AFSFid OutFid;
struct AFSFetchStatus OutFidStatus;
struct AFSFetchStatus OutDirStatus;
struct AFSCallBack CallBack;
struct AFSVolSync a_volSyncP;
memset(&DirFid, 0, sizeof(DirFid));
memset(&Name, 0, sizeof(Name));
memset(&InStatus, 0, sizeof(InStatus));
memset(&OutFid, 0, sizeof(OutFid));
memset(&OutFidStatus, 0, sizeof(OutFidStatus));
memset(&OutDirStatus, 0, sizeof(OutDirStatus));
memset(&CallBack, 0, sizeof(CallBack));
memset(&a_volSyncP, 0, sizeof(a_volSyncP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
DirFid.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
DirFid.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
DirFid.Unique = ntohl (u);
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
if(rx_Read(call, (Name), len) != len)
goto fail;
(Name)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
InStatus.Mask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
InStatus.ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
InStatus.Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
InStatus.Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
InStatus.UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
InStatus.SegSize = ntohl (u);
}
_result = SRXAFS_CreateFile(call, &DirFid, Name, &InStatus, &OutFid, &OutFidStatus, &OutDirStatus, &CallBack, &a_volSyncP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (OutFid.Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFid.Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFid.Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutFidStatus.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutDirStatus.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (CallBack.CallBackVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (CallBack.ExpirationTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (CallBack.CallBackType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_Rename(
struct rx_call *call)
{
int32_t _result;
struct AFSFid a_origDirFidP;
char a_origNameP[256];
struct AFSFid a_newDirFidP;
char a_newNameP[256];
struct AFSFetchStatus a_origDirStatusP;
struct AFSFetchStatus a_newDirStatusP;
struct AFSVolSync a_volSyncP;
memset(&a_origDirFidP, 0, sizeof(a_origDirFidP));
memset(&a_origNameP, 0, sizeof(a_origNameP));
memset(&a_newDirFidP, 0, sizeof(a_newDirFidP));
memset(&a_newNameP, 0, sizeof(a_newNameP));
memset(&a_origDirStatusP, 0, sizeof(a_origDirStatusP));
memset(&a_newDirStatusP, 0, sizeof(a_newDirStatusP));
memset(&a_volSyncP, 0, sizeof(a_volSyncP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_origDirFidP.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_origDirFidP.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_origDirFidP.Unique = ntohl (u);
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
if(rx_Read(call, (a_origNameP), len) != len)
goto fail;
(a_origNameP)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_newDirFidP.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_newDirFidP.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_newDirFidP.Unique = ntohl (u);
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
if(rx_Read(call, (a_newNameP), len) != len)
goto fail;
(a_newNameP)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
_result = SRXAFS_Rename(call, &a_origDirFidP, a_origNameP, &a_newDirFidP, a_newNameP, &a_origDirStatusP, &a_newDirStatusP, &a_volSyncP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (a_origDirStatusP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_origDirStatusP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatusP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_Symlink(
struct rx_call *call)
{
int32_t _result;
struct AFSFid a_dirFidP;
char a_nameP[256];
char a_linkContentsP[256];
struct AFSStoreStatus a_origDirStatP;
struct AFSFid a_newFidP;
struct AFSFetchStatus a_newFidStatP;
struct AFSFetchStatus a_newDirStatP;
struct AFSVolSync a_volSyncP;
memset(&a_dirFidP, 0, sizeof(a_dirFidP));
memset(&a_nameP, 0, sizeof(a_nameP));
memset(&a_linkContentsP, 0, sizeof(a_linkContentsP));
memset(&a_origDirStatP, 0, sizeof(a_origDirStatP));
memset(&a_newFidP, 0, sizeof(a_newFidP));
memset(&a_newFidStatP, 0, sizeof(a_newFidStatP));
memset(&a_newDirStatP, 0, sizeof(a_newDirStatP));
memset(&a_volSyncP, 0, sizeof(a_volSyncP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Unique = ntohl (u);
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
if(rx_Read(call, (a_nameP), len) != len)
goto fail;
(a_nameP)[len] = '\0';
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
if(rx_Read(call, (a_linkContentsP), len) != len)
goto fail;
(a_linkContentsP)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_origDirStatP.Mask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_origDirStatP.ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_origDirStatP.Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_origDirStatP.Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_origDirStatP.UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_origDirStatP.SegSize = ntohl (u);
}
_result = SRXAFS_Symlink(call, &a_dirFidP, a_nameP, a_linkContentsP, &a_origDirStatP, &a_newFidP, &a_newFidStatP, &a_newDirStatP, &a_volSyncP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (a_newFidP.Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidP.Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidP.Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_Link(
struct rx_call *call)
{
int32_t _result;
struct AFSFid a_dirFidP;
char a_nameP[256];
struct AFSFid a_existingFidP;
struct AFSFetchStatus a_newFidStatP;
struct AFSFetchStatus a_newDirStatP;
struct AFSVolSync a_volSyncP;
memset(&a_dirFidP, 0, sizeof(a_dirFidP));
memset(&a_nameP, 0, sizeof(a_nameP));
memset(&a_existingFidP, 0, sizeof(a_existingFidP));
memset(&a_newFidStatP, 0, sizeof(a_newFidStatP));
memset(&a_newDirStatP, 0, sizeof(a_newDirStatP));
memset(&a_volSyncP, 0, sizeof(a_volSyncP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_dirFidP.Unique = ntohl (u);
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
if(rx_Read(call, (a_nameP), len) != len)
goto fail;
(a_nameP)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_existingFidP.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_existingFidP.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_existingFidP.Unique = ntohl (u);
}
_result = SRXAFS_Link(call, &a_dirFidP, a_nameP, &a_existingFidP, &a_newFidStatP, &a_newDirStatP, &a_volSyncP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (a_newFidStatP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newFidStatP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirStatP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_MakeDir(
struct rx_call *call)
{
int32_t _result;
struct AFSFid a_parentDirFidP;
char a_newDirNameP[256];
struct AFSStoreStatus a_currStatP;
struct AFSFid a_newDirFidP;
struct AFSFetchStatus a_dirFidStatP;
struct AFSFetchStatus a_parentDirStatP;
struct AFSCallBack a_newDirCallBackP;
struct AFSVolSync a_volSyncP;
memset(&a_parentDirFidP, 0, sizeof(a_parentDirFidP));
memset(&a_newDirNameP, 0, sizeof(a_newDirNameP));
memset(&a_currStatP, 0, sizeof(a_currStatP));
memset(&a_newDirFidP, 0, sizeof(a_newDirFidP));
memset(&a_dirFidStatP, 0, sizeof(a_dirFidStatP));
memset(&a_parentDirStatP, 0, sizeof(a_parentDirStatP));
memset(&a_newDirCallBackP, 0, sizeof(a_newDirCallBackP));
memset(&a_volSyncP, 0, sizeof(a_volSyncP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_parentDirFidP.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_parentDirFidP.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_parentDirFidP.Unique = ntohl (u);
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
if(rx_Read(call, (a_newDirNameP), len) != len)
goto fail;
(a_newDirNameP)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_currStatP.Mask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_currStatP.ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_currStatP.Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_currStatP.Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_currStatP.UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_currStatP.SegSize = ntohl (u);
}
_result = SRXAFS_MakeDir(call, &a_parentDirFidP, a_newDirNameP, &a_currStatP, &a_newDirFidP, &a_dirFidStatP, &a_parentDirStatP, &a_newDirCallBackP, &a_volSyncP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (a_newDirFidP.Volume);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirFidP.Vnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirFidP.Unique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_dirFidStatP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_parentDirStatP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirCallBackP.CallBackVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirCallBackP.ExpirationTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newDirCallBackP.CallBackType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_RemoveDir(
struct rx_call *call)
{
int32_t _result;
struct AFSFid a_parentDirStatP;
char a_dirNameP[256];
struct AFSFetchStatus a_newParentDirStatP;
struct AFSVolSync a_volSyncP;
memset(&a_parentDirStatP, 0, sizeof(a_parentDirStatP));
memset(&a_dirNameP, 0, sizeof(a_dirNameP));
memset(&a_newParentDirStatP, 0, sizeof(a_newParentDirStatP));
memset(&a_volSyncP, 0, sizeof(a_volSyncP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_parentDirStatP.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_parentDirStatP.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_parentDirStatP.Unique = ntohl (u);
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
if(rx_Read(call, (a_dirNameP), len) != len)
goto fail;
(a_dirNameP)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
_result = SRXAFS_RemoveDir(call, &a_parentDirStatP, a_dirNameP, &a_newParentDirStatP, &a_volSyncP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (a_newParentDirStatP.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_newParentDirStatP.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volSyncP.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_GiveUpCallBacks(
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
_result = SRXAFS_GiveUpCallBacks(call, &a_fidArrayP, &a_callBackArrayP);
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

static int ydr_ps_RXAFS_GetVolumeStatus(
struct rx_call *call)
{
int32_t _result;
int32_t a_volIDP;
struct AFSFetchVolumeStatus a_volFetchStatP;
char a_volNameP[256];
char a_offLineMsgP[1024];
char a_motdP[1024];
memset(&a_volIDP, 0, sizeof(a_volIDP));
memset(&a_volFetchStatP, 0, sizeof(a_volFetchStatP));
memset(&a_volNameP, 0, sizeof(a_volNameP));
memset(&a_offLineMsgP, 0, sizeof(a_offLineMsgP));
memset(&a_motdP, 0, sizeof(a_motdP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_volIDP = ntohl (u);
}
_result = SRXAFS_GetVolumeStatus(call, a_volIDP, &a_volFetchStatP, a_volNameP, a_offLineMsgP, a_motdP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (a_volFetchStatP.Vid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volFetchStatP.ParentId);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volFetchStatP.Online);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volFetchStatP.InService);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volFetchStatP.Blessed);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volFetchStatP.NeedsSalvage);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volFetchStatP.Type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volFetchStatP.MinQuota);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volFetchStatP.MaxQuota);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volFetchStatP.BlocksInUse);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volFetchStatP.PartBlocksAvail);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_volFetchStatP.PartMaxBlocks);
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
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_SetVolumeStatus(
struct rx_call *call)
{
int32_t _result;
int32_t a_volIDP;
struct AFSStoreVolumeStatus a_volStoreStatP;
char a_volNameP[256];
char a_offLineMsgP[1024];
char a_motdP[1024];
memset(&a_volIDP, 0, sizeof(a_volIDP));
memset(&a_volStoreStatP, 0, sizeof(a_volStoreStatP));
memset(&a_volNameP, 0, sizeof(a_volNameP));
memset(&a_offLineMsgP, 0, sizeof(a_offLineMsgP));
memset(&a_motdP, 0, sizeof(a_motdP));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_volIDP = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_volStoreStatP.Mask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_volStoreStatP.MinQuota = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
a_volStoreStatP.MaxQuota = ntohl (u);
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
_result = SRXAFS_SetVolumeStatus(call, a_volIDP, &a_volStoreStatP, a_volNameP, a_offLineMsgP, a_motdP);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_GetRootVolume(
struct rx_call *call)
{
int32_t _result;
char a_rootVolNameP[256];
memset(&a_rootVolNameP, 0, sizeof(a_rootVolNameP));

_result = SRXAFS_GetRootVolume(call, a_rootVolNameP);
if (_result) goto funcfail;
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(a_rootVolNameP);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, a_rootVolNameP, len) != len)
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

static int ydr_ps_RXAFS_GetTime(
struct rx_call *call)
{
int32_t _result;
uint32_t a_secondsP;
uint32_t a_uSecondsP;
memset(&a_secondsP, 0, sizeof(a_secondsP));
memset(&a_uSecondsP, 0, sizeof(a_uSecondsP));

_result = SRXAFS_GetTime(call, &a_secondsP, &a_uSecondsP);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (a_secondsP);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (a_uSecondsP);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_NGetVolumeInfo(
struct rx_call *call)
{
int32_t _result;
char VolumeName[256];
struct AFSVolumeInfo stuff;
memset(&VolumeName, 0, sizeof(VolumeName));
memset(&stuff, 0, sizeof(stuff));

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
if(rx_Read(call, (VolumeName), len) != len)
goto fail;
(VolumeName)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
_result = SRXAFS_NGetVolumeInfo(call, VolumeName, &stuff);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (stuff.Vid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Type);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Type0);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Type1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Type2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Type3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Type4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.ServerCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Server0);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Server1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Server2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Server3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Server4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Server5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Server6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Server7);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Port0);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Port1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Port2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Port3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Port4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Port5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Port6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (stuff.Port7);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_BulkStatus(
struct rx_call *call)
{
int32_t _result;
AFSCBFids FidsArray;
AFSBulkStats StatArray;
AFSCBs CBArray;
struct AFSVolSync Sync;
memset(&FidsArray, 0, sizeof(FidsArray));
memset(&StatArray, 0, sizeof(StatArray));
memset(&CBArray, 0, sizeof(CBArray));
memset(&Sync, 0, sizeof(Sync));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
FidsArray.len = ntohl (u);
}
if (FidsArray.len > 50) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSFid );
if (overI < FidsArray.len) goto fail;
}
FidsArray.val = (struct AFSFid *)malloc(sizeof(struct AFSFid ) * FidsArray.len);
if (FidsArray.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < FidsArray.len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
FidsArray.val[i0].Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
FidsArray.val[i0].Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
FidsArray.val[i0].Unique = ntohl (u);
}
}
}
_result = SRXAFS_BulkStatus(call, &FidsArray, &StatArray, &CBArray, &Sync);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (StatArray.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSFetchStatus );
if (overI < StatArray.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < StatArray.len;++i0){
{ uint32_t u;
u = htonl (StatArray.val[i0].InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (StatArray.val[i0].ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (CBArray.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSCallBack );
if (overI < CBArray.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < CBArray.len;++i0){
{ uint32_t u;
u = htonl (CBArray.val[i0].CallBackVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (CBArray.val[i0].ExpirationTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (CBArray.val[i0].CallBackType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (Sync.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
free(FidsArray.val);
free(StatArray.val);
free(CBArray.val);
return _result;
fail:
free(FidsArray.val);
free(StatArray.val);
free(CBArray.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_SetLock(
struct rx_call *call)
{
int32_t _result;
struct AFSFid Fid;
ViceLockType Type;
struct AFSVolSync Sync;
memset(&Fid, 0, sizeof(Fid));
memset(&Type, 0, sizeof(Type));
memset(&Sync, 0, sizeof(Sync));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Unique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Type = ntohl (u);
}
_result = SRXAFS_SetLock(call, &Fid, Type, &Sync);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (Sync.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_ExtendLock(
struct rx_call *call)
{
int32_t _result;
struct AFSFid Fid;
struct AFSVolSync Sync;
memset(&Fid, 0, sizeof(Fid));
memset(&Sync, 0, sizeof(Sync));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Unique = ntohl (u);
}
_result = SRXAFS_ExtendLock(call, &Fid, &Sync);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (Sync.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_ReleaseLock(
struct rx_call *call)
{
int32_t _result;
struct AFSFid Fid;
struct AFSVolSync Sync;
memset(&Fid, 0, sizeof(Fid));
memset(&Sync, 0, sizeof(Sync));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Unique = ntohl (u);
}
_result = SRXAFS_ReleaseLock(call, &Fid, &Sync);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (Sync.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_FlushCPS(
struct rx_call *call)
{
int32_t _result;
ViceIds IdsArray;
IPAddrs AddrsArray;
int32_t spare1;
int32_t spare2;
int32_t spare3;
memset(&IdsArray, 0, sizeof(IdsArray));
memset(&AddrsArray, 0, sizeof(AddrsArray));
memset(&spare1, 0, sizeof(spare1));
memset(&spare2, 0, sizeof(spare2));
memset(&spare3, 0, sizeof(spare3));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
IdsArray.len = ntohl (u);
}
if (IdsArray.len > 10) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < IdsArray.len) goto fail;
}
IdsArray.val = (int32_t *)malloc(sizeof(int32_t ) * IdsArray.len);
if (IdsArray.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < IdsArray.len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
IdsArray.val[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
AddrsArray.len = ntohl (u);
}
if (AddrsArray.len > 10) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < AddrsArray.len) goto fail;
}
AddrsArray.val = (int32_t *)malloc(sizeof(int32_t ) * AddrsArray.len);
if (AddrsArray.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < AddrsArray.len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
AddrsArray.val[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
spare1 = ntohl (u);
}
_result = SRXAFS_FlushCPS(call, &IdsArray, &AddrsArray, spare1, &spare2, &spare3);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
free(IdsArray.val);
free(AddrsArray.val);
return _result;
fail:
free(IdsArray.val);
free(AddrsArray.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_FetchData64(
struct rx_call *call)
{
int32_t _result;
struct AFSFid Fid;
int64_t Pos;
int64_t Length;
struct AFSFetchStatus OutStatus;
struct AFSCallBack CallBack;
struct AFSVolSync Sync;
memset(&Fid, 0, sizeof(Fid));
memset(&Pos, 0, sizeof(Pos));
memset(&Length, 0, sizeof(Length));
memset(&OutStatus, 0, sizeof(OutStatus));
memset(&CallBack, 0, sizeof(CallBack));
memset(&Sync, 0, sizeof(Sync));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Unique = ntohl (u);
}
{ uint64_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Pos = be64toh (u);
}
{ uint64_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Length = be64toh (u);
}
_result = SRXAFS_FetchData64(call, &Fid, Pos, Length, &OutStatus, &CallBack, &Sync);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (OutStatus.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (CallBack.CallBackVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (CallBack.ExpirationTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (CallBack.CallBackType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_StoreData64(
struct rx_call *call)
{
int32_t _result;
struct AFSFid Fid;
struct AFSStoreStatus InStatus;
uint64_t Pos;
uint64_t Length;
uint64_t FileLength;
struct AFSFetchStatus OutStatus;
struct AFSVolSync Sync;
memset(&Fid, 0, sizeof(Fid));
memset(&InStatus, 0, sizeof(InStatus));
memset(&Pos, 0, sizeof(Pos));
memset(&Length, 0, sizeof(Length));
memset(&FileLength, 0, sizeof(FileLength));
memset(&OutStatus, 0, sizeof(OutStatus));
memset(&Sync, 0, sizeof(Sync));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Volume = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Vnode = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Fid.Unique = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
InStatus.Mask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
InStatus.ClientModTime = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
InStatus.Owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
InStatus.Group = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
InStatus.UnixModeBits = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
InStatus.SegSize = ntohl (u);
}
{ uint64_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Pos = be64toh (u);
}
{ uint64_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
Length = be64toh (u);
}
{ uint64_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
FileLength = be64toh (u);
}
_result = SRXAFS_StoreData64(call, &Fid, &InStatus, Pos, Length, FileLength, &OutStatus, &Sync);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (OutStatus.InterfaceVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.FileType);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.LinkCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.Length);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.DataVersion);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.Author);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.Owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.CallerAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.AnonymousAccess);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.UnixModeBits);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.ParentVnode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.ParentUnique);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.ResidencyMask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.ClientModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.ServerModTime);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.Group);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.SyncCounter);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.DataVersionHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.LockCount);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.LengthHigh);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (OutStatus.ErrorCode);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare3);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare4);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare5);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (Sync.spare6);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_RXAFS_GiveUpAllCallBacks(
struct rx_call *call)
{
int32_t _result;

_result = SRXAFS_GiveUpAllCallBacks(call);
if (_result) goto funcfail;
return _result;
funcfail:
return _result;
}

static int ydr_ps_RXAFS_GetCapabilities(
struct rx_call *call)
{
int32_t _result;
Capabilities capabilities;
memset(&capabilities, 0, sizeof(capabilities));

_result = SRXAFS_GetCapabilities(call, &capabilities);
if (_result) goto funcfail;
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

int32_t RXAFS_ExecuteRequest(struct rx_call *call)
{
unsigned opcode;
int32_t _result;
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
opcode = ntohl (u);
}
switch(opcode) {
case 130: {
_result = ydr_ps_RXAFS_FetchData(call);
break;
}
case 131: {
_result = ydr_ps_RXAFS_FetchACL(call);
break;
}
case 132: {
_result = ydr_ps_RXAFS_FetchStatus(call);
break;
}
case 133: {
_result = ydr_ps_RXAFS_StoreData(call);
break;
}
case 134: {
_result = ydr_ps_RXAFS_StoreACL(call);
break;
}
case 135: {
_result = ydr_ps_RXAFS_StoreStatus(call);
break;
}
case 136: {
_result = ydr_ps_RXAFS_RemoveFile(call);
break;
}
case 137: {
_result = ydr_ps_RXAFS_CreateFile(call);
break;
}
case 138: {
_result = ydr_ps_RXAFS_Rename(call);
break;
}
case 139: {
_result = ydr_ps_RXAFS_Symlink(call);
break;
}
case 140: {
_result = ydr_ps_RXAFS_Link(call);
break;
}
case 141: {
_result = ydr_ps_RXAFS_MakeDir(call);
break;
}
case 142: {
_result = ydr_ps_RXAFS_RemoveDir(call);
break;
}
case 147: {
_result = ydr_ps_RXAFS_GiveUpCallBacks(call);
break;
}
case 149: {
_result = ydr_ps_RXAFS_GetVolumeStatus(call);
break;
}
case 150: {
_result = ydr_ps_RXAFS_SetVolumeStatus(call);
break;
}
case 151: {
_result = ydr_ps_RXAFS_GetRootVolume(call);
break;
}
case 153: {
_result = ydr_ps_RXAFS_GetTime(call);
break;
}
case 154: {
_result = ydr_ps_RXAFS_NGetVolumeInfo(call);
break;
}
case 155: {
_result = ydr_ps_RXAFS_BulkStatus(call);
break;
}
case 156: {
_result = ydr_ps_RXAFS_SetLock(call);
break;
}
case 157: {
_result = ydr_ps_RXAFS_ExtendLock(call);
break;
}
case 158: {
_result = ydr_ps_RXAFS_ReleaseLock(call);
break;
}
case 162: {
_result = ydr_ps_RXAFS_FlushCPS(call);
break;
}
case 65537: {
_result = ydr_ps_RXAFS_FetchData64(call);
break;
}
case 65538: {
_result = ydr_ps_RXAFS_StoreData64(call);
break;
}
case 65539: {
_result = ydr_ps_RXAFS_GiveUpAllCallBacks(call);
break;
}
case 65540: {
_result = ydr_ps_RXAFS_GetCapabilities(call);
break;
}
default:
_result = RXGEN_OPCODE;
}
return _result;
fail:
return rx_GetCallError(call);
}

