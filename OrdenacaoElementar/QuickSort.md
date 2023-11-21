Algoritmo de Ordenação QuickSort

    Lema : Dividir e Conquistar com Pivô
    Passo a Passo
        1 - Separa os elementos 
        2 - Escolhe um pivô
        3 - Reorganiza os elementos em relação ao pivô
        4 - Pivo na posição final
        5 - Pivo marca a divisão do vetor
        6 - Repetir o processo ate que o vetor esteja ordenado
    Resumo: Escolhe um pivo e joga tudo que é menor para a esquerda e tudo que é maior para a direita, depois escolhe outro pivo e repete o processo
    Condicoes que devem ser satisfeitas
        1 - O vetor deve ser dividido em duas partes
        2 - Os elementos da primeira parte devem ser menores que os da segunda parte
        3 - O pivô deve ser colocado na posição correta
        4 - O processo deve ser repetido para as duas partes
    Complexidade de Tempo
        Melhor Caso: O(n log n)
        Caso Medio: O(n log n)
        Pior Caso: n² / 2
    In-place: Sim
    Estavel: Não
    Adaptavel: Não
    Melhorias
        Mediana de Três : Melhora o particionamento
        Inserção Direta : Melhora o desempenho para vetores pequenos
        Ordenação de 3 elementos - Three-way : Melhora o desempenho para vetores pequenos
