#include <stdio.h>
#include <stdlib.h>
#include "lseneutra.h"
#include "pilha.h"

typedef struct pilha t_pilha;

struct pilha{

    int altura;
    t_lse *elementos;

};

t_pilha* criar_pilha(){

    t_pilha *novaP = malloc(sizeof(t_pilha));

    novaP->altura = 0;
    novaP->elementos = criar_lse(NULL, NULL);

    //printf("Criou\n");
    return novaP;

}


void empilhar(t_pilha *p, void* novo){

    if(p != NULL){
        //printf("Entrou\n");

        inserir_lse(p->elementos, novo);
        p->altura++;

    }

}

void* desempilhar(t_pilha *p){

    void* el;
    if((p) && (p->altura > 0)){

        el = remover_inicio_lse(p->elementos);
        p->altura--;
        return el;

    }
    return el;

}


void* topo(t_pilha *p){

    void* el;
    if((p) && (p->altura > 0)){

        el = acessar_lse(p->elementos, 1);

    }
    return el;

}

int altura_pilha(t_pilha *p){

    if((p) && (p->altura > 0))
        return p->altura;

}

/*
int main(){

    t_pilha* p = criar_pilha();
    empilhar(p, (void*)1);

    return 0;
}
*/
