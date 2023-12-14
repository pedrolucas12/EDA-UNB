#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função busca binária que retorna o índice do dado no vetor (caso exista) e -1 caso não
long long busca_binaria(long long *v, long long n, long long dado) {
    long long l = 0, h = n;

    while (l < h) {
        long long meio = l + (h - l) / 2;

        if (dado == v[meio])
            return meio;
        else if (dado < v[meio])
            h = meio;
        else
            l = meio + 1;
    }

    return -1;
}

// Funções inserção_sort para ordenar o vetor
void insercao_sort(long long *v, long long n) {
    for (long long i = 1; i < n; i++) {
        long long chave = v[i];
        long long j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = chave;
    }
}

int main() {
    long long n, dado;

    scanf("%lld", &n);

    long long v[n];

    for (long long i = 0; i < n; i++)
        scanf("%lld", &v[i]);

    insercao_sort(v, n);

    while (scanf("%lld", &dado) != EOF) {
        long long res = busca_binaria(v, n, dado);

        if (res == -1)
            printf("nao\n");
        else
            printf("sim\n");
    }

    return 0;
}
