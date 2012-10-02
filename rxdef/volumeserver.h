/* Generated from volumeserver.xg */
#ifndef _volumeserver_
#define _volumeserver_

#include "atypes.h"

#include "fs_errors.h"
#define VLDB_MAXSERVER 80

#define VOLSERVICE_PORT 7005

#define VOLSERVICE_ID 4

#define INVALID_BID 0

#define VOLSER_MAXVOLNAME 65

#define VOLSER_OLDMAXVOLNAME 32

#define VOLSER_MAX_REPSITES 7

#define VNAMESIZE 32

#define VOLCREATEVOLUME 100

#define VOLDELETEVOLUME 101

#define VOLRESTORE 102

#define VOLFORWARD 103

#define VOLENDTRANS 104

#define VOLCLONE 105

#define VOLSETFLAGS 106

#define VOLGETFLAGS 107

#define VOLTRANSCREATE 108

#define VOLDUMP 109

#define VOLGETNTHVOLUME 110

#define VOLSETFORWARDING 111

#define VOLGETNAME 112

#define VOLGETSTATUS 113

#define VOLSIGNALRESTORE 114

#define VOLLISTPARTITIONS 115

#define VOLLISTVOLUMES 116

#define VOLSETIDTYPES 117

#define VOLMONITOR 118

#define VOLPARTITIONINFO 119

#define VOLRECLONE 120

#define VOLLISTONEVOLUME 121

#define VOLNUKEVOLUME 122

#define VOLSETDATE 123

#define VOLXLISTVOLUMES 124

#define VOLXLISTONEVOL 125

#define VOLSETINFO 126

#define VOLXLISTPARTITIONS 127

#define VOLFORWARDMULTIPLE 128

#define PARTVALID 1

#define VOK 2

#define VBUSY 110

#define VOLSERTRELE_ERROR 1492325120

#define VOLSERNO_OP 1492325121

#define VOLSERREAD_DUMPERROR 1492325122

#define VOLSERDUMPERROR 1492325123

#define VOLSERATTACH_ERROR 1492325124

#define VOLSERILLEGAL_PARTITION 1492325125

#define VOLSERDETACH_ERROR 1492325126

#define VOLSERBAD_ACCESS 1492325127

#define VOLSERVLDB_ERROR 1492325128

#define VOLSERBADNAME 1492325129

#define VOLSERVOLMOVED 1492325130

#define VOLSERBADOP 1492325131

#define VOLSERBADRELEASE 1492325132

#define VOLSERVOLBUSY 1492325133

#define VOLSERNO_MEMORY 1492325134

#define VOLSERNOVOL 1492325135

#define VOLSERMULTIRWVOL 1492325136

#define VOLSERFAILEDOP 1492325137

#define ITOffline 1

#define ITBusy 2

#define ITReadOnly 8

#define ITCreate 16

#define ITCreateVolID 4096

#define TTDeleted 1

#define VTDeleteOnSalvage 1

#define VTOutOfService 2

#define VTDeleted 4

struct volDescription {
     char volName[ 65 ];
     int32_t volId;
     int32_t volSize;
     int32_t volFlags;
     int32_t volCloneId;
};
typedef struct volDescription volDescription;

#define VOLDESCRIPTION_SIZE 276
char *ydr_encode_volDescription(const volDescription *o, char *ptr, size_t *total_len);
const char *ydr_decode_volDescription(volDescription *o, const char *ptr, size_t *total_len);
void ydr_print_volDescription(volDescription *o);
void ydr_free_volDescription(volDescription *o);
struct partList {
     int32_t partId[ 26 ];
     int32_t partFlags[ 26 ];
};
typedef struct partList partList;

#define PARTLIST_SIZE 208
char *ydr_encode_partList(const partList *o, char *ptr, size_t *total_len);
const char *ydr_decode_partList(partList *o, const char *ptr, size_t *total_len);
void ydr_print_partList(partList *o);
void ydr_free_partList(partList *o);
struct volser_status {
     int32_t volID;
     int32_t nextUnique;
     int32_t type;
     int32_t parentID;
     int32_t cloneID;
     int32_t backupID;
     int32_t restoredFromID;
     int32_t maxQuota;
     int32_t minQuota;
     int32_t owner;
     int32_t creationDate;
     int32_t accessDate;
     int32_t updateDate;
     int32_t exprirationDate;
     int32_t backupDate;
     int32_t copyDate;
};
typedef struct volser_status volser_status;

