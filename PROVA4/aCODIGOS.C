//QUESTOES CHAVES 

//Imprima os 100 menores números de um conjunto de 10^6 de números.
    #define less(A,B) (vetor[A]>vetor[B])
    int main(void){
        PQinit(101);
        for(int i = 0; i<100; i++){ //insere os 100 primeiros elementos
            int k;
            scanf("%d", &x);
            PQinsert(x);
        }
        while(scanf("%d",&x) == 1){ //enquanto tiver elementos
            PQinsert(x);
            PQdelmax();
        }
    }
    int PQespiamin(){ //retorna o menor elemento
        return vetor[pq[1]];
    }
    void PQinit(int maxN){ //inicializa a heap
        pq = malloc((maxN+1)*sizeof(int));
        N = 0;
    }
    void PQinsert(int v){ //insere um elemento na heap
        pq[++N] = v;
        fixUp(pq, N);
    }
    int PQdelmin(){ //remove o menor elemento
        exch(pq[1], pq[N]);
        fixDown(pq, 1, N-1);
        return pq[N--];
    }
    int PQdelmax(){ //remove o maior elemento
        exch(pq[1], pq[N]);
        fixDown(pq, 1, N-1);
        return pq[N--];
    }
    void PQchange(int k, int valor){ //troca o valor de uma chave
        v[k] = valor;
        if(v[k] < valor){ //se o valor for menor que o anterior
            fixUp(k);
        }
        else{
            fixDown(k, N);
        }
    }
/*

/*
Resolva o problem da contagem para o fluxo de chaves  17 21 19 4 26 30 37  usando hashing com sondagem linear.  A tabela de dispersão deve ter tamanho 13 e a função de espalhamento deve ser o resto da divisão da chave por 13.  Faça uma figura do estado final da tabela de dispersão.
*/
    void hash(int *v, int n){
        int i, j, h;
        int hash[13];
        for(i = 0; i < 13; i++){
            hash[i] = -1;
        }
        for(i = 0; i < n; i++){
            h = v[i]%13;
            if(hash[h] == -1){
                hash[h] = v[i];
            }
            else{
                j = h;
                while(hash[j] != -1){
                    j++;
                    if(j == 13){
                        j = 0;
                    }
                }
                hash[j] = v[i];
            }
        }
    }

    /*
    Insira os itens  E A S Y Q U E S T I O N, nessa ordem, em um heap decrescente inicialmente vazio. Mostre o heap que resulta.
    */
    void insert(int *v, int n){
        int i, j, aux;
        for(i = 1; i < n; i++){
            j = i;
            while(j > 0 && v[j] > v[(j-1)/2]){
                aux = v[j];
                v[j] = v[(j-1)/2];
                v[(j-1)/2] = aux;
                j = (j-1)/2;
            }
        }
    }

    /*
    Encontre o mínimo. Acrescente um método min() à classe MaxPQ. Sua implementação deve usar tempo constante e uma quantidade constante de espaço adicional.
    */
    void min(int *v, int n){
        int i, min;
        min = v[0];
        for(i = 1; i < n; i++){
            if(v[i] < min){
                min = v[i];
            }
        }
        return min;
    }

//Escreva uma versão recursiva do algoritmo de ordenação por inserção
void insertionSort(int *v, int n){
    if(n<=1) return;
    insertionSort(v, n-1);
    int x = v[n-1];
    int j = n-2;
    while(j>=0 && v[j]>x){
        v[j+1] = v[j];
        j--;
    }
    v[j+1] = x;
}


//Escreva uma função recursiva que receba um vetor de inteiros e ordene-o usando o algoritmo de ordenação por intercalação (merge sort). 
merge_sort(v, 0, 5) 
meio = (5+0)/2 = 2
merge_sort(v, 0, meio=2): esquerda
    m = (2+0)/2 = 1
    merge_sort(v, 0, 1) : esquerda
        m = (1+0)/2 = 0
        merge_sort(v, 0, 0) : esquerda
        merge_sort(v, 1, 1) : direita
        merge(v, 0, 0, 1)
        65312 4:56
        merge_sort(v, 2, 2): direita
        merge(v, 0, 1, 2) 56312 4:3
        563124:35
        563124:356

