//Implementacao do IntroSort

void intro (int *v , int l , int r , int maxrecursao ) {
    if( r -l <=15) { // tamanho do vetor <= 15
        insertion_sort (v, l, r);
        return ;
    } else if( maxrecursao == 0) { // profundidade máxima atingida
        // merge_sort (v, l, r);
        heap_sort (v , l , r ) ;
    } else { // profundidade máxima não atingida
    compexch (v[l],v[(l+r)/2]); // mediana de 3
    compexch (v[l],v[r]); // mediana de 3
    compexch (v[r],v[(l+r)/2]); // mediana de 3

    int p = partition (v , l , r ) ; // particiona
    intro (v , l , p - 1 , maxrecursao - 1) ; // ordena esquerda
    intro (v , p +1 , r , maxrecursao - 1) ; // ordena direita
    }
}

void intro_sort (int *v , int l , int r ){ 
    // duas vezes a altura da árvore 2*log do tamanho do vetor
    int maxrecursao = 2*((int)log2((double)(r-l+1))); 
    intro (v , l , r , maxrecursao ) ; 
    insertion_sort (v , l , r ) ;
}

