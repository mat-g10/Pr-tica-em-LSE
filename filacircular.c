#include <stdio.h>
#include <stdlib.h>
#include "filacircular.h"

typedef struct f_circular t_fila_circular;
struct f_circular{

    void* *elementos; //ponteiro de ponteiros
    int frente, atras; //indices
    int tamanho;

};

t_fila_circular* criar_fila_circular(int tam){

    t_fila_circular* fc = malloc(sizeof(t_fila_circular));

    fc->elementos = malloc(sizeof(void*)); //deve se instanciar os elementos pois sao ponteiros;
    fc->frente = -1; // Inicar com indice nao valido pra caracterizar que a fila está vazia
    fc->atras = -1;
    fc->tamanho = tam;

    return fc;

}

int vazia_fila_circular(t_fila_circular* fc){

    return (fc->frente == -1); ///SE  FILA CIRCULAR -> FRENTE == -1, ESTÁ VAZIA

}

int ocupacao_fila_circular(t_fila_circular* fc){

    //return tam;

    if(fc->frente < fc->atras){
        return (fc->atras - fc->frente) + 1;
    }    
    else{
        return (fc->tamanho - fc->frente) + fc->atras + 1;
    }

}

short enfileirar_fila_circular(t_fila_circular* fc, void* novo){

    if(ocupacao_fila_circular(fc) == fc->tamanho){

        return 0; //Não foi possivel enfileirar / fallhou a inserção

    }
    if(vazia_fila_circular(fc)){

        fc->atras = 0;
        fc->frente = 0;
        //fc->elementos[0] = novo; //Na primeira maneira retira essa
        fc->elementos[fc->atras] = novo; //adiciona essa

    }
    else{

        fc->atras = (fc->atras+1) % fc->tamanho; //garantindo a circularidade
        //fc->elementos[fc->atras] = novo; //e essa

    }
    fc->elementos[fc->atras] = novo; //e essa
    return 1; // true

}

void* desenfileirar_fila_circular(t_fila_circular* fc){

    void* elem = NULL;

    if(vazia_fila_circular(fc)){

        return NULL;

    }
    else{

        if(ocupacao_fila_circular(fc) == 1){

            elem = fc->elementos[fc->frente]; // 
            fc->atras = -1; //INDICA QUE A FILA ESTÁ VAZIA
            fc->frente = -1;

        }
        else{
            elem = fc->elementos[fc->frente];
            fc->frente = (fc->frente + 1) % fc->tamanho; //foi avançado uma posição a frente
        }
        return elem;

    }

}

void* primeiro_fila_circular(t_fila_circular* fc){

    void* elem = NULL;

    if(!vazia_fila_circular(fc)){

        elem = fc->elementos[fc->frente];

    }
    return elem;

}

void avancar_fila_circular(t_fila_circular* fc){

    

}