/*
Toda operacao que fazemos enquanto programamos deve ser bem pensada e quando estamos trabalhando com listas encadeadas nao e diferente.
Uma discuss˜ao comum e se devemos guardar os elementos em uma lista encadeada ordenados por algum criterio.
Existem casos em que nao e necessario (ou vantajoso) armazenar os elementos da lista ordenados?
*/
    Existem casos em que não é necessário ou vantajoso armazenar os elementos de uma lista encadeada ordenados. 
Isso pode ocorrer quando a ordem dos elementos não é relevante para a aplicação em questão, ou quando a lista é frequentemente 
modificada e a ordenação seria um processo custoso em termos de desempenho. Além disso, em alguns casos, 
a ordenação pode ser realizada apenas quando necessário, evitando a sobrecarga de manter a lista sempre ordenada.

- Não dá para fazer um algoritmo baseado em comparações melhor do que O(n lg n) 

- Algoritmos estáveis: • InsertionSort, BubbleSort e MergeSort

- Algoritmos não-estáveis: • SelectionSort, Quicksort e Heapsort

-COUNTING SORT : Contamos o número de ocorrências de cada número e Colocamos os números na posição correta 

void countingsort(int *v, int l, int r) {
int i, count[R+1];
for (i = 0; i <= R; i++)
 count[i] = 0;
 for (i = l; i <= r; i++)
    count[v[i] + 1]++;
 for (i = 1; i <= R; i++)
    count[i] += count[i-1];
 for (i = l; i <= r; i++) {
    aux[count[v[i]]] = v[i];
    count[v[i]]++;
 }
 for (i = l; i <= r; i++)
    v[i] = aux[i-l];
 }

 void radixsort(int *v, int l, int r) {
    //Tempo: O(bytesword · (R + n))
    int i, w, count[R+1];
    for (w = 0; w < bytesword; w++) {
        for (i = 0; i <= R; i++)
            count[i] = 0;
        for (i = l; i <= r; i++)
            count[digit(v[i], w) + 1]++;
        for (i = 1; i <= R; i++)
            count[i] += count[i-1];
        for (i = l; i <= r; i++) {
            aux[count[digit(v[i], w)]] = v[i];
            count[digit(v[i], w)]++;
        }
        for (i = l; i <= r; i++)
            v[i] = aux[i-l];
    }}

- BubbleSort : Melhor Caso: O(n) Pior Caso: O(n^2) Caso Medio: O(n^2) 

- SelectionSort : Melhor Caso: O(n^2) Pior Caso: O(n^2) Caso Medio: O(n^2)

- InsertionSort : Melhor Caso: O(n) Pior Caso: O(n^2) Caso Medio: O(n^2)

- Quicksort : Melhor Caso: O(n lg n) Pior Caso: O(n^2) Caso Medio: O(n lg n)

- MergeSort : Melhor Caso: O(n lg n) Pior Caso: O(n lg n) Caso Medio: O(n lg n)

- Heapsort : Melhor Caso: O(n lg n) Pior Caso: O(n lg n) Caso Medio: O(n lg n)

- CountingSort : Melhor Caso: O(n) Pior Caso: O(n) Caso Medio: O(n)

- RadixSort : Melhor Caso: O(n) Pior Caso: O(n) Caso Medio: O(n)

//Escreva uma versão recursiva do algoritmo de ordenação por inserção
void insertionSort(int *v, int n){
    if(n<=1) return;
    insertionSort(v, n-1);
    int x = v[n-1];
    int j = n-2;
    while(j>=0 && v[j]>x){
        v[j+1] = v[j];
        j--;
    }
    v[j+1] = x;
}

//Escreva uma versão recursiva do algoritmo de ordenação por seleção
void selectionSort(int *v, int n){
    if(n<=1) return;
    int max = 0;
    for(int i=1; i<n; i++){
        if(v[i]>v[max]) max = i;
    }
    troca(&v[n-1], &v[max]);
    selectionSort(v, n-1);
}
void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

//Escreva uma versão recursiva do algoritmo de ordenação por bolha
void bubbleSort(int *v, int n){
    if(n<=1) return;
    for(int i=0; i<n-1; i++){
        if(v[i]>v[i+1]) troca(&v[i], &v[i+1]);
    }
    bubbleSort(v, n-1);
}
void  troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}


