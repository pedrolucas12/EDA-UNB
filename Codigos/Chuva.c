#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int mapa1[N][N];
    int mapa2[N][N];

    // Lê o primeiro mapa
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mapa1[i][j]);
        }
    }

    // Lê o segundo mapa
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mapa2[i][j]);
        }
    }

    // Calcula a quantidade de chuva acumulada total
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mapa1[i][j] + mapa2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
