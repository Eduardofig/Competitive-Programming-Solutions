/*
   Eduardo Figueiredo Freire Andrade
   Nusp = 11232820
   Trabalho 2 de Icc 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include <math.h>

void write_wav_data(char *fname, unsigned char *header, unsigned char *data, int length)
{
    FILE *stream = fopen(fname, "wb");

    if(!stream) return;

    fwrite(header, sizeof(unsigned char), 44, stream);
    fwrite(data, sizeof(unsigned char), length, stream);

    fclose(stream);
}

unsigned char* read_wav_data(char* fname, int *sz)
{
    FILE* fp = fopen(fname, "rb");
    unsigned char buf4[4];

    fseek(fp, 40, SEEK_SET);
    fread(buf4, sizeof(buf4), 1, fp);
    *sz = buf4[0] | buf4[1]<<8 | buf4[2]<<16 | buf4[3]<<24;

    unsigned char* data = malloc(sizeof(*data) * (*sz));
    
    int i = 0;
    while (i < *sz)
        fread(&data[i++], sizeof(unsigned char), 1, fp);

    fclose(fp);
    return data;
}

double complex *DFT(unsigned char *audio, int length)
{
    double complex *coef = (double complex*)calloc(length, sizeof(double complex));

    for (int k = 0; k < length; k++)
        for (int n = 0; n < length; n++)
            coef[k] += audio[n]*cexp((-2.0*M_PI*(((k+1)*n*1.0)/(length*1.0)))*_Complex_I);

    return coef;
}

//DFT inversa
unsigned char *reverse_DFT(double complex *end_coeffs, int length)
{
    double complex num;
    unsigned char *audio = (unsigned char*)calloc(length, sizeof(unsigned char));

    for(int k = 0; k < length; k++) {
        num = 0;
        for (int n = 0; n < length; n++)
            num += end_coeffs[n]*cexp((2.0*M_PI*(((n+1)*k*1.0)/(length*1.0)))*_Complex_I);

        audio[k] = (unsigned char)(creal(num/length));
    }

    return audio;
}
