//Implementacao do RadixSort
void RadixSort (int *A, int *B, int k, int n){
    int i, j, d, m, exp = 1;
    int C[k];
    for (i = 0; i < k; i++){ //Inicializa o vetor C com 0
        C[i] = 0;
    }
    for (j = 0; j < n; j++){ //Conta quantas vezes cada elemento aparece no vetor A
        C[A[j]] = C[A[j]] + 1;
    }
    for (i = 1; i < k; i++){  //Soma o elemento anterior com o atual
        C[i] = C[i] + C[i-1];
    }
    for (j = n-1; j >= 0; j--){ //Ordena o vetor B
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    for (i = 0; i < n; i++){ //Encontra o maior elemento do vetor
        if (A[i] > m){
            m = A[i];
        }
    }
    while (m/exp > 0){ //Ordena o vetor B de acordo com o digito
        for (i = 0; i < n; i++){ //Conta quantas vezes cada elemento aparece no vetor B
            C[(A[i]/exp)%10] = C[(A[i]/exp)%10] + 1;
        }
        for (i = 1; i < k; i++){ //Soma o elemento anterior com o atual
            C[i] = C[i] + C[i-1];
        }
        for (j = n-1; j >= 0; j--){ //Ordena o vetor A
            B[C[(A[j]/exp)%10]-1] = A[j];
            C[(A[j]/exp)%10] = C[(A[j]/exp)%10] - 1;
        }
        for (i = 0; i < n; i++){ //Copia o vetor B para o vetor A
            A[i] = B[i];
        }
        exp = exp*10;
    }
}

void radix_sortLSD (int *v , int l , int r) {
int i , w;
int aux [r-l +1] , count [R +1];
    for (w =0; w < bytesword ; w ++) { // bytesword = 4
        // for (i =0; i <=R; i++) count [i] = 0;
        memset ( count , 0, sizeof (int) *( R +1) );
        for (i= l; i <= r; i ++) { // frequências
            count [ digit (v[ i], w ) +1 ]++;
        }
        for (i =1; i <= R; i ++) { // posições
            count [i] += count [i- 1];
        }
        for (i= l; i <= r; i ++) { // distribuindo
            aux [ count [ digit (v[i ], w ) ] ] = v[i ];
            count [ digit (v[i ], w ) ]++;
        }
        for (i= l; i <= r; i ++) { // copiando
            v[i] = aux [i-l];
        }
    }
}

// Strings : retorna o désimo caractere
int charAt ( char s [] , int d) {
    if (d < strlen ( s))
        return s [d ]; //d-é simo caractere
    else
        return - 1; // count [-1 + 1] = count [0]
}

// Strings : ordena para o d-é simo caractere
void radixMSD ( char a [][ maxstring ] , int l , int r , int d) { // d = 0
    if(r <= l ) return ; // vetor vazio
    char aux [r-l +1][ maxstring ];
    int count [R +1];
    memset ( count , 0, sizeof (int) *( R +1) ); // zerando
    for ( int i = l ; i <= r ; i ++) // frequências
        count [ charAt (a[i ], d) + 1]++;
    for ( int i = 1; i <= R; i ++)  // posições
        count [i] += count [i- 1];
    for ( int i = l ; i <= r ; i ++) // distribuição
        strcpy ( aux [ count [ charAt (a [i], d) ]++] , a [i ]) ;
    for ( int i = l ; i <= r ; i ++) // copiando
        strcpy (a [i], aux [i - l ]) ;
    for ( int i = 1; i <= R ; i ++) { // ordenando os que começam por i
        radixMSD (a , l + count [i- 1] , l + count [ i]-1, d +1) ;
    }
}

// Inteiros : ordena o w-é simo byte
void radix_sortMSD (int *v , int l , int r , int w) { // w = bytesword -1
    if(r <= l || w < 0) return ;
    int i , aux [r-l +1] , count [ R +1];
    memset ( count , 0, sizeof (int) *( R +1) ); // zerando
    for (i= l; i <= r; i ++) // frequências
        count [ digit (v[i], w) +1]++;
    for (i =1; i <= R; i ++) // posições
        count [ i] += count [i- 1];
    for (i= l; i <= r; i ++)    // distribuição
        aux [ count [ digit (v [i], w) ]++] = v[i ];
    for (i= l; i <= r; i ++)  // copiando
        v[i] = aux [i-l ];
    // ordenando os que come çam por zero
    radix_sortMSD (v , l , l + count [0] -1, w- 1) ; // w = bytesword -1
    for ( i = 1; i <= R; i ++) // ordenando os que começam por i
        radix_sortMSD (v , l + count [i- 1] , l + count [i ]-1, w- 1) ;
}