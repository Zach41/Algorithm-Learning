# Makefile

CC = gcc
CFLAGS = -Wall -c

libs = quickpow.o binarysearch.o gcd.o list.o

objs = max_sum.o test_utility.o test_list.o

libs: $(libs)

quickpow.o: quickpow.c
	$(CC) $(CFLAGS) quickpow.c -o $@

binarysearch.o: binarysearch.c
	$(CC) $(CFLAGS) binarysearch.c -o $@

gcd.o: gcd.c
	$(CC) $(CFLAGS) gcd.c -o $@

list.o: list.c
	$(CC) $(CFLAGS) list.c -o $@

progs: $(objs)

max_sum.o: max_sum.c
	$(CC) $< -o $@

test_utility.o: $(libs) test_utility.c
	$(CC) $^  -Wall -g -o $@

test_list.o: $(libs) test_list.c
	$(CC) $^ -Wall -g -o $@

.PHONY: clean

clean:
	-rm $(libs) $(objs)





