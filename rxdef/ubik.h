/* Generated from ubik.xg */
#ifndef _ubik_
#define _ubik_

#include <atypes.h>

#include <fs_errors.h>
struct net_tid {
     int32_t epoch;
     int32_t counter;
};
typedef struct net_tid net_tid;

#define NET_TID_SIZE 8
char *ydr_encode_net_tid(const net_tid *o, char *ptr, size_t *total_len);
const char *ydr_decode_net_tid(net_tid *o, const char *ptr, size_t *total_len);
void ydr_print_net_tid(net_tid *o);
void ydr_free_net_tid(net_tid *o);
#define UBIK_MAX_INTERFACE_ADDR 256

typedef struct net_tid net_version;

#define NET_VERSION_SIZE 8
char *ydr_encode_net_version(const net_version *o, char *ptr, size_t *total_len);
const char *ydr_decode_net_version(net_version *o, const char *ptr, size_t *total_len);
void ydr_print_net_version(net_version *o);
void ydr_free_net_version(net_version *o);
struct ubik_debug {
     int32_t now;
     int32_t lastYesTime;
     int32_t lastYesHost;
     int32_t lastYesState;
     int32_t lastYesClaim;
     int32_t lowestHost;
     int32_t lowestTime;
     int32_t syncHost;
     int32_t syncTime;
     net_version syncVersion;
     struct net_tid syncTid;
     int32_t amSyncSite;
     int32_t syncSiteUntil;
     int32_t nServers;
     int32_t lockedPages;
     int32_t writeLockedPages;
     net_version localVersion;
     int32_t activeWrite;
     int32_t tidCounter;
     int32_t anyReadLocks;
     int32_t anyWriteLocks;
     int32_t recoveryState;
     int32_t currentTrans;
     int32_t writeTrans;
     int32_t epochTime;
};
typedef struct ubik_debug ubik_debug;

#define UBIK_DEBUG_SIZE 112
char *ydr_encode_ubik_debug(const ubik_debug *o, char *ptr, size_t *total_len);
const char *ydr_decode_ubik_debug(ubik_debug *o, const char *ptr, size_t *total_len);
void ydr_print_ubik_debug(ubik_debug *o);
void ydr_free_ubik_debug(ubik_debug *o);
struct ubik_sdebug {
     int32_t addr;
     int32_t lastVoteTime;
     int32_t lastBeaconSent;
     int32_t lastVote;
     net_version remoteVersion;
     int32_t currentDB;
     int32_t beaconSinceDown;
     int32_t up;
     int32_t altAddr[ 255 ];
};
typedef struct ubik_sdebug ubik_sdebug;

#define UBIK_SDEBUG_SIZE 1056
char *ydr_encode_ubik_sdebug(const ubik_sdebug *o, char *ptr, size_t *total_len);
const char *ydr_decode_ubik_sdebug(ubik_sdebug *o, const char *ptr, size_t *total_len);
void ydr_print_ubik_sdebug(ubik_sdebug *o);
void ydr_free_ubik_sdebug(ubik_sdebug *o);
#define VOTE_BEACON 10000

#define VOTE_DEBUG 10001

#define VOTE_SDEBUG 10002

#define VOTE_GETSYNCSITE 10003

#define UNOQUORUM 5376

#define UNOTSYNC 5377

#define UNHOSTS 5378

#define UIOERROR 5379

#define UINTERNAL 5380

#define USYNC 5381

#define UNOENT 5382

#define UBADLOCK 5383

#define UBADLOG 5384

#define UBADHOST 5385

#define UBADTYPE 5386

#define UTWOENDS 5387

#define UDONE 5388

#define UNOSERVERS 5389

#define UEOF 5390

#define ULOGIO 5391

#define UBADFAM 5392

#define UBADCELL 5393

#define UBADSECGRP 5394

#define UBADGROUP 5395

#define UBADUUID 5396

#define UNOMEM 5397

#define UNOTMEMBER 5398

#define UNBINDINGS 5399

#define UBADPRINNAME 5400

#define UPIPE 5401

#define UDEADLOCK 5402

#define UEXCEPTION 5403

#define UTPQFAIL 5404

#define USKEWED 5405

#define UNOLOCK 5406

#define UNOACCESS 5407

#define UNOSPC 5408

#define UBADPATH 5409

#define UBADF 5410

#define UREINITIALIZE 5411


#include "rx_multi.h"
#define multi_Ubik_Beacon(state, voteStart, Version, tid) multi_Body(StartUbik_Beacon(multi_call, state, voteStart, Version, tid), EndUbik_Beacon(multi_call))

#endif /* ubik */
