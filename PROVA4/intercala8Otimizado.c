#include <stdio.h>

int vetor[1600006];

void insertionSort(int *vetor, int tamanho) {
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

int main() {
    int read, tamanho = 0;
    for (int i = 0; i < 8; ++i) {
        scanf("%d", &read);
        if (read == 0)
            continue;
        for (int j = 0; j < read; ++j)
            scanf("%d", &vetor[tamanho + j]);
        
        tamanho += read;
        insertionSort(&vetor[0], tamanho);
    }

    printf("%d", vetor[0]);
    for (int i = 1; i < tamanho; ++i)
        printf(" %d", vetor[i]);
    printf("\n");

    return 0;
}
