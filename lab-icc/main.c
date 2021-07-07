#include <stdio.h>
#include <string.h>

#define ALTURA_MATRIZ 32
#define LARGURA_MATRIZ 64

//Diz se a posicao esta dentro das bordas da matriz
int esta_na_matriz(int i, int j) 
{
    return (i >= 0 && i < ALTURA_MATRIZ) && (j >= 0 && j < LARGURA_MATRIZ);
}

//Troca 2 particulas de posicao
void trocar_particulas(char *elemento_1, char *elemento_2)
{
    char elemento_temporario = *elemento_1;

    *elemento_1 = *elemento_2;
    *elemento_2 = elemento_temporario;
}

//Funcao que processa a particula de agua
void processar_agua(int posicao_i, int posicao_j, char tela[ALTURA_MATRIZ][LARGURA_MATRIZ], char copia[ALTURA_MATRIZ][LARGURA_MATRIZ])
{
    int direcoes_agua[5][2] = {
        {1, 0},
        {1, -1},
        {1, 1},
        {0, -1},
        {0, 1}
    };

    int destino_i, destino_j;

    for(int i = 0; i < 5; ++i) {
        destino_i = posicao_i + direcoes_agua[i][0];
        destino_j = posicao_j + direcoes_agua[i][1];

        if(!esta_na_matriz(destino_i, destino_j)) continue;

        if(tela[destino_i][destino_j] == ' ') {
            trocar_particulas(&copia[posicao_i][posicao_j], &copia[destino_i][destino_j]);
            return;
        }
    }
}

//Funcao que processa a particula de areia
void processar_areia(int posicao_i, int posicao_j, char tela[ALTURA_MATRIZ][LARGURA_MATRIZ], char copia[ALTURA_MATRIZ][LARGURA_MATRIZ])
{
    int direcoes_areia[3][2] = {
        {1, 0},
        {1, -1},
        {1, 1}
    };

    int destino_i, destino_j;

    for(int i = 0; i < 3; ++i) {
        destino_i = posicao_i + direcoes_areia[i][0];
        destino_j = posicao_j + direcoes_areia[i][1];

        if(!esta_na_matriz(destino_i, destino_j)) continue;

        if(tela[destino_i][destino_j] == ' ' || tela[destino_i][destino_j] == '~') {
            trocar_particulas(&copia[posicao_i][posicao_j], &copia[destino_i][destino_j]);
            return;
        }
    }
}

//Funcao da engine que chama os processamentos de cada particula
void engine(char tela[ALTURA_MATRIZ][LARGURA_MATRIZ], char copia[ALTURA_MATRIZ][LARGURA_MATRIZ])
{
    for(int i = 0; i < ALTURA_MATRIZ; ++i) {
        for(int j = 0; j < LARGURA_MATRIZ; ++j) {
            switch(tela[i][j]) {
                case '@':
                case ' ':
                    break;
                case '~':
                    processar_agua(i, j, tela, copia);
                    break;
                case '#':
                    processar_areia(i, j, tela, copia);
                    break;
            }
        }
    }
}

void imprimir_matriz_e_calcular_fisica(char tela[ALTURA_MATRIZ][LARGURA_MATRIZ], char copia[ALTURA_MATRIZ][LARGURA_MATRIZ], size_t tam)
{

    //Copia a matriz copia para a matriz tela
    memcpy(tela, copia, tam);

    for(int i = 0; i < ALTURA_MATRIZ; ++i) {
        for(int j = 0; j < LARGURA_MATRIZ; ++j) {
            printf("%c", tela[i][j]);
        }
        printf("\n");
    }

    engine(tela, copia);
}

int main(int argc, char *argv[])
{
    char tela[ALTURA_MATRIZ][LARGURA_MATRIZ], copia[ALTURA_MATRIZ][LARGURA_MATRIZ];

    for(int i = 0; i < ALTURA_MATRIZ; ++i) 
        for(int j = 0; j < LARGURA_MATRIZ; ++j) 
            copia[i][j] = ' ';

    int n_frames, frame, x, y;
    char nova_particula;

    scanf("%d", &n_frames);

    int contador = 0;
    while (contador < n_frames) {

        // `scanf` retorna EOF quando chega ao fim da entrada.
        int n_lido = scanf(" %d: %d %d %c", &frame, &x, &y, &nova_particula);

        // Se não há mais partículas a serem criadas, continue até o final
        // da simulação.
        if (n_lido == EOF) {
            frame = n_frames;
        }

        // Calcula todos os frames até o próximo frame onde queremos criar
        // uma partícula.
        while (contador < frame) {
            printf("frame: %d\n", contador + 1);
            imprimir_matriz_e_calcular_fisica(tela, copia, sizeof(copia));
            contador++;
        }

        // Se há uma particula a ser criada, crie ela.
        if (n_lido != EOF) {
            copia[y][x] = nova_particula;
        }
    }

    return 0;
}
