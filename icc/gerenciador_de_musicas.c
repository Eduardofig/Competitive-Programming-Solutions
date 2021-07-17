#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void escrever_cabecalho_playlist(playlist *p, FILE *binario)
{
    if(!p) return;

    int tam_nome = strlen(p->nome_da_playlist);

    fseek(binario, 0, SEEK_SET);
    fwrite(&tam_nome, sizeof(int), 1, binario);
    fwrite(p->nome_da_playlist, sizeof(char), tam_nome, binario);
    fwrite(&(p->n_de_musicas), sizeof(int), 1, binario);
}

void escrever_musica_playlist(musica *m, FILE *binario)
{
    if(!m) return;

    int tam_nome_musica = strlen(m->nome_da_musica),
        tam_nome_artista = strlen(m->nome_do_artista);

    fwrite(&tam_nome_musica, sizeof(int), 1, binario);
    fwrite(m->nome_da_musica, sizeof(char), tam_nome_musica, binario);
    fwrite(&tam_nome_artista, sizeof(int), tam_nome_artista, binario);
    fwrite(m->nome_do_artista, sizeof(char), tam_nome_artista, binario);
    fwrite(&(m->tempo_de_duracao), sizeof(unsigned int), 1, binario);
}

musica *ler_musica(FILE *binario)
{
    musica *m = (musica*)malloc(sizeof(musica));

    int tam_nome_musica, tam_nome_artista;

    //Leitura do nome da musica
    fread(&tam_nome_musica, sizeof(int), 1, binario);
    m->nome_da_musica = (char*)malloc(sizeof(char)*(tam_nome_musica + 1));
    fread(m->nome_da_musica, sizeof(char), tam_nome_musica, binario);
    m->nome_da_musica[tam_nome_musica] = 0;

    //Leitura do nome do artista
    fread(&tam_nome_artista, sizeof(int), 1, binario);
    m->nome_do_artista = (char*)malloc(sizeof(char)*(tam_nome_artista + 1));
    fread(m->nome_do_artista, sizeof(char), tam_nome_artista, binario);
    m->nome_do_artista[tam_nome_artista] = 0;

    //Leitura da duracao da musica
    fread(&(m->tempo_de_duracao), sizeof(unsigned int), 1, binario);

    return m;
}

playlist *ler_playlist(FILE *binario)
{
    playlist *p = malloc(sizeof(playlist));

    fseek(binario, 0, SEEK_SET);

    int tam_nome_playlist, tam_nome_musica, tam_nome_artista;

    //Leitura do cabecalho
    fread(&tam_nome_playlist, sizeof(int), 1, binario);
    p->nome_da_playlist = malloc(sizeof(char)*tam_nome_playlist);
    fread(p->nome_da_playlist, sizeof(char), tam_nome_playlist, binario);
    fread(&(p->n_de_musicas), sizeof(int), 1, binario);

    for(int i = 0; i < p->n_de_musicas; ++i) 
        p->musicas[i] = ler_musica(binario);

    return p;
}

void binaryToNum(char *binFilename) {
    FILE *fp = fopen(binFilename, "rb");

    double binValue = 0;
    double accumulator = 0.01;
    char ch;
    while (fread(&ch, sizeof(char), 1, fp)) {
        binValue += (double) ch * accumulator;
        accumulator += 0.01;
    }

    fclose(fp);
    printf("%lf\n", binValue);
}


void salvar_playlist(playlist *p)
{
    char nome_binario[300];
    scanf("%s", nome_binario);

    FILE *binario = fopen(nome_binario, "wb");

    escrever_cabecalho_playlist(p, binario);

    for(int i = 0; i < p->n_de_musicas; ++i) 
        escrever_musica_playlist(p->musicas[i], binario);

    fclose(binario);
    printf("Playlist %s salva com sucesso.\n", p->nome_da_playlist);

    binaryToNum(nome_binario);
}

void carregar_playlist(playlist **p)
{
    char nome_binario[300];
    scanf("%s", nome_binario);

    FILE *binario = fopen(nome_binario, "rb");

    if(!binario) {
        printf("Arquivo %s nao existe.\n", nome_binario);
        return;
    }

    if(*p) apagar_playlist(p);

    *p = ler_playlist(binario);
    printf("Playlist %s carregada com sucesso.\n", (*p)->nome_da_playlist);

    binaryToNum(nome_binario);
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
            case 5:
                salvar_playlist(p);
                break;
            case 6:
                carregar_playlist(&p);
                break;
            default:
                apagar_playlist(&p);
                return 0;
        }
    }
    return 0;
}