//Escreva uma função que conte o número de células de uma lista encadeada. Faça duas versões: uma iterativa e uma recursiva.
void contaCelulas ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return 0 ;
    }
    No * aux = lista -> inicio ;
    int cont = 0 ;
    while ( aux != NULL ) {
        cont ++ ;
        aux = aux -> prox ;
    }
    return cont ;
}
int contaCelulasRecursiva ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return 0 ;
    }
    return 1 + contaCelulasRecursiva ( lista -> inicio -> prox ) ;
}


//Altura.  A altura de uma célula c em uma lista encadeada é a distância entre c e o fim da lista. Escreva uma função que calcule a altura de uma dada célula.
void alturaLista ( ListaEncadeada * lista , int valor ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    int cont = 0 ;
    while ( aux != NULL && aux -> info != valor ) {
        cont ++ ;
        aux = aux -> prox ;
    }
    if ( aux == NULL ) {
        return ;
    }
    int altura = contaCelulas ( aux ) ;
    return altura ;
}


//Profundidade.  A profundidade de uma célula c em uma lista encadeada é o número de passos do único caminho que vai da primeira célula da lista até c. 
// Escreva uma função que calcule a profundidade de uma dada célula.
void profundidadeLista ( ListaEncadeada * lista , int valor ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    int cont = 0 ;
    while ( aux != NULL && aux -> info != valor ) {
        cont ++ ;
        aux = aux -> prox ;
    }
    if ( aux == NULL ) {
        return ;
    }
    return cont ;
}


//Escreva uma função que verifique se uma lista encadeada que contém números inteiros está em ordem crescente.
void verificaCrescente ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    while ( aux -> prox != NULL ) {
        if ( aux -> info > aux -> prox -> info ) {
            return 0 ;
        }
        aux = aux -> prox ;
    }
    return 1 ;
}


//Escreva uma função que faça uma busca em uma lista encadeada crescente. Faça versões recursiva e iterativa.
void buscaCrescente ( ListaEncadeada * lista , int valor ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    while ( aux != NULL && aux -> info != valor ) {
        aux = aux -> prox ;
    }
    if ( aux == NULL ) {
        return 0 ;
    }
    return 1 ;
}
void buscaCrescenteRecursiva ( ListaEncadeada * lista , int valor ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    if ( lista -> inicio -> info == valor ) {
        return 1 ;
    }
    return buscaCrescenteRecursiva ( lista -> inicio -> prox , valor ) ;
}


//Escreva uma função que encontre uma célula com conteúdo mínimo. Faça duas versões: uma iterativa e uma recursiva.
void minimoLista ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    int min = aux -> info ;
    while ( aux != NULL ) {
        if ( aux -> info < min ) {
            min = aux -> info ;
        }
        aux = aux -> prox ;
    }
    return min ;
}
void minimoListaRecursiva ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    if ( lista -> inicio -> prox == NULL ) {
        return lista -> inicio -> info ;
    }
    int min = minimoListaRecursiva ( lista -> inicio -> prox ) ;
    if ( lista -> inicio -> info < min ) {
        return lista -> inicio -> info ;
    }
    return min ;
}


//Escreva uma função que verifique se duas listas encadeadas são iguais, ou melhor, se têm o mesmo conteúdo. Faça duas versões: uma iterativa e uma recursiva
void verificaIgual ( ListaEncadeada * lista1 , ListaEncadeada * lista2 ) {
    if ( listaVazia ( lista1 ) || listaVazia ( lista2 ) ) {
        return ;
    }
    No * aux1 = lista1 -> inicio ;
    No * aux2 = lista2 -> inicio ;
    while ( aux1 != NULL && aux2 != NULL ) {
        if ( aux1 -> info != aux2 -> info ) {
            return 0 ;
        }
        aux1 = aux1 -> prox ;
        aux2 = aux2 -> prox ;
    }
    if ( aux1 != NULL || aux2 != NULL ) {
        return 0 ;
    }
    return 1 ;
}
void verificaIgualRecursiva ( ListaEncadeada * lista1 , ListaEncadeada * lista2 ) {
    if ( listaVazia ( lista1 ) || listaVazia ( lista2 ) ) {
        return ;
    }
    if ( lista1 -> inicio -> info != lista2 -> inicio -> info ) {
        return 0 ;
    }
    return verificaIgualRecursiva ( lista1 -> inicio -> prox , lista2 -> inicio -> prox ) ;
}


