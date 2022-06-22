/* Eduardo Figueiredo Freire Andrade
 * NUSP: 11232820
 * Trabalho 3 de icc2:
 * Simulador de Escalonador de Processos */

#include "max_heap.h"

max_heap_t *new_heap()
{
    max_heap_t *mh = (max_heap_t*)malloc(sizeof(max_heap_t));

    mh->data = (process_t**)malloc(sizeof(process_t*));
    mh->data[0] = NULL;

    mh->size = 0;
    mh->data_len = 1;

    return mh;
}

void free_heap(max_heap_t *mh)
{
    free(mh->data);
    free(mh);
}

//Funcao que faz a troca entre 2 ponteiros para processo
static void _swap(process_t **a, process_t **b)
{
    process_t *tmp = *a;
    *a = *b;
    *b = tmp;
}

int heap_empty(max_heap_t *mh)
{
    return mh->size == 0;
}

//Funcao interna de comparacao da heap
static int _heap_cmp(const process_t *a, const process_t *b)
{
    //Se a prioridade for igual, utiliza os codigos de identificacao como criteiro
    if(a->priority == b->priority) return a->code < b->code;
    return a->priority > b->priority;
}

//Fucao que retorna o indice do pai de uma posicao
static int _heap_parent(const int i)
{
    return i >> 1;
}

//Funcao que retorna o indice de um determinado filho de uma posicao
//0 -> filho esquerdo, 1 -> filho direito
static int _heap_child(int which, int i)
{
    return (i << 1) + which;
}

//Funcao que diz um indice esta dentro dos limites da heap
static int _heap_contains(max_heap_t *mh, const int curr)
{
    return curr <= mh->size;
}

//Funcao que ve se um dos filhos eh maior que o pai e se sim retorna o maior deles
static int _heap_next_child(max_heap_t *mh, const int curr)
{
    int next = curr, tmp;

    for(int i = 0; i < 2; ++i) {
        tmp = _heap_child(i, curr);
        if(_heap_contains(mh, tmp) && _heap_cmp(mh->data[tmp], mh->data[next]))
            next = tmp;
    }

    return next;
}

//Funcao recursiva usada na insercao da heap
static void _shift_up(max_heap_t *mh, const int curr)
{
    if(_heap_contains(mh, curr) && curr != HEAP_ROOT) {
        int par = _heap_parent(curr);

        if(_heap_cmp(mh->data[curr], mh->data[par]))
            _swap(mh->data + curr, mh->data + par);

        _shift_up(mh, par);
    }
}

//Funcao recursiva usada na remocao da heap
static void _shift_down(max_heap_t *mh, const int curr)
{
    int next = _heap_next_child(mh, curr);

    if(next != curr) {
        _swap(mh->data + next, mh->data + curr);
        _shift_down(mh, next);
    }
}

void heap_push(max_heap_t *mh, process_t *val)
{
    if(mh->data_len <= mh->size + 1) {
        mh->data_len = (mh->size + 1)*2;
        process_t **tmp = (process_t**)safe_realloc(mh->data, sizeof(process_t*)*(mh->data_len));

        if(!tmp) {
            printf("ERRO: Faltou espaco na memoria");
            free_heap(mh);
            exit(1);
        }

        mh->data = tmp;

        for(int i = mh->size + 1; i < mh->data_len; ++i)
            mh->data[i] = NULL;
    }

    //Insere o elemento no final e chama a shift_up para reorganizar a heap
    mh->data[++mh->size] = val;
    _shift_up(mh, mh->size);
}

process_t *heap_max(max_heap_t *mh)
{
    if(heap_empty(mh)) return NULL;

    return mh->data[1];
}

process_t *heap_pop(max_heap_t *mh)
{
    if(heap_empty(mh)) return NULL;

    process_t *max = mh->data[HEAP_ROOT];

    //Troca o elemento da raiz com o elemento do final, diminuinto o limite da heap
    //e chama a shift down para reorganizar a heap
    _swap(mh->data + HEAP_ROOT, mh->data + mh->size--);
    _shift_down(mh, HEAP_ROOT);
    
    return max;
}
