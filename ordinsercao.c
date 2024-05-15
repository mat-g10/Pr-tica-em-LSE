//Analise sintotica
//Pior cenario == 21 COMPARAÇÕES PARA N = 6

#include <stdio.h>
#include <stdlib.h>

int main(void){


    for(i = 1; i < N; i++){

        aux = vetor[i];
        int j = i-1;
        while ((j>=0) && (vetor[j] > aux))
        {
            vetor[j+1] == vetor[j];
            j--;
        }
        vetor[j+1] = aux;
        
    }



}