/*
 *  roken.h
 *  test3
 *
 *  Created by Magnus Ahltorp on 2008-03-19.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */
#include "config.h"

#include <sys/time.h>


#define PTHREADS_LWP 1

#define FALSE 0
#define TRUE 1

#define FD_SPEED_HACK 1

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define RETSIGTYPE void

#if 0
#define DPRINT(s) printf s
#define DEBUG 1
#define RXDEBUG 1
#else
#define DPRINT(s) do {} while (0)
#endif

#define SYSCONFDIR "."

#include <sys/types.h>
#include <stdlib.h>
#include <strings.h>
#define HAVE_RES_SEARCH 1
#define HAVE_DN_EXPAND 1
#define HAVE_RESOLV_H 1
#define HAVE_ARPA_NAMESER_H 1
#define HAVE_NET_IF_DL_H 1
#define HAVE_NET_IF_TYPES_H 1
#define HAVE_NETDB_H 1
//#define __BIND_NOSTATIC 1
