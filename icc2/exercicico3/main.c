#include "list.h"

int main()
{
    list_t *l = alloc_list();

    char words[10][200] = {"eduardo", "bacana", "joncio", "otaviano", "artemio", "guilherme", "lerolero", "lambe-saco", "total", "ednaldo"};
    for(int i = 0; i < 10; ++i) insert_list(l, words[i]);

    print_list(l);

    printf("%u \n", query_list(l, "eduardo"));
    printf("%u \n", query_list(l, "joncio"));
    printf("%u \n", query_list(l, "dsjkfjs"));
    printf("%u \n", query_list(l, "epsilon"));
    printf("%u \n", query_list(l, "ednaldo"));

    free_list(&l);
}
