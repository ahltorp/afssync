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
RCSID("pts.cs.c generated from pts.xg with $Id: pts.cs.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
#include "pts.cs.h"

int PR_NameToID(
struct rx_connection *connection
, const namelist *nlist
, idlist *ilist
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
{ uint32_t u;
u = htonl ((*nlist).len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(prname );
if (overI < (*nlist).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*nlist).len;++i0){
{
int i1;
for(i1 = 0; i1 < 64;++i1){
{ uint32_t u;
u = htonl ((*nlist).val[i0][i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*ilist).len = ntohl (u);
}
if ((*ilist).len > 5000) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*ilist).len) goto fail;
}
(*ilist).val = (int32_t *)malloc(sizeof(int32_t ) * (*ilist).len);
if ((*ilist).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*ilist).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*ilist).val[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_IDToName(
struct rx_connection *connection
, const idlist *ilist
, namelist *nlist
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
u = htonl ((*ilist).len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*ilist).len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < (*ilist).len;++i0){
{ uint32_t u;
u = htonl ((*ilist).val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*nlist).len = ntohl (u);
}
if ((*nlist).len > 5000) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(prname );
if (overI < (*nlist).len) goto fail;
}
(*nlist).val = (prname *)malloc(sizeof(prname ) * (*nlist).len);
if ((*nlist).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*nlist).len;++i0){
{
int i1;
for(i1 = 0; i1 < 64;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*nlist).val[i0][i1] = ntohl (u);
}
}
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_NewEntry(
struct rx_connection *connection
, const char *name
, const int32_t flag
, const int32_t oid
, int32_t *id
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
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(name);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, name, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl (flag);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (oid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*id) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_INewEntry(
struct rx_connection *connection
, const char *name
, const int32_t id
, const int32_t oid
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (500);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(name);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, name, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl (id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (oid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_ListEntry(
struct rx_connection *connection
, const int32_t id
, struct prcheckentry *entry
)
{
struct rx_call *call;
int ret = 0;
call = rx_NewCall (connection);
{ uint32_t u;
u = htonl (512);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).id = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).creator = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).ngroups = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).nusers = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).count = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).reserved[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).name[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_DumpEntry(
struct rx_connection *connection
, const int32_t pos
, struct prdebugentry *entry
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
u = htonl (pos);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).id = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).cellid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).next = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).reserved[i0] = ntohl (u);
}
}
}
{
int i0;
for(i0 = 0; i0 < 10;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).entries[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).nextID = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).nextname = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).owner = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).creator = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).ngroups = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).nusers = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).count = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).instance = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).owned = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).nextOwned = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).parent = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).sibling = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).child = ntohl (u);
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*entry).name[i0] = ntohl (u);
}
}
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_ChangeEntry(
struct rx_connection *connection
, const int32_t id
, const char *name
, const int32_t oid
, const int32_t newid
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
u = htonl (id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ unsigned len;
char zero[4] = {0, 0, 0, 0};
unsigned padlen;
len = strlen(name);
padlen = (4 - (len % 4)) % 4;
{ uint32_t u;
u = htonl (len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
if(rx_Write(call, name, len) != len)
goto fail;
if(rx_Write(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
u = htonl (oid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (newid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_SetFieldsEntry(
struct rx_connection *connection
, const int32_t id
, const int32_t mask
, const int32_t flags
, const int32_t ngroups
, const int32_t nusers
, const int32_t spare1
, const int32_t spare2
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
u = htonl (id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (mask);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (ngroups);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (nusers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (spare1);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (spare2);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_Delete(
struct rx_connection *connection
, const int32_t id
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
u = htonl (id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_WhereIsIt(
struct rx_connection *connection
, const int32_t id
, int32_t *ps
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
{ uint32_t u;
u = htonl (id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*ps) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_AddToGroup(
struct rx_connection *connection
, const int32_t uid
, const int32_t gid
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
u = htonl (uid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (gid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_RemoveFromGroup(
struct rx_connection *connection
, const int32_t id
, const int32_t gid
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
u = htonl (id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (gid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_ListMax(
struct rx_connection *connection
, int32_t *uid
, int32_t *gid
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
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*uid) = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*gid) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_SetMax(
struct rx_connection *connection
, const int32_t uid
, const int32_t gflag
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
u = htonl (uid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (gflag);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_ListElements(
struct rx_connection *connection
, const int32_t id
, prlist *elist
, int32_t *over
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
{ uint32_t u;
u = htonl (id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*elist).len = ntohl (u);
}
if ((*elist).len > 5000) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*elist).len) goto fail;
}
(*elist).val = (int32_t *)malloc(sizeof(int32_t ) * (*elist).len);
if ((*elist).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*elist).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*elist).val[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*over) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_GetCPS(
struct rx_connection *connection
, const int32_t id
, prlist *elist
, int32_t *over
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
u = htonl (id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*elist).len = ntohl (u);
}
if ((*elist).len > 5000) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*elist).len) goto fail;
}
(*elist).val = (int32_t *)malloc(sizeof(int32_t ) * (*elist).len);
if ((*elist).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*elist).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*elist).val[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*over) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_ListOwned(
struct rx_connection *connection
, const int32_t id
, prlist *elist
, int32_t *over
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
{ uint32_t u;
u = htonl (id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl ((*over));
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*elist).len = ntohl (u);
}
if ((*elist).len > 5000) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*elist).len) goto fail;
}
(*elist).val = (int32_t *)malloc(sizeof(int32_t ) * (*elist).len);
if ((*elist).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*elist).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*elist).val[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*over) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_IsAMemberOf(
struct rx_connection *connection
, const int32_t uid
, const int32_t gid
, int32_t *flag
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
u = htonl (uid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (gid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*flag) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_GetCPS2(
struct rx_connection *connection
, const int32_t id
, const int32_t host
, prlist *elist
, int32_t *over
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
u = htonl (id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (host);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*elist).len = ntohl (u);
}
if ((*elist).len > 5000) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*elist).len) goto fail;
}
(*elist).val = (int32_t *)malloc(sizeof(int32_t ) * (*elist).len);
if ((*elist).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*elist).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*elist).val[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*over) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
int PR_GetHostCPS(
struct rx_connection *connection
, const int32_t host
, prlist *elist
, int32_t *over
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
{ uint32_t u;
u = htonl (host);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*elist).len = ntohl (u);
}
if ((*elist).len > 5000) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < (*elist).len) goto fail;
}
(*elist).val = (int32_t *)malloc(sizeof(int32_t ) * (*elist).len);
if ((*elist).val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < (*elist).len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*elist).val[i0] = ntohl (u);
}
}
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
(*over) = ntohl (u);
}
return conv_to_arla_errno(rx_EndCall (call,0));
fail:
ret = conv_to_arla_errno(rx_GetCallError(call));
rx_EndCall (call, 0);
return ret;
}
