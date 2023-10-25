#include <stdio.h>

int main() {
    int A, V, X, Y;

    int caso = 0;

    while (1) {
        scanf("%d %d", &A, &V);

        if (A == 0 && V == 0)
            break;

        int trafego[A + 1];
        for (int i = 1; i <= A; i++)
            trafego[i] = 0;

        for (int i = 0; i < V; i++) {
            scanf("%d %d", &X, &Y);
            trafego[X]++;
            trafego[Y]++;
        }

        int max_trafego = 0;

        for (int i = 1; i <= A; i++) {
            if (trafego[i] >= max_trafego)
                max_trafego = trafego[i];
        }

        printf("Teste %d\n", ++caso);

        for (int i = 1; i <= A; i++) {
            if (trafego[i] == max_trafego)
                printf("%d ", i);
        }

        printf("\n\n");
    }

    return 0;
}
