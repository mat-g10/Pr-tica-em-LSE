void mostra_vetor(int* vetor[], int k, int tam){
    for(int i=k;i<tam;i++){
        printf("%d ", *(vetor[i]) );
    }
    printf("\n");
}

int comparar_int(int* a, int *b){
    return (*a - *b);
}

int main(){
    int TAM = 10;
    int* vetor[TAM];
    for(int i = 0;i<TAM;i++){
        vetor[i] = malloc(4);
        *(vetor[i]) = rand() % 100;   
    }
    mostra_vetor(vetor,0, TAM);
//    merge_sort(vetor,TAM,comparar_int);
//    quick_sort(vetor,TAM,comparar_int);
    heap_sort(vetor,TAM,comparar_int);
    mostra_vetor(vetor,0, TAM);
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