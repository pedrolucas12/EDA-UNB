#### FILA DE PRIORIDADE
    - Uma fila de prioridade é uma estrutura de dados que mantém uma coleção de elementos, cada um com uma prioridade associada.
    - A fila pode ser com prioridade máxima(chave maior = maior prioridade) ou mínima(chave menor = maior prioridade)
    - Heap
        - Arvore binaria completa : todos os niveis sao completos, exceto o ultimo, que é preenchido da esquerda para a direita
        - Raiz é a chave de maior prioridade
        - Pai sempre tem prioridade maior que os filhos
        - Altura da arvore é log(N)
        - Inserção: O(log N)
            - Insere no final da arvore
            - Se a chave for maior que a do pai, troca com o pai ( restauracao - (fixUp))
            - Repete até que a chave seja menor que a do pai
            - F(k) = log(k) + 1
        - Remoção:
            - Troca a raiz com o elemento de menor prioridade
            - Remove o ultimo elemento
            - Se a chave for menor que a do filho, troca com o filho ( restauracao - (fixDown))
            - Repete até que a chave seja maior que a do filho
            - F(k) = 2 * log(k)
        - Alterar prioridade:
            - Troca a prioridade do elemento
            - Se a chave for maior que a do pai, troca com o pai ( restauracao - (fixUp))
            - Se a chave for menor que a do filho, troca com o filho ( restauracao - (fixDown))
            - F(k) = log(k) + 1
        - Extrai maximo : O(lgN)
        - Max-Heap 
            - Pai sempre tem prioridade maior que os filhos
            - Raiz é a chave de maior prioridade
           

#### HEAP SORT
    - Construir e destroir uma fila de prioridade
    - Fases:
        - Construção sem usar as funcoes:
            - Insere todos os elementos na fila de prioridade
            - Remove todos os elementos da fila de prioridade
            - Varedura da esquerda para a direita e de baixo para cima
            - fixUp para posicionar os elementos
            - Custo = 2 * N * log(N)
        - Ordenação sem usar as funcoes:
            - Reorganiza os elementos da fila de prioridade
            - Remove todos os elementos da fila de prioridade
        -Construcao da heap:
            - Varedura da direita para a esquerda e de baixo para cima
            - fixDown para posicionar os elementos
            - Custo = 2 * N
            - for(int k = N /2; k >=1; k - - ) {
                fixDown (k , N ) ;
            }
        - Ordenacao decrescente:
            - Troca o ultimo elemento com a raiz
            - Diminui o tamanho da heap
            - fixDown para posicionar os elementos
            - while (N >1) {
                exch ( pq [1] , pq [ N ]) ;
                fixDown (1 , - - N ) ;
            }
    - A 2 fase é mais custosa pois 
        - reorganiza a head a cada remocao
        - complexidade : 2 ∗ N ∗ log N + 2 ∗ N -> O(N log N)
        - 2 ∗ N na construção da heap e 2 ∗ N ∗ log N no conserto da heap (segunda fase)

#### INTRO SORT
    - Hibrido
        - Quick + Merge ( mais espaco ) + Insertion
        - Quick + Heap ( mais constante ) + Insertion
    - Complexidade pior caso : O(N log N)
    - In-place 
    - Não é estável
    - Não é adaptativo