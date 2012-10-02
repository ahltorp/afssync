/* Generated from ka.xg */
#include "ka.h"

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
RCSID("ka.ydr.c generated from ka.xg with $Id: ka.ydr.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
char *ydr_encode_ka_CBS(const ka_CBS *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).Seq.len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*o).Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
size_t sz = (*o).Seq.len + (4 - ((*o).Seq.len % 4)) % 4;
if (*total_len < sz) goto fail;
memcpy (ptr, (*o).Seq.val, (*o).Seq.len);
memcpy (ptr + (*o).Seq.len, zero, (4 - ((*o).Seq.len % 4)) % 4);
ptr += sz; *total_len -= sz;
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_ka_CBS(ka_CBS *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Seq.len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (((*o).Seq.len * sizeof(char )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*o).Seq.len) goto fail;
}
(*o).Seq.val = (char *)malloc(sizeof(char ) * (*o).Seq.len);
if ((*o).Seq.val == NULL) goto fail;
{
memcpy ((*o).Seq.val, ptr, (*o).Seq.len);
ptr += (*o).Seq.len + (4 - ((*o).Seq.len % 4)) % 4;
}
return ptr;
fail:
free(((*o).Seq).val);
errno = EINVAL;
return NULL;}
void ydr_print_ka_CBS(ka_CBS *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing YDR_TVARRAY (*o).Seq */
char *ptr = (*o).Seq.val;
printf("0x");for (i0 = 0; i0 < (*o).Seq.len; ++i0)
printf("%x", ptr[i0]);}

return;
}
void ydr_free_ka_CBS(ka_CBS *o)
{
free(((*o).Seq).val);
return;
}
char *ydr_encode_ka_BBS(const ka_BBS *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).MaxSeqLen); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).Seq.len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*o).Seq.len) goto fail;
}
{
char zero[4] = {0, 0, 0, 0};
size_t sz = (*o).Seq.len + (4 - ((*o).Seq.len % 4)) % 4;
if (*total_len < sz) goto fail;
memcpy (ptr, (*o).Seq.val, (*o).Seq.len);
memcpy (ptr + (*o).Seq.len, zero, (4 - ((*o).Seq.len % 4)) % 4);
ptr += sz; *total_len -= sz;
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_ka_BBS(ka_BBS *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).MaxSeqLen = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).Seq.len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (((*o).Seq.len * sizeof(char )) > *total_len) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(char );
if (overI < (*o).Seq.len) goto fail;
}
(*o).Seq.val = (char *)malloc(sizeof(char ) * (*o).Seq.len);
if ((*o).Seq.val == NULL) goto fail;
{
memcpy ((*o).Seq.val, ptr, (*o).Seq.len);
ptr += (*o).Seq.len + (4 - ((*o).Seq.len % 4)) % 4;
}
return ptr;
fail:
free(((*o).Seq).val);
errno = EINVAL;
return NULL;}
void ydr_print_ka_BBS(ka_BBS *o)
{
/* printing TSTRUCT (*o) */
printf(" .MaxSeqLen = %d", (*o).MaxSeqLen);
{
unsigned int i0;
/* printing YDR_TVARRAY (*o).Seq */
char *ptr = (*o).Seq.val;
printf("0x");for (i0 = 0; i0 < (*o).Seq.len; ++i0)
printf("%x", ptr[i0]);}

return;
}
void ydr_free_ka_BBS(ka_BBS *o)
{
free(((*o).Seq).val);
return;
}
char *ydr_encode_EncryptionKey(const EncryptionKey *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).key[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_EncryptionKey(EncryptionKey *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).key[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
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
void ydr_print_EncryptionKey(EncryptionKey *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).key */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).key[i0]);
if (i0 != 8 - 1) printf(",");
}
}