//Escreva uma função que faça uma cópia de uma lista encadeada. Faça duas versões da função: uma iterativa e uma recursiva.
void copiaLista ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    ListaEncadeada * copia = ( ListaEncadeada * ) malloc ( sizeof ( ListaEncadeada ) ) ;
    No * aux = lista -> inicio ;
    while ( aux != NULL ) {
        novoElemento ( copia , aux -> info ) ;
        aux = aux -> prox ;
    }
    return copia ;
}
void copiaListaRecursiva ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    ListaEncadeada * copia = ( ListaEncadeada * ) malloc ( sizeof ( ListaEncadeada ) ) ;
    copia -> inicio = NULL ;
    copiaListaRecursivaAux ( lista -> inicio , copia ) ;
    return copia ;
}


//Escreva uma função que concatene duas listas encadeadas (isto é, engate a segunda no fim da primeira). Faça duas versões: uma iterativa e uma recursiva.
void juntaLista ( ListaEncadeada * lista1 , ListaEncadeada * lista2 ) {
    if ( listaVazia ( lista1 ) || listaVazia ( lista2 ) ) {
        return ;
    }
    No * aux = lista1 -> inicio ;
    while ( aux -> prox != NULL ) {
        aux = aux -> prox ;
    }
    aux -> prox = lista2 -> inicio ;
    return lista1 ;
}
void juntaListaRecursiva ( ListaEncadeada * lista1 , ListaEncadeada * lista2 ) {
    if ( listaVazia ( lista1 ) || listaVazia ( lista2 ) ) {
        return ;
    }
    if ( lista1 -> inicio -> prox == NULL ) {
        lista1 -> inicio -> prox = lista2 -> inicio ;
        return lista1 ;
    }
    return juntaListaRecursiva ( lista1 -> inicio -> prox , lista2 ) ;
}



//Escreva uma função que troque de posição duas células de uma mesma lista encadeada.
void trocaPosicao ( ListaEncadeada * lista , int valor1 , int valor2 ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux1 = lista -> inicio ;
    No * aux2 = lista -> inicio ;
    while ( aux1 != NULL && aux1 -> info != valor1 ) {
        aux1 = aux1 -> prox ;
    }
    while ( aux2 != NULL && aux2 -> info != valor2 ) {
        aux2 = aux2 -> prox ;
    }
    if ( aux1 == NULL || aux2 == NULL ) {
        return ;
    }
    int aux = aux1 -> info ;
    aux1 -> info = aux2 -> info ;
    aux2 -> info = aux ;
}



//Escreva uma função que inverta a ordem das células de uma lista encadeada. Faça isso sem usar espaço auxiliar, apenas alterando ponteiros. Dê duas soluções: uma iterativa e uma recursiva.
void inverteOrdem ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    No * ant = NULL ;
    No * prox = NULL ;
    while ( aux != NULL ) {
        prox = aux -> prox ;
        aux -> prox = ant ;
        ant = aux ;
        aux = prox ;
    }
    lista -> inicio = ant ;
}
void inverteOrdemRecursiva ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    No * ant = NULL ;
    No * prox = NULL ;
    inverteOrdemRecursivaAux ( aux , ant , prox ) ;
    lista -> inicio = ant ;
}

//Escreva uma função que devolva o comprimento (ou seja, o número de elementos) da fila.
void comprimentoFila ( FilaDinamica * fila ) {
    if ( filaDinamicaVazia ( fila ) ) {
        return 0 ;
    }
    int cont = 0 ;
    No * aux = fila -> inicio ;
    while ( aux != NULL ) { 
        cont ++ ;
        aux = aux -> prox ;
    }
    return cont ;
}

