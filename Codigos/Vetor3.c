#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int pares[n], impares[n];
    int qtdePares = 0, qtdeImpares = 0;
    
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        if (num % 2 == 0) {
            pares[qtdePares++] = num;
        } else {
            impares[qtdeImpares++] = num;
        }
    }
    
    // Imprime os números pares
    for (int i = 0; i < qtdePares; i++) {
        printf("%d ", pares[i]);
    }
    printf("\n");
    
    // Imprime os números ímpares
    for (int i = 0; i < qtdeImpares; i++) {
        printf("%d ", impares[i]);
    }
    printf("\n");
    
    return 0;
}
