//Implementacao do Algoritmo de Ordenacao - Selection Sort

//Selection Sort Padrao
void Selection_Sort (int *v, int n) {
    int i, j, min, aux;
    for (i = 0; i < (n-1); i++) { // Percorre o vetor
        min = i; // O minimo assume a posicao inicial do vetor
        for (j = (i+1); j < n; j++) { // Percorre o vetor a partir da posicao i+1
            if (v[j] < v[min]) // Se o valor da posicao j for menor que o valor da posicao min
                min = j; // O minimo passa a ser a posicao j
        }
        if (v[i] != v[min]) { // Se o valor da posicao i for diferente do valor da posicao min
            aux = v[i]; // O auxiliar recebe o valor da posicao i
            v[i] = v[min]; // O valor da posicao i recebe o valor da posicao min
            v[min] = aux; // O valor da posicao min recebe o valor do auxiliar
        }
    }
}

//Selection Sort Estavel ( SEM TROCA )
void Selection_Sort_Estavel (int *v, int n) {
    int i, j, min, aux;
    for (i = 0; i < (n-1); i++) { // Percorre o vetor
        min = i; // O minimo assume a posicao inicial do vetor
        for (j = (i+1); j < n; j++) { // Percorre o vetor a partir da posicao i+1
            if (v[j] < v[min]) // Se o valor da posicao j for menor que o valor da posicao min
                min = j; // O minimo passa a ser a posicao j
        }
        if (v[i] != v[min]) { // Se o valor da posicao i for diferente do valor da posicao min
            aux = v[min]; // O auxiliar recebe o valor da posicao min
            while (min > i) { // Enquanto a posicao min for maior que a posicao i
                v[min] = v[min-1]; // O valor da posicao min recebe o valor da posicao min-1
                min--; // Decrementa a posicao min
            }
            v[i] = aux; // O valor da posicao i recebe o valor do auxiliar
        }
    }
}

//Selection Sort Recursivo
void Selection_Sort_Recursivo (int *v, int n, int i) {
    int j, min, aux;
    if (i < (n-1)) { // Se o indice for menor que o tamanho do vetor - 1
        min = i; // O minimo assume a posicao inicial do vetor
        for (j = (i+1); j < n; j++) { // Percorre o vetor a partir da posicao i+1
            if (v[j] < v[min]) // Se o valor da posicao j for menor que o valor da posicao min
                min = j; // O minimo passa a ser a posicao j
        }
        if (v[i] != v[min]) { // Se o valor da posicao i for diferente do valor da posicao min
            aux = v[i]; // O auxiliar recebe o valor da posicao i
            v[i] = v[min]; // O valor da posicao i recebe o valor da posicao min
            v[min] = aux; // O valor da posicao min recebe o valor do auxiliar
        }
        Selection_Sort_Recursivo (v, n, i+1); // Chamada recursiva
    }
}

//Selection Sort Decrescente
void Selection_Sort_Decrescente (int *v, int n) {
    int i, j, max, aux;
    for (i = 0; i < (n-1); i++) { // Percorre o vetor
        max = i; // O maximo assume a posicao inicial do vetor
        for (j = (i+1); j < n; j++) { // Percorre o vetor a partir da posicao i+1
            if (v[j] > v[max]) // Se o valor da posicao j for maior que o valor da posicao max
                max = j; // O maximo passa a ser a posicao j
        }
        if (v[i] != v[max]) { // Se o valor da posicao i for diferente do valor da posicao max
            aux = v[i]; // O auxiliar recebe o valor da posicao i
            v[i] = v[max]; // O valor da posicao i recebe o valor da posicao max
            v[max] = aux; // O valor da posicao max recebe o valor do auxiliar
        }
    }
}

//Selection Sort para Listas Encadeadas
void Selection_Sort_Lista (Lista *l) {
    int i, j, min, aux;
    No *p, *q;
    for (p = l->inicio; p != NULL; p = p->prox) { // Percorre a lista
        min = p->info; // O minimo assume a posicao inicial da lista
        for (q = p->prox; q != NULL; q = q->prox) { // Percorre a lista a partir da posicao p->prox
            if (q->info < min) // Se o valor da posicao q->info for menor que o valor da posicao min
                min = q->info; // O minimo passa a ser a posicao q->info
        }
        if (p->info != min) { // Se o valor da posicao p->info for diferente do valor da posicao min
            aux = p->info; // O auxiliar recebe o valor da posicao p->info
            p->info = min; // O valor da posicao p->info recebe o valor da posicao min
            min = aux; // O valor da posicao min recebe o valor do auxiliar
        }
    }
}

//Selection Sort para Listas Duplamente Encadeadas
void Selection_Sort_Lista_Dupla (Lista_Dupla *l) {
    int i, j, min, aux;
    No_Duplo *p, *q;
    for (p = l->inicio; p != NULL; p = p->prox) { // Percorre a lista
        min = p->info; // O minimo assume a posicao inicial da lista
        for (q = p->prox; q != NULL; q = q->prox) { // Percorre a lista a partir da posicao p->prox
            if (q->info < min) // Se o valor da posicao q->info for menor que o valor da posicao min
                min = q->info; // O minimo passa a ser a posicao q->info
        }
        if (p->info != min) { // Se o valor da posicao p->info for diferente do valor da posicao min
            aux = p->info; // O auxiliar recebe o valor da posicao p->info
            p->info = min; // O valor da posicao p->info recebe o valor da posicao min
            min = aux; // O valor da posicao min recebe o valor do auxiliar
        }
    }
}

//Selection Sort para Listas Circulares
void Selection_Sort_Lista_Circular (Lista_Circular *l) {
    int i, j, min, aux;
    No_Circular *p, *q;
    for (p = l->inicio; p != l->fim; p = p->prox) { // Percorre a lista
        min = p->info; // O minimo assume a posicao inicial da lista
        for (q = p->prox; q != l->fim; q = q->prox) { // Percorre a lista a partir da posicao p->prox
            if (q->info < min) // Se o valor da posicao q->info for menor que o valor da posicao min
                min = q->info; // O minimo passa a ser a posicao q->info
        }
        if (p->info != min) { // Se o valor da posicao p->info for diferente do valor da posicao min
            aux = p->info; // O auxiliar recebe o valor da posicao p->info
            p->info = min; // O valor da posicao p->info recebe o valor da posicao min
            min = aux; // O valor da posicao min recebe o valor do auxiliar
        }
    }
}

//Vetor ordenado pelo Selection Sort volta a ser como era
void Selection_Sort_Volta (int *v, int n) {
    int i, j, max, aux;
    for (i = 0; i < (n-1); i++) { // Percorre o vetor
        max = i; // O maximo assume a posicao inicial do vetor
        for (j = (i+1); j < n; j++) { // Percorre o vetor a partir da posicao i+1
            if (v[j] > v[max]) // Se o valor da posicao j for maior que o valor da posicao max
                max = j; // O maximo passa a ser a posicao j
        }
        if (v[i] != v[max]) { // Se o valor da posicao i for diferente do valor da posicao max
            aux = v[i]; // O auxiliar recebe o valor da posicao i
            v[i] = v[max]; // O valor da posicao i recebe o valor da posicao max
            v[max] = aux; // O valor da posicao max recebe o valor do auxiliar
        }
    }
}

