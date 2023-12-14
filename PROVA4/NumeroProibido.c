#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Função busca binaria que retorna o índice do dado no vetor (caso exista) e -1 caso não
long long busca_binaria(long long *v, long long n, long long dado) {
    long long l = 0, h = n;

    while (l < h) {
        long long  meio = l + (h - l) / 2;

        if(dado == v[meio])
            return meio;
        else if (dado < v[meio])
            h = meio;
        else
            l = meio + 1;
    }

    return -1;
}

//Funções merge e merge_sort que ordenam o vetor
void merge(long long *v, long long l, long long m, long long r) {
    long long *auxiliar = malloc(sizeof(long long) * (r - l + 1));

    long long i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
        auxiliar[k++] = v[i] <= v[j] ? v[i++] : v[j++];

    while (i <= m)
        auxiliar[k++] = v[i++];
    while (j <= r)
        auxiliar[k++] = v[j++];

    k = 0;

    for (i = l; i <= r; i++)
        v[i] = auxiliar[k++];

    free(auxiliar);
}

void merge_sort(long long *v, long long l, long long r) {
    if (r <= l)
        return;

    long long meio = (l + r) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio + 1, r);
    merge(v, l, meio, r);
}

int main() {
    long long n, dado;

    scanf("%lld", &n);

    long long v[n];

    for (long long i = 0; i < n; i++)
        scanf("%lld", &v[i]);

    merge_sort(v, 0, n);

    while (scanf("%lld", &dado) != EOF) {
        long long res = busca_binaria(v, n, dado);
        
        if(res == -1)
            printf("nao\n");
        else
            printf("sim\n");
    }
    
    return 0;
}