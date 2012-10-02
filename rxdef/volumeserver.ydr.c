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
RCSID("volumeserver.ydr.c generated from volumeserver.xg with $Id: volumeserver.ydr.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
char *ydr_encode_volDescription(const volDescription *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ int32_t tmp = htonl((*o).volName[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).volId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).volSize); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).volFlags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).volCloneId); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_volDescription(volDescription *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 65;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volName[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volSize = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volFlags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volCloneId = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 65;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_volDescription(volDescription *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).volName */
for (i0 = 0; i0 < 65; ++i0) {
printf("  = %d", (*o).volName[i0]);
if (i0 != 65 - 1) printf(",");
}
}

printf(" .volId = %d", (*o).volId);
printf(" .volSize = %d", (*o).volSize);
printf(" .volFlags = %d", (*o).volFlags);
printf(" .volCloneId = %d", (*o).volCloneId);
return;
}
void ydr_free_volDescription(volDescription *o)
{
{
int i0;
for(i0 = 0; i0 < 65;++i0){
}
}
return;
}
char *ydr_encode_partList(const partList *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 26;++i0){
{ int32_t tmp = htonl((*o).partId[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 26;++i0){
{ int32_t tmp = htonl((*o).partFlags[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_partList(partList *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 26;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).partId[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 26;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).partFlags[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 26;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 26;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_partList(partList *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).partId */
for (i0 = 0; i0 < 26; ++i0) {
printf("  = %d", (*o).partId[i0]);
if (i0 != 26 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).partFlags */
for (i0 = 0; i0 < 26; ++i0) {
printf("  = %d", (*o).partFlags[i0]);
if (i0 != 26 - 1) printf(",");
}
}

return;
}
void ydr_free_partList(partList *o)
{
{
int i0;
for(i0 = 0; i0 < 26;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 26;++i0){
}
}
return;
}
char *ydr_encode_volser_status(const volser_status *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).volID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).nextUnique); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).type); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).parentID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).cloneID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).backupID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).restoredFromID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).maxQuota); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).minQuota); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).owner); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).creationDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).accessDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).updateDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).exprirationDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).backupDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).copyDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_volser_status(volser_status *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).nextUnique = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).type = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).parentID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).cloneID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).backupID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).restoredFromID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).maxQuota = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).minQuota = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).owner = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).creationDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).accessDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).updateDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).exprirationDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).backupDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).copyDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_volser_status(volser_status *o)
{
/* printing TSTRUCT (*o) */
printf(" .volID = %d", (*o).volID);
printf(" .nextUnique = %d", (*o).nextUnique);
printf(" .type = %d", (*o).type);
printf(" .parentID = %d", (*o).parentID);
printf(" .cloneID = %d", (*o).cloneID);
printf(" .backupID = %d", (*o).backupID);
printf(" .restoredFromID = %d", (*o).restoredFromID);
printf(" .maxQuota = %d", (*o).maxQuota);
printf(" .minQuota = %d", (*o).minQuota);
printf(" .owner = %d", (*o).owner);
printf(" .creationDate = %d", (*o).creationDate);
printf(" .accessDate = %d", (*o).accessDate);
printf(" .updateDate = %d", (*o).updateDate);
printf(" .exprirationDate = %d", (*o).exprirationDate);
printf(" .backupDate = %d", (*o).backupDate);
printf(" .copyDate = %d", (*o).copyDate);
return;
}
void ydr_free_volser_status(volser_status *o)
{
return;
}
char *ydr_encode_destServer(const destServer *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).destHost); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).destPort); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).destSSID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_destServer(destServer *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).destHost = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).destPort = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).destSSID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_destServer(destServer *o)
{
/* printing TSTRUCT (*o) */
printf(" .destHost = %d", (*o).destHost);
printf(" .destPort = %d", (*o).destPort);
printf(" .destSSID = %d", (*o).destSSID);
return;
}
void ydr_free_destServer(destServer *o)
{
return;
}
char *ydr_encode_volintInfo(const volintInfo *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ int32_t tmp = htonl((*o).name[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).volid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).type); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).backupID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).parentID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).cloneID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).status); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).copyDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).inUse); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).needsSalvaged); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).destroyMe); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).creationDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).accessDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).updateDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).backupDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).dayUse); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).filecount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).maxquota); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).size); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spare0); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spare1); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spare2); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).spare3); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_volintInfo(volintInfo *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).name[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).type = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).backupID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).parentID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).cloneID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).status = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).copyDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).inUse = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).needsSalvaged = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).destroyMe = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).creationDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).accessDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).updateDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).backupDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).dayUse = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).filecount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).maxquota = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).size = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spare0 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spare1 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spare2 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).spare3 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 32;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_volintInfo(volintInfo *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).name */
for (i0 = 0; i0 < 32; ++i0) {
printf("  = %d", (*o).name[i0]);
if (i0 != 32 - 1) printf(",");
}
}

