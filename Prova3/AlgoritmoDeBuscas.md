##  Algoritmos de Busca

### Busca Binária
    -A busca binária é um algoritmo de busca em vetores que segue o paradigma de divisão e conquista.
    -A ideia é dividir o vetor em partes iguais, comparar o elemento buscado com o elemento no meio do vetor e, de acordo com o resultado dessa comparação, descartar a metade em que o elemento buscado não pode estar.
    -A busca binária é um algoritmo eficiente para se encontrar um elemento em um vetor, pois seu tempo de execução é O(log n).
    -Para que a busca binária funcione, o vetor deve estar ordenado.
    -A busca binária é um algoritmo recursivo.


### Arvore Binaria de busca
    -Para ser binaria de busca, cada nó deve ter no MÁXIMO 2 filhos
    -Em binaria, o máximo de informações que um nó pode ter é 3 (pai, filho esquerdo e filho direito)
    -Em binaria, todos os nós da ESQUERDA são MENORES que o pai e todos os nós da DIREITA são MAIORES que o pai
    -Operações básicas : Construir, Inserir, Remover, Buscar
    -Percursos: Pré-ordem, Em-ordem, Pós-ordem
    -Nó interno: nó que possui filhos
    -Nó externo: nó que não possui filhos
    -Nó raiz: nó que não possui pai
    -Nó folha: nó que não possui filhos
    -Profundidade: distancia de um nó até a raiz
    -Grau de um nó: número de filhos que um nó possui
    -Desempenho 
        Melhor caso: lgN (árvore balanceada)
        Pior caso: N (árvore desbalanceada)
        Caso médio: espera-se 2lgN 
    -Árvore balanceada: árvore em que a diferença entre a altura da subárvore esquerda e a subárvore direita de cada nó é no máximo 1.
