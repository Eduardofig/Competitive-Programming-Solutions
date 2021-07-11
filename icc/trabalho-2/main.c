#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VON_NEUMANN 0
#define MOORE 1
#define VIVA '#'
#define MORTA '.'

int checar_se_esta_inbounds(int posicao_i, int posicao_j, int dimensao_m_matriz, int dimensao_n_matriz)
{
    return (posicao_i < dimensao_m_matriz && posicao_j < dimensao_n_matriz);
}

void checar_numero_de_vizinhos(int modelo, char **matriz, int dimensao_m_matriz, int dimensao_n_matriz,
        int posicao_i, int posicao_j, int *n_vizinhos_vivos)
{
    *n_vizinhos_vivos = 0;
    int vetores_moore[6][2] = {
        {0, 1},
        {1, 1},
        {-1, 1},
        {0, -1},
        {1, -1},
        {-1, -1}
    },
        posicao_i_vizinho, posicao_j_vizinho;

    switch(modelo) {
        case MOORE:
            //Itera por todos os vizinhos que estao na soma dos vetores a posicao atual
            for(int i = 0; i < 6; ++i) {
                posicao_i_vizinho = posicao_i + vetores_moore[i][0];
                posicao_j_vizinho = posicao_j + vetores_moore[i][1];

                if(checar_se_esta_inbounds(posicao_i_vizinho, posicao_j_vizinho, dimensao_m_matriz, dimensao_n_matriz)) {
                    if(matriz[posicao_i_vizinho][posicao_j_vizinho] == '#') 
                        ++(*n_vizinhos_vivos);
                }
            }

            break;

        case VON_NEUMANN:
            //Avalia todos os vizinhos na vertical
            for(int i = 0; i < dimensao_m_matriz; ++i) {
                if(i != posicao_i || matriz[i][posicao_j] == VIVA)
                    ++(*n_vizinhos_vivos);
            }

            //Avalia todos os vizinhos na horizontal
            for(int j = 0; j < dimensao_n_matriz; ++j) {
                if(j != posicao_j || matriz[posicao_i][j] == VIVA) 
                    ++(*n_vizinhos_vivos);
            }

            break;
    }
}

void eval(char **M, char **copia, int m, int n, size_t tam)
{
    int n_vizinhos_vivos;

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            checar_numero_de_vizinhos(VON_NEUMANN, M, m, n, i, j, &n_vizinhos_vivos);

            if(M[i][j] == VIVA) {
                if(n_vizinhos_vivos < 2 || n_vizinhos_vivos > 3)
                    copia[i][j] = MORTA;
            } else {
                if(n_vizinhos_vivos == 3) copia[i][j] = VIVA;
            }
        }
    }

    memcpy(M, copia, tam);
}

int main(int argc, char *argv[])
{
    int m, n, p;

    scanf("%d %d %d", &m, &n, &p);

    if(m <= 0 || n <= 0 || p <= 0) {
        printf("Dados da entrada apresentam erro.\n");
    }

    char M[m][n], copia[m][n];

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%c", M[i] + j);
        }
    }

    return 0;
}