printf(" .volid = %d", (*o).volid);
printf(" .type = %d", (*o).type);
printf(" .backupID = %d", (*o).backupID);
printf(" .parentID = %d", (*o).parentID);
printf(" .cloneID = %d", (*o).cloneID);
printf(" .status = %d", (*o).status);
printf(" .copyDate = %d", (*o).copyDate);
printf(" .inUse = %d", (*o).inUse);
printf(" .needsSalvaged = %d", (*o).needsSalvaged);
printf(" .destroyMe = %d", (*o).destroyMe);
printf(" .creationDate = %d", (*o).creationDate);
printf(" .accessDate = %d", (*o).accessDate);
printf(" .updateDate = %d", (*o).updateDate);
printf(" .backupDate = %d", (*o).backupDate);
printf(" .dayUse = %d", (*o).dayUse);
printf(" .filecount = %d", (*o).filecount);
printf(" .maxquota = %d", (*o).maxquota);
printf(" .size = %d", (*o).size);
printf(" .flags = %d", (*o).flags);
printf(" .spare0 = %d", (*o).spare0);
printf(" .spare1 = %d", (*o).spare1);
printf(" .spare2 = %d", (*o).spare2);
printf(" .spare3 = %d", (*o).spare3);
return;
}
void ydr_free_volintInfo(volintInfo *o)
{
{
int i0;
for(i0 = 0; i0 < 32;++i0){
}
}
return;
}
char *ydr_encode_xvolintInfo(const xvolintInfo *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ int32_t tmp = htonl((*o).name[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).volid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).type); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).backupID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).parentID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).cloneID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).status); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).copyDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).inUse); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).creationDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).accessDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).updateDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).backupDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).dayUse); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).filecount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).maxquota); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).size); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 4;++i0){
{ int32_t tmp = htonl((*o).stat_reads[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 4;++i0){
{ int32_t tmp = htonl((*o).stat_writes[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ int32_t tmp = htonl((*o).stat_fileSameAuthor[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ int32_t tmp = htonl((*o).stat_fileDiffAuthor[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ int32_t tmp = htonl((*o).stat_dirSameAuthor[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ int32_t tmp = htonl((*o).stat_dirDiffAuthor[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_xvolintInfo(xvolintInfo *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).name[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).type = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).backupID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).parentID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).cloneID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).status = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).copyDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).inUse = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).creationDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).accessDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).updateDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).backupDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).dayUse = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).filecount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).maxquota = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).size = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 4;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).stat_reads[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 4;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).stat_writes[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).stat_fileSameAuthor[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).stat_fileDiffAuthor[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).stat_dirSameAuthor[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).stat_dirDiffAuthor[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 32;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 4;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 4;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_xvolintInfo(xvolintInfo *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).name */
for (i0 = 0; i0 < 32; ++i0) {
printf("  = %d", (*o).name[i0]);
if (i0 != 32 - 1) printf(",");
}
}

