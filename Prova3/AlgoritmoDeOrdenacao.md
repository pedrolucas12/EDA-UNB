
# Algoritmos de Ordenação

# Estabilidade:  
    - Um algoritmo de ordenação é estável se ele mantém a ordem relativa original dos items com chaves de ordenação duplicadas
    Algoritmos estáveis:
        • InsertionSort, BubbleSort e MergeSort
    Algoritmos não-estáveis:
        • SelectionSort, Quicksort e Heapsort

## Merge Sort - Divide ate a unidade e depois MERGE
    - O Merge Sort é um algoritmo de ordenação eficiente baseado na técnica de dividir para conquistar. Ele funciona dividindo a lista a ser ordenada ate que a sublista seja unitaria, e depois mesclando essas sub-listas em uma lista ordenada.
    - Dividir e Conquistar: A metodologia utilizada pelo Merge Sort para resolver problemas mais complexos, como a ordenação de grandes conjuntos de dados, dividindo-os em subproblemas menores, resolvendo-os individualmente e combinando as soluções.
    - Merge: O processo de combinar sub-listas ordenadas para formar uma única lista ordenada.
    - Tempo de Execução: O algoritmo de Merge Sort tem um desempenho eficiente e uma complexidade de tempo de O(n log n) no pior caso, onde n é o número de elementos a serem ordenados 4.
    - Abordagem Top-Down: O Merge Sort pode ser implementado a partir de uma abordagem top-down, dividindo a lista inteira em sub-listas e posteriormente fundindo-as 9.
    - O melhor caso para o Merge Sort ocorre quando a lista já está parcialmente ou totalmente ordenada, pois mesmo nesses casos ele ainda opera com a mesma complexidade de tempo O(n log n) 
    - Em resumo, o Merge Sort é um algoritmo de ordenação eficiente que opera com complexidade de tempo O(n log n)em qualquer caso, utilizando a técnica de dividir para conquistar e a operação de combinação (merge) para ordenar eficientemente grandes conjuntos de dados.
    - Estabilidade: O Merge Sort é um algoritmo de ordenação estável, ou seja, elementos iguais não têm suas posições trocadas durante o processo de ordenação.
    - In-Place: O Merge Sort não é um algoritmo in-place, ou seja, ele utiliza espaço extra para ordenar os elementos.
    - Otimizacoes:
        Nos sub-vetores pequenos, altere para o Insertion Sort 
        Incremente testes para verificar se o vetor já está ordenado
        Nao utilize um vetor aux local na funcao merge

## Quick Sort - Comparacoes com o PIVO
    - O Quick Sort é um algoritmo de ordenação eficiente baseado na técnica de dividir para conquistar. Ele funciona dividindo o vetor a ser ordenada em subvetores menores e depois ordenando os subvetores independentemente.
    - Merge x Quick : O Merge divide, ordena separadamente, combina reodenando e conquista um vetor mais ordenado. Já o Quick separa os elemento baseado em 1 elemento, conquista um elemento ordenado e dois subvetores não ordenados, dai divide e repete para os subvetores.
    - Ideia : Particionar ( separar ), escolher um pivo, reorgarnizar os elementos de acordo com o pivo, pivo na posicao final, pivo marca a divisao dos subvetores, repetir o processo ate ordenar os subvetores
    - Particionar: O processo de dividir o vetor em subvetores menores, de acordo com um elemento escolhido como pivô.
    - Partição: O processo de reorganizar os elementos do vetor de forma que os elementos menores que o pivô fiquem à sua esquerda e os elementos maiores que o pivô fiquem à sua direita.
    - In-Place: O Quick Sort é um algoritmo in-place, ou seja, ele não utiliza espaço extra para ordenar os elementos.
    - Estabilidade: O Quick Sort não é um algoritmo de ordenação estável, ou seja, elementos iguais podem ter suas posições trocadas durante o processo de ordenação.
    - Complexidade Assintotica: Melhor e medio caso O(n log n), pior caso O(n^2 / 2)
    - Otimizacoees :
        Mediana de 3: Escolher o pivo como a mediana entre o primeiro, o ultimo e o elemento do meio
        Insertion Sort: Para subvetores pequenos, alterar para o Insertion Sort
        Three-way partitioning: Para elementos repetidos, separar em 3 subvetores, menores, iguais e maiores que o pivo
 
## Counting Sort - Conta a frequencia e depois distribui
    - O Counting Sort é um algoritmo de ordenação eficiente que classifica os elementos de um array limitado.
    - Ele opera contando o número de elementos distintos e, em seguida, usando essas contagens para colocar os elementos na posição correta.
    - O conceito do Counting Sort é baseado em algumas etapas-chave:
        - Primeiro, ele conta as frequências de cada elemento, armazenando essas contagens em um array auxiliar.
        - Em seguida, calcula as posições/índices através das frequências para determinar a posição de cada elemento.
        - Por fim, distribui as chaves nos arrays auxiliares na ordem correta, resultando em um array ordenado.
    - O Counting Sort possui velocidade linear (O(n)) no melhor caso
    - Entretanto, seu desempenho pode ser afetado negativamente se a faixa de valores de entrada for muito grande, e a quantidade de elementos a serem ordenados for muito pequena.
    - Em resumo, o Counting Sort é uma ótima opção para ordenar um grande conjunto de dados com intervalo limitado e funciona contando as frequências, calculando as posições/índices através das frequências e distribuindo as chaves na ordem correta.
    - ESTAVEL, NAO ADAPTATIVO, NAO IN-PLACE, O(n + k) no melhor caso, O(n + k) no pior caso, O(n + k) no caso medio

