/*
 * Copyright (c) 1998 - 2002 Kungliga Tekniska Högskolan
 * (Royal Institute of Technology, Stockholm, Sweden).
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
RCSID("$Id: koerror.c,v 1.2 2008/07/23 13:22:44 ahltorp Exp $");
#endif

#include <stdio.h>
#include <string.h>

#include "roken.h"

#include "rx.h"
#include "rxkad.h"
#include "ko.h"
#include "fs_errors.h"

#include "vldb.h"
#include "volumeserver.h"

struct koerr {
    koerr_t code;
    const char *msg;
};

static struct koerr koerrmsg[] = {

    /* VL server errors */

    {VL_IDEXIST,        "VL - Volume Id entry exists in vl database."},
    {VL_IO,             "VL - I/O related error."},
    {VL_NAMEEXIST,      "VL - Volume name entry exists in vl database."},
    {VL_CREATEFAIL,     "VL - Internal creation failure."},
    {VL_NOENT,          "VL - No such entry."},
    {VL_EMPTY,          "VL - Vl database is empty."},
    {VL_ENTDELETED,     "VL - Entry is deleted (soft delete)."},
    {VL_BADNAME,        "VL - Volume name is illegal."},
    {VL_BADINDEX,       "VL - Index is out of range."},
    {VL_BADVOLTYPE,     "VL - Bad volume type."},
    {VL_BADPARTITION,   "VL - Illegal server number (out of range)."},
    {VL_BADSERVER,      "VL - Bad partition number."},
    {VL_REPSFULL,       "VL - Run out of space for Replication sites."},
    {VL_NOREPSERVER,    "VL - No such Replication server site exists."},
    {VL_DUPREPSERVER,   "VL - Replication site alreay exists."},
    {VL_RWNOTFOUND,     "VL - Parent R/W entry no found."},
    {VL_BADREFCOUNT,    "VL - Illegal reference count numner."},
    {VL_SIZEEXCEEDED,   "VL - Vl size for attributes exceeded."},
    {VL_BADENTRY,       "VL - Bad incming vl entry."},
    {VL_BADVOLIDBUMP,   "VL - Illegal max volid increment."},
    {VL_IDALREADHASED,  "VL - RO/BACK id already hashed."},
    {VL_ENTRYLOCKED,    "VL - Vl entry is already locked."},
    {VL_BADVOLOPER,     "VL - Bad volume operation code."},
    {VL_BADRELLOCKTYPE, "VL - Bad release lock type."},
    {VL_RERELEASE,      "VL - Status report: last release was aborted."},
    {VL_BADSERVERFLAG,  "VL - Invalid replication site server flag."},
    {VL_PERM,           "VL - No permission access."},
    {VL_NOMEM,          "VL - malloc(realloc) failed to alloc enough memory"},
    {VL_BADVERSION,	"VL - Bad version"},
    {VL_INDEXERANGE,	"VL - Index out of range"},
    {VL_MULTIPADDR,	"VL - Multiple IP addresses"},
    {VL_BADMASK,	"VL - Bad mask"},

    /* VOLSER errors */

    {VOLSERTRELE_ERROR,       "VOLSER - Internal error releasing "
                              "transaction."},
    {VOLSERNO_OP,             "VOLSER - Unknown internal error."},
    {VOLSERREAD_DUMPERROR,    "VOLSER - Badly formatted dump."},
    {VOLSERDUMPERROR,         "VOLSER - Badly formatted dump(2)."},
    {VOLSERATTACH_ERROR,      "VOLSER - Could not attach volume."},
    {VOLSERILLEGAL_PARTITION, "VOLSER - Illegal partition."},
    {VOLSERDETACH_ERROR,      "VOLSER - Could not detach volume."},
    {VOLSERBAD_ACCESS,        "VOLSER - Insufficient privilege for "
                              "volume operation."},
    {VOLSERVLDB_ERROR,        "VOLSER - Error from volume location database."},
    {VOLSERBADNAME,           "VOLSER - Bad volume name."},
    {VOLSERVOLMOVED,          "VOLSER - Volume moved."},
    {VOLSERBADOP,             "VOLSER - Illegal volume operation."},
    {VOLSERBADRELEASE,        "VOLSER - Volume release failed."},
    {VOLSERVOLBUSY,           "VOLSER - Volume still in use by volserver."},
    {VOLSERNO_MEMORY,         "VOLSER - Out of virtual memory."},
    {VOLSERNOVOL,	      "VOLSER - No such volume."},
    {VOLSERMULTIRWVOL,        "VOLSER - More then one read/write volume."},
    {VOLSERFAILEDOP,          "VOLSER - Failed volume server operation."},


    {RXGEN_CC_MARSHAL,	      "rxgen - cc_marshal"},
    {RXGEN_CC_UNMARSHAL,      "rxgen - cc_unmarshal"},
    {RXGEN_SS_MARSHAL,	      "rxgen - ss_marshal"},
    {RXGEN_SS_UNMARSHAL,      "rxgen - ss_unmarshal"},
    {RXGEN_DECODE,	      "rxgen - decode"},
    {RXGEN_OPCODE,	      "rxgen - opcode"},
    {RXGEN_SS_XDRFREE,	      "rxgen - ss_xdrfree"},
    {RXGEN_CC_XDRFREE,	      "rxgen - cc_xdrfree"},

