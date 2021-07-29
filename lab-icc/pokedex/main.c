#include <stdio.h>
#include <stdlib.h>

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
    int n_ataques;
    atributos_t *atributos;
    ataque_t **ataques;
}pokemon_t;

pokemon_t *ler_pokemon()
{
    pokemon_t *pokemon = (pokemon_t*)malloc(sizeof(pokemon_t));
    pokemon->atributos = (atributos_t*)malloc(sizeof(atributos_t));
    pokemon->n_ataques = 0;
    pokemon->ataques = NULL;

    scanf("%s %s %s", pokemon->nome, pokemon->tipo_primario, pokemon->tipo_secundario);
    scanf("%d %d %d %d %d %d",&(pokemon->atributos->hp), &(pokemon->atributos->ataque), &(pokemon->atributos->defesa),
            &(pokemon->atributos->ataque_especial), &(pokemon->atributos->defesa_especial),
            &(pokemon->atributos->velocidade));

    return pokemon;
}

ataque_t *ler_ataque()
{
    ataque_t *ataque = (ataque_t*)malloc(sizeof(ataque_t));

    scanf("%s %d %f\n%c", ataque->nome,
            &(ataque->poder_base), &(ataque->acuracia), &(ataque->classe));

    return ataque;
}

void print_pokemon(pokemon_t *pokemon)
{
    printf("Nome do Pokemon: %s\nTipo primario: %s\nTipo secundario: %s\n", pokemon->nome,
            pokemon->tipo_primario, pokemon->tipo_secundario);

    printf("Status: \n\tHP: %d\n\tAtaque: %d\n\tDefesa: %d\n\tAtaque Especial: %d\n",
            pokemon->atributos->hp, pokemon->atributos->ataque, pokemon->atributos->defesa,
            pokemon->atributos->ataque_especial);

    printf("\tDefesa Especial :%d\n\tVelocidade: %d\n\n", pokemon->atributos->defesa_especial,
            pokemon->atributos->velocidade);
}

void print_ataque(ataque_t *ataque)
{
    printf("Nome do Ataque: %s\nPode base: %d\nAcuracia: %f\nClasse: %c\n",
            ataque->nome, ataque->poder_base, ataque->acuracia, ataque->classe);
}

void print_pokemon_pokedex(pokemon_t **pokedex, int indice_pokemon)
{
    print_pokemon(pokedex[indice_pokemon]);
}

void print_ataque_pokedex(pokemon_t **pokedex, int indice_pokemon, int indice_ataque)
{
    print_ataque(pokedex[indice_pokemon]->ataques[indice_ataque]);
}

void free_pokemon(pokemon_t *pokemon)
{
    if(!pokemon) return;
    if(pokemon->atributos) free(pokemon->atributos);
    if(pokemon->ataques) {
        for(int i = 0; i < pokemon->n_ataques; ++i) 
            free(pokemon->ataques[i]);
    }
    free(pokemon);
}

void add_ataque(pokemon_t *pokemon, ataque_t *ataque)
{
    if(!pokemon->ataques) pokemon->ataques = (ataque_t**)malloc(sizeof(ataque_t*));
    else {
        ataque_t **tmp = (ataque_t**)realloc(pokemon->ataques, sizeof(ataque_t*)*(pokemon->n_ataques + 1));
        if(!tmp) {
            free_pokemon(pokemon);
            exit(0);
        }
        pokemon->ataques = tmp;
    }

    pokemon->ataques[(pokemon->n_ataques++)] = ler_ataque();
}

int main(int argc, char *argv[])
{
    /*print_pokemon(ler_pokemon());*/
    print_ataque(ler_ataque());
    return 0;
}
