/*
 *  cmcb.c
 *  test3
 *
 *  Created by Magnus Ahltorp on 2008-03-19.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "roken.h"

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#ifdef HAVE_NET_IF_H
#include <net/if.h>
#endif
#ifdef HAVE_NET_IF_TYPES_H
#include <net/if_types.h>
#endif
#ifdef HAVE_NET_IF_DL_H
#include <net/if_dl.h>
#endif
#ifdef HAVE_SYS_FILE_H
#include <sys/file.h>
#endif

#include <fcntl.h>
#include <ifaddrs.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <unistd.h>

#include <fs.h>

#include "afs_uuid.h"
#include "cmcb.h"

int
get_if_addr(int32_t *addr_in, int32_t *subnetmask, int32_t *mtu)
{
    struct ifaddrs *ifa, *ifa0;
    
    if (getifaddrs(&ifa0) != 0)
	ifa0 = NULL;
    
    for (ifa = ifa0; ifa != NULL; ifa = ifa->ifa_next) {
	if (ifa->ifa_addr == NULL)
	    continue;
	
	switch (ifa->ifa_addr->sa_family) {
            case AF_INET: {
                struct sockaddr_in *sin = (struct sockaddr_in *)ifa->ifa_addr;
                struct sockaddr_in *netmask = (struct sockaddr_in *)ifa->ifa_netmask;
                
                /* there are bad behavied getifaddrs() out there that
                 * doesn't set IFF_LOOPBACK */
                if (sin->sin_addr.s_addr == htonl(0x7f000001))
                    continue;
                
                memcpy(addr_in, &sin->sin_addr.s_addr, 4);
                memcpy(subnetmask, &netmask->sin_addr.s_addr, 4);
                *mtu = 1500;
                return 0;
            }
        }
    }
    return -1;
}

int
SRXAFSCB_Probe (struct rx_call *a_rxCallP)
{
    fprintf(stderr, "Probe\n");
    return 0;
}

int
SRXAFSCB_InitCallBackState (struct rx_call *a_rxCallP)
{
    fprintf(stderr, "InitCallBackState\n");
    return 0;
}

int
SRXAFSCB_CallBack (struct rx_call *a_rxCallP,
                   const AFSCBFids *a_fidArrayP,
                   const AFSCBs *a_callBackArrayP)
{
    fprintf(stderr, "CallBack\n");
    return 0;
}


int
SRXAFSCB_GetLock(struct rx_call *a_rxCallP,
                 int32_t index,
                 AFSDBLock *lock)
{
    fprintf(stderr, "GetLock\n");
    return 1;
}

int
SRXAFSCB_GetCE(struct rx_call *a_rxCallP,
               int32_t index,
               AFSDBCacheEntry *dbentry)
{
    fprintf(stderr, "GetCE\n");
    return 1;
}

int
SRXAFSCB_XStatsVersion(struct rx_call *a_rxCallP,
                       int32_t *version)
{
    fprintf(stderr, "XStatsVersion\n");
    return RXGEN_OPCODE;
}

int
SRXAFSCB_GetXStats(struct rx_call *a_rxCallP,
                   int32_t client_version_num,
                   int32_t collection_number,
                   int32_t *server_version_number,
                   int32_t *time,
                   AFSCB_CollData *stats)
{
    fprintf(stderr, "GetXStats\n");
    return RXGEN_OPCODE;
}

int
SRXAFSCB_InitCallBackState2(struct rx_call *a_rxCallP,
                            interfaceAddr *addr)
{
    fprintf(stderr, "InitCallBackState2\n");
    return RXGEN_OPCODE;
}

int
SRXAFSCB_WhoAreYou(struct rx_call *a_rxCallP,
                   interfaceAddr *addr)
{
    fprintf(stderr, "WhoAreYou\n");
    addr->numberOfInterfaces = 1;
    afsUUID_create(&addr->uuid);
    
    get_if_addr(&addr->addr_in[0], &addr->subnetmask[0], &addr->mtu[0]);
    return 0;
}

int
SRXAFSCB_InitCallBackState3(struct rx_call *a_rxCallP,
                            const afsUUID *server_uuid)
{
    fprintf(stderr, "InitCallBackState3\n");
    return 0;
}

int
SRXAFSCB_ProbeUUID(struct rx_call *a_rxCallP,
                   const afsUUID *uuid)
{
    fprintf(stderr, "ProbeUUID\n");
    return RXGEN_OPCODE;
}

int
SRXAFSCB_GetCellServDB(struct rx_call *a_rxCallP,
                       const int32_t cellIndex,
                       char *cellName,
                       serverList *cellHosts)
{
    fprintf(stderr, "GetCellServDB\n");
    return RXGEN_OPCODE;
}

int
SRXAFSCB_GetLocalCell(struct rx_call *a_rxCallP,
                      char *cellName)
{
    fprintf(stderr, "GetLocalCell\n");
    return RXGEN_OPCODE;
}

int
SRXAFSCB_GetCacheConfig(struct rx_call *a_rxCallP,
                        const uint32_t callerVersion,
                        uint32_t *serverVersion,
                        uint32_t *configCount,
                        cacheConfig *config)
{
    fprintf(stderr, "GetCacheConfig\n");
    *serverVersion = 0;
    *configCount = 0;
    config->len = 0;
    config->val = NULL;
    
    return RXGEN_OPCODE;
}

int
SRXAFSCB_GetCellByNum(struct rx_call *call,
                      const int32_t cellNumber,
                      char *cellName,
                      serverList *cellHosts)
{
    fprintf(stderr, "GetCellByNum\n");
    return RXGEN_OPCODE;
}


int
SRXAFSCB_TellMeAboutYourself(struct rx_call *call,
                             struct interfaceAddr *addr,
                             Capabilities *capabilities)
{
    fprintf(stderr, "TellMeAboutYourself\n");
#if 1
    addr->numberOfInterfaces = 1;
    afsUUID_create(&addr->uuid);
    
    get_if_addr(&addr->addr_in[0], &addr->subnetmask[0], &addr->mtu[0]);
#endif
    capabilities->len = 0;
    capabilities->val = NULL;
    return 0;
}