//Faça uma versão da função distancias que devolva a distância de uma cidade a a outra b.
void distanciaFila ( FilaDinamica * fila , int a , int b ) {
    if ( filaDinamicaVazia ( fila ) ) {
        return 0 ;
    }
    int cont = 0 ;
    No * aux = fila -> inicio ;
    while ( aux != NULL && aux -> info != a ) { 
        cont ++ ;
        aux = aux -> prox ;
    }
    if ( aux == NULL ) {
        return ;
    }
    int dist = 0 ;
    while ( aux != NULL && aux -> info != b ) {
        dist ++ ;
        aux = aux -> prox ;
    }
    if ( aux == NULL ) {
        return ;
    }
    return dist ;
}

//Implemente uma fila em uma lista encadeada circular sem célula-cabeça.
void circularSemCabeca ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    while ( aux -> prox != lista -> inicio ) {
        printf ( "%d\n" , aux -> info ) ;
        aux = aux -> prox ;
    }
    printf ( "%d\n" , aux -> info ) ;
}


//Implemente uma fila em uma lista encadeada não circular com célula-cabeça
void naoCircularComCabeca ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio -> prox ;
    while ( aux != NULL ) {
        printf ( "%d\n" , aux -> info ) ;
        aux = aux -> prox ;
    }
}



//Implemente uma fila em uma lista encadeada não circular sem célula-cabeça.
void naoCircularSemCabeca ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    while ( aux != NULL ) {
        printf ( "%d\n" , aux -> info ) ;
        aux = aux -> prox ;
    }
}



//Implemente uma fila em uma lista duplamente encadeada sem célula-cabeça. Use um ponteiro p para a primeira célula e um ponteiro u para a última.
void duplaSemCabeca ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    while ( aux != NULL ) {
        printf ( "%d\n" , aux -> info ) ;
        aux = aux -> prox ;
    }
}

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

//COUTING SORT
/*
Ordenar contando as chaves em um vetor auxiliar:
    ▶ Cada índice é uma chave: limita quantidade de chaves
    ▶ Determina a posição da uma chave, contando quantas chaves menores existem
    ▶ Histograma dos números: distribuição das frequências
    ▶ Cada chave é reposicionada na posição definitiva
*/

/*
v [2 3 3 4 1 3 4 3 1 2 2 1 2 4 3 4 4 2 3 4]
    ▶ Frequências:
        ⋆ 0: 0 vezes
        ⋆ 1: 3 vezes
        ⋆ 2: 5 vezes
        ⋆ 3: 6 vezes
        ⋆ 4: 6 vezes
    ▶ Ordenando:
        ⋆ zero 0's, três 1's, cinco 2's, seis 3's, seis 4's
v [1 1 1 2 2 2 2 2 3 3 3 3 3 3 4 4 4 4 4 4]
*/

/*
Etapa 1: contar as frequências
    ▶ Para o intervalo de chaves: 0 até R − 1
    ▶ Utiliza-se: count[R+1]
    ▶ Cada chave i em 0 até R − 1 = count[i]
    ▶ Cada count[i] = frequência da chave i − 1 (imediatamente < i)
*/

