//INSERTION SORT
void insertion_sort(int v[], int l, int r)
{
    int elem, i, j;
    for (i = l + 1; i <= r; i++)
    {
        elem = v[i];
        for (j = i; j > l && elem < v[j - 1]; j--)
            v[j] = v[j - 1]; // puxando o maior

        v[j] = elem; // encaixando o elemento
    }
}


// SHELL SORT
void shell_sort(int v[], int l, int r)
{
    int h = 1;
    while (h < (r - l + 1) / 3)
        h = 3 * h + 1;

    while (h >= 1)
    {
        for (int i = l + h; i <= r; i++)
        {
            for (int j = i; j >= l + h && v[j] < v[j - h]; j -= h)
            {
                exch(v[j], v[j - h]);
            }
        }
        h = h / 3;
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
