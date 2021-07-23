#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int tipo;
    int poder;
}ataque;

int max(int a, int b)
{
    return a > b? a: b;
}

int main(int argc, char *argv[])
{
    int m;
    float **matriz;
    scanf("%d", &m);

    matriz = (float**)malloc(sizeof(float*)*m);
    for (int i = 0; i < m; ++i) {
        matriz[i] = (float*)malloc(sizeof(float)*m);
        for (int j = 0; j < m; ++j) {
            scanf("%f", matriz[i] + j);
        }
    }
    int a, b, n_ataques = 0;
    float ans = 0;
    ataque *ataques;
    while(1) {

        scanf("%d", &a);
        if(a == -1) break;
        scanf("%d", &b);

        if(!ataques) ataques = (ataque*)malloc(sizeof(ataque));
        else ataques = (ataque*)realloc(ataques, sizeof(ataque)*(n_ataques + 1));

        ataques[n_ataques].poder = a;
        ataques[n_ataques].tipo = b;

        n_ataques++;
    }

    int tipo_inimigo;

    scanf("%d", &tipo_inimigo);

    for(int i = 0; i < n_ataques; ++i) {
        ans = max(ans, matriz[ataques[i].tipo][tipo_inimigo]*ataques[i].poder);
    }

    printf("%f\n", ans);

    return 0;
}
