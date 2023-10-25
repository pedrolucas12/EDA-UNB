#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int campo[N][M];

    // Lê o mapa do campo de minhocas
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &campo[i][j]);
        }
    }

    // Calcula o número esperado total de minhocas a serem colhidas pela máquina
    int maxSum = 0;

    // Calcula a soma máxima das colunas
    for (int j = 0; j < M; j++) {
        int colSum = 0;
        for (int i = 0; i < N; i++) {
            colSum += campo[i][j];
        }
        if (colSum > maxSum) {
            maxSum = colSum;
        }
    }

    // Calcula a soma máxima das linhas
    for (int i = 0; i < N; i++) {
        int rowSum = 0;
        for (int j = 0; j < M; j++) {
            rowSum += campo[i][j];
        }
        if (rowSum > maxSum) {
            maxSum = rowSum;
        }
    }

    printf("%d\n", maxSum);

    return 0;
}
