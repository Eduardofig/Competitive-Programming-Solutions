#include <stdio.h>
#include <stdlib.h>

#define TAM_POKEDEX 1000
#define TAM_ATAQUES 4

// structs
typedef struct
{
    char nome[20],
         classe;
    int poder_base;
    float acuracia;
}ataque_t;

typedef struct
{
    int hp,
        ataque,
        defesa,
        ataque_especial,
        defesa_especial,
        velocidade;
}atributos_t;

typedef struct
{
    char nome[50],
         tipo_primario[20],
         tipo_secundario[20];
    atributos_t *atributos;
    ataque_t *ataques[TAM_ATAQUES];
}pokemon_t;

//funcoes de leitura
pokemon_t *ler_pokemon()
{
    pokemon_t *pokemon = (pokemon_t*)malloc(sizeof(pokemon_t));
    pokemon->atributos = (atributos_t*)malloc(sizeof(atributos_t));
    for(int i = 0; i < TAM_ATAQUES; ++i)
        pokemon->ataques[i] = NULL;

    scanf("%s\n%s\n%s\n", pokemon->nome, pokemon->tipo_primario, pokemon->tipo_secundario);
    scanf("%d\n%d\n%d\n%d\n%d\n%d\n",&(pokemon->atributos->hp), &(pokemon->atributos->ataque), &(pokemon->atributos->defesa),
            &(pokemon->atributos->ataque_especial), &(pokemon->atributos->defesa_especial),
            &(pokemon->atributos->velocidade));

    return pokemon;
}

ataque_t *ler_ataque()
{
    ataque_t *ataque = (ataque_t*)malloc(sizeof(ataque_t));

    scanf("%s\n%d\n%f\n%c\n", ataque->nome,
            &(ataque->poder_base), &(ataque->acuracia), &(ataque->classe));

    return ataque;
}

//funcoes de impressao
void print_pokemon(pokemon_t *pokemon)
{
    printf("Nome do Pokemon: %s\nTipo primario: %s\nTipo secundario: %s\n", pokemon->nome,
            pokemon->tipo_primario, pokemon->tipo_secundario);

    printf("Status: \n\tHP: %d\n\tAtaque: %d\n\tDefesa: %d\n\tAtaque Especial: %d\n",
            pokemon->atributos->hp, pokemon->atributos->ataque, pokemon->atributos->defesa,
            pokemon->atributos->ataque_especial);

    printf("\tDefesa Especial: %d\n\tVelocidade: %d\n\n", pokemon->atributos->defesa_especial,
            pokemon->atributos->velocidade);
}

void print_ataque(ataque_t *ataque)
{
    printf("Nome do Ataque: %s\nPoder base: %d\nAcuracia: %f\nClasse: %c\n\n",
            ataque->nome, ataque->poder_base, ataque->acuracia, ataque->classe);
}

//Funcoes de impressao que podem ser chamadas do pokedex
void print_pokemon_pokedex(pokemon_t **pokedex, int indice_pokemon)
{
    print_pokemon(pokedex[indice_pokemon]);
}

void print_ataque_pokedex(pokemon_t *pokedex[TAM_POKEDEX], int indice_pokemon, int indice_ataque)
{
    print_ataque(pokedex[indice_pokemon]->ataques[indice_ataque]);
}

//Funcao auxiliar para apagar os pokemons
void free_pokemon(pokemon_t *pokemon)
{
    if(!pokemon) return;
    if(pokemon->atributos) free(pokemon->atributos);

    for(int i = 0; i < TAM_ATAQUES; ++i) 
        if(pokemon->ataques[i]) free(pokemon->ataques[i]);

    free(pokemon);
}

void free_pokedex(pokemon_t *pokedex[TAM_POKEDEX], int n_pokemons)
{
    for(int i = 0; i < n_pokemons; ++i)
        if(pokedex[i]) free_pokemon(pokedex[i]);
}

//Funcoes de insercao
void add_pokemon_pokedex(pokemon_t *pokedex[TAM_POKEDEX], int *n_pokemons)
{
    pokedex[(*n_pokemons)++] = ler_pokemon();
}

void add_ataque(pokemon_t *pokemon, int indice_ataque)
{
    if(pokemon->ataques[indice_ataque]) free(pokemon->ataques[indice_ataque]);
    pokemon->ataques[indice_ataque] = ler_ataque();
}

void add_ataque_pokedex(pokemon_t **pokedex, int indice_pokemon, int indice_ataque)
{
    if(!pokedex) return;
    add_ataque(pokedex[indice_pokemon], indice_ataque);
}

int main(int argc, char *argv[])
{
    int seletor;
    int n_pokemons = 0, indice_pokemon, indice_ataque;
    pokemon_t *pokedex[TAM_POKEDEX];
    while(1) {
        scanf("%d", &seletor);
        switch(seletor)
        {
            case 1:
                add_pokemon_pokedex(pokedex, &n_pokemons);
                break;
            case 2:
                scanf("%d\n%d\n", &indice_pokemon, &indice_ataque);
                add_ataque_pokedex(pokedex, indice_pokemon, indice_ataque);
                break;
            case 3:
                scanf("%d\n", &indice_pokemon);
                print_pokemon_pokedex(pokedex, indice_pokemon);
                break;
            case 4:
                scanf("%d\n%d\n", &indice_pokemon, &indice_ataque);
                print_ataque_pokedex(pokedex, indice_pokemon, indice_ataque);
                break;
            default:
                free_pokedex(pokedex, n_pokemons);
                exit(0);
        }
    }
    return 0;
}
