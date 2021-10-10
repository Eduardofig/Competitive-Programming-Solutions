#include <complex.h>

#ifndef FUNC_H
#define FUNC_H
#define complex _Complex

unsigned char* read_wav_data(char* fname);

double complex *DFT(unsigned char *audio, int length);

double *reverse_DFT(double complex *finished, int length);

#endif

