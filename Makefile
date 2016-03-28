# Makefile

CC = gcc
CFLAGS = -Wall -g -c

libs = quickpow.o binarysearch.o gcd.o

objs = max_sum.o test_utility.o

libs: $(libs)

quickpow.o: quickpow.c
	$(CC) $(CFLAGS) quickpow.c -o $@

binarysearch.o: binarysearch.c
	$(CC) $(CFLAGS) binarysearch.c -o $@

gcd.o: gcd.c
	$(CC) $(CFLAGS) gcd.c -o $@

progs: $(objs)

max_sum.o: max_sum.c
	$(CC) $< -o $@

test_utility.o: $(libs) test_utility.c
	$(CC) $^  -Wall -g -o $@





