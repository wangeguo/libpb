CFLAGS=-ansi -Wall -Werror -I../include -g -O0 --coverage
LDFLAGS=--coverage -L../lib -lpb
DEPS = person.pb.h callbacks.pb.h unittests.h unittestproto.pb.h
TESTS=test_decode1 test_encode1 decode_unittests encode_unittests

all: breakpoints $(TESTS) run_unittests

clean:
	rm -f $(TESTS) person.pb* *.o *.gcda *.gcno

%.o: %.c
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

test_decode1: test_decode1.o person.pb.o
test_encode1: test_encode1.o person.pb.o
test_decode_callbacks: test_decode_callbacks.o callbacks.pb.o
test_encode_callbacks: test_encode_callbacks.o callbacks.pb.o
decode_unittests: decode_unittests.o unittestproto.pb.o
encode_unittests: encode_unittests.o unittestproto.pb.o

%.pb: %.proto
	protoc -I. -I../include/pb -I/usr/include -o$@ $<

%.pb.c %.pb.h: %.pb ../generator/pbgen.py
	python ../generator/pbgen.py $<

breakpoints: *.c
	grep -n 'return false;' $^ | cut -d: -f-2 | xargs -n 1 echo b > $@

coverage: run_unittests
	gcov pb_encode.gcda
	gcov pb_decode.gcda

run_unittests: decode_unittests encode_unittests test_encode1 test_decode1 test_encode_callbacks test_decode_callbacks
	rm -f *.gcda
	
	./decode_unittests > /dev/null
	./encode_unittests > /dev/null
	
	[ "`./test_encode1 | ./test_decode1`" = \
	"`./test_encode1 | protoc --decode=Person -I. -I../include/pb -I/usr/include person.proto`" ]
	
	[ "`./test_encode_callbacks | ./test_decode_callbacks`" = \
	"`./test_encode_callbacks | protoc --decode=TestMessage callbacks.proto`" ]

run_fuzztest: test_decode1
	bash -c 'I=1; while cat /dev/urandom | ./test_decode1 > /dev/null; do I=$$(($$I+1)); echo -en "\r$$I"; done'
