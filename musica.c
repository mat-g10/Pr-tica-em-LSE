#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseneutra.h"
#include "pilha.h"
#include "fila.h"

typedef struct musica
{
    // int duração; se a primeira variavel da struct t_musica for int perde-se 4 bytes no parametro da função comparar
    char nome[60];
    char genero[30];
    int duracao;

}t_musica;


void remover_inicio_musica(){

}

void imprimir_musica(void *m1){ //  t_musica* m// void* usado para conversão/casting

    t_musica *m = m1;  //necessario para o casting //  se converte o tipo void para o tipo musica
    int min = m->duracao / 60;
    int seg = m->duracao - min * 60;
    printf("%s %s %02d:%02d\n", m->nome, m->genero, min, seg);

}

t_musica* criar_musica(char nome[], char genero[], int duracao){

    t_musica *nova = malloc(sizeof(t_musica));
    strcpy(nova->nome, nome);
    strcpy(nova->genero, genero);
    nova->duracao = duracao;

    return nova;

}




int comparar_musica(t_musica *m1, t_musica *m2){

    return strcmp(m1->nome, m2->nome);

/*

    if(strcmp(m1->nome, m2->nome) == 0){
        return 0;
    }
    else{
        if(strcmp(m1->nome, m2->nome) > 0){
            return 1;
        }
        else{
            if((strcmp(m1->nome, m2->nome) < 0)){
                return -1;
            }
        }
    }

*/
}