
#### LISTAS ESTÁTICAS
    - Conjunto do mesmo tipo de dado
    - Acesso aleatorio por meio do index
    - Tamanho fixo (STACK) ou dinâmico (HEAP)
    - VANTAGEM : fácil acesso
    - DESVANTAGEM : dificuldade de inserção e remoção
 
#### LISTAS ENCADEADAS SIMPLES
    - Conjunto de nós/celulas
    - Cada nó possui: um dado e um ponteiro para o próximo nó
    - Mais facil inserção e remoção, mas nao tem acesso direto aos itens
    - Fim da lista é marcado por um ponteiro nulo
    - Tipos:
        Sem cabeça: primeiro nó é o primeiro elemento da lista
        Com cabeça: primeiro nó é um nó cabeça que aponta para o primeiro elemento da lista

#### LISTAS DUPLAMENTE ENCADEADAS
    - Armazena a informacao do proximo e do anterior
    - Util quando ocorre muitas operacoes de remocao e insercao
    - Anterior do primeiro elemento e proximo do ultimo elemento apontam para NULL

#### LISTAS CIRCULARES
    - SIMPLES : ultimo elemento aponta para o primeiro
    - DUPLA : ultimo elemento aponta para o primeiro e o primeiro aponta para o ultimo
    - VANTAGENS : acesso aleatorio, facil insercao e remocao
    - DESVANTAGENS : dificil implementacao, necessidade de um ponteiro para o ultimo elemento