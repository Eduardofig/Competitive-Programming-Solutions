#include "list.h"

void insert_from_file(list_t *l, char *file_name)
{
    FILE *stream = fopen(file_name, "r");
    char *line = NULL;
    size_t len = 0;
    int sz;

    while(true) {
        sz = getline(&line, &len, stream);
        if(sz == -1) break;

        line[sz - 1] = 0;
        insert_list(l, line);
        line = NULL;
    }

    free(line);
}

int main()
{
    list_t *l = alloc_list();
    int selector, query_result;
    char file_name[100], query[300];

    while(true) {
        scanf("%d", &selector);
        switch(selector) {
            case 0:
                free_list(&l);
                exit(0);
            case 1:
                scanf("%s", file_name);
                insert_from_file(l, file_name);
                break;
            case 2:
                mock_update_vec_list(l);
                printf("%d\n", get_n_ptrs_list(l));
                break;
            case 3:
                scanf("%s", query);

                if(!is_updated_list(l)) {
                    printf("Vetor de índices não atualizado.\n");
                    break;
                }

                query_result = query_list(l, query);

                if(query_result == -1) printf("Palavra não existe na lista.\n");
                else printf("%d\n", query_result);

                break;
        }
    }

    return 0;
}
