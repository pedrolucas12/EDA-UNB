
# Algoritmos de Ordenação

## Merge Sort


## Quick Sort


## Counting Sort
    - O Counting Sort é um algoritmo de ordenação eficiente que classifica os elementos de um array limitado.
    - Ele opera contando o número de elementos distintos e, em seguida, usando essas contagens para colocar os elementos na posição correta.
    - O conceito do Counting Sort é baseado em algumas etapas-chave:
        - Primeiro, ele conta as frequências de cada elemento, armazenando essas contagens em um array auxiliar.
        - Em seguida, calcula as posições/índices através das frequências para determinar a posição de cada elemento.
        - Por fim, distribui as chaves nos arrays auxiliares na ordem correta, resultando em um array ordenado.
    - Esse algoritmo é especialmente eficiente quando os números de entrada estão dentro de um intervalo pequeno e bem definido.
    - O Counting Sort possui velocidade linear (O(n)) no melhor caso, quando comparado com outros algoritmos de ordenação, como o Quick Sort, Merge Sort ou Heap Sort, que possuem uma complexidade maior.
    - Isso o torna uma excelente opção quando os números de entrada são bastante limitados e variam em um intervalo pequeno.
    - Entretanto, seu desempenho pode ser afetado negativamente se a faixa de valores de entrada for muito grande, e a quantidade de elementos a serem ordenados for muito pequena.
    - Nesses casos, outros algoritmos como o Quick Sort ou Merge Sort podem ser mais eficientes.
    - Em resumo, o Counting Sort é uma ótima opção para ordenar um grande conjunto de dados com intervalo limitado e funciona contando as frequências, calculando as posições/índices através das frequências e distribuindo as chaves na ordem correta.
    - Ele tem uma velocidade linear no melhor caso e é eficaz especialmente em situações em que a faixa de valores de entrada é pequena, proporcionando assim uma ordenação eficiente e rápida.

## Radix Sort
    - O Radix Sort é um algoritmo de ordenação que compara as chaves ou dados de uma forma diferente dos outros algoritmos. Ele decompõe a chave em subestruturas que a compõem, como números (unidades, dezenas, centenas) ou palavras (letras) 4.
    - A cada iteração/recursão, o algoritmo compara somente parte da chave, ordenando parcialmente e, assim, movendo-se para as próximas subestruturas 4.
    - Existem métodos de classificação para o Radix Sort, como o MSD (most significant digit), que ordena da esquerda para a direita e é adequado para ordenar chaves com tamanhos variáveis 5.
    - Esse método utiliza o counting sort (key-indexed counting) e faz a ordenação recursiva dos subvetores de cada caractere 5.
    - O Radix Sort também pode ser implementado através da distribuição das chaves, utilizando vetores auxiliares e uma tabela de índices para copiar as chaves na ordem correta 9.
    - Além disso, o Radix Sort enfatiza a importância da extração do dígito mais significativo da chave, ordenando pela raiz (radix) da representação dos dados 8.
    - Em resumo, o Radix Sort é um algoritmo de ordenação que se destaca por sua abordagem de comparação e ordenação baseada na decomposição das chaves em subestruturas para atingir a ordenação desejada, além de métodos de classificação e ênfase na extração dos dígitos mais significativos das chaves para a ordenação eficiente 

## Counting Sort vs Radix Sort
    - A diferença entre os diferentes algoritmos de ordenação é a forma como eles organizam os elementos.
    - O Counting Sort é eficiente para classificar elementos em um intervalo específico, baseando-se na contagem de ocorrências de cada elemento2.
    - Já o Radix Sort classifica os números com base em cada dígito, da unidade até a maior ordem presente nos números, resultando em uma ordenação estável e eficiente5.
    - Portanto, enquanto o Counting Sort é eficaz para intervalos específicos de elementos, o Radix Sort é mais adequado para a ordenação de números inteiros com múltiplos dígitos

