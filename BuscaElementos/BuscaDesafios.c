//Escreva uma implementação de busca binária que procure x num vetor decrescente v[0..n-1].
void buscaBinariaDecrescente ( int * vetor , int n , int x ) {
    int inicio = 0 ;
    int fim = n - 1 ;
    int meio ;
    while ( inicio <= fim ) {
        meio = ( inicio + fim ) / 2 ;
        if ( vetor [ meio ] == x ) {
            return meio ;
        }
        if ( vetor [ meio ] < x ) {
            fim = meio - 1 ;
        } else {
            inicio = meio + 1 ;
        }
    }
    return -1 ;
}