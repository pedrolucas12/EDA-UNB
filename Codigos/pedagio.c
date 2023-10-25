#include <stdio.h>

int main() {
    int L, D, K, P;
    
    // Lê os valores de entrada
    scanf("%d %d", &L, &D);
    scanf("%d %d", &K, &P);
    
    // Calcula o número de pedágios
    int num_pedagios = L / D;
    
    // Calcula o custo dos pedágios
    int custo_pedagios = num_pedagios * P;
    
    // Calcula o custo da gasolina
    int custo_gasolina = L * K;
    
    // Calcula o custo total da viagem
    int custo_total = custo_pedagios + custo_gasolina;
    
    // Imprime o custo total
    printf("%d\n", custo_total);
    
    return 0;
}