## Radix Sort - Ordena por partes da chave
    - O Radix Sort é um algoritmo de ordenação que compara as chaves ou dados de uma forma diferente dos outros algoritmos. Ele decompõe a chave em subestruturas que a compõem, como números (unidades, dezenas, centenas) ou palavras (letras) .
    - A cada iteração/recursão, o algoritmo compara somente parte da chave, ordenando parcialmente e, assim, movendo-se para as próximas subestruturas.
    - Existem métodos de classificação para o Radix Sort, como o MSD (most significant digit), que ordena da esquerda para a direita e é adequado para ordenar chaves com tamanhos variáveis.
    - Esse método utiliza o counting sort (key-indexed counting) e faz a ordenação recursiva dos subvetores de cada caractere.
    - O Radix Sort também pode ser implementado através da distribuição das chaves, utilizando vetores auxiliares e uma tabela de índices para copiar as chaves na ordem correta.
    - Além disso, o Radix Sort enfatiza a importância da extração do dígito mais significativo da chave, ordenando pela raiz (radix) da representação dos dados.
    - LSD (least significant digit) : Estavel, Nao In-Place, O(n) no melhor caso, O(n * w) no pior caso, O(n * w) no caso medio
    - MSD (most significant digit) : Estavel, Nao In-Place, O(n) no melhor caso, O(n * w) no pior caso, O(n * w) no caso medio
    - ESTAVEL, NAO ADAPTATIVO, NAO IN-PLACE, O(n) no melhor caso, O(n * w) no pior caso, O(n * w) no caso medio

## Fila de Prioridades - Heap - Log n ( altura )
    - Arvore binaria completa: Uma arvore binaria completa é uma arvore binaria onde todos os niveis, exceto possivelmente o ultimo, estao completamente preenchidos, e todos os nos do ultimo nivel sao o mais a esquerda possivel.
    - Raiz : chave de maior prioridade
    - Nao ordena, quanto maior a prioridade, mais proximo da raiz
    - Insercao : Insere no final e sobe ate a posicao correta ( O(log n) )
    - Remocao : Remove a raiz e coloca o ultimo elemento no lugar, depois desce ate a posicao correta ( 2log n ) 
    - Trocar prioridade : Troca a prioridade e sobe ou desce ate a posicao correta ( O(log n) )
    - Vetor comeca na posicao 1, pois a posicao 0 nao tem pai
    - Heap -> Vetor : Pai = i, Filho esquerdo = 2i, Filho direito = 2i + 1

## Heap Sort
    - O Heap Sort é um algoritmo de ordenação que utiliza a estrutura de dados Heap binária para ordenar um conjunto de elementos. Ele é considerado um algoritmo de ordenação eficiente, com complexidade de tempo O(n log n) no pior caso.
    - O Heap é uma árvore binária completa, onde cada nó pai é maior ou menor que seus filhos, dependendo se a Heap é máxima ou mínima, respectivamente. No Heap Sort, utilizamos a Heap máxima para ordenar os elementos em ordem decrescente.
    - O processo de ordenação do Heap Sort é dividido em duas fases: a construção da Heap e a ordenação propriamente dita. Na primeira fase, os elementos são inseridos na Heap um por um, de forma que a estrutura da Heap seja mantida. Essa fase tem complexidade O(n log n).
    - Na segunda fase, os elementos são removidos da Heap um por um, de forma que o maior elemento é sempre o primeiro a ser removido. Cada elemento removido é colocado na posição correta no vetor de saída. Essa fase tem complexidade O(n log n).
    - O Heap Sort é um algoritmo in-place, ou seja, não utiliza espaço extra para ordenar os elementos. Além disso, ele não é estável, ou seja, elementos iguais podem ter suas posições trocadas durante o processo de ordenação.
    - O melhor caso de desempenho do Heap Sort é quando o vetor já está ordenado, pois a construção da Heap é desnecessária e a ordenação é feita em tempo linear O(n). No entanto, o pior caso é quando o vetor está completamente desordenado, pois a construção da Heap e a ordenação têm complexidade O(n log n).
    -NAO ESTAVEL, IN-PLACE, O(n log n) no melhor caso, O(n log n) no pior caso, O(n log n) no caso medio

## Intro Sort
   - O Intro Sort é uma combinação de algoritmos de ordenação interna
   - Ele é um algoritmo híbrido que combina as técnicas de quicksort, merge sort e insertion sort para aproveitar as vantagens de cada um e evitar suas desvantagens.
   - O algoritmo utiliza o quicksort como principal método de ordenação, devido ao seu bom desempenho na maioria dos casos.
   - Quando a profundidade da recursividade atinge um máximo estipulado, o algoritmo alterna para outro método de ordenação, como o merge sort ou o insertion sort, para evitar o pior caso de desempenho do quicksort.
   - A complexidade no pior caso do Intro Sort é O(n log n), garantindo um desempenho eficiente na maioria das situações.
   - O melhor caso de desempenho do Intro Sort é quando o vetor está quase ordenado ou possui um tamanho pequeno, pois o algoritmo pode se beneficiar do insertion sort, que tem complexidade linear em casos favoráveis.
   - NAO ESTAVEL, IN-PLACE, O(n log n) no melhor caso, O(n log n) no pior caso, O(n log n) no caso medio
