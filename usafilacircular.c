#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filacircular.h"
#include "musica.h"


int main(void){

    char nome[60], genero[30];
    int duracao;

    

    t_pilha* playlist = criar_fila_circular(10);

    scanf("%s",nome);

    while (strcmp(nome, "FIM") != 0)
    {
        scanf("%s %d", genero, &duracao);
        
        enfileirar_fila_circular(playlist, criar_musica(nome, genero, duracao));
        //inserir_ordenado_lse(playlist, criar_musica(nome, genero, duracao));
        //inserir_final_lse(playlist, criar_musica(nome, genero, duracao));

        scanf("%s", nome);
    }

    

    t_musica* m = primeiro_fila_circular(playlist);
    imprimir_musica(m);
    m = desenfileirar_fila_circular(playlist);
    free(m);
    
    printf("ocupacao = %d\n", ocupacao_fila_circular(playlist));
    
    scanf("%s", nome);
    scanf("%s %d", genero, &duracao);    
    enfileirar_fila_circular(playlist, criar_musica(nome, genero, duracao));

    printf("ocupacao = %d\n", ocupacao_fila_circular(playlist));

    /*

    //char buscado[60];
    t_musica* buscado = malloc(sizeof(t_musica)); //variavel anonima

    //scanf("%s", buscado);
    scanf("%s", buscado->nome); //usa-se somente o nome nesse caso
    t_musica* m = buscar_lse(playlist,(void*)buscado); //retorna a musica ou um ponteiro nulo se ela nao estive na lista
    if(m != NULL){
        imprimir_lse(playlist);
    }

    for(int i = 0;i<tam_lse;i++){
        t_musica *m = acessar_lse(playlist, i);
        if(m->nome == buscado){

        }
    }
 //Função buscar_lse faz isso


    //imprimir_lse(playlist);


    //remover_inicio_lse(playlist);
    //remover_final_lse(playlist);
    //imprimir_lse(playlist);

    */

}