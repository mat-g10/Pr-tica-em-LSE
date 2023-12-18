#include <stdio.h>
#include <stdlib.h>

typedef struct elem_lse{

    int idade;
    double peso;
    double altura;

    struct elem_lse* prox;

}t_elemento_lse;

typedef struct lse{

    struct t_elemento_lse* inicio;
    struct t_elemento_lse* fim;

    int tamanho;

}t_lse;

t_elemento_lse* criarElemento(int id, double pe, double al){
    t_elemento_lse* novo = malloc(sizeof(t_elemento_lse));
    novo->idade = id;
    novo->peso = pe;
    novo->altura = al;

    novo->prox = NULL;

    return novo;

}

t_lse* criarListaSE(){

    t_lse* lista = malloc(sizeof(t_lse));

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;

    return lista;

}

void inserirInicio(t_lse* lse, int id, double pe, double al){
    t_elemento_lse* novo = criarElemento(id, pe, al);

    if(lse->inicio == NULL){
        lse->inicio = novo;
        lse->fim = novo;
    }
    else{
        novo->prox = lse->inicio;
        lse->inicio = novo;
    }
    lse->tamanho++;
}

void inserirFinal(t_lse* lse, int id, double pe, double al){
    t_elemento_lse* novo = criarElemento(id, pe, al);

    if(lse->inicio == NULL){
        lse->inicio = novo;
        lse->fim = novo;
    }
    else{
        lse->fim->prox = novo;
        lse->fim = novo;
    }
    lse->tamanho++;
}



int main(void){

    return 0;
}
