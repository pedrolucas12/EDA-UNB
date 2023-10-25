#include <stdio.h>

int main() {
    int jogadorA, jogadorB, jogadorC;
    
    // Lê as escolhas dos jogadores A, B e C
    scanf("%d %d %d", &jogadorA, &jogadorB, &jogadorC);
    
    // Verifica quem ganhou ou se houve empate
    if ((jogadorA != jogadorB) && (jogadorA != jogadorC)) {
        printf("A\n");
    } else if ((jogadorB != jogadorA) && (jogadorB != jogadorC)) {
        printf("B\n");
    } else if ((jogadorC != jogadorA) && (jogadorC != jogadorB)) {
        printf("C\n");
    } else {
        printf("empate\n");
    }
    
    return 0;
}