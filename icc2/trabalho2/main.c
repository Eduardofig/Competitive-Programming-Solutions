/*
   Eduardo Figueiredo Freire Andrade
   Nusp = 11232820
   Trabalho 2 de Icc 2
*/
#include "func.h"
#include "sort.h"

int main(int argc, char *argv[])
{
    int t, sz, less_zero = 0;
    char file_name[50];

    scanf("%s %d", file_name, &t);

    unsigned char *data = read_wav_data(file_name, &sz), *compressed_audio, header[44];
    int origin[sz];
    complex double *coeffs = DFT(data, sz), end_coeffs[sz];

    //Pega o cabecalho do audio original
    FILE *stream = fopen(file_name, "rb");
    fseek(stream, 0, SEEK_SET);
    fread(header, sizeof(unsigned char), 44, stream);
    fclose(stream);

    //Inicializa o vetor origin e conta os valores menores ou iguais a zero
    for(int i = 0; i < sz; ++i) {
        origin[i] = i;
        if(creal(coeffs[i]) <= 0.0 && cimag(coeffs[i]) <= 0.0) less_zero++;
    }

    //Ordena os coeficientes em ordem decrescente de magnitude
    mergesort_coeffs(coeffs, origin, 0, sz);

    //Print to output
    printf("%d\n", sz);
    printf("%d\n", less_zero);

    for(int i = 0; i < t; ++i)
        printf("%d\n", (int)cabs(coeffs[i]));

    //zera os coeficientes nao relevantes
    for(int i = t; i < sz; ++i)
        coeffs[i] = 0;

    //coloca os coeff na posicao original
    for(int i = 0; i < sz; ++i)
        end_coeffs[origin[i]] = coeffs[i];

    //Aplica a tranformada de fourier reversa nos coeficientes
    compressed_audio = reverse_DFT(end_coeffs, sz);

    //Escreve os dados no arquivo
    write_wav_data("out.wav", header, compressed_audio, sz);

    //desaloca a memoria
    free(data);
    free(coeffs);
    free(compressed_audio);

    return 0;
}
