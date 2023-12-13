//Criar fila de prioridade
void PQinit (int maxN ) {
    pq = malloc ( sizeof ( Item ) *( maxN +1) ) ;
    N = 0;
}

//Ve se a fila esta vazia
 int PQempty () {
    return N ==0;
 }

//Insere um item na fila de prioridade
void fixUp (int k )
{
    while (k >1 && less ( pq [ k /2] , pq [ k ]) )
    {
    exch ( pq [ k ] , pq [ k /2]) ;
    k = k /2; // verifique o avô
    }
}
    void PQinsert ( Item v ) {
    pq [++ N ] = v ;
    fixUp ( N ) ;
 }

//Remove o maior item da fila de prioridade
void fixDown (int k , int N ) {
    int j ;
    // 2*k até N - dobrando a cada iteração
    // altura da árvore ~ log k
    while (2* k <= N ) { //~ log k
        j = 2* k ;
        if(j < N && less ( pq [ j ] , pq [ j +1]) ) j ++; //1
        if (! less ( pq [ k ] , pq [ j ]) ) break ; //1
        exch ( pq [ k ] , pq [ j ]) ;
        k = j ;
    }
 }
 Item PQdelmax () {
    exch ( pq [1] , pq [ N ]) ; // troque topo -> ultimo
    fixDown (1 , N - 1) ; // reposiocione
    return pq [ N - - ];
 }

 //Alterar a prioridade da lista de prioridade
 void PQchange (int k , int valor )
    {
        if ( v [ k ] < valor ) {
        v [ k ] = valor ;
        fixUp ( k ) ;
    } else {
        v [ k ] = valor ;
        fixDown (k , N ) ;
    }}

//Ordenar um vetor usando a fila de prioridade
void PQsort ( Item *v , int l , int r ) {
    PQinit ( r - l +1) ;
    for(int k = l ; k <= r ; k ++)
    {
        PQinsert ( v [ k ]) ;
    }
    for(int k = r ; k >= l ; k - - )
    {
        v [ k ] = PQdelmax () ;
 }}

//Extrair o maior item da fila de prioridade
 Item extrai_maximo(p_fp fprio) {
    int j, max = 0;
    for (j = 1; j < fprio->n; j++)
        if (fprio->v[max].chave < fprio->v[j].chave)
            max = j;
        troca(&(fprio->v[max]), &(fprio->v[fprio->n-1]));
        fprio->n--;
    return fprio->v[fprio->n];
}

 // HeapSort
 void heap_sort ( Item *v , int l , int r ) {
    pq = v + l - 1; 
    N = r - l +1;
    for(int k = N /2; k >=1; k - - )
    {
        fixDown (k , N ) ;
    }
    while (N >1)
    {
        exch ( pq [1] , pq [ N ]) ;
        fixDown (1 , - - N ) ;
    }
 }


//INTRO SORT
void intro_sort (int *v , int l , int r )
    {
        int maxdepth = 2*(( int) log2 (( double ) ( r - l +1) ) )     // duas vezes a altura da á rvore
        intro (v , l , r , maxdepth ) ;
        insertion_sort (v , l , r ) ;
    }
 void intro (int *v , int l , int r , int maxdepth ) {
    if( r -l <=15) {// insertion_sort (v, l, r);
        return ;
    } else if( maxdepth == 0) {// merge_sort (v, l, r);
        heap_sort (v , l , r ) ;
    } else {
        compexch ( v [ l ] , v [( l + r ) /2]) ;
        compexch ( v [ l ] , v [ r ]) ;
        compexch ( v [ r ] , v [( l + r ) /2]) ;
        int p = partition (v , l , r ) ;
        intro (v , l , p - 1 , maxdepth - 1) ;
        intro (v , p +1 , r , maxdepth - 1) ;
    }}

    //Desce_no_heap iterativo
    void fixDown (int k , int N ) {
        int j ;
        // 2*k até N - dobrando a cada iteração
        // altura da árvore ~ log k
        while (2* k <= N ) { //~ log k
            j = 2* k ;
            if(j < N && less ( pq [ j ] , pq [ j +1]) ) j ++; //1
            if (! less ( pq [ k ] , pq [ j ]) ) break ; //1
            exch ( pq [ k ] , pq [ j ]) ;
            k = j ;
        }
     }

     //Sobe_no_heap iterativo
        void fixUp (int k )
        {
            while (k >1 && less ( pq [ k /2] , pq [ k ]) )
            {
            exch ( pq [ k ] , pq [ k /2]) ;
            k = k /2; // verifique o avô
            }
        }
