// Merge sort 
void merge_sort(int *v, int l, int r)
{
    if (l >= r)
        return;
    int m = (r + l) / 2;
    merge_sort(v, l, m);
    merge_sort(v, m + 1, r);
    merge(v, l, m, r);
}

//Merge
void merge(int *v, int l, int m, int r) {
    int tam = r + 1 - l;
    int *aux = malloc(sizeof(int) * tam); // alocar espaço auxiliar
    int i = l; // inicio do sub-vetor esquerdo
    int j = m + 1; // inicio do sub-vetor direito
    int k = 0; // inicio do vetor auxiliar
    while (i <= m && j <= r) { // percorrer os sub-vetores
        if (v[i] <= v[j]) // testar sub-vetores
            aux[k++] = v[i++]; // ordenar no vetor auxiliar
        else
            aux[k++] = v[j++]; // ordenar no vetor auxiliar
    }
    while (i <= m ) aux [ k ++] = v [ i ++]; // ainda tem elementos no sub - vetor direito ?
    while (j <= r ) aux [ k ++] = v [ j ++];
    k =0; // indice do aux
    for( i = l ; i <= r ; i ++) // indice do v
    v [ i ] = aux [ k ++]; // copiar o aux[k] para v[i] // liberar memória
    free ( aux ) ;
 }

 //MergeSort Bottom Up
 void mergeBU_sort (int *v , int l , int r )
{
    int tam = (r - l +1) ;
    for (int sz =1; sz < tam ; sz =2* sz )
    {
        for (int lo = l ; lo < tam - sz ; lo +=2* sz )
        {
            int hi = lo +2* sz -1;
            if( hi > tam -1) hi = tam -1;
            merge (v , lo , lo + sz -1 , hi ) ;
 }}}
