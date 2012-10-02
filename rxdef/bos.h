/* Generated from bos.xg */
#ifndef _bos_
#define _bos_

#include <atypes.h>

#include <fs_errors.h>
#define BZNOTACTIVE 39424

#define BZNOENT 39425

#define BZBUSY 39426

#define BZEXISTS 39427

#define BZNOCREATE 39428

#define BZDOM 39429

#define BZACCESS 39430

#define BZSYNTAX 39431

#define BZIO 39432

#define BZNET 39433

#define BZBADTYPE 39434

#define BOZO_BSSIZE 256

#define BSTAT_SHUTDOWN 0

#define BSTAT_NORMAL 1

#define BSTAT_SHUTTINGDOWN 2

#define BSTAT_STARTINGUP 3

#define BOZO_PRUNEOLD 1

#define BOZO_PRUNEBAK 2

#define BOZO_PRUNECORE 4

#define BPROC_STARTED 1

#define BPROC_EXITED 2

#define BOZO_HASCORE 1

#define BOZO_ERRORSTOP 2

#define BOZO_BADDIRACCESS 4

#define BNODE_NEEDTIMEOUT 1

#define BNODE_ACTIVE 2

#define BNODE_WAIT 4

#define BNODE_DELETE 8

#define BNODE_ERRORSTOP 16

#define KTIME_HOUR 1

#define KTIME_MIN 2

#define KTIME_SEC 4

#define KTIME_DAY 8

#define KTIME_TIME 7

#define KTIME_NEVER 16

#define KTIME_NOW 32

#define BOZO_RESTARTTIME_GENERAL 1

#define BOZO_RESTARTTIME_NEWBIN 2

struct bozo_status {
     int32_t goal;
     int32_t fileGoal;
     int32_t porcStartTime;
     int32_t procStarts;
     int32_t lastAnyExit;
     int32_t lastErrorExit;
     int32_t errorCode;
     int32_t errorSignal;
     int32_t flags;
     int32_t spare[ 8 ];
};
typedef struct bozo_status bozo_status;

#define BOZO_STATUS_SIZE 68
char *ydr_encode_bozo_status(const bozo_status *o, char *ptr, size_t *total_len);
const char *ydr_decode_bozo_status(bozo_status *o, const char *ptr, size_t *total_len);
void ydr_print_bozo_status(bozo_status *o);
void ydr_free_bozo_status(bozo_status *o);
struct bozo_netKTime {
     int32_t mask;
     int16_t hour;
     int16_t min;
     int16_t sec;
     int16_t day;
};
typedef struct bozo_netKTime bozo_netKTime;

#define BOZO_NETKTIME_SIZE 20
char *ydr_encode_bozo_netKTime(const bozo_netKTime *o, char *ptr, size_t *total_len);
const char *ydr_decode_bozo_netKTime(bozo_netKTime *o, const char *ptr, size_t *total_len);
void ydr_print_bozo_netKTime(bozo_netKTime *o);
void ydr_free_bozo_netKTime(bozo_netKTime *o);
struct bozo_key {
     char data[ 8 ];
};
typedef struct bozo_key bozo_key;

#define BOZO_KEY_SIZE 32
char *ydr_encode_bozo_key(const bozo_key *o, char *ptr, size_t *total_len);
const char *ydr_decode_bozo_key(bozo_key *o, const char *ptr, size_t *total_len);
void ydr_print_bozo_key(bozo_key *o);
void ydr_free_bozo_key(bozo_key *o);
struct bozo_keyInfo {
     int32_t mod_sec;
     int32_t mod_usec;
     uint32_t keyCheckSum;
     int32_t spare2;
};
typedef struct bozo_keyInfo bozo_keyInfo;

#define BOZO_KEYINFO_SIZE 16
char *ydr_encode_bozo_keyInfo(const bozo_keyInfo *o, char *ptr, size_t *total_len);
const char *ydr_decode_bozo_keyInfo(bozo_keyInfo *o, const char *ptr, size_t *total_len);
void ydr_print_bozo_keyInfo(bozo_keyInfo *o);
void ydr_free_bozo_keyInfo(bozo_keyInfo *o);

#endif /* bos */
