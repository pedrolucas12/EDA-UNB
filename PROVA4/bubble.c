// Bubble sort
void bubble_sort(int v[], int l, int r) {
    for (; r > l; r--) {
        for (int j = l; j < r; j++) {
            if (v[j] > v[j + 1]) {
                exch(v[j], v[j + 1]);
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