#include <stdio.h>

typedef struct 
{
    int x, y;
}ponto;

int main(int argc, char *argv[])
{
    //Declaracao das variaveis
    ponto re1[4], re2_centro;
    int altura1, altura2, largura1, largura2;
    //Leitura das variaveis
    scanf("%d %d %d %d %d %d %d %d", &re1[0].x, &re1[0].y, &largura1, &altura1, &re2_centro.x, &re2_centro.y, &largura2, &altura2); 
    re1[1].x = re1[0].x + largura1; re1[1].y = re1[0].y;
    re1[2].x = re1[0].x + largura1; re1[2].y = re1[0].y + altura1;
    re1[3].x = re1[0].x; re1[3].y = re1[0].y + altura1;
    if(re1[0].x == re2_centro.x && re1[0].y == re2_centro.y && re1[1].x == re2_centro.x + largura2 && re1[1].y == re2_centro.y + altura2) {
        printf("HIT: %d %d %d %d\n", re2_centro.x, re2_centro.y, largura2, altura2);
        return 0;
    }
    for (int i = 0; i < 4; ++i) {
        if(re1[i].x == re2_centro.x && re1[i].y == re2_centro.y || re1[i].x == re2_centro.x + largura2 && re1[i].y == re2_centro.y ||
                re1[i].x == re2_centro.x + largura2 && re1[i].y == re2_centro.y + altura2 || re1[i].x == re2_centro.x && re1[i].y == re2_centro.y) {

            printf("HIT 0 0 0 0\n");
        }
        if(re1[i].x > re2_centro.x && re1[i].x < re2_centro.x + largura2 && re1[i].y > re2_centro.y && re1[i].y < re2_centro.y + altura2) {
            switch(i)
            {
                case 0:
                    printf("HIT: %d %d %d %d\n", re1[i].x, re1[i].y, re2_centro.x + largura2 - re1[0].x, re2_centro.y + altura2 - re1[0].x);
                    return 0;
                case 1:
                    printf("HIT: %d %d %d %d\n", re2_centro.x, re1[i].y, re1[i].x - re2_centro.x, re2_centro.y - re1[i].y);
                    return 0;
                case 2:
                    printf("HIT: %d %d %d %d\n", re2_centro.x, re2_centro.y, re1[i].x - re2_centro.x, re1[i].y - re2_centro.y);
                    return 0;
                default:
                    printf("HIT: %d %d %d %d\n", re1[i].x, re2_centro.y, re2_centro.x + largura2 - re1[i].x, re1[i].y - re2_centro.y);
                    return 0;

            }
        }
    }
    printf("MISS\n");
    return 0;
    //Impressao do resultado
}
