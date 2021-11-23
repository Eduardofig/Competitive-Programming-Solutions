max_heap.o: max_heap.c
	gcc -c max_heap.c -o max_heap.o
all: max_heap.o main.c
	gcc main.c max_heap.o -g -fsanitize=address -o main
run: main
	./main
