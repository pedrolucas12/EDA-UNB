Algoritmo de Ordenacao MergeSort

    -Lema : Dividir e conquistar
    -Passo a Passo : 
        1 - Dividir o vetor em pequenas partes
        2 - Ordenar as partes
        3 - Juntar as partes ordenadas
        4 - Ate que o vetor esteja ordenado
    -Resumo : A cada chamada, divide a entrada em sub-vetores para serem ordenados, quando o tamanho ser unitario esta ordenado em 1, depois volta fazendo o merge dos sub-vetores ordenados
    -Complexidade : O(n log n)
    -Adaptabilidade : Não
    -Estabilidade : Não
    -In-Place : Não
    -Otimizacoes 
        - Se o tamanho do vetor for menor que 15, usar o InsertionSort
        - Se o vetor ja estiver ordenado, nao fazer o merge
        - Nao utilizar o vetor auxiliar, mas sim alternar entre os vetores
    -ShellSort VS MergeSort
        - ShellSort : Melhor para vetores pequenos
        - MergeSort : Melhor para vetores grandes