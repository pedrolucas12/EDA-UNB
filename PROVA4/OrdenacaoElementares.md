#### CONCEITOS
    -Estabilidade : MANTEM A ORDEM ORIGINAL DOS ELEMENTOS IGUAIS
    -In-place : NAO UTILIZA MEMORIA EXTRA
    -Adaptabilidade : APROVEITA A ORDENACAO EXISTENTE
    -ELEMENTARES X EFICIENTES : ELEMENTARES SAO MAIS SIMPLES COM CUSTO MAIOR E EFICIENTES SAO MAIS COMPLEXOS 

#### SELECTION SORT
    -Passo a passo:
        -Encontrar o menor elemento do vetor
        -Trocar o menor elemento com o primeiro elemento do vetor
        -Encontrar o segundo menor elemento do vetor
        -Trocar o segundo menor elemento com o segundo elemento do vetor
        -Repetir até que o vetor esteja ordenado
    -Complexidade assintótica: N^2/2 ( comparacoes ) + N^2 ( trocas )
    -COMPLEXIDADE: O(N^2)
    -NAO ADAPTATIVO
    -NAO ESTAVEL
    -IN-PLACE

#### BUBBLE SORT
    -Passo a passo:
        -No inicio, flutuar o item
        -Ao achar uma bolha maior, flutuar a bolha
        -No fim, o maior elemento estará na ultima posição ( topo )
        -Repetir até que o vetor esteja ordenado
    -Complexidade assintótica: N^2/2 ( comparacoes ) + N^2/2 ( trocas )
    -COMPLEXIDADE: O(N^2)
    -ADAPTATIVO
    -ESTAVEL
    -IN-PLACE

#### INSERTION SORT
    -Passo a passo:
        -No inicio, o primeiro elemento está ordenado
        -Ao achar um elemento menor, inserir o elemento
        -Repetir até que o vetor esteja ordenado
    -Comparacao item a item
    -Complexidade assintótica: 
        PIOR CASO : N^2/2 ( comparacoes ) + N^2/2 ( trocas ) -> -COMPLEXIDADE: O(N^2 / 2)
        MEDIO CASO: N^2/4 ( comparacoes ) + N^2/4 ( trocas ) -> -COMPLEXIDADE: O(N^2 / 4)
        MELHOR CASO : N ( comparacoes ) + 0 ( trocas ) -> -COMPLEXIDADE: O(N)
    -ADAPTATIVO
    -ESTAVEL
    -IN-PLACE
    -> SHELL SORT
        - Ideia : ordenacao parcial a cada passagem
        - Diminui o numero de movimentacoes
        - Complexidade : 
            - PIOR CASO : N^3/2 ( comparacoes ) + N^3/2 ( trocas ) -> -COMPLEXIDADE: O(N^2) - PIOR OU O(Nlog^2n) - MELHOR
            - MELHOR CASO : O(nlogn)
            - COMPLEXIDADE : O(N^1.25)
        - NAO ADAPTATIVO
        - NAO ESTAVEL
        - IN-PLACE