return;
}
void ydr_free_EncryptionKey(EncryptionKey *o)
{
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
return;
}
char *ydr_encode_kaname(const kaname *o, char *ptr, size_t *total_len)
{
{
unsigned len = strlen((*o));
if (*total_len < len) goto fail;
*total_len -= len;
{ int32_t tmp = htonl(len); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
strncpy (ptr, (*o), len);
ptr += len + (4 - (len % 4)) % 4;
*total_len -= len + (4 - (len % 4)) % 4;
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_kaname(kaname *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
unsigned len;
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); len = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
if (*total_len < len) goto fail;
*total_len -= len;
if(len >= 64)
goto fail;
memcpy (((*o)), ptr, len);
((*o))[len] = '\0';
ptr += len + (4 - (len % 4)) % 4;
*total_len -= len + (4 - (len % 4)) % 4;
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
void ydr_print_kaname(kaname *o)
{
/* printing TSTRING (*o) */
printf("  = %s", (*o));return;
}
void ydr_free_kaname(kaname *o)
{
return;
}
char *ydr_encode_kaident(const kaident *o, char *ptr, size_t *total_len)
{
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp = htonl((*o).name[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp = htonl((*o).instance[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_kaident(kaident *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).name[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).instance[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_kaident(kaident *o)
{
/* printing TSTRUCT (*o) */
{
unsigned int i0;
/* printing ARRAY (*o).name */
for (i0 = 0; i0 < 64; ++i0) {
printf("  = %d", (*o).name[i0]);
if (i0 != 64 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).instance */
for (i0 = 0; i0 < 64; ++i0) {
printf("  = %d", (*o).instance[i0]);
if (i0 != 64 - 1) printf(",");
}
}

return;
}
void ydr_free_kaident(kaident *o)
{
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
return;
}
char *ydr_encode_kaentryinfo(const kaentryinfo *o, char *ptr, size_t *total_len)
{
{ int32_t tmp = htonl((*o).minor_version); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).flags); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).user_expiration); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).modification_time); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp = htonl((*o).modification_user.name[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp = htonl((*o).modification_user.instance[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).change_password_time); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).max_ticket_lifetime); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).key_version); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp = htonl((*o).key.key[i0]); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp = htonl((*o).keyCheckSym); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).reserved2); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).reserved3); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp = htonl((*o).reserved4); if (*total_len < sizeof(tmp)) goto fail;
memcpy (ptr, (char*)&tmp, sizeof(tmp)); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
errno = EINVAL;
return NULL;}
const char *ydr_decode_kaentryinfo(kaentryinfo *o, const char *ptr, size_t *total_len)
{
memset(o, 0, sizeof(*o));
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).minor_version = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).flags = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).user_expiration = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).modification_time = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).modification_user.name[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).modification_user.instance[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).change_password_time = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).max_ticket_lifetime = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).key_version = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).key.key[i0] = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
}
}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).keyCheckSym = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).reserved2 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).reserved3 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
{ int32_t tmp; if (*total_len < sizeof(tmp)) goto fail;memcpy ((char*)&tmp, ptr, sizeof(tmp)); (*o).reserved4 = ntohl(tmp); ptr += sizeof(tmp); *total_len -= sizeof(tmp);}
return ptr;
fail:
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
errno = EINVAL;
return NULL;}
void ydr_print_kaentryinfo(kaentryinfo *o)
{
/* printing TSTRUCT (*o) */
printf(" .minor_version = %d", (*o).minor_version);
printf(" .flags = %d", (*o).flags);
printf(" .user_expiration = %d", (*o).user_expiration);
printf(" .modification_time = %d", (*o).modification_time);
/* printing TSTRUCT (*o).modification_user */
{
unsigned int i0;
/* printing ARRAY (*o).modification_user.name */
for (i0 = 0; i0 < 64; ++i0) {
printf("  = %d", (*o).modification_user.name[i0]);
if (i0 != 64 - 1) printf(",");
}
}

{
unsigned int i0;
/* printing ARRAY (*o).modification_user.instance */
for (i0 = 0; i0 < 64; ++i0) {
printf("  = %d", (*o).modification_user.instance[i0]);
if (i0 != 64 - 1) printf(",");
}
}


printf(" .change_password_time = %d", (*o).change_password_time);
printf(" .max_ticket_lifetime = %d", (*o).max_ticket_lifetime);
printf(" .key_version = %d", (*o).key_version);
/* printing TSTRUCT (*o).key */
{
unsigned int i0;
/* printing ARRAY (*o).key.key */
for (i0 = 0; i0 < 8; ++i0) {
printf("  = %d", (*o).key.key[i0]);
if (i0 != 8 - 1) printf(",");
}
}


printf(" .keyCheckSym = %d", (*o).keyCheckSym);
printf(" .reserved2 = %d", (*o).reserved2);
printf(" .reserved3 = %d", (*o).reserved3);
printf(" .reserved4 = %d", (*o).reserved4);
return;
}
void ydr_free_kaentryinfo(kaentryinfo *o)
{
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
}
}
{
int i0;
for(i0 = 0; i0 < 8;++i0){
}
}
return;
}
