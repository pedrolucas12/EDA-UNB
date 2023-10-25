#include <stdio.h>
#include <string.h>

int main() {

    int a, b, N, soma;

    printf("Digite a quantidade de numeros que vao ser somados : ");
    scanf("%d", &N);

    soma = 0;

    for (int i = 0; i < N; i++) {
        printf("Digite o numero: ");
        scanf("%d", &a);

        soma = a + soma;

    }

        printf("A soma dos numeros e: %d\n", soma);

        return 0;

}