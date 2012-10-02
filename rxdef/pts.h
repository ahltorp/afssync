/* Generated from pts.xg */
#ifndef _pts_
#define _pts_

#include <atypes.h>

#include <fs_errors.h>
#define PRINEWUSER 500

#define PRWHEREISIT 501

#define PRDUMPENTRY 502

#define PRADDTOGROUP 503

#define PRNAMETOUID 504

#define PRIDTONAME 505

#define PRDELETE 506

#define PRREMOVEFROMGROUP 507

#define PRGETCPS 508

#define PRNEWENTRY 509

#define PRLISTMAX 510

#define PRSETMAX 511

#define PRLISTENTRY 512

#define PRCHANGEENTRY 513

#define PRLISTELEMENTS 514

#define PROSAMEMBEROF 515

#define PRSETFIELDSENTRY 516

#define PRLISTOWNED 517

#define PRGETCPS2 518

#define PRGETHOSTCPS 519

#define PR_MAXNAMELEN 64

#define PR_MAXGROUPS 5000

#define PR_MAXLIST 5000

#define PRSIZE 10

#define COSIZE 39

#define PRSRV 73

#define ENTRYSIZE 192

#define HASHSIZE 8191

#define PRDBVERSION 0

#define PR_SF_NGROUPS 2147483647

#define PR_SF_NUSERS 1073741824

#define PR_SF_ALLBITS 255

#define PR_SYSADMINID -204

#define PR_ANYUSERID -101

#define PR_AUTHUSERID -102

#define PR_ANONYMOUSID 32766

#define PR_BADID 2147483647

#define PRTYPE 63

#define PRFREE 1

#define PRGRP 2

#define PRCONT 4

#define PRCELL 8

#define PRFOREIGN 16

#define PRINST 32

#define PRUSER 0

#define PRACCESS 64

#define PRQUOTA 128

#define PRP_REMOVE_MEM 65536

#define PRP_ADD_MEM 131072

#define PRP_ADD_ANY 262144

#define PRP_MEMBER_MEM 524288

#define PRP_MEMBER_ANY 1048576

#define PRP_OWNED_ANY 2097152

#define PRP_STATUS_MEM 4194304

#define PRP_STATUS_ANY 8388608

#define PRSUCCESS 0

#define PR_REMEMBER_TIMES 1

struct prheader {
     int32_t version;
     int32_t headerSize;
     int32_t freePtr;
     int32_t eofPtr;
     int32_t maxGroup;
     int32_t maxID;
     int32_t maxForeign;
     int32_t maxInst;
     int32_t orphan;
     int32_t usercount;
     int32_t groupcount;
     int32_t foreigncount;
     int32_t instcount;
     int32_t reserved[ 5 ];
     int32_t nameHash[ 8191 ];
     int32_t idHash[ 8191 ];
};
typedef struct prheader prheader;

#define PRHEADER_SIZE 65600
char *ydr_encode_prheader(const prheader *o, char *ptr, size_t *total_len);
const char *ydr_decode_prheader(prheader *o, const char *ptr, size_t *total_len);
void ydr_print_prheader(prheader *o);
void ydr_free_prheader(prheader *o);
struct prheader_disk {
     int32_t version;
     int32_t headerSize;
     int32_t maxGroup;
     int32_t maxID;
     struct {
unsigned len;
int32_t *val;
} orphan;
     int32_t usercount;
     int32_t groupcount;
};
typedef struct prheader_disk prheader_disk;

char *ydr_encode_prheader_disk(const prheader_disk *o, char *ptr, size_t *total_len);
const char *ydr_decode_prheader_disk(prheader_disk *o, const char *ptr, size_t *total_len);
void ydr_print_prheader_disk(prheader_disk *o);
void ydr_free_prheader_disk(prheader_disk *o);
struct prentry {
     int32_t flags;
     int32_t id;
     int32_t cellid;
     int32_t next;
     int32_t reserved[ 5 ];
     int32_t entries[ 10 ];
     int32_t nextID;
     int32_t nextName;
     int32_t owner;
     int32_t creator;
     int32_t ngroups;
     int32_t nusers;
     int32_t count;
     int32_t instance;
     int32_t owned;
     int32_t nextOwned;
     int32_t parent;
     int32_t sibling;
     int32_t child;
     char name[ 64 ];
};
typedef struct prentry prentry;

