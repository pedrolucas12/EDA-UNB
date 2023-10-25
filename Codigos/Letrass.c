#include <stdio.h>
#include <string.h>

int main() {
    char letra;
    char texto[1000];

    // Lê a letra de interesse
    scanf("%c", &letra);
    getchar(); // Lê o caractere de quebra de linha

    // Lê o texto
    fgets(texto, sizeof(texto), stdin);

    // Remove a quebra de linha do final do texto, se houver
    int len = strlen(texto);
    if (texto[len - 1] == '\n') {
        texto[len - 1] = '\0';
    }

    int palavrasComLetra = 0;
    int totalPalavras = 0;

    // Tokeniza o texto em palavras
    char *token = strtok(texto, " ");
    while (token != NULL) {
        totalPalavras++;

        // Verifica se a letra está na palavra (ignorando maiúsculas/minúsculas)
        char *ptr = token;
        while (*ptr) {
            if (*ptr == letra || *ptr == letra + 32 || *ptr == letra - 32) {
                palavrasComLetra++;
                break;
            }
            ptr++;
        }

        token = strtok(NULL, " ");
    }

    // Calcula a porcentagem
    float porcentagem = (float) palavrasComLetra / totalPalavras * 100;

    // Imprime o resultado com uma casa decimal
    printf("%.1f\n", porcentagem);

    return 0;
}
