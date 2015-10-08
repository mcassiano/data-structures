CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -g


tree-test: tree-test.o libtree.a
tree-test.o: tree-test.c tree.o
tree.o: tree.c tree.h
libtree.a: tree.o
	ar rc libtree.a tree.o

.PHONY: clean
clean:
	rm -f *.o *~a.out libtree.a *.gch tree-test
