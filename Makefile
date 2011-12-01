CC ?= gcc

#---------------------------------------------
# Uncomment exactly one of the lines labelled (A), (B), and (C) below
# to switch between compilation modes.

OPT ?= -O2 -DNDEBUG         # (A) Production use (optimized mode)
# OPT ?= -g2                # (B) Debug mode, w/ full line-level debugging symbols
# OPT ?= -O2 -g2 -DNDEBUG   # (C) Profiling mode: opt, but w/debugging symbols
#---------------------------------------------

CFLAGS = -c -I./include $(OPT)

LIBOBJECTS = ./src/decode.o ./src/encode.o
LIBRARY = ./lib/libpb.a
SUBDIRS = example tests docs


all: $(LIBRARY)

clean:
	-rm -rf ./lib/ ./src/*.o
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean || exit $$?; \
	done

$(LIBRARY): $(LIBOBJECTS)
	test -d lib || mkdir lib
	$(AR) -rs $@ $(LIBOBJECTS)

# for libpb developer
descriptor:
	-rm -f ./generator/pb_pb2.py
	protoc -I./include/pb -I/usr/include --python_out=./generator/ ./include/pb/pb.proto
	
.c.o:
	$(CC) $(CFLAGS) $< -o $@

install:
	cp -vf $(LIBRARY) /usr/local/lib/
	cp -vrf ./include/pb /usr/local/include/
