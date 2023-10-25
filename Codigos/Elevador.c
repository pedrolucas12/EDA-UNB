#include <stdio.h>

int main() {
    int N, C, S, E;
    int ocupacao = 0;
    int excedeu = 0;
    
    // Lê o número de leituras e a capacidade máxima
    scanf("%d %d", &N, &C);
    
    for (int i = 0; i < N; i++) {
        // Lê o número de pessoas que saíram e entraram no andar
        scanf("%d %d", &S, &E);
        
        // Atualiza a ocupação do elevador
        ocupacao -= S;
        ocupacao += E;
        
        // Verifica se a capacidade máxima foi excedida
        if (ocupacao > C) {
            excedeu = 1;
        }
    }
    
    // Imprime o resultado
    if (excedeu) {
        printf("S\n");
    } else {
        printf("N\n");
    }
    
    return 0;
}
