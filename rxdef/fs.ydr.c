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
RCSID("fs.ydr.c generated from fs.xg with $Id: fs.ydr.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
char *ydr_encode_AFSFid(const AFSFid *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).Volume); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Vnode); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Unique); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_AFSFid(AFSFid *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Volume = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Vnode = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Unique = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_AFSFid(AFSFid *o)
{
/* printing TSTRUCT (*o) */
printf(" .Volume = %d", (*o).Volume);
printf(" .Vnode = %d", (*o).Vnode);
printf(" .Unique = %d", (*o).Unique);
return;
}
void ydr_free_AFSFid(AFSFid *o)
{
return;
}
char *ydr_encode_VenusFid(const VenusFid *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).Cell); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).fid.Volume); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).fid.Vnode); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).fid.Unique); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_VenusFid(VenusFid *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Cell = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).fid.Volume = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).fid.Vnode = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).fid.Unique = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_VenusFid(VenusFid *o)
{
/* printing TSTRUCT (*o) */
printf(" .Cell = %d", (*o).Cell);
/* printing TSTRUCT (*o).fid */
printf(" .Volume = %d", (*o).fid.Volume);
printf(" .Vnode = %d", (*o).fid.Vnode);
printf(" .Unique = %d", (*o).fid.Unique);

return;
}
void ydr_free_VenusFid(VenusFid *o)
{
return;
}
char *ydr_encode_AFSCallBack(const AFSCallBack *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).CallBackVersion); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ExpirationTime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).CallBackType); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_AFSCallBack(AFSCallBack *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).CallBackVersion = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ExpirationTime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).CallBackType = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_AFSCallBack(AFSCallBack *o)
{
/* printing TSTRUCT (*o) */
printf(" .CallBackVersion = %d", (*o).CallBackVersion);
printf(" .ExpirationTime = %d", (*o).ExpirationTime);
printf(" .CallBackType = %d", (*o).CallBackType);
return;
}
void ydr_free_AFSCallBack(AFSCallBack *o)
{
return;
}
char *ydr_encode_CallBackType(const CallBackType *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o)); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_CallBackType(CallBackType *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o) = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_CallBackType(CallBackType *o)
{
/* print ENUM (*o) */
printf(" = ");switch((*o)) {
case 1:
printf("CBEXCLUSIVE");
break;
case 2:
printf("CBSHARED");
break;
case 3:
printf("CBDROPPED");
break;
default:
printf(" unknown enum %d", (*o));
}
return;
}
void ydr_free_CallBackType(CallBackType *o)
{
return;
}
char *ydr_encode_AFSVolSync(const AFSVolSync *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).spare1); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spare2); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spare3); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spare4); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spare5); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spare6); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_AFSVolSync(AFSVolSync *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spare1 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spare2 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spare3 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spare4 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spare5 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spare6 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_AFSVolSync(AFSVolSync *o)
{
/* printing TSTRUCT (*o) */
printf(" .spare1 = %d", (*o).spare1);
printf(" .spare2 = %d", (*o).spare2);
printf(" .spare3 = %d", (*o).spare3);
printf(" .spare4 = %d", (*o).spare4);
printf(" .spare5 = %d", (*o).spare5);
printf(" .spare6 = %d", (*o).spare6);
return;
}
void ydr_free_AFSVolSync(AFSVolSync *o)
{
return;
}
char *ydr_encode_AFSFetchStatus(const AFSFetchStatus *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).InterfaceVersion); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).FileType); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).LinkCount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Length); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).DataVersion); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Author); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Owner); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).CallerAccess); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).AnonymousAccess); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).UnixModeBits); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ParentVnode); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ParentUnique); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ResidencyMask); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ClientModTime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ServerModTime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Group); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).SyncCounter); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).DataVersionHigh); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).LockCount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).LengthHigh); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ErrorCode); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_AFSFetchStatus(AFSFetchStatus *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).InterfaceVersion = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).FileType = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).LinkCount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Length = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).DataVersion = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Author = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Owner = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).CallerAccess = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).AnonymousAccess = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).UnixModeBits = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ParentVnode = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ParentUnique = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ResidencyMask = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ClientModTime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ServerModTime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Group = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).SyncCounter = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).DataVersionHigh = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).LockCount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).LengthHigh = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ErrorCode = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_AFSFetchStatus(AFSFetchStatus *o)
{
/* printing TSTRUCT (*o) */
printf(" .InterfaceVersion = %d", (*o).InterfaceVersion);
printf(" .FileType = %d", (*o).FileType);
printf(" .LinkCount = %d", (*o).LinkCount);
printf(" .Length = %d", (*o).Length);
printf(" .DataVersion = %d", (*o).DataVersion);
printf(" .Author = %d", (*o).Author);
printf(" .Owner = %d", (*o).Owner);
printf(" .CallerAccess = %d", (*o).CallerAccess);
printf(" .AnonymousAccess = %d", (*o).AnonymousAccess);
printf(" .UnixModeBits = %d", (*o).UnixModeBits);
printf(" .ParentVnode = %d", (*o).ParentVnode);
printf(" .ParentUnique = %d", (*o).ParentUnique);
printf(" .ResidencyMask = %d", (*o).ResidencyMask);
printf(" .ClientModTime = %d", (*o).ClientModTime);
printf(" .ServerModTime = %d", (*o).ServerModTime);
printf(" .Group = %d", (*o).Group);
printf(" .SyncCounter = %d", (*o).SyncCounter);
printf(" .DataVersionHigh = %d", (*o).DataVersionHigh);
printf(" .LockCount = %d", (*o).LockCount);
printf(" .LengthHigh = %d", (*o).LengthHigh);
printf(" .ErrorCode = %d", (*o).ErrorCode);
return;
}
void ydr_free_AFSFetchStatus(AFSFetchStatus *o)
{
return;
}
char *ydr_encode_AFSStoreStatus(const AFSStoreStatus *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).Mask); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ClientModTime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Owner); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Group); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).UnixModeBits); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).SegSize); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_AFSStoreStatus(AFSStoreStatus *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Mask = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ClientModTime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Owner = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Group = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).UnixModeBits = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).SegSize = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_AFSStoreStatus(AFSStoreStatus *o)
{
/* printing TSTRUCT (*o) */
printf(" .Mask = %d", (*o).Mask);
printf(" .ClientModTime = %d", (*o).ClientModTime);
printf(" .Owner = %d", (*o).Owner);
printf(" .Group = %d", (*o).Group);
printf(" .UnixModeBits = %d", (*o).UnixModeBits);
printf(" .SegSize = %d", (*o).SegSize);
return;
}
void ydr_free_AFSStoreStatus(AFSStoreStatus *o)
{
return;
}
char *ydr_encode_AFSFetchVolumeStatus(const AFSFetchVolumeStatus *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).Vid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ParentId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Online); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).InService); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Blessed); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).NeedsSalvage); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Type); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).MinQuota); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).MaxQuota); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).BlocksInUse); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).PartBlocksAvail); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).PartMaxBlocks); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_AFSFetchVolumeStatus(AFSFetchVolumeStatus *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Vid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ParentId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Online = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).InService = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Blessed = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).NeedsSalvage = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Type = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).MinQuota = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).MaxQuota = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).BlocksInUse = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).PartBlocksAvail = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).PartMaxBlocks = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_AFSFetchVolumeStatus(AFSFetchVolumeStatus *o)
{
/* printing TSTRUCT (*o) */
printf(" .Vid = %d", (*o).Vid);
printf(" .ParentId = %d", (*o).ParentId);
printf(" .Online = %d", (*o).Online);
printf(" .InService = %d", (*o).InService);
printf(" .Blessed = %d", (*o).Blessed);
printf(" .NeedsSalvage = %d", (*o).NeedsSalvage);
printf(" .Type = %d", (*o).Type);
printf(" .MinQuota = %d", (*o).MinQuota);
printf(" .MaxQuota = %d", (*o).MaxQuota);
printf(" .BlocksInUse = %d", (*o).BlocksInUse);
printf(" .PartBlocksAvail = %d", (*o).PartBlocksAvail);
printf(" .PartMaxBlocks = %d", (*o).PartMaxBlocks);
return;
}
void ydr_free_AFSFetchVolumeStatus(AFSFetchVolumeStatus *o)
{
return;
}
char *ydr_encode_AFSStoreVolumeStatus(const AFSStoreVolumeStatus *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).Mask); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).MinQuota); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).MaxQuota); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_AFSStoreVolumeStatus(AFSStoreVolumeStatus *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Mask = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).MinQuota = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).MaxQuota = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_AFSStoreVolumeStatus(AFSStoreVolumeStatus *o)
{
/* printing TSTRUCT (*o) */
printf(" .Mask = %d", (*o).Mask);
printf(" .MinQuota = %d", (*o).MinQuota);
printf(" .MaxQuota = %d", (*o).MaxQuota);
return;
}
void ydr_free_AFSStoreVolumeStatus(AFSStoreVolumeStatus *o)
{
return;
}
char *ydr_encode_AFSOpaque(const AFSOpaque *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*o).len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
size_t sz = (*o).len + (4 - ((*o).len % 4)) % 4;
if (*total_len < sz) goto fail;
memcpy (ptr, (*o).val, (*o).len);
memcpy (ptr + (*o).len, zero, (4 - ((*o).len % 4)) % 4);
ptr += sz; *total_len -= sz;
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_AFSOpaque(AFSOpaque *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).len > 1024) goto fail;
if (((*o).len * sizeof(char )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*o).len) goto fail;
}
(*o).val = (char *)malloc(sizeof(char ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
memcpy ((*o).val, ptr, (*o).len);
ptr += (*o).len + (4 - ((*o).len % 4)) % 4;
}
return ptr;
fail:
free(((*o)).val);
errno = EINVAL;
return NULL;}
void ydr_print_AFSOpaque(AFSOpaque *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
char *ptr = (*o).val;
printf("0x");for (i0 = 0; i0 < (*o).len; ++i0)
printf("%x", ptr[i0]);}
return;
}
void ydr_free_AFSOpaque(AFSOpaque *o)
{
free(((*o)).val);
return;
}
char *ydr_encode_ViceLockType(const ViceLockType *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o)); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_ViceLockType(ViceLockType *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o) = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_ViceLockType(ViceLockType *o)
{
printf("  = %d", (*o));return;
}
void ydr_free_ViceLockType(ViceLockType *o)
{
return;
}
char *ydr_encode_AFSCBs(const AFSCBs *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSCallBack );
if (overI < (*o).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp = htonl((*o).val[i0].CallBackVersion); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].ExpirationTime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].CallBackType); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_AFSCBs(AFSCBs *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).len > 50) goto fail;
if (((*o).len * sizeof(struct AFSCallBack )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSCallBack );
if (overI < (*o).len) goto fail;
}
(*o).val = (struct AFSCallBack *)malloc(sizeof(struct AFSCallBack ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].CallBackVersion = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].ExpirationTime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].CallBackType = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
errno = EINVAL;
return NULL;}
void ydr_print_AFSCBs(AFSCBs *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
for (i0 = 0; i0 < (*o).len; ++i0) {
/* printing TSTRUCT (*o).val[i0] */
printf(" .CallBackVersion = %d", (*o).val[i0].CallBackVersion);
printf(" .ExpirationTime = %d", (*o).val[i0].ExpirationTime);
printf(" .CallBackType = %d", (*o).val[i0].CallBackType);

if (i0 != (*o).len - 1) printf(",");
}
}
return;
}
void ydr_free_AFSCBs(AFSCBs *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
return;
}
char *ydr_encode_AFSBulkStats(const AFSBulkStats *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSFetchStatus );
if (overI < (*o).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp = htonl((*o).val[i0].InterfaceVersion); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].FileType); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].LinkCount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].Length); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].DataVersion); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].Author); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].Owner); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].CallerAccess); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].AnonymousAccess); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].UnixModeBits); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].ParentVnode); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].ParentUnique); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].ResidencyMask); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].ClientModTime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].ServerModTime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].Group); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].SyncCounter); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].DataVersionHigh); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].LockCount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].LengthHigh); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].ErrorCode); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_AFSBulkStats(AFSBulkStats *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).len > 50) goto fail;
if (((*o).len * sizeof(struct AFSFetchStatus )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSFetchStatus );
if (overI < (*o).len) goto fail;
}
(*o).val = (struct AFSFetchStatus *)malloc(sizeof(struct AFSFetchStatus ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].InterfaceVersion = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].FileType = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].LinkCount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].Length = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].DataVersion = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].Author = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].Owner = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].CallerAccess = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].AnonymousAccess = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].UnixModeBits = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].ParentVnode = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].ParentUnique = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].ResidencyMask = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].ClientModTime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].ServerModTime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].Group = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].SyncCounter = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].DataVersionHigh = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].LockCount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].LengthHigh = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].ErrorCode = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
errno = EINVAL;
return NULL;}
void ydr_print_AFSBulkStats(AFSBulkStats *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
for (i0 = 0; i0 < (*o).len; ++i0) {
/* printing TSTRUCT (*o).val[i0] */
printf(" .InterfaceVersion = %d", (*o).val[i0].InterfaceVersion);
printf(" .FileType = %d", (*o).val[i0].FileType);
printf(" .LinkCount = %d", (*o).val[i0].LinkCount);
printf(" .Length = %d", (*o).val[i0].Length);
printf(" .DataVersion = %d", (*o).val[i0].DataVersion);
printf(" .Author = %d", (*o).val[i0].Author);
printf(" .Owner = %d", (*o).val[i0].Owner);
printf(" .CallerAccess = %d", (*o).val[i0].CallerAccess);
printf(" .AnonymousAccess = %d", (*o).val[i0].AnonymousAccess);
printf(" .UnixModeBits = %d", (*o).val[i0].UnixModeBits);
printf(" .ParentVnode = %d", (*o).val[i0].ParentVnode);
printf(" .ParentUnique = %d", (*o).val[i0].ParentUnique);
printf(" .ResidencyMask = %d", (*o).val[i0].ResidencyMask);
printf(" .ClientModTime = %d", (*o).val[i0].ClientModTime);
printf(" .ServerModTime = %d", (*o).val[i0].ServerModTime);
printf(" .Group = %d", (*o).val[i0].Group);
printf(" .SyncCounter = %d", (*o).val[i0].SyncCounter);
printf(" .DataVersionHigh = %d", (*o).val[i0].DataVersionHigh);
printf(" .LockCount = %d", (*o).val[i0].LockCount);
printf(" .LengthHigh = %d", (*o).val[i0].LengthHigh);
printf(" .ErrorCode = %d", (*o).val[i0].ErrorCode);

if (i0 != (*o).len - 1) printf(",");
}
}
return;
}
void ydr_free_AFSBulkStats(AFSBulkStats *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
return;
}
char *ydr_encode_AFSCBFids(const AFSCBFids *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSFid );
if (overI < (*o).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp = htonl((*o).val[i0].Volume); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].Vnode); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].Unique); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_AFSCBFids(AFSCBFids *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).len > 50) goto fail;
if (((*o).len * sizeof(struct AFSFid )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct AFSFid );
if (overI < (*o).len) goto fail;
}
(*o).val = (struct AFSFid *)malloc(sizeof(struct AFSFid ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].Volume = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].Vnode = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].Unique = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
errno = EINVAL;
return NULL;}
void ydr_print_AFSCBFids(AFSCBFids *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
for (i0 = 0; i0 < (*o).len; ++i0) {
/* printing TSTRUCT (*o).val[i0] */
printf(" .Volume = %d", (*o).val[i0].Volume);
printf(" .Vnode = %d", (*o).val[i0].Vnode);
printf(" .Unique = %d", (*o).val[i0].Unique);

if (i0 != (*o).len - 1) printf(",");
}
}
return;
}
void ydr_free_AFSCBFids(AFSCBFids *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
return;
}
char *ydr_encode_AFSVolumeInfo(const AFSVolumeInfo *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).Vid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Type); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Type0); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Type1); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Type2); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Type3); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Type4); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ServerCount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Server0); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Server1); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Server2); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Server3); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Server4); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Server5); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Server6); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Server7); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Port0); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Port1); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Port2); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Port3); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Port4); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Port5); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Port6); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Port7); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_AFSVolumeInfo(AFSVolumeInfo *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Vid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Type = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Type0 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Type1 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Type2 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Type3 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Type4 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ServerCount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Server0 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Server1 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Server2 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Server3 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Server4 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Server5 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Server6 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Server7 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Port0 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Port1 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Port2 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Port3 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Port4 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Port5 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Port6 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Port7 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_AFSVolumeInfo(AFSVolumeInfo *o)
{
/* printing TSTRUCT (*o) */
printf(" .Vid = %d", (*o).Vid);
printf(" .Type = %d", (*o).Type);
printf(" .Type0 = %d", (*o).Type0);
printf(" .Type1 = %d", (*o).Type1);
printf(" .Type2 = %d", (*o).Type2);
printf(" .Type3 = %d", (*o).Type3);
printf(" .Type4 = %d", (*o).Type4);
printf(" .ServerCount = %d", (*o).ServerCount);
printf(" .Server0 = %d", (*o).Server0);
printf(" .Server1 = %d", (*o).Server1);
printf(" .Server2 = %d", (*o).Server2);
printf(" .Server3 = %d", (*o).Server3);
printf(" .Server4 = %d", (*o).Server4);
printf(" .Server5 = %d", (*o).Server5);
printf(" .Server6 = %d", (*o).Server6);
printf(" .Server7 = %d", (*o).Server7);
printf(" .Port0 = %d", (*o).Port0);
printf(" .Port1 = %d", (*o).Port1);
printf(" .Port2 = %d", (*o).Port2);
printf(" .Port3 = %d", (*o).Port3);
printf(" .Port4 = %d", (*o).Port4);
printf(" .Port5 = %d", (*o).Port5);
printf(" .Port6 = %d", (*o).Port6);
printf(" .Port7 = %d", (*o).Port7);
return;
}
void ydr_free_AFSVolumeInfo(AFSVolumeInfo *o)
{
return;
}
char *ydr_encode_afsUUID(const afsUUID *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).time_low); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).time_mid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).time_hi_and_version); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).clock_seq_hi_and_reserved); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).clock_seq_low); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ int32_t tmp = htonl((*o).node[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_afsUUID(afsUUID *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).time_low = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).time_mid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).time_hi_and_version = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).clock_seq_hi_and_reserved = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).clock_seq_low = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).node[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 6;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_afsUUID(afsUUID *o)
{
/* printing TSTRUCT (*o) */
printf(" .time_low = %d", (*o).time_low);
printf(" .time_mid = %d", (*o).time_mid);
printf(" .time_hi_and_version = %d", (*o).time_hi_and_version);
printf(" .clock_seq_hi_and_reserved = %d", (*o).clock_seq_hi_and_reserved);
printf(" .clock_seq_low = %d", (*o).clock_seq_low);
{
unsigned int i0;
/* printing ARRAY (*o).node */
for (i0 = 0; i0 < 6; ++i0) {
printf("  = %d", (*o).node[i0]);
if (i0 != 6 - 1) printf(",");
}
}

return;
}
void ydr_free_afsUUID(afsUUID *o)
{
{
int i0;
for(i0 = 0; i0 < 6;++i0){
}
}
return;
}
char *ydr_encode_Capabilities(const Capabilities *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp = htonl((*o).val[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_Capabilities(Capabilities *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).len > 196) goto fail;
if (((*o).len * sizeof(int32_t )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).len) goto fail;
}
(*o).val = (int32_t *)malloc(sizeof(int32_t ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
errno = EINVAL;
return NULL;}
void ydr_print_Capabilities(Capabilities *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
for (i0 = 0; i0 < (*o).len; ++i0) {
printf("  = %d", (*o).val[i0]);
if (i0 != (*o).len - 1) printf(",");
}
}
return;
}
void ydr_free_Capabilities(Capabilities *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
return;
}
char *ydr_encode_ViceIds(const ViceIds *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp = htonl((*o).val[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_ViceIds(ViceIds *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).len > 10) goto fail;
if (((*o).len * sizeof(int32_t )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).len) goto fail;
}
(*o).val = (int32_t *)malloc(sizeof(int32_t ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
errno = EINVAL;
return NULL;}
void ydr_print_ViceIds(ViceIds *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
for (i0 = 0; i0 < (*o).len; ++i0) {
printf("  = %d", (*o).val[i0]);
if (i0 != (*o).len - 1) printf(",");
}
}
return;
}
void ydr_free_ViceIds(ViceIds *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
return;
}
char *ydr_encode_IPAddrs(const IPAddrs *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp = htonl((*o).val[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_IPAddrs(IPAddrs *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).len > 10) goto fail;
if (((*o).len * sizeof(int32_t )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).len) goto fail;
}
(*o).val = (int32_t *)malloc(sizeof(int32_t ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
errno = EINVAL;
return NULL;}
void ydr_print_IPAddrs(IPAddrs *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
for (i0 = 0; i0 < (*o).len; ++i0) {
printf("  = %d", (*o).val[i0]);
if (i0 != (*o).len - 1) printf(",");
}
}
return;
}
void ydr_free_IPAddrs(IPAddrs *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
return;
}
