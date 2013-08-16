run: main.o SList.o test.o
	cc -o run main.c SList.c test.o
main.o:main.c test.h
	cc -c main.c
test.o:test.c test.h SList.h
	cc -c test.c
SList.o:SList.c SList.h
	cc -c SList.c
clean:
	rm -f *.o run
