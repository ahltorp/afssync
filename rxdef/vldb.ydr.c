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
RCSID("vldb.ydr.c generated from vldb.xg with $Id: vldb.ydr.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
char *ydr_encode_bulk(const bulk *o, char *ptr, size_t *total_len)
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
const char *ydr_decode_bulk(bulk *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).len > 10000) goto fail;
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
void ydr_print_bulk(bulk *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
char *ptr = (*o).val;
printf("0x");for (i0 = 0; i0 < (*o).len; ++i0)
printf("%x", ptr[i0]);}
return;
}
void ydr_free_bulk(bulk *o)
{
free(((*o)).val);
return;
}
char *ydr_encode_vldbentry(const vldbentry *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ int32_t tmp = htonl((*o).name[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).volumeType); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).nServers); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).serverNumber[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).serverPartition[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).serverFlags[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp = htonl((*o).volumeId[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).cloneId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_vldbentry(vldbentry *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).name[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volumeType = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nServers = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverNumber[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverPartition[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverFlags[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volumeId[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).cloneId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 65;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_vldbentry(vldbentry *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).name */
for (i0 = 0; i0 < 65; ++i0) {
printf("  = %d", (*o).name[i0]);
if (i0 != 65 - 1) printf(",");
}
}

printf(" .volumeType = %d", (*o).volumeType);
printf(" .nServers = %d", (*o).nServers);
{
unsigned int i0;
/* printing ARRAY (*o).serverNumber */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).serverNumber[i0]);
if (i0 != 8 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).serverPartition */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).serverPartition[i0]);
if (i0 != 8 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).serverFlags */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).serverFlags[i0]);
if (i0 != 8 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).volumeId */
for (i0 = 0; i0 < 3; ++i0) {
printf("  = %d", (*o).volumeId[i0]);
if (i0 != 3 - 1) printf(",");
}
}

