//Implementacao do algoritmo BubbleSort

//Bubble Sort Padrao
void bubbleSort(int *vetor, int tamanho){
    int i, j, aux;
    for(i = 0; i < tamanho; i++){ //Percorre o vetor
        for(j = 0; j < tamanho - 1; j++){ //Percorre o vetor - 1
            if(vetor[j] > vetor[j + 1]){ //Se o elemento atual for maior que o proximo
                aux = vetor[j]; //Troca os elementos
                vetor[j] = vetor[j + 1]; //Troca os elementos
                vetor[j + 1] = aux; //Troca os elementos
            }
        }
    }
}

//Bubble Sort com Listas Encadeadas
void bubbleSortListaEncadeada(ListaEncadeada *lista){
    int i, j, aux;
    for(i = 0; i < lista->tamanho; i++){ //Percorre a lista
        for(j = 0; j < lista->tamanho - 1; j++){ //Percorre a lista - 1
            if(lista->vetor[j] > lista->vetor[j + 1]){ //Se o elemento atual for maior que o proximo
                aux = lista->vetor[j]; //Troca os elementos
                lista->vetor[j] = lista->vetor[j + 1]; //Troca os elementos
                lista->vetor[j + 1] = aux; //Troca os elementos
            }
        }
    }
}

//Bubble Sort melhorado e otimizado ( SHAKER SORT -> coloca menor em cima e maior no fundo )
void bubbleSortShakerSort (int *vetor, int tamanho){
    int i, j, aux, troca;
    for(i = 0; i < tamanho; i++){ //Percorre o vetor
        troca = 0; //Variavel de controle
        for(j = 0; j < tamanho - 1; j++){ //Percorre o vetor - 1
            if(vetor[j] > vetor[j + 1]){ //Se o elemento atual for maior que o proximo
                aux = vetor[j]; //Troca os elementos
                vetor[j] = vetor[j + 1]; //Troca os elementos
                vetor[j + 1] = aux; //Troca os elementos
                troca = 1; //Troca os elementos
            }
        }
        if(troca == 0){ //Se nao houve troca
            break; //Para o loop
        }
        troca = 0; //Variavel de controle
        for(j = tamanho - 1; j > 0; j--){ //Percorre o vetor - 1
            if(vetor[j] < vetor[j - 1]){ //Se o elemento atual for menor que o anterior
                aux = vetor[j]; //Troca os elementos
                vetor[j] = vetor[j - 1]; //Troca os elementos
                vetor[j - 1] = aux; //Troca os elementos
                troca = 1; //Troca os elementos
            }
        }
        if(troca == 0){ //Se nao houve troca
            break; //Para o loop
        }
    }
}
