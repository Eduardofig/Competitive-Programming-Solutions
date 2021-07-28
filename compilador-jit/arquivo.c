#include <stdio.h>

int main() {
    char mem[3000];
    int i = 0;
    for(int j = 0; j < 3000; ++j) {
        mem[j] = 0;
    }
    mem[i]++;
    mem[i]++;
    i++;
    mem[i]++;
    mem[i]++;
    putchar(mem[i]);
    while(mem[i]) {
        mem[i]--;
    }
    printf("\n");
    for(int j = 0; j < 3000; ++j){
        if (mem[j] != 0) {
            printf("%d ", mem[j]);
        }
    }

    printf("\n");

    return 0;
}