printf(" .cloneId = %d", (*o).cloneId);
printf(" .flags = %d", (*o).flags);
return;
}
void ydr_free_vldbentry(vldbentry *o)
{
{
int i0;
for(i0 = 0; i0 < 65;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
return;
}
char *ydr_encode_nvldbentry(const nvldbentry *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ int32_t tmp = htonl((*o).name[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).nServers); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ int32_t tmp = htonl((*o).serverNumber[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ int32_t tmp = htonl((*o).serverPartition[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ int32_t tmp = htonl((*o).serverFlags[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp = htonl((*o).volumeId[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).cloneId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).matchindex); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares2); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares3); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares4); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares5); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares6); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares7); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares8); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares9); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_nvldbentry(nvldbentry *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).name[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nServers = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverNumber[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverPartition[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverFlags[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volumeId[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).cloneId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).matchindex = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares2 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares3 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares4 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares5 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares6 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares7 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares8 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares9 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 65;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_nvldbentry(nvldbentry *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).name */
for (i0 = 0; i0 < 65; ++i0) {
printf("  = %d", (*o).name[i0]);
if (i0 != 65 - 1) printf(",");
}
}

printf(" .nServers = %d", (*o).nServers);
{
unsigned int i0;
/* printing ARRAY (*o).serverNumber */
for (i0 = 0; i0 < 13; ++i0) {
printf("  = %d", (*o).serverNumber[i0]);
if (i0 != 13 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).serverPartition */
for (i0 = 0; i0 < 13; ++i0) {
printf("  = %d", (*o).serverPartition[i0]);
if (i0 != 13 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).serverFlags */
for (i0 = 0; i0 < 13; ++i0) {
printf("  = %d", (*o).serverFlags[i0]);
if (i0 != 13 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).volumeId */
for (i0 = 0; i0 < 3; ++i0) {
printf("  = %d", (*o).volumeId[i0]);
if (i0 != 3 - 1) printf(",");
}
}

printf(" .cloneId = %d", (*o).cloneId);
printf(" .flags = %d", (*o).flags);
printf(" .matchindex = %d", (*o).matchindex);
printf(" .spares2 = %d", (*o).spares2);
printf(" .spares3 = %d", (*o).spares3);
printf(" .spares4 = %d", (*o).spares4);
printf(" .spares5 = %d", (*o).spares5);
printf(" .spares6 = %d", (*o).spares6);
printf(" .spares7 = %d", (*o).spares7);
printf(" .spares8 = %d", (*o).spares8);
printf(" .spares9 = %d", (*o).spares9);
return;
}
void ydr_free_nvldbentry(nvldbentry *o)
{
{
int i0;
for(i0 = 0; i0 < 65;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
return;
}
char *ydr_encode_vlentry(const vlentry *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp = htonl((*o).volumeId[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).LockAfsId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).LockTimestamp); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).cloneId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).AssociatedChain); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp = htonl((*o).nextIdHash[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).nextNameHash); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 2;++i0){
{ int32_t tmp = htonl((*o).spares1[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ int32_t tmp = htonl((*o).name[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).volumeType); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).serverNumber[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).serverPartition[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).serverFlags[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).RefCount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 1;++i0){
{ int32_t tmp = htonl((*o).spares2[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_vlentry(vlentry *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volumeId[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).LockAfsId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).LockTimestamp = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).cloneId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).AssociatedChain = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nextIdHash[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nextNameHash = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 2;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares1[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).name[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volumeType = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverNumber[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverPartition[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverFlags[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).RefCount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 1;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares2[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 2;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 1;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_vlentry(vlentry *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).volumeId */
for (i0 = 0; i0 < 3; ++i0) {
printf("  = %d", (*o).volumeId[i0]);
if (i0 != 3 - 1) printf(",");
}
}

printf(" .flags = %d", (*o).flags);
printf(" .LockAfsId = %d", (*o).LockAfsId);
printf(" .LockTimestamp = %d", (*o).LockTimestamp);
printf(" .cloneId = %d", (*o).cloneId);
printf(" .AssociatedChain = %d", (*o).AssociatedChain);
{
unsigned int i0;
/* printing ARRAY (*o).nextIdHash */
for (i0 = 0; i0 < 3; ++i0) {
printf("  = %d", (*o).nextIdHash[i0]);
if (i0 != 3 - 1) printf(",");
}
}

printf(" .nextNameHash = %d", (*o).nextNameHash);
{
unsigned int i0;
/* printing ARRAY (*o).spares1 */
for (i0 = 0; i0 < 2; ++i0) {
printf("  = %d", (*o).spares1[i0]);
if (i0 != 2 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).name */
for (i0 = 0; i0 < 65; ++i0) {
printf("  = %d", (*o).name[i0]);
if (i0 != 65 - 1) printf(",");
}
}

printf(" .volumeType = %d", (*o).volumeType);
{
unsigned int i0;
/* printing ARRAY (*o).serverNumber */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).serverNumber[i0]);
if (i0 != 8 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).serverPartition */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).serverPartition[i0]);
if (i0 != 8 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).serverFlags */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).serverFlags[i0]);
if (i0 != 8 - 1) printf(",");
}
}

printf(" .RefCount = %d", (*o).RefCount);
{
unsigned int i0;
/* printing ARRAY (*o).spares2 */
for (i0 = 0; i0 < 1; ++i0) {
printf("  = %d", (*o).spares2[i0]);
if (i0 != 1 - 1) printf(",");
}
}

return;
}
void ydr_free_vlentry(vlentry *o)
{
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 2;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 1;++i0){
}
}
return;
}
char *ydr_encode_disk_vlentry(const disk_vlentry *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp = htonl((*o).volumeId[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).cloneId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
unsigned len = strlen((*o).name);
if (*total_len < len) goto fail;
*total_len -= len;
{ int32_t tmp = htonl(len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
strncpy (ptr, (*o).name, len);
ptr += len + (4 - (len % 4)) % 4;
*total_len -= len + (4 - (len % 4)) % 4;
}
{ int32_t tmp = htonl((*o).serverNumber.len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).serverNumber.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).serverNumber.len;++i0){
{ int32_t tmp = htonl((*o).serverNumber.val[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).serverPartition.len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).serverPartition.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).serverPartition.len;++i0){
{ int32_t tmp = htonl((*o).serverPartition.val[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).serverFlags.len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).serverFlags.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).serverFlags.len;++i0){
{ int32_t tmp = htonl((*o).serverFlags.val[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_disk_vlentry(disk_vlentry *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volumeId[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).cloneId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
unsigned len;
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (*total_len < len) goto fail;
*total_len -= len;
if (len == (uint32_t) -1) {
goto fail;
}
((*o).name) = malloc(len + 1);
if (((*o).name) == NULL) {
goto fail;
}
memcpy (((*o).name), ptr, len);
((*o).name)[len] = '\0';
ptr += len + (4 - (len % 4)) % 4;
*total_len -= len + (4 - (len % 4)) % 4;
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverNumber.len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (((*o).serverNumber.len * sizeof(int32_t )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).serverNumber.len) goto fail;
}
(*o).serverNumber.val = (int32_t *)malloc(sizeof(int32_t ) * (*o).serverNumber.len);
if ((*o).serverNumber.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).serverNumber.len;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverNumber.val[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverPartition.len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (((*o).serverPartition.len * sizeof(int32_t )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).serverPartition.len) goto fail;
}
(*o).serverPartition.val = (int32_t *)malloc(sizeof(int32_t ) * (*o).serverPartition.len);
if ((*o).serverPartition.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).serverPartition.len;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverPartition.val[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverFlags.len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (((*o).serverFlags.len * sizeof(int32_t )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).serverFlags.len) goto fail;
}
(*o).serverFlags.val = (int32_t *)malloc(sizeof(int32_t ) * (*o).serverFlags.len);
if ((*o).serverFlags.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).serverFlags.len;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverFlags.val[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
{
unsigned int i0;
for (i0 = 0; i0 < (*o).serverNumber.len; ++i0) {
}
}
free(((*o).serverNumber).val);
{
unsigned int i0;
for (i0 = 0; i0 < (*o).serverPartition.len; ++i0) {
}
}
free(((*o).serverPartition).val);
{
unsigned int i0;
for (i0 = 0; i0 < (*o).serverFlags.len; ++i0) {
}
}
free(((*o).serverFlags).val);
errno = EINVAL;
return NULL;}
void ydr_print_disk_vlentry(disk_vlentry *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).volumeId */
for (i0 = 0; i0 < 3; ++i0) {
printf("  = %d", (*o).volumeId[i0]);
if (i0 != 3 - 1) printf(",");
}
}

printf(" .flags = %d", (*o).flags);
printf(" .cloneId = %d", (*o).cloneId);
/* printing TSTRING (*o).name */
printf(" .name = %s", (*o).name);
{
unsigned int i0;
/* printing YDR_TVARRAY (*o).serverNumber */
for (i0 = 0; i0 < (*o).serverNumber.len; ++i0) {
printf("  = %d", (*o).serverNumber.val[i0]);
if (i0 != (*o).serverNumber.len - 1) printf(",");
}
}

{
unsigned int i0;
/* printing YDR_TVARRAY (*o).serverPartition */
for (i0 = 0; i0 < (*o).serverPartition.len; ++i0) {
printf("  = %d", (*o).serverPartition.val[i0]);
if (i0 != (*o).serverPartition.len - 1) printf(",");
}
}

{
unsigned int i0;
/* printing YDR_TVARRAY (*o).serverFlags */
for (i0 = 0; i0 < (*o).serverFlags.len; ++i0) {
printf("  = %d", (*o).serverFlags.val[i0]);
if (i0 != (*o).serverFlags.len - 1) printf(",");
}
}

return;
}
void ydr_free_disk_vlentry(disk_vlentry *o)
{
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
{
unsigned int i0;
for (i0 = 0; i0 < (*o).serverNumber.len; ++i0) {
}
}
free(((*o).serverNumber).val);
{
unsigned int i0;
for (i0 = 0; i0 < (*o).serverPartition.len; ++i0) {
}
}
free(((*o).serverPartition).val);
{
unsigned int i0;
for (i0 = 0; i0 < (*o).serverFlags.len; ++i0) {
}
}
free(((*o).serverFlags).val);
return;
}
char *ydr_encode_vital_vlheader(const vital_vlheader *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).vldbversion); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).headersize); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).freePtr); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).eofPtr); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).allocs); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).frees); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).MaxVolumeId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp = htonl((*o).totalEntries[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_vital_vlheader(vital_vlheader *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).vldbversion = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).headersize = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).freePtr = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).eofPtr = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).allocs = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).frees = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).MaxVolumeId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).totalEntries[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_vital_vlheader(vital_vlheader *o)
{
/* printing TSTRUCT (*o) */
printf(" .vldbversion = %d", (*o).vldbversion);
printf(" .headersize = %d", (*o).headersize);
printf(" .freePtr = %d", (*o).freePtr);
printf(" .eofPtr = %d", (*o).eofPtr);
printf(" .allocs = %d", (*o).allocs);
printf(" .frees = %d", (*o).frees);
printf(" .MaxVolumeId = %d", (*o).MaxVolumeId);
{
unsigned int i0;
/* printing ARRAY (*o).totalEntries */
for (i0 = 0; i0 < 3; ++i0) {
printf("  = %d", (*o).totalEntries[i0]);
if (i0 != 3 - 1) printf(",");
}
}

return;
}
void ydr_free_vital_vlheader(vital_vlheader *o)
{
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
return;
}
char *ydr_encode_longarray(const longarray *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp = htonl((*o)[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_longarray(longarray *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o)[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_longarray(longarray *o)
{
{
unsigned int i0;
/* printing ARRAY (*o) */
for (i0 = 0; i0 < 3; ++i0) {
printf("  = %d", (*o)[i0]);
if (i0 != 3 - 1) printf(",");
}
}
return;
}
void ydr_free_longarray(longarray *o)
{
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
return;
}
char *ydr_encode_vlheader(const vlheader *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).vital_header.vldbversion); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).vital_header.headersize); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).vital_header.freePtr); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).vital_header.eofPtr); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).vital_header.allocs); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).vital_header.frees); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).vital_header.MaxVolumeId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp = htonl((*o).vital_header.totalEntries[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
{ int32_t tmp = htonl((*o).IpMappedAddr[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8191;++i0){
{ int32_t tmp = htonl((*o).VolnameHash[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8191;++i0){
{
int i1;
for(i1 = 0; i1 < 3;++i1){
{ int32_t tmp = htonl((*o).VolidHash[i0][i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_vlheader(vlheader *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).vital_header.vldbversion = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).vital_header.headersize = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).vital_header.freePtr = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).vital_header.eofPtr = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).vital_header.allocs = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).vital_header.frees = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).vital_header.MaxVolumeId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).vital_header.totalEntries[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).IpMappedAddr[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8191;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).VolnameHash[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8191;++i0){
{
int i1;
for(i1 = 0; i1 < 3;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).VolidHash[i0][i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8191;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8191;++i0){
{
int i1;
for(i1 = 0; i1 < 3;++i1){
}
}
}
}
errno = EINVAL;
return NULL;}
void ydr_print_vlheader(vlheader *o)
{
/* printing TSTRUCT (*o) */
/* printing TSTRUCT (*o).vital_header */
printf(" .vldbversion = %d", (*o).vital_header.vldbversion);
printf(" .headersize = %d", (*o).vital_header.headersize);
printf(" .freePtr = %d", (*o).vital_header.freePtr);
printf(" .eofPtr = %d", (*o).vital_header.eofPtr);
printf(" .allocs = %d", (*o).vital_header.allocs);
printf(" .frees = %d", (*o).vital_header.frees);
printf(" .MaxVolumeId = %d", (*o).vital_header.MaxVolumeId);
{
unsigned int i0;
/* printing ARRAY (*o).vital_header.totalEntries */
for (i0 = 0; i0 < 3; ++i0) {
printf("  = %d", (*o).vital_header.totalEntries[i0]);
if (i0 != 3 - 1) printf(",");
}
}


{
unsigned int i0;
/* printing ARRAY (*o).IpMappedAddr */
for (i0 = 0; i0 < 30; ++i0) {
printf("  = %d", (*o).IpMappedAddr[i0]);
if (i0 != 30 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).VolnameHash */
for (i0 = 0; i0 < 8191; ++i0) {
printf("  = %d", (*o).VolnameHash[i0]);
if (i0 != 8191 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).VolidHash */
for (i0 = 0; i0 < 8191; ++i0) {
{
unsigned int i1;
/* printing ARRAY (*o).VolidHash[i0] */
for (i1 = 0; i1 < 3; ++i1) {
printf("  = %d", (*o).VolidHash[i0][i1]);
if (i1 != 3 - 1) printf(",");
}
}

if (i0 != 8191 - 1) printf(",");
}
}

return;
}
void ydr_free_vlheader(vlheader *o)
{
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8191;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8191;++i0){
{
int i1;
for(i1 = 0; i1 < 3;++i1){
}
}
}
}
return;
}
char *ydr_encode_VldbUpdateEntry(const VldbUpdateEntry *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).Mask); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ int32_t tmp = htonl((*o).name[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).volumeType); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ReadOnlyId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).BackupId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).cloneid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).nModifiedRepsites); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).RepsitesMask[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).RepsitesTargetServer[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).RepsitesTargetPart[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).RepsitesNewServer[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).RepsitesNewPart[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).RepsitesNewFlags[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_VldbUpdateEntry(VldbUpdateEntry *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Mask = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).name[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volumeType = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ReadOnlyId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).BackupId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).cloneid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nModifiedRepsites = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).RepsitesMask[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).RepsitesTargetServer[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).RepsitesTargetPart[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).RepsitesNewServer[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).RepsitesNewPart[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).RepsitesNewFlags[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 65;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_VldbUpdateEntry(VldbUpdateEntry *o)
{
/* printing TSTRUCT (*o) */
printf(" .Mask = %d", (*o).Mask);
{
unsigned int i0;
/* printing ARRAY (*o).name */
for (i0 = 0; i0 < 65; ++i0) {
printf("  = %d", (*o).name[i0]);
if (i0 != 65 - 1) printf(",");
}
}

printf(" .volumeType = %d", (*o).volumeType);
printf(" .flags = %d", (*o).flags);
printf(" .ReadOnlyId = %d", (*o).ReadOnlyId);
printf(" .BackupId = %d", (*o).BackupId);
printf(" .cloneid = %d", (*o).cloneid);
printf(" .nModifiedRepsites = %d", (*o).nModifiedRepsites);
{
unsigned int i0;
/* printing ARRAY (*o).RepsitesMask */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).RepsitesMask[i0]);
if (i0 != 8 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).RepsitesTargetServer */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).RepsitesTargetServer[i0]);
if (i0 != 8 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).RepsitesTargetPart */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).RepsitesTargetPart[i0]);
if (i0 != 8 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).RepsitesNewServer */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).RepsitesNewServer[i0]);
if (i0 != 8 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).RepsitesNewPart */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).RepsitesNewPart[i0]);
if (i0 != 8 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).RepsitesNewFlags */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).RepsitesNewFlags[i0]);
if (i0 != 8 - 1) printf(",");
}
}

