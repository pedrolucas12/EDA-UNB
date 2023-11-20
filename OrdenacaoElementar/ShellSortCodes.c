//Implementacao do Algoritmo de Ordenacao Shell Sort

//Shell Sort
void shellSort(int *vetor, int tamanho){
    int i, j, aux, h = 1;
    do{ //calcula o valor de h
        h = (h * 3) + 1;
    }while(h < tamanho); //enquanto h for menor que o tamanho do vetor
        do{
            h /= 3; //atualiza o valor de h
            for(i = h; i < tamanho; i++){ //percorre o vetor
                aux = vetor[i]; //guarda o valor atual
                j = i;
                while((j >= h) && (aux < vetor[j-h])){ //percorre o vetor da posicao atual ate a primeira posicao
                    vetor[j] = vetor[j-h]; //troca os valores
                    j -= h; //decrementa a posicao
                }
                vetor[j] = aux; //guarda o valor atual na posicao correta
            }
    } while(h != 1);
}

//Shell Sort Recursivo
void shellSortRecursivo(int *vetor, int tamanho, int h){
    int i, j, aux;
    if(h < tamanho){ //se h for menor que o tamanho do vetor
        for(i = h; i < tamanho; i++){ //percorre o vetor
            aux = vetor[i]; //guarda o valor atual
            j = i;
            while((j >= h) && (aux < vetor[j-h])){ //percorre o vetor da posicao atual ate a primeira posicao
                vetor[j] = vetor[j-h]; //troca os valores
                j -= h; //decrementa a posicao
            }
            vetor[j] = aux; //guarda o valor atual na posicao correta
        }
        shellSortRecursivo(vetor, tamanho, h/3); //chama a funcao novamente com h/3
    }
}

//Shell Sort com Insercao Direta
void shellSortInsercaoDireta(int *vetor, int tamanho){
    int i, j, aux, h = 1;
    do{ //calcula o valor de h
        h = (h * 3) + 1;
    }while(h < tamanho); //enquanto h for menor que o tamanho do vetor
        do{
            h /= 3; //atualiza o valor de h
            for(i = h; i < tamanho; i++){ //percorre o vetor
                aux = vetor[i]; //guarda o valor atual
                j = i;
                while((j >= h) && (aux < vetor[j-h])){ //percorre o vetor da posicao atual ate a primeira posicao
                    vetor[j] = vetor[j-h]; //troca os valores
                    j -= h; //decrementa a posicao
                }
                vetor[j] = aux; //guarda o valor atual na posicao correta
            }
    } while(h != 1);
    insercaoDireta(vetor, tamanho); //chama a funcao de insercao direta
}

//Shell Sort em Lista Encadeada
void shellSortListaEncadeada(Lista *lista){
    int i, j, aux, h = 1;
    do{ //calcula o valor de h
        h = (h * 3) + 1;
    }while(h < lista->tamanho); //enquanto h for menor que o tamanho da lista
        do{
            h /= 3; //atualiza o valor de h
            for(i = h; i < lista->tamanho; i++){ //percorre a lista
                aux = lista->inicio; //guarda o valor atual
                j = i;
                while((j >= h) && (aux < lista->inicio)){ //percorre a lista da posicao atual ate a primeira posicao
                    lista->inicio = lista->inicio->proximo; //troca os valores
                    j -= h; //decrementa a posicao
                }
                lista->inicio = aux; //guarda o valor atual na posicao correta
            }
    } while(h != 1);
}