#define VOLSER_STATUS_SIZE 64
char *ydr_encode_volser_status(const volser_status *o, char *ptr, size_t *total_len);
const char *ydr_decode_volser_status(volser_status *o, const char *ptr, size_t *total_len);
void ydr_print_volser_status(volser_status *o);
void ydr_free_volser_status(volser_status *o);
struct destServer {
     int32_t destHost;
     int32_t destPort;
     int32_t destSSID;
};
typedef struct destServer destServer;

#define DESTSERVER_SIZE 12
char *ydr_encode_destServer(const destServer *o, char *ptr, size_t *total_len);
const char *ydr_decode_destServer(destServer *o, const char *ptr, size_t *total_len);
void ydr_print_destServer(destServer *o);
void ydr_free_destServer(destServer *o);
struct volintInfo {
     char name[ 32 ];
     int32_t volid;
     int32_t type;
     int32_t backupID;
     int32_t parentID;
     int32_t cloneID;
     int32_t status;
     int32_t copyDate;
     char inUse;
     char needsSalvaged;
     char destroyMe;
     int32_t creationDate;
     int32_t accessDate;
     int32_t updateDate;
     int32_t backupDate;
     int32_t dayUse;
     int32_t filecount;
     int32_t maxquota;
     int32_t size;
     int32_t flags;
     int32_t spare0;
     int32_t spare1;
     int32_t spare2;
     int32_t spare3;
};
typedef struct volintInfo volintInfo;

#define VOLINTINFO_SIZE 220
char *ydr_encode_volintInfo(const volintInfo *o, char *ptr, size_t *total_len);
const char *ydr_decode_volintInfo(volintInfo *o, const char *ptr, size_t *total_len);
void ydr_print_volintInfo(volintInfo *o);
void ydr_free_volintInfo(volintInfo *o);
struct xvolintInfo {
     char name[ 32 ];
     int32_t volid;
     int32_t type;
     int32_t backupID;
     int32_t parentID;
     int32_t cloneID;
     int32_t status;
     int32_t copyDate;
     char inUse;
     int32_t creationDate;
     int32_t accessDate;
     int32_t updateDate;
     int32_t backupDate;
     int32_t dayUse;
     int32_t filecount;
     int32_t maxquota;
     int32_t size;
     int32_t stat_reads[ 4 ];
     int32_t stat_writes[ 4 ];
     int32_t stat_fileSameAuthor[ 6 ];
     int32_t stat_fileDiffAuthor[ 6 ];
     int32_t stat_dirSameAuthor[ 6 ];
     int32_t stat_dirDiffAuthor[ 6 ];
};
typedef struct xvolintInfo xvolintInfo;

#define XVOLINTINFO_SIZE 320
char *ydr_encode_xvolintInfo(const xvolintInfo *o, char *ptr, size_t *total_len);
const char *ydr_decode_xvolintInfo(xvolintInfo *o, const char *ptr, size_t *total_len);
void ydr_print_xvolintInfo(xvolintInfo *o);
void ydr_free_xvolintInfo(xvolintInfo *o);
struct transDebugInfo {
     int32_t tid;
     int32_t time;
     int32_t creationTime;
     int32_t returnCode;
     int32_t volid;
     int32_t partition;
     int16_t iflags;
     char vflags;
     char tflags;
     char lastProcName[ 30 ];
     int32_t callValid;
     int32_t readNext;
     int32_t transmitNext;
     int32_t lastSendTime;
     int32_t lastReceiveTime;
};
typedef struct transDebugInfo transDebugInfo;

#define TRANSDEBUGINFO_SIZE 176
char *ydr_encode_transDebugInfo(const transDebugInfo *o, char *ptr, size_t *total_len);
const char *ydr_decode_transDebugInfo(transDebugInfo *o, const char *ptr, size_t *total_len);
void ydr_print_transDebugInfo(transDebugInfo *o);
void ydr_free_transDebugInfo(transDebugInfo *o);
struct pIDs {
     int32_t partIds[ 26 ];
};
typedef struct pIDs pIDs;

