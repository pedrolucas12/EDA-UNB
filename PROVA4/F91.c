#include <stdio.h>

int f91(int N) {
    if (N >= 101) { // N > 100
        return N - 10; // f91(N) = N - 10
    } else { // N <= 100
        return f91(f91(N + 11));
    }
}
int main() {
    int N;
    while (1) { // Loop infinito
        scanf("%d", &N);
        if (N == 0) { // Se N = 0
            break;  // Fim da entrada
        }
        int M = f91(N); // M = f91(N)
        printf("f91(%d) = %d\n", N, M); 
    }
    return 0;
}
