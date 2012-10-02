/* Generated from pts.xg */
#include "pts.h"

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
RCSID("pts.ydr.c generated from pts.xg with $Id: pts.ydr.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
char *ydr_encode_prheader(const prheader *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).version); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).headerSize); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).freePtr); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).eofPtr); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).maxGroup); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).maxID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).maxForeign); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).maxInst); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).orphan); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).usercount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).groupcount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).foreigncount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).instcount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ int32_t tmp = htonl((*o).reserved[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8191;++i0){
{ int32_t tmp = htonl((*o).nameHash[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8191;++i0){
{ int32_t tmp = htonl((*o).idHash[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_prheader(prheader *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).version = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).headerSize = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).freePtr = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).eofPtr = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).maxGroup = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).maxID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).maxForeign = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).maxInst = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).orphan = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).usercount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).groupcount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).foreigncount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).instcount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).reserved[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8191;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nameHash[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 8191;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).idHash[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 5;++i0){
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
}
}
errno = EINVAL;
return NULL;}
void ydr_print_prheader(prheader *o)
{
/* printing TSTRUCT (*o) */
printf(" .version = %d", (*o).version);
printf(" .headerSize = %d", (*o).headerSize);
printf(" .freePtr = %d", (*o).freePtr);
printf(" .eofPtr = %d", (*o).eofPtr);
printf(" .maxGroup = %d", (*o).maxGroup);
printf(" .maxID = %d", (*o).maxID);
printf(" .maxForeign = %d", (*o).maxForeign);
printf(" .maxInst = %d", (*o).maxInst);
printf(" .orphan = %d", (*o).orphan);
printf(" .usercount = %d", (*o).usercount);
printf(" .groupcount = %d", (*o).groupcount);
printf(" .foreigncount = %d", (*o).foreigncount);
printf(" .instcount = %d", (*o).instcount);
{
unsigned int i0;
/* printing ARRAY (*o).reserved */
for (i0 = 0; i0 < 5; ++i0) {
printf("  = %d", (*o).reserved[i0]);
if (i0 != 5 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).nameHash */
for (i0 = 0; i0 < 8191; ++i0) {
printf("  = %d", (*o).nameHash[i0]);
if (i0 != 8191 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).idHash */
for (i0 = 0; i0 < 8191; ++i0) {
printf("  = %d", (*o).idHash[i0]);
if (i0 != 8191 - 1) printf(",");
}
}

return;
}
void ydr_free_prheader(prheader *o)
{
{
int i0;
for(i0 = 0; i0 < 5;++i0){
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
}
}
return;
}
char *ydr_encode_prheader_disk(const prheader_disk *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).version); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).headerSize); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).maxGroup); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).maxID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).orphan.len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).orphan.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).orphan.len;++i0){
{ int32_t tmp = htonl((*o).orphan.val[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).usercount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).groupcount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_prheader_disk(prheader_disk *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).version = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).headerSize = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).maxGroup = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).maxID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).orphan.len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (((*o).orphan.len * sizeof(int32_t )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).orphan.len) goto fail;
}
(*o).orphan.val = (int32_t *)malloc(sizeof(int32_t ) * (*o).orphan.len);
if ((*o).orphan.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).orphan.len;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).orphan.val[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).usercount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).groupcount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
{
unsigned int i0;
for (i0 = 0; i0 < (*o).orphan.len; ++i0) {
}
}
free(((*o).orphan).val);
errno = EINVAL;
return NULL;}
void ydr_print_prheader_disk(prheader_disk *o)
{
/* printing TSTRUCT (*o) */
printf(" .version = %d", (*o).version);
printf(" .headerSize = %d", (*o).headerSize);
printf(" .maxGroup = %d", (*o).maxGroup);
printf(" .maxID = %d", (*o).maxID);
{
unsigned int i0;
/* printing YDR_TVARRAY (*o).orphan */
for (i0 = 0; i0 < (*o).orphan.len; ++i0) {
printf("  = %d", (*o).orphan.val[i0]);
if (i0 != (*o).orphan.len - 1) printf(",");
}
}

printf(" .usercount = %d", (*o).usercount);
printf(" .groupcount = %d", (*o).groupcount);
return;
}
void ydr_free_prheader_disk(prheader_disk *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).orphan.len; ++i0) {
}
}
free(((*o).orphan).val);
return;
}
char *ydr_encode_prentry(const prentry *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).id); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).cellid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).next); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ int32_t tmp = htonl((*o).reserved[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 10;++i0){
{ int32_t tmp = htonl((*o).entries[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).nextID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).nextName); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).owner); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).creator); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ngroups); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).nusers); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).count); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).instance); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).owned); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).nextOwned); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).parent); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).sibling); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).child); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp = htonl((*o).name[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_prentry(prentry *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).id = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).cellid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).next = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).reserved[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 10;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).entries[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nextID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nextName = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).owner = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).creator = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ngroups = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nusers = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).count = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).instance = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).owned = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nextOwned = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).parent = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).sibling = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).child = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).name[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 5;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 10;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_prentry(prentry *o)
{
/* printing TSTRUCT (*o) */
printf(" .flags = %d", (*o).flags);
printf(" .id = %d", (*o).id);
printf(" .cellid = %d", (*o).cellid);
printf(" .next = %d", (*o).next);
{
unsigned int i0;
/* printing ARRAY (*o).reserved */
for (i0 = 0; i0 < 5; ++i0) {
printf("  = %d", (*o).reserved[i0]);
if (i0 != 5 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).entries */
for (i0 = 0; i0 < 10; ++i0) {
printf("  = %d", (*o).entries[i0]);
if (i0 != 10 - 1) printf(",");
}
}

printf(" .nextID = %d", (*o).nextID);
printf(" .nextName = %d", (*o).nextName);
printf(" .owner = %d", (*o).owner);
printf(" .creator = %d", (*o).creator);
printf(" .ngroups = %d", (*o).ngroups);
printf(" .nusers = %d", (*o).nusers);
printf(" .count = %d", (*o).count);
printf(" .instance = %d", (*o).instance);
printf(" .owned = %d", (*o).owned);
printf(" .nextOwned = %d", (*o).nextOwned);
printf(" .parent = %d", (*o).parent);
printf(" .sibling = %d", (*o).sibling);
printf(" .child = %d", (*o).child);
{
unsigned int i0;
/* printing ARRAY (*o).name */
for (i0 = 0; i0 < 64; ++i0) {
printf("  = %d", (*o).name[i0]);
if (i0 != 64 - 1) printf(",");
}
}

return;
}
void ydr_free_prentry(prentry *o)
{
{
int i0;
for(i0 = 0; i0 < 5;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 10;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
return;
}
char *ydr_encode_prentry_disk(const prentry_disk *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).id); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).cellid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).owner); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).creator); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ngroups); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).owned.len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).owned.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).owned.len;++i0){
{ int32_t tmp = htonl((*o).owned.val[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
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
{ int32_t tmp = htonl((*o).entries.len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).entries.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).entries.len;++i0){
{ int32_t tmp = htonl((*o).entries.val[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_prentry_disk(prentry_disk *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).id = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).cellid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).owner = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).creator = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ngroups = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).owned.len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).owned.len > 5000) goto fail;
if (((*o).owned.len * sizeof(int32_t )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).owned.len) goto fail;
}
(*o).owned.val = (int32_t *)malloc(sizeof(int32_t ) * (*o).owned.len);
if ((*o).owned.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).owned.len;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).owned.val[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
unsigned len;
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (*total_len < len) goto fail;
*total_len -= len;
if(len >= 64)
goto fail;
memcpy (((*o).name), ptr, len);
((*o).name)[len] = '\0';
ptr += len + (4 - (len % 4)) % 4;
*total_len -= len + (4 - (len % 4)) % 4;
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).entries.len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).entries.len > 5000) goto fail;
if (((*o).entries.len * sizeof(int32_t )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*o).entries.len) goto fail;
}
(*o).entries.val = (int32_t *)malloc(sizeof(int32_t ) * (*o).entries.len);
if ((*o).entries.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).entries.len;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).entries.val[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
unsigned int i0;
for (i0 = 0; i0 < (*o).owned.len; ++i0) {
}
}
free(((*o).owned).val);
{
unsigned int i0;
for (i0 = 0; i0 < (*o).entries.len; ++i0) {
}
}
free(((*o).entries).val);
errno = EINVAL;
return NULL;}
void ydr_print_prentry_disk(prentry_disk *o)
{
/* printing TSTRUCT (*o) */
printf(" .flags = %d", (*o).flags);
printf(" .id = %d", (*o).id);
printf(" .cellid = %d", (*o).cellid);
printf(" .owner = %d", (*o).owner);
printf(" .creator = %d", (*o).creator);
printf(" .ngroups = %d", (*o).ngroups);
{
unsigned int i0;
/* printing YDR_TVARRAY (*o).owned */
for (i0 = 0; i0 < (*o).owned.len; ++i0) {
printf("  = %d", (*o).owned.val[i0]);
if (i0 != (*o).owned.len - 1) printf(",");
}
}

/* printing TSTRING (*o).name */
printf(" .name = %s", (*o).name);
{
unsigned int i0;
/* printing YDR_TVARRAY (*o).entries */
for (i0 = 0; i0 < (*o).entries.len; ++i0) {
printf("  = %d", (*o).entries.val[i0]);
if (i0 != (*o).entries.len - 1) printf(",");
}
}

return;
}
void ydr_free_prentry_disk(prentry_disk *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).owned.len; ++i0) {
}
}
free(((*o).owned).val);
{
unsigned int i0;
for (i0 = 0; i0 < (*o).entries.len; ++i0) {
}
}
free(((*o).entries).val);
return;
}
char *ydr_encode_prdebugentry(const prdebugentry *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).id); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).cellid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).next); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ int32_t tmp = htonl((*o).reserved[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 10;++i0){
{ int32_t tmp = htonl((*o).entries[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).nextID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).nextname); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).owner); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).creator); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ngroups); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).nusers); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).count); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).instance); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).owned); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).nextOwned); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).parent); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).sibling); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).child); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp = htonl((*o).name[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_prdebugentry(prdebugentry *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).id = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).cellid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).next = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).reserved[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 10;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).entries[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nextID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nextname = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).owner = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).creator = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ngroups = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nusers = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).count = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).instance = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).owned = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nextOwned = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).parent = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).sibling = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).child = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).name[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 5;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 10;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_prdebugentry(prdebugentry *o)
{
/* printing TSTRUCT (*o) */
printf(" .flags = %d", (*o).flags);
printf(" .id = %d", (*o).id);
printf(" .cellid = %d", (*o).cellid);
printf(" .next = %d", (*o).next);
{
unsigned int i0;
/* printing ARRAY (*o).reserved */
for (i0 = 0; i0 < 5; ++i0) {
printf("  = %d", (*o).reserved[i0]);
if (i0 != 5 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).entries */
for (i0 = 0; i0 < 10; ++i0) {
printf("  = %d", (*o).entries[i0]);
if (i0 != 10 - 1) printf(",");
}
}

printf(" .nextID = %d", (*o).nextID);
printf(" .nextname = %d", (*o).nextname);
printf(" .owner = %d", (*o).owner);
printf(" .creator = %d", (*o).creator);
printf(" .ngroups = %d", (*o).ngroups);
printf(" .nusers = %d", (*o).nusers);
printf(" .count = %d", (*o).count);
printf(" .instance = %d", (*o).instance);
printf(" .owned = %d", (*o).owned);
printf(" .nextOwned = %d", (*o).nextOwned);
printf(" .parent = %d", (*o).parent);
printf(" .sibling = %d", (*o).sibling);
printf(" .child = %d", (*o).child);
{
unsigned int i0;
/* printing ARRAY (*o).name */
for (i0 = 0; i0 < 64; ++i0) {
printf("  = %d", (*o).name[i0]);
if (i0 != 64 - 1) printf(",");
}
}

return;
}
void ydr_free_prdebugentry(prdebugentry *o)
{
{
int i0;
for(i0 = 0; i0 < 5;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 10;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
return;
}
char *ydr_encode_prcheckentry(const prcheckentry *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).id); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).owner); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).creator); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).ngroups); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).nusers); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).count); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ int32_t tmp = htonl((*o).reserved[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp = htonl((*o).name[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_prcheckentry(prcheckentry *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).id = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).owner = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).creator = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).ngroups = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nusers = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).count = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).reserved[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).name[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 5;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_prcheckentry(prcheckentry *o)
{
/* printing TSTRUCT (*o) */
printf(" .flags = %d", (*o).flags);
printf(" .id = %d", (*o).id);
printf(" .owner = %d", (*o).owner);
printf(" .creator = %d", (*o).creator);
printf(" .ngroups = %d", (*o).ngroups);
printf(" .nusers = %d", (*o).nusers);
printf(" .count = %d", (*o).count);
{
unsigned int i0;
/* printing ARRAY (*o).reserved */
for (i0 = 0; i0 < 5; ++i0) {
printf("  = %d", (*o).reserved[i0]);
if (i0 != 5 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).name */
for (i0 = 0; i0 < 64; ++i0) {
printf("  = %d", (*o).name[i0]);
if (i0 != 64 - 1) printf(",");
}
}

return;
}
void ydr_free_prcheckentry(prcheckentry *o)
{
{
int i0;
for(i0 = 0; i0 < 5;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
return;
}
char *ydr_encode_prname(const prname *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp = htonl((*o)[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_prname(prname *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o)[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_prname(prname *o)
{
{
unsigned int i0;
/* printing ARRAY (*o) */
for (i0 = 0; i0 < 64; ++i0) {
printf("  = %d", (*o)[i0]);
if (i0 != 64 - 1) printf(",");
}
}
return;
}
void ydr_free_prname(prname *o)
{
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
return;
}
char *ydr_encode_namelist(const namelist *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(prname );
if (overI < (*o).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{
int i1;
for(i1 = 0; i1 < 64;++i1){
{ int32_t tmp = htonl((*o).val[i0][i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_namelist(namelist *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).len > 5000) goto fail;
if (((*o).len * sizeof(prname )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(prname );
if (overI < (*o).len) goto fail;
}
(*o).val = (prname *)malloc(sizeof(prname ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{
int i1;
for(i1 = 0; i1 < 64;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0][i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
}
}
return ptr;
fail:
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
{
int i1;
for(i1 = 0; i1 < 64;++i1){
}
}
}
}
free(((*o)).val);
errno = EINVAL;
return NULL;}
void ydr_print_namelist(namelist *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
for (i0 = 0; i0 < (*o).len; ++i0) {
{
unsigned int i1;
/* printing ARRAY (*o).val[i0] */
for (i1 = 0; i1 < 64; ++i1) {
printf("  = %d", (*o).val[i0][i1]);
if (i1 != 64 - 1) printf(",");
}
}

if (i0 != (*o).len - 1) printf(",");
}
}
return;
}
void ydr_free_namelist(namelist *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
{
int i1;
for(i1 = 0; i1 < 64;++i1){
}
}
}
}
free(((*o)).val);
return;
}
char *ydr_encode_idlist(const idlist *o, char *ptr, size_t *total_len)
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
const char *ydr_decode_idlist(idlist *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).len > 5000) goto fail;
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
void ydr_print_idlist(idlist *o)
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
void ydr_free_idlist(idlist *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
return;
}
char *ydr_encode_prlist(const prlist *o, char *ptr, size_t *total_len)
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
const char *ydr_decode_prlist(prlist *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).len > 5000) goto fail;
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
void ydr_print_prlist(prlist *o)
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
void ydr_free_prlist(prlist *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
return;
}
