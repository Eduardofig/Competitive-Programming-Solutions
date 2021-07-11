#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define VON_NEUMANN 'N'
#define MOORE 'M'
#define VIVA 'x'
#define MORTA '.'

int checar_se_esta_inbounds(int posicao_i, int posicao_j, int dimensao_m_matriz, int dimensao_n_matriz)
{
    return (posicao_i >= 0 && posicao_i < dimensao_m_matriz && posicao_j >= 0 && posicao_j < dimensao_n_matriz);
}

int contar_vizinhos_vivos(char modelo, char **matriz, int dimensao_m_matriz, int dimensao_n_matriz,
        int posicao_i, int posicao_j)
{
    int vetores_moore[8][2] = {
        {0, 1},
        {1, 1},
        {-1, 1},
        {0, -1},
        {1, -1},
        {-1, -1},
        {1, 0},
        {-1, 0}
    },
        posicao_i_vizinho, posicao_j_vizinho, n_vizinhos_vivos = 0;

    switch(modelo) {
        case MOORE:
            //Itera por todos os vizinhos que estao na soma dos vetores a posicao atual
            /*printf("[%d][%d]:\n", posicao_i, posicao_j);*/
            for(int i = 0; i < 8; ++i) {
                posicao_i_vizinho = posicao_i + vetores_moore[i][0];
                posicao_j_vizinho = posicao_j + vetores_moore[i][1];

                if(checar_se_esta_inbounds(posicao_i_vizinho, posicao_j_vizinho, dimensao_m_matriz, dimensao_n_matriz)) {
                    /*printf("[%d][%d] = %c\n", posicao_i_vizinho, posicao_j_vizinho, matriz[posicao_i_vizinho][posicao_j_vizinho]);*/
                    if(matriz[posicao_i_vizinho][posicao_j_vizinho] == VIVA) 
                        ++n_vizinhos_vivos;
                }
            }

            break;

        case VON_NEUMANN:
            //Avalia todos os vizinhos na vertical
            for(int i = 0; i < dimensao_m_matriz; ++i) {
                if(i != posicao_i || matriz[i][posicao_j] == VIVA)
                    ++n_vizinhos_vivos;
            }

            //Avalia todos os vizinhos na horizontal
            for(int j = 0; j < dimensao_n_matriz; ++j) {
                if(j != posicao_j || matriz[posicao_i][j] == VIVA) 
                    ++n_vizinhos_vivos;
            }

            break;
    }
    return n_vizinhos_vivos;
}

void avaliar_geracao(char **matriz, char **copia, char modelo, int dimensao_m_matriz, int dimensao_n_matriz,
        size_t tamanho_matriz)
{
    int n_vizinhos_vivos;

    for(int i = 0; i < dimensao_m_matriz; ++i) {
        for(int j = 0; j < dimensao_n_matriz; ++j) {
            n_vizinhos_vivos = contar_vizinhos_vivos(modelo, matriz, dimensao_m_matriz, dimensao_n_matriz, i, j);
            /*printf("[%d][%d] = %c, n_vizinhos =  %d\n", i, j, matriz[i][j], n_vizinhos_vivos);*/

            if(matriz[i][j] == VIVA) {
                if(n_vizinhos_vivos < 2 || n_vizinhos_vivos > 3) {
                    printf("morrer: [%d][%d]\n", i, j);
                    copia[i][j] = MORTA;
                }
            } else {
                if(n_vizinhos_vivos == 3) {
                    printf("viver: [%d][%d]\n", i, j);
                    copia[i][j] = VIVA;
                }
            }
        }
    }

    memcpy(matriz, copia, tamanho_matriz);
}

void imprimir_matriz(char **matriz, int dimensao_m_matriz, int dimensao_n_matriz)
{
    for(int i = 0; i < dimensao_m_matriz; ++i) {
        for(int j = 0; j < dimensao_n_matriz; ++j) {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int m, n, p;
    char v;

    scanf("%d %d %d %c", &m, &n, &p, &v);

    if(m <= 0 || n <= 0 || p <= 0) {
        printf("Dados da entrada apresentam erro.\n");
        exit(0);
    }

    char **M = (char**)malloc(sizeof(char*)*m), **copia = (char**)malloc(sizeof(char*)*m);

    for(int i = 0; i < m; ++i) {
        M[i] = (char*)malloc(sizeof(char)*n);
        copia[i] = (char*)malloc(sizeof(char)*n);
        scanf("%s", M[i]);
    }

    memcpy(copia, M, sizeof(char)*m*n);

    imprimir_matriz(M, m, n);
    for(int i = 0; i < p; ++i) {
        /*system("clear");*/
        avaliar_geracao(M, copia, v, m, n, sizeof(char)*m*n);
        printf("\n");
        imprimir_matriz(M, m, n);
        /*usleep(800000);*/
    }
    printf("final.\n");

    /*for(int i = 0; i < m; ++i) {*/
    /*free(M[i]);*/
    /*free(copia[i]);*/
    /*}*/
    /*free(M);*/
    /*free(copia);*/

    return 0;
}
