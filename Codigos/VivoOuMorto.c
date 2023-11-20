#include <stdio.h>

int main() {
    int caso = 1;
    int P, R;

    while (1) {
        scanf("%d %d", &P, &R);
        if (P == 0 && R == 0) break;

        int fila[P];
        int eliminados[P] = {0};

        for (int i = 0; i < P; i++) {
            scanf("%d", &fila[i]);
        }

        for (int i = 0; i < R; i++) {
            int N, J;
            scanf("%d %d", &N, &J);

            for (int j = 0; j < N; j++) {
                int acao;
                scanf("%d", &acao);

                if (acao == 0) {
                    eliminados[fila[j] - 1] = 1;
                }
            }

            int novoIndice = 0;
            for (int j = 0; j < N; j++) {
                if (!eliminados[fila[j] - 1]) {
                    fila[novoIndice] = fila[j];
                    novoIndice++;
                }
            }

            P = novoIndice;
        }

        printf("Teste %d\n", caso);
        for (int i = 0; i < P; i++) {
            if (!eliminados[fila[i] - 1]) {
                printf("%d\n", fila[i]);
                break;
            }
        }
        printf("\n");

        caso++;
    }

    return 0;
}
