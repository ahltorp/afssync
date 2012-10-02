/* Generated from bos.xg */
#include "bos.h"

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
RCSID("bos.ydr.c generated from bos.xg with $Id: bos.ydr.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
char *ydr_encode_bozo_status(const bozo_status *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).goal); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).fileGoal); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).porcStartTime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).procStarts); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).lastAnyExit); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).lastErrorExit); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).errorCode); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).errorSignal); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).spare[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_bozo_status(bozo_status *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).goal = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).fileGoal = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).porcStartTime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).procStarts = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).lastAnyExit = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).lastErrorExit = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).errorCode = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).errorSignal = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spare[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_bozo_status(bozo_status *o)
{
/* printing TSTRUCT (*o) */
printf(" .goal = %d", (*o).goal);
printf(" .fileGoal = %d", (*o).fileGoal);
printf(" .porcStartTime = %d", (*o).porcStartTime);
printf(" .procStarts = %d", (*o).procStarts);
printf(" .lastAnyExit = %d", (*o).lastAnyExit);
printf(" .lastErrorExit = %d", (*o).lastErrorExit);
printf(" .errorCode = %d", (*o).errorCode);
printf(" .errorSignal = %d", (*o).errorSignal);
printf(" .flags = %d", (*o).flags);
{
unsigned int i0;
/* printing ARRAY (*o).spare */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).spare[i0]);
if (i0 != 8 - 1) printf(",");
}
}

return;
}
void ydr_free_bozo_status(bozo_status *o)
{
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
return;
}
char *ydr_encode_bozo_netKTime(const bozo_netKTime *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).mask); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).hour); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).min); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).sec); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).day); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_bozo_netKTime(bozo_netKTime *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).mask = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).hour = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).min = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).sec = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).day = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_bozo_netKTime(bozo_netKTime *o)
{
/* printing TSTRUCT (*o) */
printf(" .mask = %d", (*o).mask);
printf(" .hour = %d", (*o).hour);
printf(" .min = %d", (*o).min);
printf(" .sec = %d", (*o).sec);
printf(" .day = %d", (*o).day);
return;
}
void ydr_free_bozo_netKTime(bozo_netKTime *o)
{
return;
}
char *ydr_encode_bozo_key(const bozo_key *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).data[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_bozo_key(bozo_key *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).data[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_bozo_key(bozo_key *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).data */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).data[i0]);
if (i0 != 8 - 1) printf(",");
}
}

return;
}
void ydr_free_bozo_key(bozo_key *o)
{
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
return;
}
char *ydr_encode_bozo_keyInfo(const bozo_keyInfo *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).mod_sec); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).mod_usec); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).keyCheckSum); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spare2); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_bozo_keyInfo(bozo_keyInfo *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).mod_sec = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).mod_usec = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).keyCheckSum = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spare2 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_bozo_keyInfo(bozo_keyInfo *o)
{
/* printing TSTRUCT (*o) */
printf(" .mod_sec = %d", (*o).mod_sec);
printf(" .mod_usec = %d", (*o).mod_usec);
printf(" .keyCheckSum = %d", (*o).keyCheckSum);
printf(" .spare2 = %d", (*o).spare2);
return;
}
void ydr_free_bozo_keyInfo(bozo_keyInfo *o)
{
return;
}
