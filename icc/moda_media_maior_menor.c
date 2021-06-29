#include <stdio.h>
#include <stdlib.h>

int funcao_comparacao (const void * a, const void * b) {
   return (*(int*)a - *(int*)b);
}

int moda(int *numeros)
{
    //Ordenacao do array
    qsort(numeros, 10, sizeof(int), funcao_comparacao);
    int moda = numeros[0], atual = numeros[0], contagem_moda = 0, contagem_atual = 0;

    for(int i = 0; i < 10; ++i) {
        //Se o numero eh diferente do atual, atualiza o atual e a contagem_atual fica zero
        if(numeros[i] != atual) {
            atual = numeros[i];
            contagem_atual = 0;
        }
        //Se o numero atual eh mais recorrente que a moda, a moda vira o atual
        if(contagem_atual > contagem_moda) {
            contagem_moda = contagem_atual;
            moda = atual;
        }
        contagem_atual++;
    }

    return moda;
}

int maior(int *numeros)
{
    int maior = numeros[0];
    for(int i = 1; i < 10; ++i) if(numeros[i] > maior) maior = numeros[i];
    return maior;
}

int menor(int *numeros) 
{
    int menor = numeros[0];
    for(int i = 1; i < 10; ++i) if(numeros[i] < menor) menor = numeros[i];
    return menor;
}

float media(int *numeros)
{
    float media = 0;
    for(int i = 0; i < 10; ++i) media += numeros[i];
    return media/10;
}

int main(int argc, char *argv[])
{
    int numeros[10];
    for(int i = 0; i < 10; ++i) scanf("%d", numeros + i);
    printf("%d %d %.2f %d\n", maior(numeros), menor(numeros), media(numeros), moda(numeros));
    return 0;
}
