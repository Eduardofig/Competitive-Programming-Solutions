#include <stdio.h>
#include <stdlib.h>

//Struct para armazenamento da musica
typedef struct
{
    unsigned int tempo_de_duracao;
    char *nome_do_artista;
    char *nome_da_musica;
}musica;

//Struct para armazenamento da playlist
typedef struct
{
    musica *musicas[15];
    int tocando_agora;
    int n_de_musicas;
    char *nome_da_playlist;
}playlist;

//Funcao que le uma string determinada por array de possiveis delimitadores
char *read_token(char *delimitadores)
{
    size_t tamanho_da_linha = sizeof(char);
    char c, *linha = malloc(tamanho_da_linha), *failsafe;
    for(int i = 0; scanf("%c", &c) == 1; i++) {
        //Quando chega no final da linha retorna a linha e adiciona o '\0' no final
        for(int j = 0; delimitadores[j] != 0; ++j) {
            if(c == delimitadores[j]) {
                if(c == '\r') scanf("%c", &c);
                linha[i] = 0;
                return linha;
            }
        }
        linha[i] = c;
        tamanho_da_linha += sizeof(char);
        failsafe = realloc(linha, tamanho_da_linha);
        //Se o realloc der errado
        if(!failsafe) {
            free(linha);
            return NULL;
        }
        linha = failsafe;
    }
    free(linha);
    return NULL;
}

//Le uma musica input, cria a struct e retorna o ponteiro para a sua struct
musica *read_musica()
{
    musica *m = (musica*)malloc(sizeof(musica));
    m->nome_da_musica = read_token("\r\n");
    m->nome_do_artista = read_token("\r\n");
    scanf("%d", &(m->tempo_de_duracao));
    return m;
}

//Le o nome da playlist do input e cria a playlist retornando o ponteiro para a playlist
playlist *criar_playlist()
{
    playlist *p = malloc(sizeof(playlist));
    for(int i = 0; i < 15; ++i) 
        p->musicas[i] = NULL;
    p->tocando_agora = 0;
    p->n_de_musicas = 0;
    p->nome_da_playlist = read_token("\r\n");
    return p;
}

//Apaga a musica e redireciona seu ponteiro para NULL
void apagar_musica(musica **m) {
    free((*m)->nome_da_musica);
    free((*m)->nome_do_artista);
    free(*m);
    *m = NULL;
}

//Apaga a playlist e redireciona seu ponteiro para null
void apagar_playlist(playlist **p)
{
    for(int i = 0; i < (*p)->n_de_musicas; ++i)
        if((*p)->musicas[i]) apagar_musica((*p)->musicas + i);
    free((*p)->nome_da_playlist);
    free(*p);
    *p = NULL;
}


//Tenta inserir uma musica na playlist
void inserir_musica(playlist *p) 
{
    if(p->n_de_musicas == 15) {
        printf("Playlist cheia!\n");
        return;
    }
    musica *m = read_musica();
    p->musicas[(p->n_de_musicas)++] = m;
    printf("Musica %s de %s adicionada com sucesso.\n", m->nome_da_musica, m->nome_do_artista);
}

void avancar_de_musica(playlist *p) 
{
    if(p->tocando_agora == 14) {
        p->tocando_agora = 0;
        return;
    }
    (p->tocando_agora)++;
}

void retroceder_de_musica(playlist *p)
{
    if(p->tocando_agora == 0) {
        p->tocando_agora = 14;
        return;
    }
    (p->tocando_agora)--;
}

void exibir_playlist(playlist *p) {
    printf("---- Playlist: %s ----\n", p->nome_da_playlist);
    printf("Total de musicas: %d\n\n", p->n_de_musicas);
    for(int i = 0; i < p->n_de_musicas; i++) {
        if(p->tocando_agora == i) printf("=== NOW PLAYING ===\n");
        printf("(%d). '%s'\n", i + 1, p->musicas[i]->nome_da_musica);
        printf("Artista: %s\n", p->musicas[i]->nome_do_artista);
        printf("Duracao: %d segundos\n\n", p->musicas[i]->tempo_de_duracao);
    }
}

int main(int argc, char *argv[])
{
    playlist *p = criar_playlist();
    int seletor;
    while(scanf("%d\n", &seletor)) {
        switch(seletor)
        {
            case 1:
                inserir_musica(p);
                break;
            case 2:
                exibir_playlist(p);
                break;
            case 3:
                avancar_de_musica(p);
                break;
            case 4:
                retroceder_de_musica(p);
                break;
            default:
                apagar_playlist(&p);
                return 0;
        }
    }
    return 0;
}
