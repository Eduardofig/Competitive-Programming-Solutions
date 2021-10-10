func.o: func.c
	gcc -c func.c -o func.o
main.o: main.c func.o
	gcc -c main.c -o main.o
all: main.o func.o
	gcc main.o func.o -lm -o main
run: main
	./main
