#include <stdio.h>
#include <stdlib.h>

typedef struct instrucao {
    int id;
    char palavra_chave[16];
} instrucao;

void merge(instrucao *v, int l, int m, int r) {
    instrucao *auxiliar = (instrucao *)malloc(sizeof(instrucao) * (r - l));

    int i = l, j = m, k = 0;

    while (i < m && j < r)
        auxiliar[k++] = v[i].id <= v[j].id ? v[i++] : v[j++];

    while (i < m)
        auxiliar[k++] = v[i++];
    while (j < r)
        auxiliar[k++] = v[j++];

    for (i = l; i < r; i++)
        v[i] = auxiliar[i - l];

    free(auxiliar);
}

void merge_sort(instrucao *v, int l, int r) {
    if (r - 1 <= l)
        return;

    int meio = l + (r - l) / 2;

    merge_sort(v, meio, r);
    merge_sort(v, l, meio);
    merge(v, l, meio, r);
}

int busca_binaria(instrucao *v, int n, int dado) {
    int l = 0, h = n;

    while (h > l) {
        int meio = l + (h - l) / 2;
        if (v[meio].id == dado)
            return meio;
        else if (v[meio].id > dado)
            h = meio;
        else
            l = meio + 1;
    }

    return -1;
}

int main() {
    int n, dado;

    scanf("%d", &n);

    instrucao vetor[n];

    for (int i = 0; i < n; i++)
        scanf("%d %s", &vetor[i].id, vetor[i].palavra_chave);

    merge_sort(vetor, 0, n);

    while (scanf("%d", &dado) != EOF) {
        int resposta = busca_binaria(vetor, n, dado);

        if (resposta == -1)
            printf("undefined\n");
        else
            printf("%s\n", vetor[resposta].palavra_chave);
    }

    return 0;
}