#include <stdio.h>

int main() {
    char c;
    char reversedStr[1000]; // Array para armazenar a string reversa
    int tamanho = 0;

    // Leia a string caractere por caractere e calcule o tamanho ao mesmo tempo
    while (scanf("%c", &c) == 1 && c != '\n') {
        reversedStr[tamanho] = c;
        tamanho++;
    }

    // Imprima a string ao contrário
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%c", reversedStr[i]);
    }

    printf("\n");

    return 0;
}
