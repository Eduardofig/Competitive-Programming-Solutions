binary_tree.o: binary_tree.c
	gcc -c binary_tree.c -o binary_tree.o
int_set.o: int_set.c
	gcc -c int_set.c -o int_set.o
max_heap.o: max_heap.c
	gcc -c max_heap.c -o max_heap.o
priority_queue.o: priority_queue.c
	gcc -c priority_queue.c -o priority_queue.o
utils.o: utils.c
	gcc -c utils.c -o utils.o
process.o: process.c
	gcc -c process.c -o process.o
scheduler.o: scheduler.c
	gcc -c scheduler.c -o scheduler.o
all: process.o utils.o int_set.o priority_queue.o main.c binary_tree.o max_heap.o scheduler.o
	gcc main.c process.o utils.o binary_tree.o max_heap.o priority_queue.o int_set.o scheduler.o -o main
run: main
	./main
clear: 
	rm *.o main
