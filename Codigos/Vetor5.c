#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int vetor[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }

    int X;
    scanf("%d", &X);

    int encontrado = 0;

    for (int i = 0; i < N; i++) {
        if (vetor[i] == X) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        printf("pertence\n");
    } else {
        printf("nao pertence\n");
    }

    return 0;
}
