#include <stdio.h>

int main() {
    int m;
    int teste = 1;
    
    while (1) {
        scanf("%d", &m);
        if (m == 0) break;
        
        int resultado;
        scanf("%d", &resultado);
        
        char operador;
        int num;
        
        for (int i = 1; i < m; i++) {
            scanf(" %c %d", &operador, &num);
            
            if (operador == '+') {
                resultado += num;
            } else {
                resultado -= num;
            }
        }
        
        printf("Teste %d\n", teste++);
        printf("%d\n\n", resultado);
    }
    
    return 0;
}