printf(" .volid = %d", (*o).volid);
printf(" .type = %d", (*o).type);
printf(" .backupID = %d", (*o).backupID);
printf(" .parentID = %d", (*o).parentID);
printf(" .cloneID = %d", (*o).cloneID);
printf(" .status = %d", (*o).status);
printf(" .copyDate = %d", (*o).copyDate);
printf(" .inUse = %d", (*o).inUse);
printf(" .creationDate = %d", (*o).creationDate);
printf(" .accessDate = %d", (*o).accessDate);
printf(" .updateDate = %d", (*o).updateDate);
printf(" .backupDate = %d", (*o).backupDate);
printf(" .dayUse = %d", (*o).dayUse);
printf(" .filecount = %d", (*o).filecount);
printf(" .maxquota = %d", (*o).maxquota);
printf(" .size = %d", (*o).size);
{
unsigned int i0;
/* printing ARRAY (*o).stat_reads */
for (i0 = 0; i0 < 4; ++i0) {
printf("  = %d", (*o).stat_reads[i0]);
if (i0 != 4 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).stat_writes */
for (i0 = 0; i0 < 4; ++i0) {
printf("  = %d", (*o).stat_writes[i0]);
if (i0 != 4 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).stat_fileSameAuthor */
for (i0 = 0; i0 < 6; ++i0) {
printf("  = %d", (*o).stat_fileSameAuthor[i0]);
if (i0 != 6 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).stat_fileDiffAuthor */
for (i0 = 0; i0 < 6; ++i0) {
printf("  = %d", (*o).stat_fileDiffAuthor[i0]);
if (i0 != 6 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).stat_dirSameAuthor */
for (i0 = 0; i0 < 6; ++i0) {
printf("  = %d", (*o).stat_dirSameAuthor[i0]);
if (i0 != 6 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).stat_dirDiffAuthor */
for (i0 = 0; i0 < 6; ++i0) {
printf("  = %d", (*o).stat_dirDiffAuthor[i0]);
if (i0 != 6 - 1) printf(",");
}
}

return;
}
void ydr_free_xvolintInfo(xvolintInfo *o)
{
{
int i0;
for(i0 = 0; i0 < 32;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 4;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 4;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 6;++i0){
}
}
return;
}
char *ydr_encode_transDebugInfo(const transDebugInfo *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).tid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).time); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).creationTime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).returnCode); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).volid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).partition); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).iflags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).vflags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).tflags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
{ int32_t tmp = htonl((*o).lastProcName[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).callValid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).readNext); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).transmitNext); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).lastSendTime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).lastReceiveTime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_transDebugInfo(transDebugInfo *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).tid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).time = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).creationTime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).returnCode = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).volid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).partition = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).iflags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).vflags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).tflags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 30;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).lastProcName[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).callValid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).readNext = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).transmitNext = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).lastSendTime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).lastReceiveTime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 30;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_transDebugInfo(transDebugInfo *o)
{
/* printing TSTRUCT (*o) */
printf(" .tid = %d", (*o).tid);
printf(" .time = %d", (*o).time);
printf(" .creationTime = %d", (*o).creationTime);
printf(" .returnCode = %d", (*o).returnCode);
printf(" .volid = %d", (*o).volid);
printf(" .partition = %d", (*o).partition);
printf(" .iflags = %d", (*o).iflags);
printf(" .vflags = %d", (*o).vflags);
printf(" .tflags = %d", (*o).tflags);
{
unsigned int i0;
/* printing ARRAY (*o).lastProcName */
for (i0 = 0; i0 < 30; ++i0) {
printf("  = %d", (*o).lastProcName[i0]);
if (i0 != 30 - 1) printf(",");
}
}

printf(" .callValid = %d", (*o).callValid);
printf(" .readNext = %d", (*o).readNext);
printf(" .transmitNext = %d", (*o).transmitNext);
printf(" .lastSendTime = %d", (*o).lastSendTime);
printf(" .lastReceiveTime = %d", (*o).lastReceiveTime);
return;
}
void ydr_free_transDebugInfo(transDebugInfo *o)
{
{
int i0;
for(i0 = 0; i0 < 30;++i0){
}
}
return;
}
char *ydr_encode_pIDs(const pIDs *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 26;++i0){
{ int32_t tmp = htonl((*o).partIds[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_pIDs(pIDs *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 26;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).partIds[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 26;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_pIDs(pIDs *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).partIds */
for (i0 = 0; i0 < 26; ++i0) {
printf("  = %d", (*o).partIds[i0]);
if (i0 != 26 - 1) printf(",");
}
}

return;
}
void ydr_free_pIDs(pIDs *o)
{
{
int i0;
for(i0 = 0; i0 < 26;++i0){
}
}
return;
}
char *ydr_encode_diskPartition(const diskPartition *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ int32_t tmp = htonl((*o).name[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ int32_t tmp = htonl((*o).devName[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).lock_fd); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).totalUsable); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).free); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).minFree); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_diskPartition(diskPartition *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).name[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).devName[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).lock_fd = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).totalUsable = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).free = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).minFree = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 32;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_diskPartition(diskPartition *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).name */
for (i0 = 0; i0 < 32; ++i0) {
printf("  = %d", (*o).name[i0]);
if (i0 != 32 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).devName */
for (i0 = 0; i0 < 32; ++i0) {
printf("  = %d", (*o).devName[i0]);
if (i0 != 32 - 1) printf(",");
}
}

