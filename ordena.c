#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ordena.h"


typedef int(*t_ordena_comparar)(void*, void*);

static void trocar(void* elems[], int i, int j){ //static para nao gerar conflitos

    void* aux = elems[i];
    elems[i] = elems[j];
    elems[j] = aux;

}

static void desce_heap(void* elems[], int i, int ultima, t_ordena_comparar compara){

    // 2 descendencias
    //2*i + 1
    //2*i + 2

    //na ideia de heap de maxima
    int imaior = i; //imaior = raiz(primeiro elemento)
    do{
        i = imaior;
        if((2*i+1 <= ultima) && (compara(elems[i], elems[2*i+1])<0)){ //verifica se tem descendente á esquerda //se <0, o segundo é maior

            imaior = 2*i+1;

        }

        if((2*i+2 <= ultima) && (compara(elems[imaior], elems[2*i+2])<0)){

            imaior = 2*i+2;

        }   
        trocar(elems, i, imaior);

    }while(i!=imaior); //enquanto isso acontecer signfica q houve trocas


}

void construir_heap(void* elems[], int tamanho, t_ordena_comparar compara){ //tamanho = ultimo indice 

    int i = (int)floor((tamanho-1)/2); //achar ponto central arredondado pra baixo
    int imaior = i;
    while(i>=0){ //para vericar descendencia

        //Muito similar ao desce heap
        /*
        i = imaior; //verificar se os descendentes tem descendentes
        if((2*i+1 < tamanho) && (compara(elems[i], elems[2*i+1])<0)){ //para restabelecer a ordem

            imaior = 2*i+1;

        }

        if((2*i+2 < tamanho) && (compara(elems[imaior], elems[2*i+2]<0))){

            imaior =  2*i+2;

        }

        if(i != imaior){
            trocar(elems, i, imaior);
        }
        */

       //Portanto usa-se a função desce_heap

       desce_heap(elems, i, tamanho-1, compara); //tamngo-1 representa o ultimo indice
       i = i - 1;

    }

}

void heap_sort(void* elems[], int tamanho, t_ordena_comparar compara){

    construir_heap(elems, tamanho, compara);
    int ultima = tamanho-1;
    while (ultima >= 1 )
    {
        trocar(elems, 0, ultima); //trocar o ultimo elemento com a raiz
        ultima = ultima-1;
        desce_heap(elems, 0, ultima, compara); //ate o ultimo elemento
    }

}

int particao(void* elems[], int lim_i, int lim_j, t_ordena_comparar compara){

    int i_pivo = (lim_i + lim_j)/2;
    trocar(elems, i_pivo, lim_j);

    int i = lim_i;
    int j = lim_j - 1; //

    do{

        while(compara(elems[i], elems[lim_j])<0){  //lim_j está no pivo //

            i++;
            //prin

        }
        while((j >= 0) && compara(elems[j], elems[lim_j])>0){ //j precisa ser >= 0 evitando que ultrapasse os limites do vetor
            j--;
        }
        if(i < j){

            trocar(elems, i, j);

        }


    }while(i <= j);
    trocar(elems, i, lim_j);
    return i;

}


static void qs(void* elems, int i, int j, t_ordena_comparar compara){ //i e j sao delimitadores; i = comeco, j = fim

    if((j-i) >= 1){ //se for igual a 1 ja ta ordenado, nesse caso se forem iguais o tamanho é = 0

        int meio = particao(elems, i, j, compara); //particiona o conjunto em 2

        qs(elems, i, meio-1, compara);

        qs(elems, meio+1, j, compara);

    }

} 

void quick_sort(void* elems[], int tamanho, t_ordena_comparar compara){

    qs(elems, 0, tamanho-1, compara);


}

void intercalar(void* elems[], int lim_i, int meio, int lim_j, t_ordena_comparar compara){
    void* aux[lim_j-lim_i+1];
    int k = 0;
    int i=lim_i, j=meio+1;
    while((i<=meio) &&(j<=lim_j)){
        if (compara(elems[i],elems[j])<0){
            aux[k] = elems[i];
            i++;
        }else{
            aux[k] = elems[j];
            j++;
        }
        k++;
    }
    while(i<=meio){
        aux[k] = elems[i];
        i++;k++;
    }
    while(j<=lim_j){
        aux[k] = elems[j];
        j++;k++;
    }

    for(i=0;i<k;i++){
        elems[lim_i+i] = aux[i];
    }
}

void static ms(void* elems[], int i, int j, t_ordena_comparar compara){

    if((j-i) > 1){
        int meio = (i+j)/2;
        ms(elems, i, meio, compara);
        ms(elems, meio+1, j, compara);
        intercalar(elems, i, meio, j, compara);
    }


}

void merge_sort(void* elems[], int tamanho, t_ordena_comparar compara){ //inverso do 

    ms(elems, 0, tamanho-1, compara);

}

void mostra_vetor(int* vetor[], int k, int tam){
    for(int i=k;i<tam;i++){
        printf("%d ", *(vetor[i]) );
    }
    printf("\n");
}

int comparar_int(void* a, void *b){
    //return (*a - *b);
    int* aa = a;
    int* bb = b;
    return (*aa - *bb); // cast
}

int main(){
    int TAM = 10;
    int* vetor[TAM];
    for(int i = 0;i<TAM;i++){
        vetor[i] = malloc(4);
        *(vetor[i]) = rand() % 100;   
    }
   
    mostra_vetor(vetor,0, TAM);
    //merge_sort(vetor,TAM,comparar_int);
    //quick_sort(vetor,TAM,comparar_int);
    heap_sort((void**)vetor,TAM,comparar_int); //TAM-1 representta o ultimo indice
    mostra_vetor(vetor,0, TAM);
}