## Heap Sort
    - O Heap Sort é um algoritmo de ordenação que utiliza a estrutura de dados Heap binária para ordenar um conjunto de elementos. Ele é considerado um algoritmo de ordenação eficiente, com complexidade de tempo O(n log n) no pior caso.
    - O Heap é uma árvore binária completa, onde cada nó pai é maior ou menor que seus filhos, dependendo se a Heap é máxima ou mínima, respectivamente. No Heap Sort, utilizamos a Heap máxima para ordenar os elementos em ordem decrescente.
    - O processo de ordenação do Heap Sort é dividido em duas fases: a construção da Heap e a ordenação propriamente dita. Na primeira fase, os elementos são inseridos na Heap um por um, de forma que a estrutura da Heap seja mantida. Essa fase tem complexidade O(n log n).
    - Na segunda fase, os elementos são removidos da Heap um por um, de forma que o maior elemento é sempre o primeiro a ser removido. Cada elemento removido é colocado na posição correta no vetor de saída. Essa fase tem complexidade O(n log n).
    - O Heap Sort é um algoritmo in-place, ou seja, não utiliza espaço extra para ordenar os elementos. Além disso, ele não é estável, ou seja, elementos iguais podem ter suas posições trocadas durante o processo de ordenação.
    - O melhor caso de desempenho do Heap Sort é quando o vetor já está ordenado, pois a construção da Heap é desnecessária e a ordenação é feita em tempo linear O(n). No entanto, o pior caso é quando o vetor está completamente desordenado, pois a construção da Heap e a ordenação têm complexidade O(n log n).
    - Em resumo, o Heap Sort é um algoritmo de ordenação eficiente que utiliza a estrutura de dados Heap binária para ordenar um conjunto de elementos em ordem decrescente. Ele é in-place, não estável e tem complexidade O(n log n) no pior caso.

## Intro Sort
   - O Intro Sort é uma combinação de algoritmos de ordenação interna, sendo utilizado em linguagens como C++, C# e Java (este último utiliza uma variação chamada quicksort three-way).
   - Ele é um algoritmo híbrido que combina as técnicas de quicksort, merge sort e insertion sort para aproveitar as vantagens de cada um e evitar suas desvantagens.
   - O algoritmo utiliza o quicksort como principal método de ordenação, devido ao seu bom desempenho na maioria dos casos.
   - Quando a profundidade da recursividade atinge um máximo estipulado, o algoritmo alterna para outro método de ordenação, como o merge sort ou o insertion sort, para evitar o pior caso de desempenho do quicksort.
   - O Intro Sort utiliza o quicksort como método principal, mas alterna para outros métodos de ordenação quando necessário para garantir um desempenho eficiente.
   - A complexidade no pior caso do Intro Sort é O(n log n), garantindo um desempenho eficiente na maioria das situações.
   - O melhor caso de desempenho do Intro Sort é quando o vetor está quase ordenado ou possui um tamanho pequeno, pois o algoritmo pode se beneficiar do insertion sort, que tem complexidade linear em casos favoráveis.

## Heap Sort vs Intro Sort
   - O Heap Sort utiliza a estrutura de dados Heap binária para ordenar os elementos, enquanto o Intro Sort utiliza principalmente o quicksort, mas pode alternar para outros métodos de ordenação, como o merge sort e o insertion sort.
   - O Heap Sort tem complexidade O(n log n) no pior caso, assim como o Intro Sort. No entanto, o Intro Sort pode alternar para outros métodos de ordenação quando necessário, o que pode melhorar seu desempenho em casos extremos.
   - O Heap Sort não é um algoritmo estável, ou seja, elementos iguais podem ter suas posições trocadas durante o processo de ordenação. Já o Intro Sort também não é estável.
   - O Heap Sort é um algoritmo in-place, ou seja, não utiliza espaço extra para ordenar os elementos. O Intro Sort também é in-place.
   - O Intro Sort é adaptativo, ou seja, ele pode se adaptar ao estado do vetor e escolher o método de ordenação mais adequado para cada situação. Já o Heap Sort não é adaptativo.
   - O melhor caso de desempenho do Heap Sort é quando o vetor já está ordenado, pois a construção da Heap é desnecessária e a ordenação é feita em tempo linear O(n). Já o melhor caso do Intro Sort é quando o vetor está quase ordenado ou possui um tamanho pequeno, pois o algoritmo pode se beneficiar do insertion sort, que tem complexidade linear em casos favoráveis.