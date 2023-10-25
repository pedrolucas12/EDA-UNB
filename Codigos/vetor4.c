#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int numeros[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

    // Separar os índices dos elementos pares e ímpares
    int indices_pares[n];
    int indices_impares[n];
    int num_pares = 0, num_impares = 0;

    for (int i = 0; i < n; i++) {
        if (numeros[i] % 2 == 0) {
            indices_pares[num_pares] = i;
            num_pares++;
        } else {
            indices_impares[num_impares] = i;
            num_impares++;
        }
    }

    // Imprimir os índices dos elementos pares
    for (int i = 0; i < num_pares; i++) {
        printf("%d", indices_pares[i]);
        if (i < num_pares - 1) {
            printf(" ");
        }
    }
    printf("\n");

    // Imprimir os índices dos elementos ímpares
    for (int i = 0; i < num_impares; i++) {
        printf("%d", indices_impares[i]);
        if (i < num_impares - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
