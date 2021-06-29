#include <stdio.h>
#include <string.h>

#define TERRA 0
#define VENUS 1
#define MERCURIO 2
#define JUPITER 3

void converter_horario_interplanetario(int segundos, int planeta, int *p_dias, int *p_horas, int *p_minutos, int *p_segundos)
{
    //Preenchimento do array de conversoes de dias interplanetarios
    int dia_interplanetario_em_segundos[4], minuto_em_segundos = 60, hora_em_segundos = 60*minuto_em_segundos;
    dia_interplanetario_em_segundos[TERRA] = 24*hora_em_segundos;
    dia_interplanetario_em_segundos[VENUS] = 243*dia_interplanetario_em_segundos[TERRA];
    dia_interplanetario_em_segundos[MERCURIO] = 58*dia_interplanetario_em_segundos[TERRA] + 16*hora_em_segundos;
    dia_interplanetario_em_segundos[JUPITER] = 9*hora_em_segundos + 56*minuto_em_segundos;

    //Calculo do horario interplanetario
    *p_dias = segundos/dia_interplanetario_em_segundos[planeta];
    segundos %= dia_interplanetario_em_segundos[planeta];
    *p_horas = segundos/hora_em_segundos;
    segundos %= hora_em_segundos;
    *p_minutos = segundos/minuto_em_segundos;
    segundos %= minuto_em_segundos;
    *p_segundos = segundos;
}

int main(int argc, char *argv[])
{
    int segundos, p_segundos, p_minutos, p_horas, p_dias, planeta;
    char nome_planeta[100];

    //Pega input e define o planeta
    scanf("%d %s", &segundos, nome_planeta);
    if(!strcmp(nome_planeta, "Terra")) planeta = TERRA;
    else if(!strcmp(nome_planeta, "Venus")) planeta = VENUS;
    else if(!strcmp(nome_planeta, "Mercurio")) planeta = MERCURIO;
    else planeta = JUPITER;

    converter_horario_interplanetario(segundos, planeta, &p_dias, &p_horas, &p_minutos, &p_segundos);

    printf("%d segundos no planeta Terra equivalem a:\n", segundos);
    printf("%d dias, %d horas, %d minutos, %d segundos\n", p_dias, p_horas, p_minutos, p_segundos);
    return 0;
}
