CC = clang

HEIMDAL=/usr/heimdal

# Mac OS X 10.7
OS_CFLAGS = -arch x86_64 -I/System/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7 -DHAVE_NET_IF_DL_H=1 -DHAVE_NET_IF_TYPES_H=1
OS_LINKFLAGS = -Wl,-F. -bundle -undefined dynamic_lookup

# Ubuntu 12
#OS_CFLAGS = -I/usr/include/python2.7 -std=gnu99 -fPIC
#OS_LINKFLAGS = -pthread -shared -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-Bsymbolic-functions -Wl,-z,relro -Wl,-rpath,$(HEIMDAL)/lib

# Solaris 10
#OS_CFLAGS = -I/usr/include/python2.6 -std=gnu99 -fPIC -DHAVE_NET_IF_TYPES_H=1 -DHAVE_POSIX_SIGNALS=1 -D HAVE_SYS_SOCKIO_H=1 -I $(HEIMDAL)/include/roken
#OS_LINKFLAGS = -shared -Wl,-rpath,$(HEIMDAL)/lib

CFLAGS = -g -I . -I include -I rx -I lwp -I bufdir -I rxdef -I ko -I util -I rxkad -I $(HEIMDAL)/include -I lib -DHAVE_CONFIG_H $(OS_CFLAGS)

LIBKO=ko/afs_uuid.o \
 ko/afsconf.o ko/misc.o \
 ko/part.o \
 ko/ports.o ko/uae.o \
 ko/vlmisc.o \
 ko/kocell.o ko/resolve.o \
 ko/koerror.o

LIBLWP = lwp/fasttime.o lwp/plwp.o \
 lwp/iomgr.o lwp/preempt.o \
 lwp/lock.o lwp/q.o lwp/timer.o

LIBRX = rx/rx.o rx/rx_misc.o rx/rx_trace.o \
 rx/rx_clock.o rx/rx_user.o \
 rx/rx_null.o rx/rx_event.o rx/rx_pkt.o \
 rx/rx_globs.o rx/rx_rdwr.o

LIBRXDEF = rxdef/cb.ss.o rxdef/fs.cs.o \
 rxdef/vldb.cs.o rxdef/volumeserver.cs.o

LIBRXKAD = rxkad/decomp_ticket.o rxkad/rw.o rxkad/rxk_info.o \
 rxkad/lifetime.o rxkad/rxk_clnt.o rxkad/rxk_locl.o \
 rxkad/osi_alloc.o rxkad/rxk_crpt.o rxkad/rxk_serv.o

LIBUTIL = util/arlamath.o util/list.o util/timeval.o \
 util/hash.o util/localtime_r.o \
 util/heap.o util/log.o util/sha.o

ALLOBJECTS = $(LIBKO) $(LIBLWP) bufdir/fbuf.o bufdir/fdir.o lib/afskrb5.o lib/arlalib.o cmcb.o $(LIBRX) $(LIBRXDEF) $(LIBRXKAD) $(LIBUTIL) 

HEIMDALLIBS = -L$(HEIMDAL)/lib -lkrb5 -lcrypto -lresolv -lasn1 -lcom_err -lroken

all: all-objects pythoninterface.o
	$(CC) $(OS_LINKFLAGS) $(ALLOBJECTS) $(HEIMDALLIBS) pythoninterface.o -o arlalow.so

clean:
	rm $(ALLOBJECTS) pythoninterface.o

all-objects: $(ALLOBJECTS)
