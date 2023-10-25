#include <stdio.h>
#include <stdlib.h>

int main() {
    int Xm, Ym, Xr, Yr;
    
    // Lê as coordenadas de Maria e da reunião
    scanf("%d %d %d %d", &Xm, &Ym, &Xr, &Yr);
    
    // Calcula a distância de Manhattan
    int distancia = abs(Xr - Xm) + abs(Yr - Ym);
    
    // Imprime a distância calculada
    printf("%d\n", distancia);
    
    return 0;
}
