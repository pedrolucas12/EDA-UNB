#include <stdio.h>
#include <stdlib.h>

//Funções merge e merge_sort para ordenar o vetor
void merge(int *v, int l, int m, int r) {
    int *auxiliar = malloc(sizeof(int) * (r - l));

    int i = l, j = m, k = 0;

    while (i < m && j < r)
        auxiliar[k++] = v[i] <= v[j] ? v[i++] : v[j++];

    while (i < m)
        auxiliar[k++] = v[i++];
    while (j < r)
        auxiliar[k++] = v[j++];

    for (i = l; i < r; i++)
        v[i] = auxiliar[i - l];

    free(auxiliar);
}

void merge_sort(int *v, int l, int r) {
    if (r - 1 <= l)
        return;

    int meio = l + (r - l) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio, r);
    merge(v, l, meio, r);
}

//Função busca binária que retorna o índice do dado no vetor (caso exista) ou -1
int busca_binaria(int *v, int n, int dado) {
    int l = 0, h = n;

    while (l < h) {
        int meio = l + (h - l) / 2;
        if (v[meio] == dado)
            return meio;
        if (v[meio] > dado)
            h = meio;
        else
            l = meio + 1;
    }

    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int vetor[200000];

    //Lendo dados do vetor
    for (int i = 0; i < n; i++)
        scanf("%d", &vetor[i]);

    //Ordenando os dados do vetor
    merge_sort(vetor, 0, n);

    //Eliminando índices repetidos
    int novo_indice = 0;
    for (int i = 1; i < n; i++)
        if (vetor[novo_indice] != vetor[i])
            vetor[++novo_indice] = vetor[i];

    novo_indice++;

    //Caso o tamanho do vetor novo seja ímpar, adicionar 1000000000 ao final
    if (novo_indice % 2 != 0)
        vetor[novo_indice++] = 1000000000;

    //Criando os números malucos únicos (somando os adjacentes) e os adicionando ao final do vetor
    int nmu_i = novo_indice;
    for (int i = 1; i < novo_indice; i += 2) {
        vetor[nmu_i] = vetor[i] + vetor[i - 1];

        //Verificando se o número obtido está presente no vetor (caso sim, remove do final do vetor)
        if (busca_binaria(vetor, novo_indice, vetor[nmu_i]) == -1)
            nmu_i++;
    }

    //Reordenando o vetor com os números malucos únicos reinseridos
    merge_sort(vetor, 0, nmu_i);

    //Imprimindo os dados do vetor de 4 em 4 índices
    for (int i = 0; i < nmu_i; i += 4)
        printf("%d\n", vetor[i]);

    //Imprimindo a quantidade de elementos do vetor
    printf("Elementos: %d\n", nmu_i);

    return 0;
}