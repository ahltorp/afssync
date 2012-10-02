/* Generated from ka.xg */
#ifndef _ka_
#define _ka_

#include <atypes.h>

#define AUTHENTICATE_OLD 1

#define CHANGEPASSWORD 2

#define GETTICKET_OLD 3

#define SETPASSWORD 4

#define SETFIELDS 5

#define CREATEUSER 6

#define DELETEUSER 7

#define GETENTRY 8

#define LISTENTRY 9

#define GETSTATS 10

#define DEBUG 11

#define GETPASSWORD 12

#define GETRANDOMKEY 13

#define AUTHENTICATE 21

#define GETTICKET 23

#define MAXKAKVNO 127

#define KAFNORMAL 1

#define KAFREE 2

#define KAOLDKEYS 16

#define KASPECIAL 256

#define KAFASSOCROOT 512

#define KAFASSOC 768

#define KAFADMIN 4

#define KAFNOTGS 8

#define KAFNOSEAL 32

#define KAFNOCPW 64

#define KAFNEWASSOC 128

#define KAMAJORVERSION 5

#define KAMINORVERSION 1

#define NEVERDATE 2147483647

#define KADEBUGKCINFOSIZE 25

#define KADATABASEINCONSISTENT 180480

#define KAEXIST 180481

#define KAIO 180482

#define KACREATEFAIL 180483

#define KANOENT 180484

#define KAEMPTY 180485

#define KABADNAME 180486

#define KABADINDEX 180487

#define KANOAUTH 180488

#define KAANSWERTOOLONG 180489

#define KABADREQUEST 180490

#define KAOLDINTERFACE 180491

#define KABADARGUMENT 180492

#define KABADCMD 180493

#define KANOKEYS 180494

#define KAREADPW 180495

#define KABADKEY 180496

#define KAUBIKINIT 180497

#define KAUBIKCALL 180498

#define KABADPROTOCOL 180499

#define KANOCELLS 180500

#define KANOCELL 180501

#define KATOOMANYUBIKS 180502

#define KATOOMANYKEYS 180503

#define KABADTICKET 180504

#define KAUNKNOWNKEY 180505

#define KAKEYCACHEINVALID 180506

#define KABADSERVER 180507

#define KABADUSER 180508

#define KABADCPW 180509

#define KABADCREATE 180510

#define KANOTICKET 180511

#define KAASSOCUSER 180512

#define KANOTSPECIAL 180513

#define KACLOCKSKEW 180514

#define KANORECURSE 180515

#define KARXFAIL 180516

#define KANULLPASSWORD 180517

#define KAINTERNALERROR 180518

#define KAPWEXPIRED 180519

#define KAREUSED 180520

#define KATOOSOON 180521

#define KALOCKED 180522

struct ka_CBS {
     struct {
unsigned len;
char *val;
} Seq;
};
typedef struct ka_CBS ka_CBS;

char *ydr_encode_ka_CBS(const ka_CBS *o, char *ptr, size_t *total_len);
const char *ydr_decode_ka_CBS(ka_CBS *o, const char *ptr, size_t *total_len);
void ydr_print_ka_CBS(ka_CBS *o);
void ydr_free_ka_CBS(ka_CBS *o);
struct ka_BBS {
     int32_t MaxSeqLen;
     struct {
unsigned len;
char *val;
} Seq;
};
typedef struct ka_BBS ka_BBS;

char *ydr_encode_ka_BBS(const ka_BBS *o, char *ptr, size_t *total_len);
const char *ydr_decode_ka_BBS(ka_BBS *o, const char *ptr, size_t *total_len);
void ydr_print_ka_BBS(ka_BBS *o);
void ydr_free_ka_BBS(ka_BBS *o);
struct EncryptionKey {
     char key[ 8 ];
};
typedef struct EncryptionKey EncryptionKey;

#define ENCRYPTIONKEY_SIZE 32
char *ydr_encode_EncryptionKey(const EncryptionKey *o, char *ptr, size_t *total_len);
const char *ydr_decode_EncryptionKey(EncryptionKey *o, const char *ptr, size_t *total_len);
void ydr_print_EncryptionKey(EncryptionKey *o);
void ydr_free_EncryptionKey(EncryptionKey *o);
#define MAXKANAMELEN 64

#define KA_LABELSIZE 4

#ifndef MAXKTCTICKETLEN
#define MAXKTCTICKETLEN 344

#endif
typedef char kaname[64];

#define KANAME_SIZE 64
char *ydr_encode_kaname(const kaname *o, char *ptr, size_t *total_len);
const char *ydr_decode_kaname(kaname *o, const char *ptr, size_t *total_len);
void ydr_print_kaname(kaname *o);
void ydr_free_kaname(kaname *o);
struct kaident {
     char name[ 64 ];
     char instance[ 64 ];
};
typedef struct kaident kaident;

#define KAIDENT_SIZE 512
char *ydr_encode_kaident(const kaident *o, char *ptr, size_t *total_len);
const char *ydr_decode_kaident(kaident *o, const char *ptr, size_t *total_len);
void ydr_print_kaident(kaident *o);
void ydr_free_kaident(kaident *o);
struct kaentryinfo {
     int32_t minor_version;
     int32_t flags;
     uint32_t user_expiration;
     uint32_t modification_time;
     struct kaident modification_user;
     uint32_t change_password_time;
     int32_t max_ticket_lifetime;
     int32_t key_version;
     struct EncryptionKey key;
     uint32_t keyCheckSym;
     int32_t reserved2;
     int32_t reserved3;
     int32_t reserved4;
};
typedef struct kaentryinfo kaentryinfo;

#define KAENTRYINFO_SIZE 588
char *ydr_encode_kaentryinfo(const kaentryinfo *o, char *ptr, size_t *total_len);
const char *ydr_decode_kaentryinfo(kaentryinfo *o, const char *ptr, size_t *total_len);
void ydr_print_kaentryinfo(kaentryinfo *o);
void ydr_free_kaentryinfo(kaentryinfo *o);

#endif /* ka */
