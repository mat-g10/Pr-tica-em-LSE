#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "lseneutra.h"
#include "fila.h"
#include "pilha.h"

#define PLAYING 1
#define PAUSE 2
#define STOP 3
#define LOAD 4
#define RESUME 6
#define END 7
#define FORWARD 8
#define BACKWARD 9
#define FINAL 5



typedef struct {
    char nome[60];
    char genero[30];
    int duracao;
} t_musica;

void imprimir_musica(void* m1){
    t_musica *m = m1;
    int min = m->duracao / 60;
    int seg = m->duracao - min*60;
    printf("%s %s %02d:%02d\n", m->nome, m->genero, min, seg);
    
}

t_musica* criar_musica(char nome[], char genero[], int duracao){
    t_musica *nova = malloc(sizeof(t_musica));
    
    strcpy(nova->nome, nome);
    strcpy(nova->genero, genero);
    nova->duracao = duracao;

    return nova;
}

int comparar_musica(t_musica* m1, t_musica* m2){
    
    return strcmp(m1->nome, m2->nome);

}

typedef struct playlist t_playlist;
struct playlist{
    char nome[60];
    int duracao;
    char descricao[1000];
    int qtde;
    int dia,mes,ano; // data de criacao
    t_lse *musicas; 
};

typedef struct biblioteca t_biblioteca;
struct biblioteca{
    t_lse *musicas;
    t_lse *playlists; // playlists do usuário
    t_lse *generos; // generos
    t_lse *artistas; // artistas
    t_lse *albuns; // albuns; 
};

typedef struct tocador t_tocador;
struct tocador{
    int status;
    t_musica *faixa_carregada;
    
    // fila de reproducao
    t_fila* proximas;

    // ultimas tocadas
    t_pilha* ultimas;

    // biblioteca de musicas
    
};

t_tocador *criar_tocador(){
    t_tocador *novo = malloc(sizeof(t_tocador));
    novo->status = STOP;
    novo->faixa_carregada = NULL;
    novo->proximas = criar_fila();
    novo->ultimas = criar_pilha();

    return novo;
}

void play_tocador(t_tocador *t){
    if (t->status == LOAD){
        printf("Reproduzindo \n");
        imprimir_musica(t->faixa_carregada);
        t->status = PLAYING;
    }
}

void pause_tocador(t_tocador *t){
    if (t->status == PLAYING){
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

void loading_tocador(t_tocador *t){
    if (t->status == STOP){
        t->faixa_carregada = NULL;
        if ( ! vazia_fila(t->proximas) ) {
            t->faixa_carregada = primeiro_fila(t->proximas);
            t->status = LOAD;
        }
    }
}

void resume_tocador(t_tocador *t){
    if (t->status == PAUSE){
        printf("retomando \n");
        imprimir_musica(t->faixa_carregada);
        t->status = PLAYING;
    }
}

void end_tocador(t_tocador* t){
    if(t->status == PLAYING){
        t->status = STOP;
        t_musica* m = desenfileirar(t->proximas);
        empilhar(t->ultimas, m);

        //loading_tocador(t);
    }

}


static void loading_proximas(t_tocador *t){
    int status;
    scanf("%d", &status);

    while(status==1){
        t_musica *musica = malloc(sizeof(t_musica));

        scanf("%s", musica->nome);
        scanf("%s", musica->genero);
        scanf("%d", &(musica->duracao));   

        enfileirar(t->proximas, musica);
        scanf("%d", &status);
    }
}

int main(){
    int acao;
    t_tocador* tocador = criar_tocador();

    loading_proximas(tocador);

    do{
        scanf("%d", &acao);
        switch (acao)
        {
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
        default:
            break;
        }

    }while(acao != FINAL);

    imprimir_musica(topo(tocador->ultimas));

}


//     char nome[60], genero[30];
//     int duracao;
//     t_lse *playlist = criar_lse(imprimir_musica, comparar_musica);
//     scanf("%s", nome);
//     while(strcmp(nome,"FIM")!=0){
//         scanf("%s", genero);
//         scanf("%d", &duracao);
//         inserir_ordenado_lse(playlist,criar_musica(nome,genero,duracao));
// //        inserir_final_lse(playlist, criar_musica(nome,genero,duracao));

//         scanf("%s", nome);
//     }
//     t_musica* buscado = malloc(sizeof(t_musica));
    
//     scanf("%s", buscado->nome);
//     t_musica* m = buscar_lse(playlist,(void*)buscado);
//     if (m!=NULL)
//         imprimir_musica(m);

//     imprimir_lse(playlist);
