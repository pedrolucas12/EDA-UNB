#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int vetor[N];
    int menor = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);

        if (vetor[i] < vetor[menor]) {
            menor = i;
        }
    }

    printf("%d\n", menor);

    return 0;
}
