func.o: func.c
	gcc -c func.c -o func.o
sort.o: sort.c
	gcc -c sort.c -o sort.o
main.o: main.c
	gcc -c main.c -o main.o
all: main.o func.o sort.o
	gcc main.o func.o sort.o -lm -o main
run: main
	./main
clean: main func.o sort.o main.o
	rm *.o main
