/*
   Eduardo Figueiredo Freire Andrade
   Nusp = 11232820
   Trabalho 2 de Icc 2
*/
#include <complex.h>

#ifndef FUNC_H
#define FUNC_H
#define complex _Complex

//Funcao que le os dados do arquivo wav
unsigned char* read_wav_data(char* fname, int *sz);

//Funcao que escreve os dados no arquivo wav
void write_wav_data(char *fname, unsigned char *header, unsigned char *data, int length);

//Transformada de fourier discreta
double complex *DFT(unsigned char *audio, int length);

//Transformadad de fourier discreta inversa
unsigned char *reverse_DFT(double complex *end_coeffs, int length);

#endif
