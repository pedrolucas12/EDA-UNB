#### BUSCA BINÁRIA
    -Paradigma: Dividir para conquistar
    -Procura o elemento na esquerda : elemento < meio
    -Procura o elemento na direita : elemento > meio
    -Repetir até encontrar o elemento ou até que o início seja maior que o fim
    -Complexidade: O(log n)
    -Motivo da complexidade : A cada iteração o tamanho do vetor é dividido por 2 

#### ARVORE BINÁRIA DE BUSCA
    -Combina flexibilidade de insercao nas litas encadeadas com a eficiencia de busca dos vetores
    -Todo no interno tem 2 ponteiros: esquerda e direita
    -No folha aponta para NULL
    -Chaves : elementos que estao armazenados nos nos
    -Chave de um no e maior que todas as chaves da subarvore esquerda
    -Chave de um no e menor que todas as chaves da subarvore direita
    -Caso o item procurado seja menor que a raiz, procure na sub-árvore esquerda
    -Caso contrário, procure na sub-árvore direita
    -Remover um nó
        -Se o nó não tiver filhos, basta removê-lo
        -Se o nó tiver apenas um filho, basta substituí-lo pelo seu filho
        -Se o nó tiver dois filhos, substitua-o pelo seu antecessor (ou sucessor) e remova o antecessor (ou sucessor)
    -Altura da arvore = lg n
    -Complexidade
        Melhor caso: lg N 
        Pior caso: N
        Caso médio: 2 lg N - arvores nao balanceadas
    -Motivo da complexidade: A cada iteração o tamanho do vetor é dividido por 2, e no pior caso o vetor é percorrido inteiro