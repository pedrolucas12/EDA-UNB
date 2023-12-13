#### COUTING SORT
    - Funcionamento:
        - Cada indice é uma chave do vetor de entrada
        - Determina a posicao da chave, contando quantas chaves sao menores que ela
        - Distribuicao de frequencia
        - Cada chave é reposicionada na posicao DEFINITIVA
    -Etapas:
        - Contagem de frequencia
            for (i =0; i <= R; i ++) count [i] = 0;
            for (i= l; i <= r; i ++) count [v[i ]+1]++;
        - Calcular as posicoes/indices
            for (i = 1; i <= R; i ++) count [i] += count [i-1];
        - Distribuir os elementos
            for (i = l; i <= r; i ++) {
                aux [count [v[i]]++] = v[i];
                count [ v[i ]]++;}


#### RADIX SORT 
    - Funcionamento:
        - Compara a estrutura das chaves
        - Decomposicao da chave em subestruturas
        - A cada iteracao/recursao comparar somente parte da chave
    - Chaves grandes e pequenas
        - Chaves grandes: Radix Sort
        - Chaves pequenas: Counting Sort
    - Metodo LSD
        - COMPRIMENTO FIXO
        - Least Significant Digit
        - Ordenacao de tras para frente ( DIREITA PARA ESQUERDA)
        - Ordenacao estavel
        - Complexidade proporcional a W * N ( W = tamanho da chave, N = numero de chaves)
    - Metodo MSD
        - COMPRIMENTO VARIAVEL
        - Most Significant Digit
        - Ordenacao da esquerda para direita
        - Ordenacao instavel
        - Complexidade proporcional a 7 ∗ W ∗ N + 3 ∗ W ∗ R ( W = tamanho da chave, N = numero de chaves)
    -Estavel
    -Nao in-place