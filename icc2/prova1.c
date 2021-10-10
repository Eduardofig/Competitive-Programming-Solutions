/* Prova 1 de Icc 2
 * Eduardo Figureiredo Freire Andrade
 * Nusp = 11232820
 * */
#include <stdio.h>
#include <stdlib.h>

//Funcao que faz o merge entre duas particoes do mergesort
void merge(int *line, int st, int e)
{
    int *aux = (int*)malloc(sizeof(int)*(e - st + 1)),
    mid = (e + st)/2, i = st, j = mid + 1, k;

    //Insere os elementos ordenadamente no vetor auxiliar
    for(k = 0; i <= mid && j <= e; k++) {
        if (line[i] <= line[j]) aux[k] = line[i++];
        else aux[k] = line[j++];
    }

    //insere os elementos que sobraram da primeira particao
    while(i <= mid)
        aux[k++] = line[i++];

    //insere os elementos que sobraram da segunda particao
    while(j <= e)
        aux[k++] = line[j++];

    //Passa os elementos do vetor auxiliar para o vetor inical
    for(i = st, k = 0; i <= e; i++, k++)
        line[i] = aux[k];

    free(aux);

}

//Funcao que ordena um vetor usando o metodo mergesortj
void mergesort(int *line, int st, int e)
{
    //Caso base que encerra a recursao
    if (e <= st)
        return;

    int c = (e + st)/2;

    //Chamada recursiva do inicio ate o meio e do meio ate o final
    mergesort(line, st, c);
    mergesort(line, c + 1, e);

    //Merge das duas particoes
    merge(line, st, e);
}

int** alloc_matrix(int m)
{
    int **mat = malloc(sizeof(int*)*m);
    srand(m);

    int in = 0;

    // aloca matriz ordenada
    for (int i = 0; i < m; i++) {
        mat[i] = malloc(sizeof(int)*m);
        for (int j = 0; j < m; j++) {
            if (i == j) in += (rand() % 3) + 1;
            else in += rand() % 3;
            mat[i][j] = in;
        }
    }

    // desordena matriz triangular superior
    for (int i = 0; i < m - 2; i++) {
        for (int j = i + 1; j < m - 1; j++) {
            int swaps = (int)((m - j)/2.0)+1;
            for (int t = 1; t <= swaps; t++) {
                int a = (rand() % (m - j)) + j;
                int b = (rand() % (m - j)) + j;
                int tmp = mat[i][a];
                mat[i][a] = mat[i][b];
                mat[i][b] = tmp;
            }
        }

    }
    return mat;
}

//Funcao que ordena a matriz
void sort_matrix(int **matrix, int m)
{
    //Para cada linha da matriz ordena usando o mergesort da diagonal principal ate o fim
    for(int i = 0; i < m; ++i)
        mergesort(matrix[i], i, m - 1);
}

//Funcao que printa a matriz
void print_matrix(int **matrix, int m)
{
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(int **matrix, int m)
{
    for(int i = 0; i < m; ++i)
        free(matrix[i]);

    free(matrix);
}

int find_num(int num, int **matrix, int m)
{
    int st, e, mid;
    for(int i = 0; i < m; ++i) {
        st = 0;
        e = m - 1;
        if(num <= matrix[i][m - 1]) {
            while(st < e - 1) {
                mid = (st + e)/2;
                /*printf("comeco=%d fim=%d meio=%d procurando=%d atual=%d\n", st, e, mid, num, matrix[i][mid]);*/
                if(matrix[i][mid] == num) return 1;

                if(num > matrix[i][mid]) {
                    st = mid;
                } else {
                    e = mid;
                }
            }
        }

        if(matrix[i][st] == mid || matrix[i][e] == mid) return 1;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int m, z[10000], number;
    scanf("%d %d", &m, &number);

    int **matrix = alloc_matrix(m);

    sort_matrix(matrix, m);
    /*print_matrix(matrix, m);*/

    int count = 0;
    for(int i = 0; i < number; ++i) {
        printf("%d ", find_num(i, matrix, m));
    }

    free_matrix(matrix, m);

    return 0;
}
