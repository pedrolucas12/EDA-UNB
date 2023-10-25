#include <stdio.h>

int main() {
    int A, B, C, X, Y, Z;
    
    // Lê as dimensões dos contêineres e do navio
    scanf("%d %d %d", &A, &B, &C);
    scanf("%d %d %d", &X, &Y, &Z);
    
    // Calcula o número máximo de contêineres em cada dimensão
    int max_containers_x = X / A;
    int max_containers_y = Y / B;
    int max_containers_z = Z / C;
    
    // Calcula a quantidade máxima de contêineres que podem ser carregados
    int max_containers = max_containers_x * max_containers_y * max_containers_z;
    
    // Imprime a quantidade máxima de contêineres
    printf("%d\n", max_containers);
    
    return 0;
}
