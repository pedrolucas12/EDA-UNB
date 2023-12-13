#### MERGE SORT
    -Metodo dividir e conquistar
    -Passo a passo:
        -Dividir o vetor em partes iguais
        -Ordenar cada parte recursivamente
        -Juntar as partes ordenadas
    -A cada chamada divide a entrada em sub-vetores, quando chegar em um vetor de tamanho 1, ele retorna e começa a ordenar os sub-vetores ( merge )
    -Complexidade assintotica:
        -Melhor caso: O(n log n)
        -Pior caso: O(n log n)
        -Caso medio: O(n log n)
        -Motivo : 2 * f(n/2) (particao) + n(merge) -> O(n log n)
    -ADAPTATIVO
    -ESTAVEL
    -NAO IN-PLACE


#### QUICK SORT
    - Particiona o vetor em sub-vetores
    - Merge vs Quick
        - Merge: divide o vetor, ordena separado e depois junta
        - Quick: divide com base em um pivo, conquista 1 elemento ordenado e 2 subvetores nao ordenados, divide e repete
    - Passo a passo:
        -Particionar o vetor
        -Escollher um pivo
        -Reorganiza de acordo com o pivo
        -Pivo fica na posicao correta
        -Pivo marca a divisao dos sub-vetores
        -Repete o processo recursivamente
    - Complexidade assintotica:
        -Melhor caso:n + 2 * f(n/2) ->  O(n log n) - entradas aleatórias
        -Pior caso: n + f(n-1) -> O(n^2/2)
        -Caso medio: O(n log n) - entradas aleatórias
        -Motivo: n + 2 * f(n/2) -> O(n log n)
    - NAO ADAPTATIVO
    - NAO ESTAVEL
    - IN-PLACE
    -Melhorias
        -Mediana de 3 : Pivô: usar a mediana de uma pequena amostra de itens. Melhora o partiocionamento
        ```c 
            int meio = ( l + r ) /2;
            if( v [ meio ] < v [ l ]) swap ( v [ meio ] , v [ l ]) ;
            if( v [ r ] < v [ l ]) swap ( v [ l ] , v [ r ]) ;
            if( v [ meio ] < v [ r ]) swap ( v [ r ] , v [ meio ]) ;
        ```
        ````c
            compexch ( v [ l ] , v [( l + r ) /2]) ;
            compexch ( v [ l ] , v [ r ]) ;
            compexch ( v [ r ] , v [( l + r ) /2]) ;
        ```