#define PRENTRY_SIZE 384
char *ydr_encode_prentry(const prentry *o, char *ptr, size_t *total_len);
const char *ydr_decode_prentry(prentry *o, const char *ptr, size_t *total_len);
void ydr_print_prentry(prentry *o);
void ydr_free_prentry(prentry *o);
struct prentry_disk {
     int32_t flags;
     int32_t id;
     int32_t cellid;
     int32_t owner;
     int32_t creator;
     int32_t ngroups;
     struct {
unsigned len;
int32_t *val;
} owned;
     char name[64];
     struct {
unsigned len;
int32_t *val;
} entries;
};
typedef struct prentry_disk prentry_disk;

#define PRENTRY_DISK_MAX_SIZE 40096
char *ydr_encode_prentry_disk(const prentry_disk *o, char *ptr, size_t *total_len);
const char *ydr_decode_prentry_disk(prentry_disk *o, const char *ptr, size_t *total_len);
void ydr_print_prentry_disk(prentry_disk *o);
void ydr_free_prentry_disk(prentry_disk *o);
struct prdebugentry {
     int32_t flags;
     int32_t id;
     int32_t cellid;
     int32_t next;
     int32_t reserved[ 5 ];
     int32_t entries[ 10 ];
     int32_t nextID;
     int32_t nextname;
     int32_t owner;
     int32_t creator;
     int32_t ngroups;
     int32_t nusers;
     int32_t count;
     int32_t instance;
     int32_t owned;
     int32_t nextOwned;
     int32_t parent;
     int32_t sibling;
     int32_t child;
     char name[ 64 ];
};
typedef struct prdebugentry prdebugentry;

#define PRDEBUGENTRY_SIZE 384
char *ydr_encode_prdebugentry(const prdebugentry *o, char *ptr, size_t *total_len);
const char *ydr_decode_prdebugentry(prdebugentry *o, const char *ptr, size_t *total_len);
void ydr_print_prdebugentry(prdebugentry *o);
void ydr_free_prdebugentry(prdebugentry *o);
struct prcheckentry {
     int32_t flags;
     int32_t id;
     int32_t owner;
     int32_t creator;
     int32_t ngroups;
     int32_t nusers;
     int32_t count;
     int32_t reserved[ 5 ];
     char name[ 64 ];
};
typedef struct prcheckentry prcheckentry;

#define PRCHECKENTRY_SIZE 304
char *ydr_encode_prcheckentry(const prcheckentry *o, char *ptr, size_t *total_len);
const char *ydr_decode_prcheckentry(prcheckentry *o, const char *ptr, size_t *total_len);
void ydr_print_prcheckentry(prcheckentry *o);
void ydr_free_prcheckentry(prcheckentry *o);
typedef char prname[ 64 ];

#define PRNAME_SIZE 256
char *ydr_encode_prname(const prname *o, char *ptr, size_t *total_len);
const char *ydr_decode_prname(prname *o, const char *ptr, size_t *total_len);
void ydr_print_prname(prname *o);
void ydr_free_prname(prname *o);
typedef struct {
unsigned len;
prname *val;
} namelist;

#define NAMELIST_MAX_SIZE 1280004
char *ydr_encode_namelist(const namelist *o, char *ptr, size_t *total_len);
const char *ydr_decode_namelist(namelist *o, const char *ptr, size_t *total_len);
void ydr_print_namelist(namelist *o);
void ydr_free_namelist(namelist *o);
typedef struct {
unsigned len;
int32_t *val;
} idlist;

#define IDLIST_MAX_SIZE 20004
char *ydr_encode_idlist(const idlist *o, char *ptr, size_t *total_len);
const char *ydr_decode_idlist(idlist *o, const char *ptr, size_t *total_len);
void ydr_print_idlist(idlist *o);
void ydr_free_idlist(idlist *o);
typedef struct {
unsigned len;
int32_t *val;
} prlist;

#define PRLIST_MAX_SIZE 20004
char *ydr_encode_prlist(const prlist *o, char *ptr, size_t *total_len);
const char *ydr_decode_prlist(prlist *o, const char *ptr, size_t *total_len);
void ydr_print_prlist(prlist *o);
void ydr_free_prlist(prlist *o);
#define PREXIST 267264

#define PRIDEXIST 267265

#define PRNOIDS 267266

#define PRDBFAIL 267267

#define PRNOENT 267268

#define PRPERM 267269

#define PRNOTGROUP 267270

#define PRNOTUSER 267271

#define PRBADNAM 267272

#define PRBADARG 267273

#define PRNOMORE 267274

#define PRDBBAD 267275

#define PRGROUPEMPTY 267276

#define PRINCONSISTENT 267277

#define PRBADDR 267278

#define PRTOOMANY 267279


#endif /* pts */
