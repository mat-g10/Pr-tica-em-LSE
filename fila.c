#include "stdio.h"
#include "stdlib.h"
#include "lseneutra.h"

typedef struct fila t_fila; 
struct fila{
    int tamanho;
    t_lse *elementos;
};

t_fila* criar_fila(){
    t_fila *f = malloc(sizeof(t_fila));
    f->tamanho = 0;
    f->elementos = criar_lse(NULL,NULL);

    return f;
}

void enfileirar(t_fila *f, void* novo){
    if(f!=NULL){
        inserir_final_lse(f->elementos, novo);
        f->tamanho++;
    }
}

void* desenfileirar(t_fila* f){
    void* el = NULL;
    if ((f!=NULL) && (f->tamanho>0)){
        el = remover_inicio_lse(f->elementos);
        f->tamanho--;
    }
    return el;
}

void* primeiro_fila(t_fila *f){
    void* el = NULL;
    if((f!=NULL) && (f->tamanho>0)){
        el = acessar_lse(f->elementos,1);
    }
    return el;
}

int tamanho_fila(t_fila *f){
    return f->tamanho;
}

short vazia_fila(t_fila *f){
    return (f->tamanho == 0);
}