#ifdef KERBEROS
    /* rxkad - XXX more sane messages */

    {RXKADINCONSISTENCY,      "rxkad - Inconsistency."},
    {RXKADPACKETSHORT,        "rxkad - Packet too short."},
    {RXKADLEVELFAIL,          "rxkad - Security level failed."},
    {RXKADTICKETLEN,          "rxkad - Invalid ticket length."},
    {RXKADOUTOFSEQUENCE,      "rxkad - Out of sequence."},
    {RXKADNOAUTH,             "rxkad - No authentication."},
    {RXKADBADKEY,             "rxkad - Bad key."},
    {RXKADBADTICKET,          "rxkad - Bad ticket."},
    {RXKADUNKNOWNKEY,         "rxkad - Unknown key."},
    {RXKADEXPIRED,            "rxkad - Ticket expired."},
    {RXKADSEALEDINCON,        "rxkad - Seal inconsistency."},
    {RXKADDATALEN,            "rxkad - Datalength error."},
    {RXKADILLEGALLEVEL,       "rxkad - Illegal level."},

#endif

    {ARLA_VSALVAGE,           "arla-fs-error - salvaging"},
    {ARLA_VNOVNODE,           "arla-fs-error - no such vnode"},
    {ARLA_VNOVOL,             "arla-fs-error - no such volume"},
    {ARLA_VVOLEXISTS,         "arla-fs-error - volume already exists"},
    {ARLA_VNOSERVICE,         "arla-fs-error - no service"},
    {ARLA_VOFFLINE,           "arla-fs-error - volume offline"},
    {ARLA_VONLINE,            "arla-fs-error - volume online"},
    {ARLA_VDISKFULL,          "arla-fs-error - disk full"},
    {ARLA_VOVERQUOTA,         "arla-fs-error - quoua full"},
    {ARLA_VBUSY,              "arla-fs-error - busy volume"},
    {ARLA_VMOVED,             "arla-fs-error - moved volume"},
    {ARLA_VIO,                "arla-fs-error - I/O error"},
    {ARLA_VRESTARTING,        "arla-fs-error - restarting"},

    /* rx errors */

    {ARLA_CALL_DEAD,		"rx - call dead"},
    {ARLA_INVALID_OPERATION,	"rx - invalid operation"},
    {ARLA_CALL_TIMEOUT,		"rx - call timeout"},
    {ARLA_EOF,			"rx - end of data"},
    {ARLA_PROTOCOL_ERROR,	"rx - protocol error"},
    {ARLA_USER_ABORT,		"rx - user abort"},
    {ARLA_ADDRINUSE,		"rx - address already in use"},
    {ARLA_MSGSIZE,		"rx - packet too big"},

    /* Not a known error */

    { 0L,              "Unknown error"}
};



const char *
koerr_gettext(koerr_t err) 
{
    const char *ret = NULL;
    struct koerr *koerror = koerrmsg;

    while (koerror->code != 0) {
	if (err == koerror->code)
	    break;
	++koerror;
    }

    if (koerror->code == 0)
	ret = strerror(err);
    if (!ret)
	ret = koerror->msg;

    return ret;
}
