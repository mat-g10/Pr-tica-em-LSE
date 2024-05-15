#include "stdio.h"
#include "stdlib.h"

typedef struct elem_lse{

    int idade;
    double peso;
    double altura;

    struct elem_lse* prox;

}t_elemento_lse;

typedef struct lse{

    t_elemento_lse* inicio;
    t_elemento_lse* fim;

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

// inserir_final_lse

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


// remover_inicio_lse

typedef struct{
    int idade;
    double peso;
    double altura;

}retornoRemover;


retornoRemover remover_elemento_inicio(t_lse* lse){

    t_elemento_lse* aux = lse->inicio;
    lse->inicio = aux->prox;

    retornoRemover retorno;
    retorno.idade = aux->idade;
    retorno.peso = aux->peso;
    retorno.altura = aux->altura;
    lse->tamanho--;
    free(aux);

    
    return retorno;

}

// tamanho_lse

// criar_lse

t_lse* criarListaSE(){

    t_lse* lista = malloc(sizeof(t_lse));

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;

    return lista;

}

// implemente aqui a entrada de dados
// para testar seu código
int main(int argc, char const *argv[])
{
    t_lse* lista = criarListaSE();
    int num = 1;
    int id;
    double pe, al;

    while(num == 1){
        int opcao;
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:  //Inserir No Final
            if(lista){
                scanf("%d",&id);
                scanf("%lf",&pe);
                scanf("%lf",&al);
                inserirFinal(lista, id, pe, al);
            }
            break;

        case 2: //Remover do Inicio
            if(lista->tamanho > 0){
                retornoRemover result = remover_elemento_inicio(lista);
                printf("%d ",result.idade);
                printf("%.1lf ",result.peso);
                printf("%.1lf\n",result.altura);
            }
            break;

        case 3: //Tamanho Da Lista
            if(lista){
                printf("%d\n",lista->tamanho);
            }
            break;

        case 0:
            num = 0;
            break;

        default:
            num = 0;
            break;
        }
    }
    return 0;
}
