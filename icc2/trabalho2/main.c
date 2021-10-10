#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "func.h"
#include "sort.h"

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
    double magnitude[sz], *compressed_audio;

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

    compressed_audio = reverse_DFT(finished, sz);

    for(int i = 0; i < sz; ++i) printf("%lf\n", compressed_audio[i]);

    free(data);
    free(compressed);
    return 0;
}
