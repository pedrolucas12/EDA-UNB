//Implementacao do algoritmo de ordenacao Insertion Sort

//Insertion Sort
void insertionSort(int *vetor, int tamanho){
    int i, j, aux;
    for(i = 1; i < tamanho; i++){ //percorre o vetor
        aux = vetor[i]; //guarda o valor atual
        for(j = i; (j > 0) && (aux < vetor[j-1]); j--){ //percorre o vetor da posicao atual ate a primeira posicao
            vetor[j] = vetor[j-1]; //troca os valores
        } 
        vetor[j] = aux; //guarda o valor atual na posicao correta
    }
}

//Insertion Sort Recursivo
void insertionSortRecursivo(int *vetor, int tamanho){
    if(tamanho > 1){ //se o tamanho for maior que 1
        insertionSortRecursivo(vetor, tamanho-1); //chama a funcao recursivamente com o tamanho - 1
        int aux = vetor[tamanho-1]; //guarda o valor atual
        int j = tamanho-1; //guarda a posicao atual
        while((j > 0) && (aux < vetor[j-1])){ //percorre o vetor da posicao atual ate a primeira posicao
            vetor[j] = vetor[j-1]; //troca os valores
            j--; //decrementa a posicao
        }
        vetor[j] = aux; //guarda o valor atual na posicao correta
    }
}

//Insertion Sort para Baralho de Cartas
void insertionSortBaralho(int *vetor, int tamanho){
    int i, j, aux;
    for(i = 1; i < tamanho; i++){ //percorre o vetor
        aux = vetor[i]; //guarda o valor atual
        for(j = i; (j > 0) && (aux < vetor[j-1]); j--){ //percorre o vetor da posicao atual ate a primeira posicao
            vetor[j] = vetor[j-1]; //troca os valores
        } 
        vetor[j] = aux; //guarda o valor atual na posicao correta
    }
}

///Função que permute os elementos de um vetor v[0..n-1] de modo que eles fiquem em ordem decrescente
void insertionSortDecrescente(int *vetor, int tamanho){
    int i, j, aux;
    for(i = 1; i < tamanho; i++){ //percorre o vetor
        aux = vetor[i]; //guarda o valor atual
        for(j = i; (j > 0) && (aux > vetor[j-1]); j--){ //percorre o vetor da posicao atual ate a primeira posicao
            vetor[j] = vetor[j-1]; //troca os valores
        } 
        vetor[j] = aux; //guarda o valor atual na posicao correta
    }
}

//Insertion Sort em Listas Encadeadas
void insertionSortListaEncadeada(ListaEncadeada *lista){
    if(lista != NULL){ //se a lista nao for nula
        No *atual = lista->inicio->proximo; //guarda o primeiro elemento
        while(atual != NULL){ //percorre a lista
            No *aux = atual; //guarda o elemento atual
            while((aux->anterior != NULL) && (aux->valor < aux->anterior->valor)){ //percorre a lista da posicao atual ate a primeira posicao
                int temp = aux->valor; //guarda o valor atual
                aux->valor = aux->anterior->valor; //troca os valores
                aux->anterior->valor = temp;
                aux = aux->anterior; //decrementa a posicao
            }
            atual = atual->proximo; //incrementa a posicao
        }
    }
}



/*
    - A ideia é "puxar" os maiores e encaixar/inserir/reposicionar o elemento somente quando achar sua posição em relação aos seus antecessores (sem swaps, somente atribuições).
*/
//Insertion Sort Otimizado
void insertionSortOtimizado(int *vetor, int tamanho){
    int i, j, aux;
    for(i = 1; i < tamanho; i++){ //percorre o vetor
        aux = vetor[i]; //guarda o valor atual
        for(j = i; (j > 0) && (aux < vetor[j-1]); j--){ //percorre o vetor da posicao atual ate a primeira posicao
            vetor[j] = vetor[j-1]; //troca os valores
        } 
        vetor[j] = aux; //guarda o valor atual na posicao correta
    }
}

/*
- Mais uma otimização possível é utilizar um sentinela, inserindo o menor elemento na primeira posição antes das outras ordenações. Empurrar o menor para a esquerda (sentinela), enquanto "puxa" os maiores para a direita.
*/
//Insertion Sort com Sentinela
void insertionSortSentinela(int *vetor, int tamanho){
    int i, j, aux;
    for(i = 1; i < tamanho; i++){ //percorre o vetor
        aux = vetor[i]; //guarda o valor atual
        for(j = i; (j > 0) && (aux < vetor[j-1]); j--){ //percorre o vetor da posicao atual ate a primeira posicao
            vetor[j] = vetor[j-1]; //troca os valores
        } 
        vetor[j] = aux; //guarda o valor atual na posicao correta
    }
}

