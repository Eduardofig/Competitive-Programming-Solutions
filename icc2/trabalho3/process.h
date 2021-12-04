#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>

#define true 1
#define false 0

typedef unsigned int bool_t;

typedef struct process_t
{
    int code;
    int entry_quant;
    int remaining_quant;
    int priority;
} process_t;

process_t *new_process(int code, int entry_quant, int remaining_quant, int priority);

#endif
