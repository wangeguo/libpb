CFLAGS=-ansi -Wall -I../include -g -O0
LDFLAGS = -L../lib -lpb

all: server client

clean:
	-rm -rf server client fileproto.pb.c fileproto.pb.h *.dSYM

%: %.c fileproto.pb.h fileproto.pb.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< fileproto.pb.c common.c

fileproto.pb.c fileproto.pb.h: fileproto.proto ../generator/pbgen.py
	protoc -I. -I../include/pb -I/usr/include -ofileproto.pb $<
	python ../generator/pbgen.py fileproto.pb
