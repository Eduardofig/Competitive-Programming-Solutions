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