#define PIDS_SIZE 104
char *ydr_encode_pIDs(const pIDs *o, char *ptr, size_t *total_len);
const char *ydr_decode_pIDs(pIDs *o, const char *ptr, size_t *total_len);
void ydr_print_pIDs(pIDs *o);
void ydr_free_pIDs(pIDs *o);
struct diskPartition {
     char name[ 32 ];
     char devName[ 32 ];
     int32_t lock_fd;
     int32_t totalUsable;
     int32_t free;
     int32_t minFree;
};
typedef struct diskPartition diskPartition;

#define DISKPARTITION_SIZE 272
char *ydr_encode_diskPartition(const diskPartition *o, char *ptr, size_t *total_len);
const char *ydr_decode_diskPartition(diskPartition *o, const char *ptr, size_t *total_len);
void ydr_print_diskPartition(diskPartition *o);
void ydr_free_diskPartition(diskPartition *o);
struct restoreCookie {
     char name[ 32 ];
     int32_t type;
     int32_t clone;
     int32_t parent;
};
typedef struct restoreCookie restoreCookie;

#define RESTORECOOKIE_SIZE 140
char *ydr_encode_restoreCookie(const restoreCookie *o, char *ptr, size_t *total_len);
const char *ydr_decode_restoreCookie(restoreCookie *o, const char *ptr, size_t *total_len);
void ydr_print_restoreCookie(restoreCookie *o);
void ydr_free_restoreCookie(restoreCookie *o);
typedef struct {
unsigned len;
struct transDebugInfo *val;
} transDebugEntries;

char *ydr_encode_transDebugEntries(const transDebugEntries *o, char *ptr, size_t *total_len);
const char *ydr_decode_transDebugEntries(transDebugEntries *o, const char *ptr, size_t *total_len);
void ydr_print_transDebugEntries(transDebugEntries *o);
void ydr_free_transDebugEntries(transDebugEntries *o);
typedef struct {
unsigned len;
struct volintInfo *val;
} volEntries;

char *ydr_encode_volEntries(const volEntries *o, char *ptr, size_t *total_len);
const char *ydr_decode_volEntries(volEntries *o, const char *ptr, size_t *total_len);
void ydr_print_volEntries(volEntries *o);
void ydr_free_volEntries(volEntries *o);
typedef struct {
unsigned len;
struct xvolintInfo *val;
} xvolEntries;

char *ydr_encode_xvolEntries(const xvolEntries *o, char *ptr, size_t *total_len);
const char *ydr_decode_xvolEntries(xvolEntries *o, const char *ptr, size_t *total_len);
void ydr_print_xvolEntries(xvolEntries *o);
void ydr_free_xvolEntries(xvolEntries *o);
typedef struct {
unsigned len;
int32_t *val;
} part_entries;

char *ydr_encode_part_entries(const part_entries *o, char *ptr, size_t *total_len);
const char *ydr_decode_part_entries(part_entries *o, const char *ptr, size_t *total_len);
void ydr_print_part_entries(part_entries *o);
void ydr_free_part_entries(part_entries *o);
typedef struct {
unsigned len;
int32_t *val;
} multi_results;

char *ydr_encode_multi_results(const multi_results *o, char *ptr, size_t *total_len);
const char *ydr_decode_multi_results(multi_results *o, const char *ptr, size_t *total_len);
void ydr_print_multi_results(multi_results *o);
void ydr_free_multi_results(multi_results *o);
struct replica {
     int32_t trans_id;
     struct destServer destserver;
};
typedef struct replica replica;

#define REPLICA_SIZE 16
char *ydr_encode_replica(const replica *o, char *ptr, size_t *total_len);
const char *ydr_decode_replica(replica *o, const char *ptr, size_t *total_len);
void ydr_print_replica(replica *o);
void ydr_free_replica(replica *o);
typedef struct {
unsigned len;
struct replica *val;
} manyDests;

#define MANYDESTS_MAX_SIZE 4084
char *ydr_encode_manyDests(const manyDests *o, char *ptr, size_t *total_len);
const char *ydr_decode_manyDests(manyDests *o, const char *ptr, size_t *total_len);
void ydr_print_manyDests(manyDests *o);
void ydr_free_manyDests(manyDests *o);

#endif /* volumeserver */
