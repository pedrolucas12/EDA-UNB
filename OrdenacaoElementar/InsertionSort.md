Algoritmo de ordenacao - Insertion Sort

    -Lema : Inserir na posicao correta
    -Passo a passo:
        1 - Inserir cada elemento na posicao correta em relacao aos elementos anteriores
        2 - Comparacao item a item com os elementos anteriores
    -Resumo : Percorre o array, procura os antecessores menores e insere na posicao correta. Empurra o menor para a esquerda e puxa o maior para a direita.
    -Complexidade : 
        Nao é indicado para grandes entradas totalmente desordenadas ou inversamente ordenadas
        Trocas apenas entre elementos adjacentes
        Melhor caso: O(n) - Array ordenado
        Pior caso: O(n²) - Array inversamente ordenado
    Adaptabilidade: Sim
    Estavel: Sim    
    -In-place: Sim
    -Uso : Pequenas entradas ou entradas parcialmente ordenadas
    -Bubble Sort x Insertion Sort:
        Bubble Sort: O posicionamento de um item não garante a ordenacao de outros, apenas que esquerda é menor e direita é maior
        Insertion Sort: O posicionamento de um item garante a ordenacao dos anteriores
    -Selection Sort x Insertion Sort:
        Selection Sort: Em relacao a uma posicao atual -> ordenado e na posicao final
        Insertion Sort: Em relacao a uma posicao atual -> ordenado mas pode nao estar na posicao final
