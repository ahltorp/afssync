/*
 *  config.h
 *  test3
 *
 *  Created by Magnus Ahltorp on 2008-03-20.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#define HAVE_OPENSSL 1
#define HAVE_NETDB_H 1
#define HAVE_RES_SEARCH 1
#define HAVE_DN_EXPAND 1
#define HAVE_RESOLV_H 1
#define HAVE_ARPA_NAMESER_H 1
#define HAVE_NET_IF_DL_H 1
#define HAVE_NET_IF_TYPES_H 1

#define PTHREADS_LWP 1

#define EFF_NTOHL ntohl

#define RCSID(a) static char *rcsid = ""

#define SYSCONFDIR "."

#define RXDEBUG 1

#define HAVE_KRB5

#ifndef HAVE_ERRNO_H
#define HAVE_ERRNO_H
#endif

#if 0
#define DPRINT(s) printf s
#define DEBUG 1
#define RXDEBUG 1
#else
#define DPRINT(s) do {} while (0)
#endif

#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <strings.h>

#define FD_SPEED_HACK 1