printf(" .lock_fd = %d", (*o).lock_fd);
printf(" .totalUsable = %d", (*o).totalUsable);
printf(" .free = %d", (*o).free);
printf(" .minFree = %d", (*o).minFree);
return;
}
void ydr_free_diskPartition(diskPartition *o)
{
{
int i0;
for(i0 = 0; i0 < 32;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 32;++i0){
}
}
return;
}
char *ydr_encode_restoreCookie(const restoreCookie *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ int32_t tmp = htonl((*o).name[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).type); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).clone); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).parent); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_restoreCookie(restoreCookie *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 32;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).name[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).type = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).clone = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).parent = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 32;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_restoreCookie(restoreCookie *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).name */
for (i0 = 0; i0 < 32; ++i0) {
printf("  = %d", (*o).name[i0]);
if (i0 != 32 - 1) printf(",");
}
}

printf(" .type = %d", (*o).type);
printf(" .clone = %d", (*o).clone);
printf(" .parent = %d", (*o).parent);
return;
}
void ydr_free_restoreCookie(restoreCookie *o)
{
{
int i0;
for(i0 = 0; i0 < 32;++i0){
}
}
return;
}
char *ydr_encode_transDebugEntries(const transDebugEntries *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct transDebugInfo );
if (overI < (*o).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp = htonl((*o).val[i0].tid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].time); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].creationTime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].returnCode); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].volid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].partition); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].iflags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].vflags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].tflags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i1;
for(i1 = 0; i1 < 30;++i1){
{ int32_t tmp = htonl((*o).val[i0].lastProcName[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).val[i0].callValid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].readNext); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].transmitNext); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].lastSendTime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].lastReceiveTime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_transDebugEntries(transDebugEntries *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (((*o).len * sizeof(struct transDebugInfo )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct transDebugInfo );
if (overI < (*o).len) goto fail;
}
(*o).val = (struct transDebugInfo *)malloc(sizeof(struct transDebugInfo ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].tid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].time = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].creationTime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].returnCode = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].volid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].partition = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].iflags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].vflags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].tflags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i1;
for(i1 = 0; i1 < 30;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].lastProcName[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].callValid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].readNext = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].transmitNext = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].lastSendTime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].lastReceiveTime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
{
int i1;
for(i1 = 0; i1 < 30;++i1){
}
}
}
}
free(((*o)).val);
errno = EINVAL;
return NULL;}
void ydr_print_transDebugEntries(transDebugEntries *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
for (i0 = 0; i0 < (*o).len; ++i0) {
/* printing TSTRUCT (*o).val[i0] */
printf(" .tid = %d", (*o).val[i0].tid);
printf(" .time = %d", (*o).val[i0].time);
printf(" .creationTime = %d", (*o).val[i0].creationTime);
printf(" .returnCode = %d", (*o).val[i0].returnCode);
printf(" .volid = %d", (*o).val[i0].volid);
printf(" .partition = %d", (*o).val[i0].partition);
printf(" .iflags = %d", (*o).val[i0].iflags);
printf(" .vflags = %d", (*o).val[i0].vflags);
printf(" .tflags = %d", (*o).val[i0].tflags);
{
unsigned int i1;
/* printing ARRAY (*o).val[i0].lastProcName */
for (i1 = 0; i1 < 30; ++i1) {
printf("  = %d", (*o).val[i0].lastProcName[i1]);
if (i1 != 30 - 1) printf(",");
}
}

printf(" .callValid = %d", (*o).val[i0].callValid);
printf(" .readNext = %d", (*o).val[i0].readNext);
printf(" .transmitNext = %d", (*o).val[i0].transmitNext);
printf(" .lastSendTime = %d", (*o).val[i0].lastSendTime);
printf(" .lastReceiveTime = %d", (*o).val[i0].lastReceiveTime);

if (i0 != (*o).len - 1) printf(",");
}
}
return;
}
void ydr_free_transDebugEntries(transDebugEntries *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
{
int i1;
for(i1 = 0; i1 < 30;++i1){
}
}
}
}
free(((*o)).val);
return;
}
char *ydr_encode_volEntries(const volEntries *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct volintInfo );
if (overI < (*o).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{
int i1;
for(i1 = 0; i1 < 32;++i1){
{ int32_t tmp = htonl((*o).val[i0].name[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).val[i0].volid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].type); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].backupID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].parentID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].cloneID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].status); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].copyDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].inUse); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].needsSalvaged); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].destroyMe); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].creationDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].accessDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].updateDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].backupDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].dayUse); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].filecount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].maxquota); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].size); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spare0); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spare1); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spare2); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].spare3); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_volEntries(volEntries *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (((*o).len * sizeof(struct volintInfo )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct volintInfo );
if (overI < (*o).len) goto fail;
}
(*o).val = (struct volintInfo *)malloc(sizeof(struct volintInfo ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{
int i1;
for(i1 = 0; i1 < 32;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].name[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].volid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].type = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].backupID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].parentID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].cloneID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].status = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].copyDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].inUse = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].needsSalvaged = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].destroyMe = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].creationDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].accessDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].updateDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].backupDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].dayUse = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].filecount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].maxquota = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].size = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spare0 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spare1 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spare2 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].spare3 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
{
int i1;
for(i1 = 0; i1 < 32;++i1){
}
}
}
}
free(((*o)).val);
errno = EINVAL;
return NULL;}
void ydr_print_volEntries(volEntries *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
for (i0 = 0; i0 < (*o).len; ++i0) {
/* printing TSTRUCT (*o).val[i0] */
{
unsigned int i1;
/* printing ARRAY (*o).val[i0].name */
for (i1 = 0; i1 < 32; ++i1) {
printf("  = %d", (*o).val[i0].name[i1]);
if (i1 != 32 - 1) printf(",");
}
}

printf(" .volid = %d", (*o).val[i0].volid);
printf(" .type = %d", (*o).val[i0].type);
printf(" .backupID = %d", (*o).val[i0].backupID);
printf(" .parentID = %d", (*o).val[i0].parentID);
printf(" .cloneID = %d", (*o).val[i0].cloneID);
printf(" .status = %d", (*o).val[i0].status);
printf(" .copyDate = %d", (*o).val[i0].copyDate);
printf(" .inUse = %d", (*o).val[i0].inUse);
printf(" .needsSalvaged = %d", (*o).val[i0].needsSalvaged);
printf(" .destroyMe = %d", (*o).val[i0].destroyMe);
printf(" .creationDate = %d", (*o).val[i0].creationDate);
printf(" .accessDate = %d", (*o).val[i0].accessDate);
printf(" .updateDate = %d", (*o).val[i0].updateDate);
printf(" .backupDate = %d", (*o).val[i0].backupDate);
printf(" .dayUse = %d", (*o).val[i0].dayUse);
printf(" .filecount = %d", (*o).val[i0].filecount);
printf(" .maxquota = %d", (*o).val[i0].maxquota);
printf(" .size = %d", (*o).val[i0].size);
printf(" .flags = %d", (*o).val[i0].flags);
printf(" .spare0 = %d", (*o).val[i0].spare0);
printf(" .spare1 = %d", (*o).val[i0].spare1);
printf(" .spare2 = %d", (*o).val[i0].spare2);
printf(" .spare3 = %d", (*o).val[i0].spare3);

if (i0 != (*o).len - 1) printf(",");
}
}
return;
}
void ydr_free_volEntries(volEntries *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
{
int i1;
for(i1 = 0; i1 < 32;++i1){
}
}
}
}
free(((*o)).val);
return;
}
char *ydr_encode_xvolEntries(const xvolEntries *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct xvolintInfo );
if (overI < (*o).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{
int i1;
for(i1 = 0; i1 < 32;++i1){
{ int32_t tmp = htonl((*o).val[i0].name[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).val[i0].volid); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].type); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].backupID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].parentID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].cloneID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].status); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].copyDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].inUse); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].creationDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].accessDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].updateDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].backupDate); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].dayUse); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].filecount); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].maxquota); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].size); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
{ int32_t tmp = htonl((*o).val[i0].stat_reads[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
{ int32_t tmp = htonl((*o).val[i0].stat_writes[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ int32_t tmp = htonl((*o).val[i0].stat_fileSameAuthor[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ int32_t tmp = htonl((*o).val[i0].stat_fileDiffAuthor[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ int32_t tmp = htonl((*o).val[i0].stat_dirSameAuthor[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ int32_t tmp = htonl((*o).val[i0].stat_dirDiffAuthor[i1]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_xvolEntries(xvolEntries *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (((*o).len * sizeof(struct xvolintInfo )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct xvolintInfo );
if (overI < (*o).len) goto fail;
}
(*o).val = (struct xvolintInfo *)malloc(sizeof(struct xvolintInfo ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{
int i1;
for(i1 = 0; i1 < 32;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].name[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].volid = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].type = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].backupID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].parentID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].cloneID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].status = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].copyDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].inUse = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].creationDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].accessDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].updateDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].backupDate = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].dayUse = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].filecount = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].maxquota = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].size = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].stat_reads[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].stat_writes[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].stat_fileSameAuthor[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].stat_fileDiffAuthor[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].stat_dirSameAuthor[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].stat_dirDiffAuthor[i1] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
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
for(i1 = 0; i1 < 32;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
}
}
}
}
free(((*o)).val);
errno = EINVAL;
return NULL;}
void ydr_print_xvolEntries(xvolEntries *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
for (i0 = 0; i0 < (*o).len; ++i0) {
/* printing TSTRUCT (*o).val[i0] */
{
unsigned int i1;
/* printing ARRAY (*o).val[i0].name */
for (i1 = 0; i1 < 32; ++i1) {
printf("  = %d", (*o).val[i0].name[i1]);
if (i1 != 32 - 1) printf(",");
}
}

printf(" .volid = %d", (*o).val[i0].volid);
printf(" .type = %d", (*o).val[i0].type);
printf(" .backupID = %d", (*o).val[i0].backupID);
printf(" .parentID = %d", (*o).val[i0].parentID);
printf(" .cloneID = %d", (*o).val[i0].cloneID);
printf(" .status = %d", (*o).val[i0].status);
printf(" .copyDate = %d", (*o).val[i0].copyDate);
printf(" .inUse = %d", (*o).val[i0].inUse);
printf(" .creationDate = %d", (*o).val[i0].creationDate);
printf(" .accessDate = %d", (*o).val[i0].accessDate);
printf(" .updateDate = %d", (*o).val[i0].updateDate);
printf(" .backupDate = %d", (*o).val[i0].backupDate);
printf(" .dayUse = %d", (*o).val[i0].dayUse);
printf(" .filecount = %d", (*o).val[i0].filecount);
printf(" .maxquota = %d", (*o).val[i0].maxquota);
printf(" .size = %d", (*o).val[i0].size);
{
unsigned int i1;
/* printing ARRAY (*o).val[i0].stat_reads */
for (i1 = 0; i1 < 4; ++i1) {
printf("  = %d", (*o).val[i0].stat_reads[i1]);
if (i1 != 4 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].stat_writes */
for (i1 = 0; i1 < 4; ++i1) {
printf("  = %d", (*o).val[i0].stat_writes[i1]);
if (i1 != 4 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].stat_fileSameAuthor */
for (i1 = 0; i1 < 6; ++i1) {
printf("  = %d", (*o).val[i0].stat_fileSameAuthor[i1]);
if (i1 != 6 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].stat_fileDiffAuthor */
for (i1 = 0; i1 < 6; ++i1) {
printf("  = %d", (*o).val[i0].stat_fileDiffAuthor[i1]);
if (i1 != 6 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].stat_dirSameAuthor */
for (i1 = 0; i1 < 6; ++i1) {
printf("  = %d", (*o).val[i0].stat_dirSameAuthor[i1]);
if (i1 != 6 - 1) printf(",");
}
}

{
unsigned int i1;
/* printing ARRAY (*o).val[i0].stat_dirDiffAuthor */
for (i1 = 0; i1 < 6; ++i1) {
printf("  = %d", (*o).val[i0].stat_dirDiffAuthor[i1]);
if (i1 != 6 - 1) printf(",");
}
}


if (i0 != (*o).len - 1) printf(",");
}
}
return;
}
void ydr_free_xvolEntries(xvolEntries *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
{
int i1;
for(i1 = 0; i1 < 32;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 4;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
}
}
{
int i1;
for(i1 = 0; i1 < 6;++i1){
}
}
}
}
free(((*o)).val);
return;
}
char *ydr_encode_part_entries(const part_entries *o, char *ptr, size_t *total_len)
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
const char *ydr_decode_part_entries(part_entries *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
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
void ydr_print_part_entries(part_entries *o)
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
void ydr_free_part_entries(part_entries *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
return;
}
char *ydr_encode_multi_results(const multi_results *o, char *ptr, size_t *total_len)
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
const char *ydr_decode_multi_results(multi_results *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
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
void ydr_print_multi_results(multi_results *o)
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
void ydr_free_multi_results(multi_results *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
return;
}
char *ydr_encode_replica(const replica *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).trans_id); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).destserver.destHost); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).destserver.destPort); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).destserver.destSSID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_replica(replica *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).trans_id = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).destserver.destHost = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).destserver.destPort = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).destserver.destSSID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_replica(replica *o)
{
/* printing TSTRUCT (*o) */
printf(" .trans_id = %d", (*o).trans_id);
/* printing TSTRUCT (*o).destserver */
printf(" .destHost = %d", (*o).destserver.destHost);
printf(" .destPort = %d", (*o).destserver.destPort);
printf(" .destSSID = %d", (*o).destserver.destSSID);

return;
}
void ydr_free_replica(replica *o)
{
return;
}
char *ydr_encode_manyDests(const manyDests *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct replica );
if (overI < (*o).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp = htonl((*o).val[i0].trans_id); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].destserver.destHost); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].destserver.destPort); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).val[i0].destserver.destSSID); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_manyDests(manyDests *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if ((*o).len > 255) goto fail;
if (((*o).len * sizeof(struct replica )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(struct replica );
if (overI < (*o).len) goto fail;
}
(*o).val = (struct replica *)malloc(sizeof(struct replica ) * (*o).len);
if ((*o).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*o).len;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].trans_id = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].destserver.destHost = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].destserver.destPort = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).val[i0].destserver.destSSID = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
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
void ydr_print_manyDests(manyDests *o)
{
{
unsigned int i0;
/* printing YDR_TVARRAY (*o) */
for (i0 = 0; i0 < (*o).len; ++i0) {
/* printing TSTRUCT (*o).val[i0] */
printf(" .trans_id = %d", (*o).val[i0].trans_id);
/* printing TSTRUCT (*o).val[i0].destserver */
printf(" .destHost = %d", (*o).val[i0].destserver.destHost);
printf(" .destPort = %d", (*o).val[i0].destserver.destPort);
printf(" .destSSID = %d", (*o).val[i0].destserver.destSSID);


if (i0 != (*o).len - 1) printf(",");
}
}
return;
}
void ydr_free_manyDests(manyDests *o)
{
{
unsigned int i0;
for (i0 = 0; i0 < (*o).len; ++i0) {
}
}
free(((*o)).val);
return;
}
