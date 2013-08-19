#########################################################
# 	 Makefile -- For data_structure run 
# 
# 	Author:   Shuting Chen (cst),cicy0125@gmail.com 
# 	Company:  ucas.ict.bwstor
# 
##########################################################

CC=cc
OFLAGS=-lm
OBJECTS:=main.o test.o
OBJECTS+=SList.o CStack.o BTree.o VStack.o

SOURCE:=main.c test.c
SOURCE+=SList.c CStack.c BTree.c VStack.c

TEST_SOURCE:=test.c test.h
TEST_SOURCE+=SList.h CStack.h BTree.h

run:$(OBJECTS)
	$(CC) -o run $(SOURCE)
main.o:main.c test.h
	$(CC) -c main.c
test.o:$(TEST_SOURCE)
	$(CC) -c test.c
SList.o:SList.c SList.h
	$(CC) -c SList.c
CStask.o:CStack.c CStack.h
	$(CC) -c CStack.c
BTree.o:BTree.c BTree.h
	$(CC) -c BTree.c
VStack.o:VStack.c VStack.h
	$(CC) -c VStack.c
clean:
	rm -f *.o run
