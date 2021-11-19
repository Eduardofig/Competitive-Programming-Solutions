list.o: list.c
	gcc -c list.c -g -fsanitize=address -o list.o
all: list.o
	gcc main.c list.o -g -fsanitize=address -o main
run: main
	./main