return;
}
void ydr_free_VldbUpdateEntry(VldbUpdateEntry *o)
{
{
int i0;
for(i0 = 0; i0 < 65;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
return;
}
char *ydr_encode_VldbListByAttributes(const VldbListByAttributes *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).Mask); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).server); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).partition); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).volumetype); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).volumeid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).flag); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_VldbListByAttributes(VldbListByAttributes *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Mask = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).server = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).partition = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volumetype = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volumeid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).flag = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_VldbListByAttributes(VldbListByAttributes *o)
{
/* printing TSTRUCT (*o) */
printf(" .Mask = %d", (*o).Mask);
printf(" .server = %d", (*o).server);
printf(" .partition = %d", (*o).partition);
printf(" .volumetype = %d", (*o).volumetype);
printf(" .volumeid = %d", (*o).volumeid);
printf(" .flag = %d", (*o).flag);
return;
}
void ydr_free_VldbListByAttributes(VldbListByAttributes *o)
{
return;
}
char *ydr_encode_uvldbentry(const uvldbentry *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ int32_t tmp = htonl((*o).name[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).nServers); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ int32_t tmp = htonl((*o).serverNumber[i0].time_low); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).serverNumber[i0].time_mid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).serverNumber[i0].time_hi_and_version); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).serverNumber[i0].clock_seq_hi_and_reserved); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).serverNumber[i0].clock_seq_low); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ int32_t tmp = htonl((*o).serverNumber[i0].node[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ int32_t tmp = htonl((*o).serverUnique[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ int32_t tmp = htonl((*o).serverPartition[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ int32_t tmp = htonl((*o).serverFlags[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp = htonl((*o).volumeId[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).cloneId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares1); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares2); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares3); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares4); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares5); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares6); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares7); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares8); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spares9); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_uvldbentry(uvldbentry *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).name[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nServers = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverNumber[i0].time_low = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverNumber[i0].time_mid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverNumber[i0].time_hi_and_version = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverNumber[i0].clock_seq_hi_and_reserved = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverNumber[i0].clock_seq_low = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverNumber[i0].node[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverUnique[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverPartition[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).serverFlags[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volumeId[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).cloneId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares1 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares2 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares3 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares4 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares5 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares6 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares7 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares8 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spares9 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 65;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{
int i1;
for(i1 = 0; i1 < 6;++i1){
}
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_uvldbentry(uvldbentry *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).name */
for (i0 = 0; i0 < 65; ++i0) {
printf("  = %d", (*o).name[i0]);
if (i0 != 65 - 1) printf(",");
}
}

printf(" .nServers = %d", (*o).nServers);
{
unsigned int i0;
/* printing ARRAY (*o).serverNumber */
for (i0 = 0; i0 < 13; ++i0) {
/* printing TSTRUCT (*o).serverNumber[i0] */
printf(" .time_low = %d", (*o).serverNumber[i0].time_low);
printf(" .time_mid = %d", (*o).serverNumber[i0].time_mid);
printf(" .time_hi_and_version = %d", (*o).serverNumber[i0].time_hi_and_version);
printf(" .clock_seq_hi_and_reserved = %d", (*o).serverNumber[i0].clock_seq_hi_and_reserved);
printf(" .clock_seq_low = %d", (*o).serverNumber[i0].clock_seq_low);
{
unsigned int i1;
/* printing ARRAY (*o).serverNumber[i0].node */
for (i1 = 0; i1 < 6; ++i1) {
printf("  = %d", (*o).serverNumber[i0].node[i1]);
if (i1 != 6 - 1) printf(",");
}
}


if (i0 != 13 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).serverUnique */
for (i0 = 0; i0 < 13; ++i0) {
printf("  = %d", (*o).serverUnique[i0]);
if (i0 != 13 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).serverPartition */
for (i0 = 0; i0 < 13; ++i0) {
printf("  = %d", (*o).serverPartition[i0]);
if (i0 != 13 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).serverFlags */
for (i0 = 0; i0 < 13; ++i0) {
printf("  = %d", (*o).serverFlags[i0]);
if (i0 != 13 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).volumeId */
for (i0 = 0; i0 < 3; ++i0) {
printf("  = %d", (*o).volumeId[i0]);
if (i0 != 3 - 1) printf(",");
}
}

printf(" .cloneId = %d", (*o).cloneId);
printf(" .flags = %d", (*o).flags);
printf(" .spares1 = %d", (*o).spares1);
printf(" .spares2 = %d", (*o).spares2);
printf(" .spares3 = %d", (*o).spares3);
printf(" .spares4 = %d", (*o).spares4);
printf(" .spares5 = %d", (*o).spares5);
printf(" .spares6 = %d", (*o).spares6);
printf(" .spares7 = %d", (*o).spares7);
printf(" .spares8 = %d", (*o).spares8);
printf(" .spares9 = %d", (*o).spares9);
return;
}
void ydr_free_uvldbentry(uvldbentry *o)
{
{
int i0;
for(i0 = 0; i0 < 65;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
{
int i1;
for(i1 = 0; i1 < 6;++i1){
}
}
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 13;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 3;++i0){
}
}
return;
}
char *ydr_encode_vldstats(const vldstats *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).start_time); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
{ int32_t tmp = htonl((*o).requests[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
{ int32_t tmp = htonl((*o).aborts[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ int32_t tmp = htonl((*o).reserved[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_vldstats(vldstats *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).start_time = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).requests[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).aborts[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).reserved[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 30;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_vldstats(vldstats *o)
{
/* printing TSTRUCT (*o) */
printf(" .start_time = %d", (*o).start_time);
{
unsigned int i0;
/* printing ARRAY (*o).requests */
for (i0 = 0; i0 < 30; ++i0) {
printf("  = %d", (*o).requests[i0]);
if (i0 != 30 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).aborts */
for (i0 = 0; i0 < 30; ++i0) {
printf("  = %d", (*o).aborts[i0]);
if (i0 != 30 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).reserved */
for (i0 = 0; i0 < 5; ++i0) {
printf("  = %d", (*o).reserved[i0]);
if (i0 != 5 - 1) printf(",");
}
}

return;
}
void ydr_free_vldstats(vldstats *o)
{
{
int i0;
for(i0 = 0; i0 < 30;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
}
}
return;
}
char *ydr_encode_bulkentries(const bulkentries *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct vldbentry );
if (overI < (*o).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{
int i1;
for(i1 = 0; i1 < 65;++i1){
{ int32_t tmp = htonl((*o).val[i0].name[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).val[i0].volumeType); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].nServers); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
{ int32_t tmp = htonl((*o).val[i0].serverNumber[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
{ int32_t tmp = htonl((*o).val[i0].serverPartition[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
{ int32_t tmp = htonl((*o).val[i0].serverFlags[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
{ int32_t tmp = htonl((*o).val[i0].volumeId[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).val[i0].cloneId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_bulkentries(bulkentries *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (((*o).len * sizeof(struct vldbentry )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct vldbentry );
if (overI < (*o).len) goto fail;
}
(*o).val = (struct vldbentry *)malloc(sizeof(struct vldbentry ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{
int i1;
for(i1 = 0; i1 < 65;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].name[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].volumeType = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].nServers = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverNumber[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverPartition[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverFlags[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].volumeId[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].cloneId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
{
int i1;
for(i1 = 0; i1 < 65;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
}
}
}
}
free(((*o)).val);
errno = EINVAL;
return NULL;}
void ydr_print_bulkentries(bulkentries *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
for (i0 = 0; i0 < (*o).len; ++i0) {
/* printing TSTRUCT (*o).val[i0] */
{
unsigned int i1;
/* printing ARRAY (*o).val[i0].name */
for (i1 = 0; i1 < 65; ++i1) {
printf("  = %d", (*o).val[i0].name[i1]);
if (i1 != 65 - 1) printf(",");
}
}

printf(" .volumeType = %d", (*o).val[i0].volumeType);
printf(" .nServers = %d", (*o).val[i0].nServers);
{
unsigned int i1;
/* printing ARRAY (*o).val[i0].serverNumber */
for (i1 = 0; i1 < 8; ++i1) {
printf("  = %d", (*o).val[i0].serverNumber[i1]);
if (i1 != 8 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].serverPartition */
for (i1 = 0; i1 < 8; ++i1) {
printf("  = %d", (*o).val[i0].serverPartition[i1]);
if (i1 != 8 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].serverFlags */
for (i1 = 0; i1 < 8; ++i1) {
printf("  = %d", (*o).val[i0].serverFlags[i1]);
if (i1 != 8 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].volumeId */
for (i1 = 0; i1 < 3; ++i1) {
printf("  = %d", (*o).val[i0].volumeId[i1]);
if (i1 != 3 - 1) printf(",");
}
}

printf(" .cloneId = %d", (*o).val[i0].cloneId);
printf(" .flags = %d", (*o).val[i0].flags);

if (i0 != (*o).len - 1) printf(",");
}
}
return;
}
void ydr_free_bulkentries(bulkentries *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
{
int i1;
for(i1 = 0; i1 < 65;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 8;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
}
}
}
}
free(((*o)).val);
return;
}
char *ydr_encode_nbulkentries(const nbulkentries *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct nvldbentry );
if (overI < (*o).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{
int i1;
for(i1 = 0; i1 < 65;++i1){
{ int32_t tmp = htonl((*o).val[i0].name[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).val[i0].nServers); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ int32_t tmp = htonl((*o).val[i0].serverNumber[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ int32_t tmp = htonl((*o).val[i0].serverPartition[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ int32_t tmp = htonl((*o).val[i0].serverFlags[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
{ int32_t tmp = htonl((*o).val[i0].volumeId[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).val[i0].cloneId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].matchindex); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares2); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares3); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares4); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares5); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares6); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares7); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares8); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares9); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_nbulkentries(nbulkentries *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (((*o).len * sizeof(struct nvldbentry )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct nvldbentry );
if (overI < (*o).len) goto fail;
}
(*o).val = (struct nvldbentry *)malloc(sizeof(struct nvldbentry ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{
int i1;
for(i1 = 0; i1 < 65;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].name[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].nServers = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverNumber[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverPartition[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverFlags[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].volumeId[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].cloneId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].matchindex = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares2 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares3 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares4 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares5 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares6 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares7 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares8 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares9 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
{
int i1;
for(i1 = 0; i1 < 65;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
}
}
}
}
free(((*o)).val);
errno = EINVAL;
return NULL;}
void ydr_print_nbulkentries(nbulkentries *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
for (i0 = 0; i0 < (*o).len; ++i0) {
/* printing TSTRUCT (*o).val[i0] */
{
unsigned int i1;
/* printing ARRAY (*o).val[i0].name */
for (i1 = 0; i1 < 65; ++i1) {
printf("  = %d", (*o).val[i0].name[i1]);
if (i1 != 65 - 1) printf(",");
}
}

printf(" .nServers = %d", (*o).val[i0].nServers);
{
unsigned int i1;
/* printing ARRAY (*o).val[i0].serverNumber */
for (i1 = 0; i1 < 13; ++i1) {
printf("  = %d", (*o).val[i0].serverNumber[i1]);
if (i1 != 13 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].serverPartition */
for (i1 = 0; i1 < 13; ++i1) {
printf("  = %d", (*o).val[i0].serverPartition[i1]);
if (i1 != 13 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].serverFlags */
for (i1 = 0; i1 < 13; ++i1) {
printf("  = %d", (*o).val[i0].serverFlags[i1]);
if (i1 != 13 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].volumeId */
for (i1 = 0; i1 < 3; ++i1) {
printf("  = %d", (*o).val[i0].volumeId[i1]);
if (i1 != 3 - 1) printf(",");
}
}

printf(" .cloneId = %d", (*o).val[i0].cloneId);
printf(" .flags = %d", (*o).val[i0].flags);
printf(" .matchindex = %d", (*o).val[i0].matchindex);
printf(" .spares2 = %d", (*o).val[i0].spares2);
printf(" .spares3 = %d", (*o).val[i0].spares3);
printf(" .spares4 = %d", (*o).val[i0].spares4);
printf(" .spares5 = %d", (*o).val[i0].spares5);
printf(" .spares6 = %d", (*o).val[i0].spares6);
printf(" .spares7 = %d", (*o).val[i0].spares7);
printf(" .spares8 = %d", (*o).val[i0].spares8);
printf(" .spares9 = %d", (*o).val[i0].spares9);

if (i0 != (*o).len - 1) printf(",");
}
}
return;
}
void ydr_free_nbulkentries(nbulkentries *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
{
int i1;
for(i1 = 0; i1 < 65;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
}
}
}
}
free(((*o)).val);
return;
}
char *ydr_encode_ubulkentries(const ubulkentries *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct uvldbentry );
if (overI < (*o).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{
int i1;
for(i1 = 0; i1 < 65;++i1){
{ int32_t tmp = htonl((*o).val[i0].name[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).val[i0].nServers); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ int32_t tmp = htonl((*o).val[i0].serverNumber[i1].time_low); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].serverNumber[i1].time_mid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].serverNumber[i1].time_hi_and_version); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].serverNumber[i1].clock_seq_hi_and_reserved); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].serverNumber[i1].clock_seq_low); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i2;
for(i2 = 0; i2 < 6;++i2){
{ int32_t tmp = htonl((*o).val[i0].serverNumber[i1].node[i2]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ int32_t tmp = htonl((*o).val[i0].serverUnique[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ int32_t tmp = htonl((*o).val[i0].serverPartition[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ int32_t tmp = htonl((*o).val[i0].serverFlags[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
{ int32_t tmp = htonl((*o).val[i0].volumeId[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).val[i0].cloneId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares1); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares2); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares3); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares4); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares5); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares6); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares7); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares8); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spares9); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_ubulkentries(ubulkentries *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (((*o).len * sizeof(struct uvldbentry )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct uvldbentry );
if (overI < (*o).len) goto fail;
}
(*o).val = (struct uvldbentry *)malloc(sizeof(struct uvldbentry ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{
int i1;
for(i1 = 0; i1 < 65;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].name[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].nServers = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverNumber[i1].time_low = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverNumber[i1].time_mid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverNumber[i1].time_hi_and_version = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverNumber[i1].clock_seq_hi_and_reserved = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverNumber[i1].clock_seq_low = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i2;
for(i2 = 0; i2 < 6;++i2){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverNumber[i1].node[i2] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverUnique[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverPartition[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].serverFlags[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].volumeId[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].cloneId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares1 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares2 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares3 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares4 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares5 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares6 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares7 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares8 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spares9 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
{
int i1;
for(i1 = 0; i1 < 65;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{
int i2;
for(i2 = 0; i2 < 6;++i2){
}
}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
}
}
}
}
free(((*o)).val);
errno = EINVAL;
return NULL;}
void ydr_print_ubulkentries(ubulkentries *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
for (i0 = 0; i0 < (*o).len; ++i0) {
/* printing TSTRUCT (*o).val[i0] */
{
unsigned int i1;
/* printing ARRAY (*o).val[i0].name */
for (i1 = 0; i1 < 65; ++i1) {
printf("  = %d", (*o).val[i0].name[i1]);
if (i1 != 65 - 1) printf(",");
}
}

printf(" .nServers = %d", (*o).val[i0].nServers);
{
unsigned int i1;
/* printing ARRAY (*o).val[i0].serverNumber */
for (i1 = 0; i1 < 13; ++i1) {
/* printing TSTRUCT (*o).val[i0].serverNumber[i1] */
printf(" .time_low = %d", (*o).val[i0].serverNumber[i1].time_low);
printf(" .time_mid = %d", (*o).val[i0].serverNumber[i1].time_mid);
printf(" .time_hi_and_version = %d", (*o).val[i0].serverNumber[i1].time_hi_and_version);
printf(" .clock_seq_hi_and_reserved = %d", (*o).val[i0].serverNumber[i1].clock_seq_hi_and_reserved);
printf(" .clock_seq_low = %d", (*o).val[i0].serverNumber[i1].clock_seq_low);
{
unsigned int i2;
/* printing ARRAY (*o).val[i0].serverNumber[i1].node */
for (i2 = 0; i2 < 6; ++i2) {
printf("  = %d", (*o).val[i0].serverNumber[i1].node[i2]);
if (i2 != 6 - 1) printf(",");
}
}


if (i1 != 13 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].serverUnique */
for (i1 = 0; i1 < 13; ++i1) {
printf("  = %d", (*o).val[i0].serverUnique[i1]);
if (i1 != 13 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].serverPartition */
for (i1 = 0; i1 < 13; ++i1) {
printf("  = %d", (*o).val[i0].serverPartition[i1]);
if (i1 != 13 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].serverFlags */
for (i1 = 0; i1 < 13; ++i1) {
printf("  = %d", (*o).val[i0].serverFlags[i1]);
if (i1 != 13 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].volumeId */
for (i1 = 0; i1 < 3; ++i1) {
printf("  = %d", (*o).val[i0].volumeId[i1]);
if (i1 != 3 - 1) printf(",");
}
}

printf(" .cloneId = %d", (*o).val[i0].cloneId);
printf(" .flags = %d", (*o).val[i0].flags);
printf(" .spares1 = %d", (*o).val[i0].spares1);
printf(" .spares2 = %d", (*o).val[i0].spares2);
printf(" .spares3 = %d", (*o).val[i0].spares3);
printf(" .spares4 = %d", (*o).val[i0].spares4);
printf(" .spares5 = %d", (*o).val[i0].spares5);
printf(" .spares6 = %d", (*o).val[i0].spares6);
printf(" .spares7 = %d", (*o).val[i0].spares7);
printf(" .spares8 = %d", (*o).val[i0].spares8);
printf(" .spares9 = %d", (*o).val[i0].spares9);

if (i0 != (*o).len - 1) printf(",");
}
}
return;
}
void ydr_free_ubulkentries(ubulkentries *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
{
int i1;
for(i1 = 0; i1 < 65;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
{
int i2;
for(i2 = 0; i2 < 6;++i2){
}
}
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 13;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 3;++i1){
}
}
}
}
free(((*o)).val);
return;
}
char *ydr_encode_bulkaddrs(const bulkaddrs *o, char *ptr, size_t *total_len)
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
const char *ydr_decode_bulkaddrs(bulkaddrs *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).len > 1024) goto fail;
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
void ydr_print_bulkaddrs(bulkaddrs *o)
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
void ydr_free_bulkaddrs(bulkaddrs *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
return;
}
char *ydr_encode_ListAddrByAttributes(const ListAddrByAttributes *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).Mask); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ipaddr); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).index); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spare); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).uuid.time_low); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).uuid.time_mid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).uuid.time_hi_and_version); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).uuid.clock_seq_hi_and_reserved); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).uuid.clock_seq_low); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ int32_t tmp = htonl((*o).uuid.node[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_ListAddrByAttributes(ListAddrByAttributes *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Mask = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ipaddr = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).index = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spare = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).uuid.time_low = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).uuid.time_mid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).uuid.time_hi_and_version = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).uuid.clock_seq_hi_and_reserved = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).uuid.clock_seq_low = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).uuid.node[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
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
void ydr_print_ListAddrByAttributes(ListAddrByAttributes *o)
{
/* printing TSTRUCT (*o) */
printf(" .Mask = %d", (*o).Mask);
printf(" .ipaddr = %d", (*o).ipaddr);
printf(" .index = %d", (*o).index);
printf(" .spare = %d", (*o).spare);
/* printing TSTRUCT (*o).uuid */
printf(" .time_low = %d", (*o).uuid.time_low);
printf(" .time_mid = %d", (*o).uuid.time_mid);
printf(" .time_hi_and_version = %d", (*o).uuid.time_hi_and_version);
printf(" .clock_seq_hi_and_reserved = %d", (*o).uuid.clock_seq_hi_and_reserved);
printf(" .clock_seq_low = %d", (*o).uuid.clock_seq_low);
{
unsigned int i0;
/* printing ARRAY (*o).uuid.node */
for (i0 = 0; i0 < 6; ++i0) {
printf("  = %d", (*o).uuid.node[i0]);
if (i0 != 6 - 1) printf(",");
}
}


return;
}
void ydr_free_ListAddrByAttributes(ListAddrByAttributes *o)
{
{
int i0;
for(i0 = 0; i0 < 6;++i0){
}
}
return;
}
char *ydr_encode_VL_Callback(const VL_Callback *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).version); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).expiration_time); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).time); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).handle); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_VL_Callback(VL_Callback *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).version = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).expiration_time = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).time = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).handle = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_VL_Callback(VL_Callback *o)
{
/* printing TSTRUCT (*o) */
printf(" .version = %d", (*o).version);
printf(" .expiration_time = %d", (*o).expiration_time);
printf(" .time = %d", (*o).time);
printf(" .handle = %d", (*o).handle);
return;
}
void ydr_free_VL_Callback(VL_Callback *o)
{
return;
}
