    #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseneutra.h"
#include "pilha.h"
#include "fila.h"

#define PLAYING 1
#define PAUSE 2
#define STOP 3
#define LOAD 4
#define RESUME 5

//interações com ultimas tocadas e proximas

#define END 7 //dizer que a musica chegou ao final
#define FORWARD 8 //avançar
#define BACKWARD 9 //voltar

#define FINAL 6 //dizer que as interações acabaram

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
typedef struct playlist t_playlist;

struct playlist{

    char nome[60];
    int duracao;
    char descricao[1200];
    int quantidadeMusicas;
    int dia, mes, ano;

    t_lse *musicas; //ententendo de que tipo de playlist se trata


};


typedef struct biblioteca t_biblioteca;

struct biblioteca
{
    t_lse *musicas;
    t_lse *playlists;   //deve-se pensar também onde ficarão as playlists //playlists do usuario
    t_lse *generos;
    t_lse *artistas;
    t_lse *albuns;

};





typedef struct tocador t_tocador;

typedef struct tocador
{
    int status;
    t_musica* faixa_carregada; //musica a ser tocada

    //biblioteca de musica var // --> seria uma lista de musicas com suas devidas propriedades

    //fila de reproducao;
    t_fila* proximas;

    //ultimas tocadas
    t_pilha* ultimas;




}t_tocador;


t_tocador *criar_tocador(){

    t_tocador *novo = malloc(sizeof(t_tocador));

    novo->status = STOP;
    novo->faixa_carregada = NULL;

    //atualização

    novo->proximas = criar_fila();
    novo->ultimas = criar_pilha();

    return novo;

}

void play_tocador(t_tocador *t){

    if(t->status == LOAD){
        printf("Reproduzindo \n");
        imprimir_musica(t->faixa_carregada);
        t->status = PLAYING;
    }

}

void pause_tocador(t_tocador *t){

    if(t->status == PLAYING){
        printf("Pausando \n");
        imprimir_musica(t->faixa_carregada);
        t->status = PAUSE;
    }

}

void stop_tocador(t_tocador *t){

    if(t->status != STOP){

        printf("Parando \n");
        t->status = STOP;

    }

}

void loading_tocador(t_tocador *t){ //loading tem de vir da fila de proximas a tocar

    if (t->status == STOP){
    
        // fila de musicas pode nao ter mais nenhuma musica
        t->faixa_carregada = NULL;

        if (!(vazia_fila(t->proximas))){
            
            t->faixa_carregada = primeiro_fila(t->proximas);
            //printf("jf\n");
            t->status = LOAD;
        }

        //musicas devem agora ser carregadas da fila de proximas

        //t->faixa_carregada = primeiro_fila(t->proximas);


        //t->faixa_carregada = malloc(sizeof(t_musica));
        //scanf("%s", t->faixa_carregada->nome);
        //scanf("%s %d", t->faixa_carregada->genero, &t->faixa_carregada->duracao);
    
        //t->status = LOAD;

    }
}

void resume_tocador(t_tocador *t){

    if(t->status == PAUSE){

        printf("Retomando \n");
        imprimir_musica(t->faixa_carregada);
        t->status = PLAYING;

    }

}

static void loading_proximas(t_tocador *t){ //static é utilizado de maneira interna; só pode ser usada pelo tocador;

    int status;
    scanf("%d", &status);
    //printf("1fj\n");
    while(status == 1){

        t_musica *musica = malloc(sizeof(t_musica));

        scanf("%s", musica->nome);
        scanf("%s", musica->genero);
        scanf("%d", &(musica->duracao));  

        //printf("jdf\n");
        enfileirar(t->proximas, musica);
        //printf("jdf2\n");

        scanf("%d", &status);
    }
    //printf("2sj\n");

}

void end_tocador(t_tocador *t){

    if(t->status == PLAYING){

        t->status = STOP;

        t_musica* m = desenfileirar(t->proximas); //musica chegando deve entrar no topo da pilha
        empilhar(t->ultimas, m);

        //AUTO PLAY
        //loading_tocador(t);

    }
}

void forward_tocador(t_tocador *t){

    if(!(vazia_fila(t->proximas))){

        t_musica *m = desenfileirar(t->proximas);

        t->faixa_carregada = primeiro_fila(t->proximas);

        printf("Avancando...\n");
        imprimir_musica(m);
        empilhar(t->ultimas, m);

    }

}

void backward_tocador(t_tocador *t){

    if(altura_pilha(t->ultimas)>0){

        t_musica *m = desempilhar(t->ultimas);

        t->faixa_carregada = m;
        printf("Retornando...\n");
        imprimir_musica(m);
        enfileirar(t->proximas, m);

    }

}

int main(void){


    int acao; // interação com o tocador
    t_tocador *tocador = criar_tocador();


    //carga inicial de musicas

    loading_proximas(tocador);

    do{

        scanf("%d", &acao);

        switch (acao){
            case LOAD:
                loading_tocador(tocador);
                break;

            case PLAYING:
                play_tocador(tocador);
                break;

            case PAUSE:
                pause_tocador(tocador);
                break;

            case STOP:
                stop_tocador(tocador);
                break;

            case RESUME:
                resume_tocador(tocador);
                break;

            case END:
                end_tocador(tocador);
                break;
    
            case FORWARD:
                forward_tocador(tocador);
                break;

            case BACKWARD:
                backward_tocador(tocador);
                break;
            
            default:
                break;
        }

        //scanf("%d", &acao);

    }while(acao != FINAL);
    

    //imprimir_musica(topo(tocador->ultimas));









/*

    char nome[60], genero[30];
    int duracao;

    

    t_lse* playlist = criar_lse(imprimir_musica, comparar_musica);

    scanf("%s",nome);

    while (strcmp(nome, "FIM") != 0)
    {
        scanf("%s %d", genero, &duracao);
        
        inserir_ordenado_lse(playlist, criar_musica(nome, genero, duracao));
        //inserir_final_lse(playlist, criar_musica(nome, genero, duracao));

        scanf("%s", nome);
    }

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

*/
    //remover_inicio_lse(playlist);
    //remover_final_lse(playlist);
    //imprimir_lse(playlist);

}