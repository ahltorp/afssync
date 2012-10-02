#include "rx_locl.h"

RCSID("$Id: rx_misc.c,v 1.1.1.1 2008/03/22 16:58:37 ahltorp Exp $");

/*
 * We currently only include below the errors that
 * affect us the most. We should add to this list
 * more code mappings, as necessary.
 */

/*
 * Convert from the local (host) to the standard
 * (network) system error code.
 */
uint32_t
hton_syserr_conv(uint32_t code)
{
    uint32_t error;

#if 0
    if (code == ENOSPC)
	error = VDISKFULL;
#ifndef	AFS_SUN5_ENV
    /* EDQUOT doesn't exist on solaris */
    else if (code == EDQUOT)
	error = VOVERQUOTA;
#endif
    else
#endif
	error = code;
    return error;
}


/*
 * Convert from the standard (Network) format to the
 * local (host) system error code.
 */
uint32_t
ntoh_syserr_conv(uint32_t code)
{
    uint32_t error;

#if 0
    if (code == VDISKFULL)
	error = ENOSPC;
    else if (code == VOVERQUOTA)
#ifdef	AFS_SUN5_ENV
	error = ENOSPC;
#else
	error = EDQUOT;
#endif
    else
#endif
	error = code;
    return error;
}
