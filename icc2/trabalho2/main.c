#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "func.h"

//Funcao que faz o merge entre duas particoes do mergesort
void merge(double *magnitude, double complex *compressed, int *origin, int st, int e)
{
    double *aux = (double*)malloc(sizeof(double)*(e - st + 1));
    double complex *z_aux = (double complex*)malloc(sizeof(double complex)*(e - st + 1));
    int *o_aux = (int*)malloc(sizeof(int)*(e - st + 1));

    int mid = (e + st) / 2, i = st, j = mid + 1, k;

    // Insere os elementos ordenadamente no vetor auxiliar
    for (k = 0; i <= mid && j <= e; k++) {
        if(magnitude[i] >= magnitude[j]) {
            o_aux[k] = origin[i];
            z_aux[k] = compressed[i];
            aux[k] = magnitude[i++];
        } else {
            o_aux[k] = origin[j];
            z_aux[k] = compressed[j];
            aux[k] = magnitude[j++];
        }
    }

    // insere os elementos que sobraram da primeira particao
    while(i <= mid) {
        o_aux[k] = origin[i];
        z_aux[k] = compressed[i];
        aux[k++] = magnitude[i++];
    }

    // insere os elementos que sobraram da segunda particao
    while(j <= e) {
        o_aux[k] = origin[j];
        z_aux[k] = compressed[j];
        aux[k++] = magnitude[j++];
    }

    // Passa os elementos do vetor auxiliar para o vetor inical
    for(i = st, k = 0; i <= e; i++, k++) {
        origin[i] = o_aux[k];
        compressed[i] = z_aux[k];
        magnitude[i] = aux[k];
    }

    free(aux);
}

//Funcao que ordena um vetor usando o metodo mergesortj
void mergesort_compressed(double *magnitude, double complex *compressed, int *origin, int st, int e)
{
    // Caso base que encerra a recursao
    if (e <= st)
        return;

    int c = (e + st)/2;

    // Chamada recursiva do inicio ate o meio e do meio ate o final
    mergesort_compressed(magnitude, compressed, origin, st, c);
    mergesort_compressed(magnitude, compressed, origin, c + 1, e);

    // Merge das duas particoes
    merge(magnitude, compressed, origin, st, e);
}

double get_magnitude(double complex z)
{
    return sqrt(pow(creal(z), 2) + pow(creal(z), 2));
}

int main(int argc, char *argv[])
{
    int t;
    char file_name[100];
    scanf("%s %d", file_name, &t);
    unsigned char *data = read_wav_data(file_name);
    int sz = (int)strlen(data), origin[sz];
    complex double *compressed = DFT(data, sz), finished[sz];
    double magnitude[sz];

    for(int i = 0; i < sz; ++i) {
        origin[i] = i;
        magnitude[i] = get_magnitude(compressed[i]);
        printf("%lf\n", magnitude[i]);
    }

    mergesort_compressed(magnitude, compressed, origin, 0, sz);
    for(int i = t; i < sz; ++i) {
        magnitude[i] = 0;
        compressed[i] = 0;
    }

    for(int i = 0; i < sz; ++i)
        printf("number: %f + %f*i, magnitude: %lf, origin: %d\n", creal(compressed[i]), cimag(compressed[i]), get_magnitude(compressed[i]), origin[i]);

    for(int i = 0; i < sz; ++i) {
        finished[origin[i]] = compressed[i];
    }

    for(int i = 0; i < sz; ++i)
        printf("number: %f + %f*i, magnitude: %lf, origin: %d\n", creal(finished[i]), cimag(finished[i]), get_magnitude(finished[i]), origin[i]);

    free(data);
    free(compressed);
    return 0;
}
