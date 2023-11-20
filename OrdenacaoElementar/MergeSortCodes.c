//Implementacao do Algorigtmo de Ordenacao MergeSort

//MergeSort
void mergeSort(int *vetor, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio + fim)/2);
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

//Merge do MergeSort
void merge(int *vetor, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0; 
    tamanho = fim - inicio + 1; //tamanho do vetor
    p1 = inicio; //ponteiro 1
    p2 = meio + 1; //ponteiro 2
    temp = (int *) malloc(tamanho*sizeof(int)); //vetor temporario
    if(temp != NULL){ 
        for(i = 0; i < tamanho; i++){ //percorre o vetor
            if(!fim1 && !fim2){ //se nao chegou ao fim
                if(vetor[p1] < vetor[p2]){ //se o valor do ponteiro 1 for menor que o do ponteiro 2
                    temp[i] = vetor[p1++];
                }else{ //se o valor do ponteiro 2 for menor que o do ponteiro 1
                    temp[i] = vetor[p2++];
                }
                if(p1 > meio){ //se o ponteiro 1 chegou ao fim
                    fim1 = 1;
                }
                if(p2 > fim){ //se o ponteiro 2 chegou ao fim
                    fim2 = 1;
                }
            }else{ //se chegou ao fim
                if(!fim1){  //se o ponteiro 1 nao chegou ao fim
                    temp[i] = vetor[p1++];
                }else{ //se o ponteiro 2 nao chegou ao fim
                    temp[i] = vetor[p2++];
                }
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++, k++){ //percorre o vetor
            vetor[k] = temp[j]; //atribui os valores do vetor temporario ao vetor original
        }
    }
    free(temp);
}

//Merge do MergeSort com Listas Encadeadas
void mergeListas(Lista *lista, int inicio, int meio, int fim){
    int tamanho, i, j, k;
    int fim1 = 0, fim2 = 0; 
    tamanho = fim - inicio + 1; //tamanho do vetor
    int p1 = inicio; //ponteiro 1
    int p2 = meio + 1; //ponteiro 2
    int *temp = (int *) malloc(tamanho*sizeof(int)); //vetor temporario
    if(temp != NULL){ 
        for(i = 0; i < tamanho; i++){ //percorre o vetor
            if(!fim1 && !fim2){ //se nao chegou ao fim
                if(lista->vetor[p1] < lista->vetor[p2]){ //se o valor do ponteiro 1 for menor que o do ponteiro 2
                    temp[i] = lista->vetor[p1++];
                }else{ //se o valor do ponteiro 2 for menor que o do ponteiro 1
                    temp[i] = lista->vetor[p2++];
                }
                if(p1 > meio){ //se o ponteiro 1 chegou ao fim
                    fim1 = 1;
                }
                if(p2 > fim){ //se o ponteiro 2 chegou ao fim
                    fim2 = 1;
                }
            }else{ //se chegou ao fim
                if(!fim1){  //se o ponteiro 1 nao chegou ao fim
                    temp[i] = lista->vetor[p1++];
                }else{ //se o ponteiro 2 nao chegou ao fim
                    temp[i] = lista->vetor[p2++];
                }
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++, k++){ //percorre o vetor
            lista->vetor[k] = temp[j]; //atribui os valores do vetor temporario ao vetor original
        }
    }
    free(temp);
}

//Merge sem vetor auxiliar
void mergeSemVetorAux (int *vetor, int inicio, int meio, int fim){
    int i, j, k;
    int tamanho = fim - inicio + 1; //tamanho do vetor
    int *temp = (int *) malloc(tamanho*sizeof(int)); //vetor temporario
    if(temp != NULL){ 
        for(i = inicio, j = meio + 1, k = 0; k < tamanho; k++){ //percorre o vetor
            if(i > meio){ //se o ponteiro 1 chegou ao fim
                temp[k] = vetor[j++];
            }else{
                if(j > fim){ //se o ponteiro 2 chegou ao fim
                    temp[k] = vetor[i++];
                }else{
                    if(vetor[i] < vetor[j]){ //se o valor do ponteiro 1 for menor que o do ponteiro 2
                        temp[k] = vetor[i++];
                    }else{ //se o valor do ponteiro 2 for menor que o do ponteiro 1
                        temp[k] = vetor[j++];
                    }
                }
            }
        }
        for(i = inicio, k = 0; i <= fim; i++, k++){ //percorre o vetor
            vetor[i] = temp[k]; //atribui os valores do vetor temporario ao vetor original
        }
    }
    free(temp);
}

//Merge Bottom-Up
void mergeBottomUp(int *vetor, int inicio, int fim){
    int i, j, k, meio;
    int tamanho = fim - inicio + 1; //tamanho do vetor
    int *temp = (int *) malloc(tamanho*sizeof(int)); //vetor temporario
    if(temp != NULL){ 
        for(i = 1; i < tamanho; i = i + i){ //percorre o vetor
            for(j = inicio; j < tamanho - i; j += i + i){ //percorre o vetor
                meio = j + i - 1; //meio do vetor
                fim = j + i + i - 1; //fim do vetor
                if(fim > tamanho - 1){ //se o fim for maior que o tamanho do vetor
                    fim = tamanho - 1;
                }
                mergeSemVetorAux(vetor, j, meio, fim); //chama a funcao merge sem vetor auxiliar
            }
        }
    }
    free(temp);
}


//MergeSort Iterativo
void mergeSortIterativo(int *vetor, int inicio, int fim){
    int i, j, k, meio;
    int tamanho = fim - inicio + 1; //tamanho do vetor
    int *temp = (int *) malloc(tamanho*sizeof(int)); //vetor temporario
    if(temp != NULL){ 
        for(i = 1; i < tamanho; i = i + i){ //percorre o vetor
            for(j = inicio; j < tamanho - i; j += i + i){ //percorre o vetor
                meio = j + i - 1; //meio do vetor
                fim = j + i + i - 1; //fim do vetor
                if(fim > tamanho - 1){ //se o fim for maior que o tamanho do vetor
                    fim = tamanho - 1;
                }
                mergeSemVetorAux(vetor, j, meio, fim); //chama a funcao merge sem vetor auxiliar
            }
        }
    }
    free(temp);
}

