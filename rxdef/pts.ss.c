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
RCSID("pts.ss.c generated from pts.xg with $Id: pts.ss.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");
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
#include "pts.ss.h"

static int ydr_ps_PR_NameToID(
struct rx_call *call)
{
int32_t _result;
namelist nlist;
idlist ilist;
memset(&nlist, 0, sizeof(nlist));
memset(&ilist, 0, sizeof(ilist));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
nlist.len = ntohl (u);
}
if (nlist.len > 5000) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(prname );
if (overI < nlist.len) goto fail;
}
nlist.val = (prname *)malloc(sizeof(prname ) * nlist.len);
if (nlist.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < nlist.len;++i0){
{
int i1;
for(i1 = 0; i1 < 64;++i1){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
nlist.val[i0][i1] = ntohl (u);
}
}
}
}
}
_result = SPR_NameToID(call, &nlist, &ilist);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (ilist.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < ilist.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < ilist.len;++i0){
{ uint32_t u;
u = htonl (ilist.val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
free(nlist.val);
free(ilist.val);
return _result;
fail:
free(nlist.val);
free(ilist.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_IDToName(
struct rx_call *call)
{
int32_t _result;
idlist ilist;
namelist nlist;
memset(&ilist, 0, sizeof(ilist));
memset(&nlist, 0, sizeof(nlist));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
ilist.len = ntohl (u);
}
if (ilist.len > 5000) goto fail;
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < ilist.len) goto fail;
}
ilist.val = (int32_t *)malloc(sizeof(int32_t ) * ilist.len);
if (ilist.val == NULL) goto fail;
{
int i0;
for(i0 = 0; i0 < ilist.len;++i0){
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
ilist.val[i0] = ntohl (u);
}
}
}
_result = SPR_IDToName(call, &ilist, &nlist);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (nlist.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(prname );
if (overI < nlist.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < nlist.len;++i0){
{
int i1;
for(i1 = 0; i1 < 64;++i1){
{ uint32_t u;
u = htonl (nlist.val[i0][i1]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
}
}
free(ilist.val);
free(nlist.val);
return _result;
fail:
free(ilist.val);
free(nlist.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_NewEntry(
struct rx_call *call)
{
int32_t _result;
char name[64];
int32_t flag;
int32_t oid;
int32_t id;
memset(&name, 0, sizeof(name));
memset(&flag, 0, sizeof(flag));
memset(&oid, 0, sizeof(oid));
memset(&id, 0, sizeof(id));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (name), len) != len)
goto fail;
(name)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
flag = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
oid = ntohl (u);
}
_result = SPR_NewEntry(call, name, flag, oid, &id);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_INewEntry(
struct rx_call *call)
{
int32_t _result;
char name[64];
int32_t id;
int32_t oid;
memset(&name, 0, sizeof(name));
memset(&id, 0, sizeof(id));
memset(&oid, 0, sizeof(oid));

{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (name), len) != len)
goto fail;
(name)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
id = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
oid = ntohl (u);
}
_result = SPR_INewEntry(call, name, id, oid);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_ListEntry(
struct rx_call *call)
{
int32_t _result;
int32_t id;
struct prcheckentry entry;
memset(&id, 0, sizeof(id));
memset(&entry, 0, sizeof(entry));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
id = ntohl (u);
}
_result = SPR_ListEntry(call, id, &entry);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (entry.flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.creator);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.ngroups);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.nusers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.count);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ uint32_t u;
u = htonl (entry.reserved[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ uint32_t u;
u = htonl (entry.name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_DumpEntry(
struct rx_call *call)
{
int32_t _result;
int32_t pos;
struct prdebugentry entry;
memset(&pos, 0, sizeof(pos));
memset(&entry, 0, sizeof(entry));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
pos = ntohl (u);
}
_result = SPR_DumpEntry(call, pos, &entry);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (entry.flags);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.id);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.cellid);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.next);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 5;++i0){
{ uint32_t u;
u = htonl (entry.reserved[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{
int i0;
for(i0 = 0; i0 < 10;++i0){
{ uint32_t u;
u = htonl (entry.entries[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (entry.nextID);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.nextname);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.owner);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.creator);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.ngroups);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.nusers);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.count);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.instance);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.owned);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.nextOwned);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.parent);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.sibling);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{ uint32_t u;
u = htonl (entry.child);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
int i0;
for(i0 = 0; i0 < 64;++i0){
{ uint32_t u;
u = htonl (entry.name[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_ChangeEntry(
struct rx_call *call)
{
int32_t _result;
int32_t id;
char name[64];
int32_t oid;
int32_t newid;
memset(&id, 0, sizeof(id));
memset(&name, 0, sizeof(name));
memset(&oid, 0, sizeof(oid));
memset(&newid, 0, sizeof(newid));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
id = ntohl (u);
}
{ unsigned len;
unsigned padlen;
char zero[4] = {0, 0, 0, 0};
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
len = ntohl (u);
}
if (len >= 64) {
rx_SetCallError(call, ENOMEM);
goto fail;
}
if(rx_Read(call, (name), len) != len)
goto fail;
(name)[len] = '\0';
padlen = (4 - (len % 4)) % 4;
if(rx_Read(call, zero, padlen) != padlen)
goto fail;
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
oid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
newid = ntohl (u);
}
_result = SPR_ChangeEntry(call, id, name, oid, newid);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_SetFieldsEntry(
struct rx_call *call)
{
int32_t _result;
int32_t id;
int32_t mask;
int32_t flags;
int32_t ngroups;
int32_t nusers;
int32_t spare1;
int32_t spare2;
memset(&id, 0, sizeof(id));
memset(&mask, 0, sizeof(mask));
memset(&flags, 0, sizeof(flags));
memset(&ngroups, 0, sizeof(ngroups));
memset(&nusers, 0, sizeof(nusers));
memset(&spare1, 0, sizeof(spare1));
memset(&spare2, 0, sizeof(spare2));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
id = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
mask = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
flags = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
ngroups = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
nusers = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
spare1 = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
spare2 = ntohl (u);
}
_result = SPR_SetFieldsEntry(call, id, mask, flags, ngroups, nusers, spare1, spare2);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_Delete(
struct rx_call *call)
{
int32_t _result;
int32_t id;
memset(&id, 0, sizeof(id));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
id = ntohl (u);
}
_result = SPR_Delete(call, id);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_WhereIsIt(
struct rx_call *call)
{
int32_t _result;
int32_t id;
int32_t ps;
memset(&id, 0, sizeof(id));
memset(&ps, 0, sizeof(ps));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
id = ntohl (u);
}
_result = SPR_WhereIsIt(call, id, &ps);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (ps);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_AddToGroup(
struct rx_call *call)
{
int32_t _result;
int32_t uid;
int32_t gid;
memset(&uid, 0, sizeof(uid));
memset(&gid, 0, sizeof(gid));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
gid = ntohl (u);
}
_result = SPR_AddToGroup(call, uid, gid);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_RemoveFromGroup(
struct rx_call *call)
{
int32_t _result;
int32_t id;
int32_t gid;
memset(&id, 0, sizeof(id));
memset(&gid, 0, sizeof(gid));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
id = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
gid = ntohl (u);
}
_result = SPR_RemoveFromGroup(call, id, gid);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_ListMax(
struct rx_call *call)
{
int32_t _result;
int32_t uid;
int32_t gid;
memset(&uid, 0, sizeof(uid));
memset(&gid, 0, sizeof(gid));

_result = SPR_ListMax(call, &uid, &gid);
if (_result) goto funcfail;
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
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_SetMax(
struct rx_call *call)
{
int32_t _result;
int32_t uid;
int32_t gflag;
memset(&uid, 0, sizeof(uid));
memset(&gflag, 0, sizeof(gflag));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
gflag = ntohl (u);
}
_result = SPR_SetMax(call, uid, gflag);
if (_result) goto funcfail;
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_ListElements(
struct rx_call *call)
{
int32_t _result;
int32_t id;
prlist elist;
int32_t over;
memset(&id, 0, sizeof(id));
memset(&elist, 0, sizeof(elist));
memset(&over, 0, sizeof(over));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
id = ntohl (u);
}
_result = SPR_ListElements(call, id, &elist, &over);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (elist.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < elist.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < elist.len;++i0){
{ uint32_t u;
u = htonl (elist.val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (over);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
free(elist.val);
return _result;
fail:
free(elist.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_GetCPS(
struct rx_call *call)
{
int32_t _result;
int32_t id;
prlist elist;
int32_t over;
memset(&id, 0, sizeof(id));
memset(&elist, 0, sizeof(elist));
memset(&over, 0, sizeof(over));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
id = ntohl (u);
}
_result = SPR_GetCPS(call, id, &elist, &over);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (elist.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < elist.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < elist.len;++i0){
{ uint32_t u;
u = htonl (elist.val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (over);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
free(elist.val);
return _result;
fail:
free(elist.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_ListOwned(
struct rx_call *call)
{
int32_t _result;
int32_t id;
prlist elist;
int32_t over;
memset(&id, 0, sizeof(id));
memset(&elist, 0, sizeof(elist));
memset(&over, 0, sizeof(over));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
id = ntohl (u);
}
_result = SPR_ListOwned(call, id, &elist, &over);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (elist.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < elist.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < elist.len;++i0){
{ uint32_t u;
u = htonl (elist.val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (over);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
free(elist.val);
return _result;
fail:
free(elist.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_IsAMemberOf(
struct rx_call *call)
{
int32_t _result;
int32_t uid;
int32_t gid;
int32_t flag;
memset(&uid, 0, sizeof(uid));
memset(&gid, 0, sizeof(gid));
memset(&flag, 0, sizeof(flag));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
uid = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
gid = ntohl (u);
}
_result = SPR_IsAMemberOf(call, uid, gid, &flag);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (flag);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
return _result;
fail:
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_GetCPS2(
struct rx_call *call)
{
int32_t _result;
int32_t id;
int32_t host;
prlist elist;
int32_t over;
memset(&id, 0, sizeof(id));
memset(&host, 0, sizeof(host));
memset(&elist, 0, sizeof(elist));
memset(&over, 0, sizeof(over));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
id = ntohl (u);
}
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
host = ntohl (u);
}
_result = SPR_GetCPS2(call, id, host, &elist, &over);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (elist.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < elist.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < elist.len;++i0){
{ uint32_t u;
u = htonl (elist.val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (over);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
free(elist.val);
return _result;
fail:
free(elist.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

static int ydr_ps_PR_GetHostCPS(
struct rx_call *call)
{
int32_t _result;
int32_t host;
prlist elist;
int32_t over;
memset(&host, 0, sizeof(host));
memset(&elist, 0, sizeof(elist));
memset(&over, 0, sizeof(over));

{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
host = ntohl (u);
}
_result = SPR_GetHostCPS(call, host, &elist, &over);
if (_result) goto funcfail;
{ uint32_t u;
u = htonl (elist.len);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
{
uint32_t overI;
overI = ((uint32_t )~((uint32_t )0) >> 1) / sizeof(int32_t );
if (overI < elist.len) goto fail;
}
{
int i0;
for(i0 = 0; i0 < elist.len;++i0){
{ uint32_t u;
u = htonl (elist.val[i0]);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
}
}
{ uint32_t u;
u = htonl (over);
if(rx_Write(call, &u, sizeof(u)) != sizeof(u))
goto fail;
}
free(elist.val);
return _result;
fail:
free(elist.val);
return rx_GetCallError(call);
funcfail:
return _result;
}

int32_t PR_ExecuteRequest(struct rx_call *call)
{
unsigned opcode;
int32_t _result;
{ uint32_t u;
if(rx_Read(call, &u, sizeof(u)) != sizeof(u))
goto fail;
opcode = ntohl (u);
}
switch(opcode) {
case 504: {
_result = ydr_ps_PR_NameToID(call);
break;
}
case 505: {
_result = ydr_ps_PR_IDToName(call);
break;
}
case 509: {
_result = ydr_ps_PR_NewEntry(call);
break;
}
case 500: {
_result = ydr_ps_PR_INewEntry(call);
break;
}
case 512: {
_result = ydr_ps_PR_ListEntry(call);
break;
}
case 502: {
_result = ydr_ps_PR_DumpEntry(call);
break;
}
case 513: {
_result = ydr_ps_PR_ChangeEntry(call);
break;
}
case 516: {
_result = ydr_ps_PR_SetFieldsEntry(call);
break;
}
case 506: {
_result = ydr_ps_PR_Delete(call);
break;
}
case 501: {
_result = ydr_ps_PR_WhereIsIt(call);
break;
}
case 503: {
_result = ydr_ps_PR_AddToGroup(call);
break;
}
case 507: {
_result = ydr_ps_PR_RemoveFromGroup(call);
break;
}
case 510: {
_result = ydr_ps_PR_ListMax(call);
break;
}
case 511: {
_result = ydr_ps_PR_SetMax(call);
break;
}
case 514: {
_result = ydr_ps_PR_ListElements(call);
break;
}
case 508: {
_result = ydr_ps_PR_GetCPS(call);
break;
}
case 517: {
_result = ydr_ps_PR_ListOwned(call);
break;
}
case 515: {
_result = ydr_ps_PR_IsAMemberOf(call);
break;
}
case 518: {
_result = ydr_ps_PR_GetCPS2(call);
break;
}
case 519: {
_result = ydr_ps_PR_GetHostCPS(call);
break;
}
default:
_result = RXGEN_OPCODE;
}
return _result;
fail:
return rx_GetCallError(call);
}

