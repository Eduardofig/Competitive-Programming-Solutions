max_heap.o: max_heap.c
	gcc -c max_heap.c -o max_heap.o
priority_queue.o: max_heap.o priority_queue.c
	gcc -c priority_queue.c max_heap.o -o priority_queue.o
all: max_heap.o priority_queue.o main.c
	gcc main.c priority_queue.o max_heap.o -o main
run: main
	./main
