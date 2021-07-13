#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define VON_NEUMANN 'N'
#define MOORE 'M'
#define VIVA 'x'
#define MORTA '.'

//Funcao que mantem as posicoes de vizinhanca dentro da matriz, dando a volta para o outro lado se 
//preciso
void manter_inbounds(int *posicao_i, int *posicao_j, int dimensao_m_matriz, int dimensao_n_matriz)
{
    if(*posicao_i >= dimensao_m_matriz) *posicao_i -= dimensao_m_matriz;
    else if(*posicao_i < 0) *posicao_i += dimensao_m_matriz;

    if(*posicao_j >= dimensao_n_matriz) *posicao_j -= dimensao_n_matriz;
    else if(*posicao_j < 0) *posicao_j += dimensao_n_matriz;
}

//Funcao que retorna o numero de vizinhos vivos de uma determinada celula
int contar_vizinhos_vivos(char modelo, char **matriz, int dimensao_m_matriz, int dimensao_n_matriz,
        int posicao_i, int posicao_j)
{
    int posicao_i_vizinho, posicao_j_vizinho, seletor_vetor, n_vizinhos_vivos = 0,
        vetores_direcao[2][8][2] = {
            {
                {0, 1},
                {0, 2},
                {0, -1},
                {0, -2},
                {1, 0},
                {2, 0},
                {-1, 0},
                {-2, 0}
            },
            {
                {0, 1},
                {1, 1},
                {-1, 1},
                {0, -1},
                {1, -1},
                {-1, -1},
                {1, 0},
                {-1, 0}
            }
        };

    if(modelo == VON_NEUMANN) seletor_vetor = 0;
    else if(modelo == MOORE) seletor_vetor = 1;

    for(int i = 0; i < 8; ++i) {
        posicao_i_vizinho = posicao_i + vetores_direcao[seletor_vetor][i][0];
        posicao_j_vizinho = posicao_j + vetores_direcao[seletor_vetor][i][1];

        manter_inbounds(&posicao_i_vizinho, &posicao_j_vizinho, dimensao_m_matriz, dimensao_n_matriz);

        if(matriz[posicao_i_vizinho][posicao_j_vizinho] == VIVA) 
            ++n_vizinhos_vivos;
    }

    return n_vizinhos_vivos;
}

//Funcao que aplica todas as mortes e vidas de uma determinada geracao
void avaliar_geracao(char **matriz, char **copia, char modelo, int dimensao_m_matriz, int dimensao_n_matriz)
{
    int n_vizinhos_vivos;

    for(int i = 0; i < dimensao_m_matriz; ++i) {
        for(int j = 0; j < dimensao_n_matriz; ++j) {
            n_vizinhos_vivos = contar_vizinhos_vivos(modelo, matriz, dimensao_m_matriz, dimensao_n_matriz, i, j);

            if(matriz[i][j] == VIVA) {
                if(n_vizinhos_vivos < 2 || n_vizinhos_vivos > 3) {
                    copia[i][j] = MORTA;
                }
            } else {
                if(n_vizinhos_vivos == 3) {
                    copia[i][j] = VIVA;
                }
            }
        }
    }

    for(int i = 0; i < dimensao_m_matriz; ++i)
        memcpy(matriz[i], copia[i], sizeof(char)*dimensao_n_matriz);
}

//Funcao que imprime a matriz
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
        printf("Dados de entrada apresentam erro.\n");
        exit(0);
    }

    char **M = (char**)malloc(sizeof(char*)*m), **copia = (char**)malloc(sizeof(char*)*m);

    scanf(" ");

    //scan das matrizes
    for(int i = 0; i < m; ++i) {
        M[i] = (char*)malloc(sizeof(char)*n);
        copia[i] = (char*)malloc(sizeof(char)*n);

        for(int j = 0; j < n; ++j) {
            scanf("%c", M[i] + j);
            if(M[i][j] != VIVA && M[i][j] != MORTA) {
                printf("Dados de entrada apresentam erro.\n");
                for(int k = 0; k < i; ++k) {
                    free(M[k]);
                    free(copia[k]);
                }
                free(M);
                free(copia);
                exit(0);
            }
            scanf("\n");
        }

        memcpy(copia[i], M[i], sizeof(char)*n);
    }

    for(int i = 0; i < p; ++i) {
        system("clear");
        imprimir_matriz(M, m, n);
        avaliar_geracao(M, copia, v, m, n);
        usleep(3e5);
    }

    imprimir_matriz(M, m, n);

    for(int i = 0; i < m; ++i) {
        free(M[i]);
        free(copia[i]);
    }
    free(M);
    free(copia);

    return 0;
}
