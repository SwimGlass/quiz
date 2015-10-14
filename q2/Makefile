CC ?= gcc
CFLAGS_common ?= -O0 -g -Wall -std=gnu99

#EXEC = iterative recursive
EXEC = iterative iterative_str
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

iterative_str: iterative_str.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

per: iterative
	perf stat -r 10 -e cache-misses,cache-references,L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses ./$^
per_str: iterative_str
	perf stat -r 10 -e cache-misses,cache-references,L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses ./$^
clean:
	$(RM) $(EXEC) *.o perf.*
