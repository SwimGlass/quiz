CC ?= gcc
CFLAGS_common ?= -O0 -g -Wall -std=gnu99

EXEC = iterative recursive
all: $(EXEC)

iterative: iterative_v2.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

clean:
	$(RM) $(EXEC) *.o perf.*
