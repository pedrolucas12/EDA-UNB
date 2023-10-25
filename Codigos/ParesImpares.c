#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int sequencia[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &sequencia[i]);
    }

    printf("Pares: ");
    for (int i = 0; i < N; i++) {
        if (sequencia[i] % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("Ímpares: ");
    for (int i = 0; i < N; i++) {
        if (sequencia[i] % 2 != 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
