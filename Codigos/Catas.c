#include <stdio.h>

int main() {
    int cartas[5];
    
    // Lê as cinco cartas da sequência
    for (int i = 0; i < 5; i++) {
        scanf("%d", &cartas[i]);
    }
    
    int crescente = 1;
    int decrescente = 1;
    
    // Verifica se a sequência é crescente
    for (int i = 0; i < 4; i++) {
        if (cartas[i] >= cartas[i + 1]) {
            crescente = 0;
            break;
        }
    }
    
    // Verifica se a sequência é decrescente
    for (int i = 0; i < 4; i++) {
        if (cartas[i] <= cartas[i + 1]) {
            decrescente = 0;
            break;
        }
    }
    
    // Verifica e imprime o resultado
    if (crescente) {
        printf("C\n");
    } else if (decrescente) {
        printf("D\n");
    } else {
        printf("N\n");
    }
    
    return 0;
}
