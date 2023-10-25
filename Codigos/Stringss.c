#include <stdio.h>

int main() {
    char str[1000]; // Declare um array de caracteres grande o suficiente para a entrada

    // Leia a string da entrada padrão (teclado) e calcule o tamanho ao mesmo tempo
    int tamanho = 0;
    while (scanf("%c", &str[tamanho]) == 1 && str[tamanho] != '\n') {
        tamanho++;
    }

    // Imprima o tamanho da string
    printf("%d\n", tamanho);

    return 0;
}