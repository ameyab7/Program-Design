a.out: main.o code.o
		gcc main.o code.o

main.o: main.c header.h
		gcc -c main.c
		
code.o: code.c header.h
		gcc -c code.c

clean:
		rm -f a.out main.o code.o
