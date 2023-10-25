#include <stdio.h>

int main() {
    int R, A, B, totalA, totalB, rodada = 1;
    
    while (1) {
        // Lê o número de rodadas
        scanf("%d", &R);
        
        if (R == 0) {
            break; // Fim da entrada
        }
        
        totalA = totalB = 0;
        
        // Processa cada rodada
        for (int i = 0; i < R; i++) {
            scanf("%d %d", &A, &B);
            totalA += A;
            totalB += B;
        }
        
        // Determina o vencedor da partida
        char vencedor[6];
        if (totalA > totalB) {
            sprintf(vencedor, "Aldo");
        } else {
            sprintf(vencedor, "Beto");
        }
        
        // Imprime o resultado
        printf("Teste %d\n%s\n\n", rodada, vencedor);
        rodada++;
    }
    
    return 0;
}
