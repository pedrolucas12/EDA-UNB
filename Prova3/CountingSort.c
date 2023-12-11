//Implementação do Counting Sort
void CoutingSort (int *A, int *B, int k, int n){ 
    int i, j;
    int C[k];
    for (i = 0; i < k; i++){ //Inicializa o vetor C com 0
        C[i] = 0;
    }
    for (j = 0; j < n; j++){ //Conta quantas vezes cada elemento aparece no vetor A
        C[A[j]] = C[A[j]] + 1;
    }
    for (i = 1; i < k; i++){  //Soma o elemento anterior com o atual
        C[i] = C[i] + C[i-1]; //Soma com anterior
    }
    for (j = n-1; j >= 0; j--){ //Ordena o vetor B
        B[C[A[j]]-1] = A[j]; //B recebe o valor de A
        C[A[j]] = C[A[j]] - 1;  //Decrementa o valor de C
    }
}

//Counting Sort Recursivo
void CountingSortRecursivo (int *A, int *B, int k, int n, int i){ 
    int j;
    int C[k];
    for (j = 0; j < k; j++){ //Inicializa o vetor C com 0
        C[j] = 0;
    }
    for (j = 0; j < n; j++){ //Conta quantas vezes cada elemento aparece no vetor A
        C[A[j]] = C[A[j]] + 1;
    }
    for (j = 1; j < k; j++){  //Soma o elemento anterior com o atual
        C[j] = C[j] + C[j-1]; //Soma com anterior
    }
    for (j = n-1; j >= 0; j--){ //Ordena o vetor B
        B[C[A[j]]-1] = A[j]; //B recebe o valor de A
        C[A[j]] = C[A[j]] - 1;  //Decrementa o valor de C
    }
    if (i < n){
        CountingSortRecursivo (B, A, k, n, i+1);
    }
}

/*
Etapa 1: contar as frequências
    ▶ Para o intervalo de chaves: 0 até R − 1
    ▶ Utiliza-se: count[R+1]
    ▶ Cada chave i em 0 até R − 1 = count[i]
    ▶ Cada count[i] = frequência da chave i − 1 (imediatamente < i)
*/
    for (i =0; i <= R; i ++){ // zerando
        count [i] = 0;
    }
    for (i= l; i <= r; i ++){ // frequências
        count [v[i ]+1]++;
    }
/*
Etapa 2: Calculando as posições/índices através das frequências
    ▶ Se count[i] contém a quantidade de chaves imediatamente menores que i,
    ▶ Então, se, count[i] = count[i] + count[i-1] + ... + count[0],
    ▶ count[i] vai conter a quantidade de todas as chaves menores que i,
    ▶ count[i] vai conter a quantidade de posições que devem ser "puladas" para a
    inserção das chaves menores que i,
    ▶ Portanto, count[i] contém a distância de 0 até a chave i (posição de i)
*/
    for (i =1; i <= R; i ++){ // posições
        count[i] += count[i- 1];
    }
/*
Etapa 3: distribuindo as chaves
    ▶ count[R+1]: tabela de índices
    ▶ aux[r-l+1]: auxiliar para copiar as chaves na ordem,
        ⋆ count[ v[i] ]: posição ordenada da chave v[i]
        ⋆ aux[count[v[i]]] = v[i]: v[i] em sua posição ordenada em aux[ ]
        ⋆ count[ v[i] ]++: próxima v[i] em sua posição ordenada em aux[ ]
*/
    for ( i = l; i <= r; i ++) { // distribuição
        aux[count[v[i]]] = v[i];
        count[v[i]]++;
    }

//CODIGO COMPLETO
void countingsort ( int *v , int l , int r) {
    int i , count [R +1];
    // zerando
    for (i = 0; i <= R; i ++) {
        count [i] = 0;
    }
    // frequencias
    for (i = l; i <= r; i ++) {
        count [v[i ] + 1]++;
    }
    // posições
    for (i = 1; i <= R; i ++) {
        count [i] += count [ i- 1];
    }
    // distribuição
    for (i = l; i <= r; i ++) {
        aux [ count [v[ i ]]] = v[ i ];
        count [ v[i ]]++;
    }
    //cópia: a partir de aux [0]
    for (i = l; i <= r; i ++) {
        v [i] = aux [ i-l ];
    }
}



