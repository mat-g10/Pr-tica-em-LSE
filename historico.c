#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define LOAD 1
#define IMPRIMIR_ULTIMA 2
#define IMPRIMIR_HISTORICO 3
#define REMOVER_HISTORICO 4
#define FIM 5

typedef struct elem_historico{

    char url[100];
    int dia, mes;
    int hora, minuto;

}t_elem_historico;

typedef struct historico{

    //pilha
    t_pilha* visitadas;

}t_historico;

t_elem_historico* criar_elem_historico(char url[], int d, int m, int hr, int min){

    t_elem_historico* novo = malloc(sizeof(t_elem_historico));

    strcpy(novo->url, url);
    novo->dia = d;
    novo->mes = m;
    novo->hora = hr;
    novo->minuto = min;
    
    return novo;

}

t_historico* criar_historico(){

    t_historico* novo = malloc(sizeof(t_historico));

    novo->visitadas = criar_pilha();

    return novo;

}

void imprimir_ultimo_site(void* h){

    t_elem_historico* h1 = h;
    printf("Ultimo site visitado: %s %d %d %d %d\n", h1->url, h1->dia, h1->mes, h1->hora, h1->minuto);

}

void load_site(){

    t_elem_historico* novo;



}

int main(){

    char url[100];
    int dia, mes;
    int hora, minuto;

    t_historico* historico = criar_historico();

    int entrada;
    scanf("%d", &entrada);
    while(entrada == 1){

        //printf("Informe as informações da url: ");
        scanf("%s %d %d %d %d", url, &dia, &mes, &hora, &minuto);

        empilhar(historico->visitadas, criar_elem_historico(url, dia, mes, hora, minuto));
        printf("%d\n", altura_pilha(historico->visitadas));
        printf("Foi\n");

        scanf("%d", &entrada);
    }

    imprimir_ultimo_site(topo(historico->visitadas));

    /*
    int acao;
    scanf("%d", &acao);

    do{
        switch (acao)
        {
        case LOAD:
            
            break;
        
        default:
            break;
        }

    }while(acao != FIM);
    */

    return 0;
}