// memset (count , 0 , sizeof ( int )*(R +1) )
for (i =0; i <= R; i ++){
    count [i] = 0;
}
for (i= l; i <= r; i ++){
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

for (i =1; i <= R; i ++){
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

for ( i = l; i <= r; i ++) {
    aux[count[v[i]]] = v[i];
    count[v[i]]++;
}



/*
Radix:
    ▶ ordenar pela a raiz(radix) da representação dos dados
    ▶ extraindo o i-ésimo digito da chave
Obs.: caso a chave seja pequena não compensa a extração dos bits: use o
counting sort
*/


// LSD

/*
A partir dígito menos significativo (least significant digit - LSD): direita para
esquerda
    ▶ Ordena estavelmente chaves de comprimento fixo
        ⋆ Tamanho da palavra (word) que representa o dado
        ⋆ int: 4 * 8 bits = 32 bits = 4 bytes
        ⋆ strings de tamanho W
Complexidade ≈ 7 ∗ W ∗ N + 3 ∗ W ∗ R acessos:
    ▶ N chaves
    ▶ chaves de tamanho W
    ▶ cujo alfabeto são de tamanho R
R, em geral, é muito menor que N, portanto a complexidade é proporcional a
W ∗ N
*/


void radix_sortLSD (int *v , int l , int r) {
int i , w;
int aux [r-l +1] , count [R +1];

    //w -> deslocamento de bytes
    for (w =0; w < bytesword ; w ++) {
        // for (i =0; i <=R; i++) count [i] = 0;
        memset ( count , 0, sizeof (int) *( R +1) );

        // frequencias
        for (i= l; i <= r; i ++) {
            count [ digit (v[ i], w ) +1 ]++;
        }

        // posições
        for (i =1; i <= R; i ++) {
            count [i] += count [i- 1];
        }

        // distruibuição
        for (i= l; i <= r; i ++) {
            aux [ count [ digit (v[i ], w ) ] ] = v[i ];
            count [ digit (v[i ], w ) ]++;
        }

        // copiando : a partir de aux [0]
        for (i= l; i <= r; i ++) {
            v[i] = aux [i-l];
        }
    }
}


//MSD

/*
A partir dígito mais signigicativo (most significant digit - MSD): esquerda
para direita
    ▶ Ordenação de propósito geral: chaves com tamanhos variáveis
        ⋆ Conjunto de várias palavras
        ⋆ string: N * 8 bits = N * 1 byte, N variável
    ▶ Usa-se primeiro o counting sort (key-indexed counting)
    ▶ Depois, recursivamente, ordena-se os sub-vetores de cada caractere
Complexidade ≈ 7 ∗ W ∗ N + 3 ∗ W ∗ R acessos:
*/

typedef char Item ;
# define maxstring 101
# define bitsbyte 8
# define R (1 << bitsbyte ) // 00000001 < <8 = 2^8 = 256

int charAt ( char s [] , int d) {
    if (d < strlen ( s))
        return s [d ]; //d-é simo caractere
    else
        return - 1; // count [-1 + 1] = count [0]
    // count [0] = qtde . de palavras menores que d
}

// Strings : ordena para o d-é simo caractere
void radixMSD ( char a [][ maxstring ] , int l , int r , int d) {
    if(r <= l ) return ;

    char aux [r-l +1][ maxstring ];

    int count [R +1];
    memset ( count , 0, sizeof (int) *( R +1) );
    // for ( int i =0; i <=R; i++) count [i] = 0;
    // frequencia dos d-é simos caracteres
    for ( int i = l ; i <= r ; i ++)
        count [ charAt (a[i ], d) + 1]++;

    // tabela de í ndices : calculando as posi ções
    for ( int i = 1; i <= R; i ++)
        count [i] += count [i- 1];

    // redistribui as chaves : ordena em aux
    for ( int i = l ; i <= r ; i ++)
        strcpy ( aux [ count [ charAt (a [i], d) ]++] , a [i ]) ;

    // copia para o original
    for ( int i = l ; i <= r ; i ++)
        strcpy (a [i], aux [i - l ]) ;

    // ordenar por subconjunto : count [0] = já ordenadas
    for ( int i = 1; i <= R ; i ++) {
        // count [i-1] posi ção da primeira chave com o caractere i
        // count [i]-1 posi ção da ú ltima chave com o caractere i
        radixMSD (a , l + count [i- 1] , l + count [ i]-1, d +1) ;
    }
}
// Inteiros : ordena o w-é simo byte
void radix_sortMSD (int *v , int l , int r , int w) {
    if(r <= l || w < 0) return ;
    int i , aux [r-l +1] , count [ R +1];
    memset ( count , 0, sizeof (int) *( R +1) );

    for (i= l; i <= r; i ++)
        count [ digit (v[i], w) +1]++;

    for (i =1; i <= R; i ++)
        count [ i] += count [i- 1];

    for (i= l; i <= r; i ++)
        aux [ count [ digit (v [i], w) ]++] = v[i ];

    for (i= l; i <= r; i ++) 
        v[i] = aux [i-l ];

    // ordenando os que come çam por zero
    radix_sortMSD (v , l , l + count [0] -1, w- 1) ;
    for ( i = 1; i <= R; i ++)
        radix_sortMSD (v , l + count [i- 1] , l + count [i ]-1, w- 1) ;
}

// EXERCICIO DO TORNEIO
p_no torneio(int *v, int l, int r) {
	p_no esq, dir;
	int valor, m = (l + r) / 2;
	if (l == r)
		return criar_arvore(v[l], NULL, NULL);
	esq = torneio(v, l, m);
	dir = torneio(v, m+1, r);
	valor = esq->dado > dir->dado ? esq->dado : dir->dado;
	return criar_arvore(valor, esq, dir);
}

//Percursos em profundidade
//PRE ORDEM
void pre_ordem(p_no raiz) {
	if (raiz != NULL) {
		printf("%d ", raiz->dado); /* visita raiz */
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}
}

void pre_ordem(p_no raiz) {
	p_pilha p; /* pilha de p_no */
	p = criar_pilha();
	empilhar(p, raiz);
	while(!pilha_vazia(p)) {
		raiz = desempilhar(p);
		if (raiz != NULL) {
			empilhar(p, raiz->dir);
			empilhar(p, raiz->esq);
			printf("%d ", raiz->dado); /* visita raiz */
		}
	}
	destruir_pilha(p);
}

//POS ORDEM
void pos_ordem(p_no raiz) {
	if (raiz != NULL) {
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);
		printf("%d ", raiz->dado); /* visita raiz */
	}
}

//INORDEM
void inordem(p_no raiz) {
	if (raiz != NULL) {
		inordem(raiz->esq);
		printf("%d ", raiz->dado); /* visita raiz */
		inordem(raiz->dir);
	}
}

// PERCURSO EM LARGURA
void percurso_em_largura(p_no raiz) {
	p_fila f;
	f = criar_fila();
	enfileirar(f, raiz);
	while(!fila_vazia(f)) {
		raiz = desenfileirar(f);
		if (raiz != NULL) {
			enfileirar(f, raiz->esq);
			enfileirar(f, raiz->dir);
			printf("%d ", raiz->dado); /* visita raiz */
		}
	}
	destruir_fila(f);
}

/* EXERCÍCIOS */

//////////////////////////////////////////
// verifica se duas arvores são iguais //
////////////////////////////////////////

int sao_iguais(p_no raiz1, p_no raiz2) {
    // Se ambas as árvores são nulas, elas são iguais.
    if (raiz1 == NULL && raiz2 == NULL) {
        return 1;
    }

    // Se uma árvore é nula e a outra não, elas não são iguais.
    if (raiz1 == NULL || raiz2 == NULL) {
        return 0;
    }

    // Verifique se os valores dos nós correspondentes são iguais.
    if (raiz1->dado != raiz2->dado) {
        return 0;
    }

    // Recursivamente verifique as subárvores esquerdas e direitas.
    int esq_iguais = sao_iguais(raiz1->esq, raiz2->esq);
    int dir_iguais = sao_iguais(raiz1->dir, raiz2->dir);

    // As árvores são iguais apenas se ambas as subárvores esquerdas e direitas forem iguais.
    return esq_iguais && dir_iguais;
}

////////////////////////////////////////////
// APAGAR TODAS AS FOLHAS COM UM VALOR X //
//////////////////////////////////////////

p_no apagar_folhas_com_valor(p_no raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    // Verifique se o nó atual é uma folha com o valor dado.
    if (raiz->esq == NULL && raiz->dir == NULL && raiz->dado == valor) {
        free(raiz); // Libera a memória do nó.
        return NULL;
    }

    // Recursivamente processe as subárvores esquerda e direita.
    raiz->esq = apagar_folhas_com_valor(raiz->esq, valor);
    raiz->dir = apagar_folhas_com_valor(raiz->dir, valor);

    return raiz;
}

///////////////////////////////////////////////////////////////////////////
// Escreva uma função que calcula o número de folhas em uma árvore dada //
/////////////////////////////////////////////////////////////////////////

int numero_de_folhas(p_no raiz) {
    if (raiz == NULL) {
        return 0;
    }
    
    // Se o nó atual é uma folha (sem filhos), retorne 1.
    if (raiz->esq == NULL && raiz->dir == NULL) {
        return 1;
    }
    
    // Caso contrário, conte as folhas nas subárvores esquerda e direita e some-as.
    int folhas_esq = numero_de_folhas(raiz->esq);
    int folhas_dir = numero_de_folhas(raiz->dir);
    
    return folhas_esq + folhas_dir;
}


