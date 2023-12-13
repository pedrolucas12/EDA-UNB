//COUNTING SORT
void countingsort ( int *v , int l , int r) {
int i , count [R +1];
    for (i = 0; i <= R; i ++) count [i] = 0; // inicializa o vetor de contagem
    for (i = l; i <= r; i ++) count [v[i ] + 1]++; // conta as ocorrencias
    for (i = 1; i <= R; i ++) count [i] += count [ i- 1]; // acumula as ocorrencias
    for (i = l; i <= r; i ++) { // distribui os elementos
        aux [ count [v[ i ]]] = v[ i ]; // coloca o elemento na posicao correta
        count [ v[i ]]++;} // atualiza o proximo indice
    for (i = l; i <= r; i ++) v [i] = aux [ i-l ]; // copia de volta para o vetor original
 }

 