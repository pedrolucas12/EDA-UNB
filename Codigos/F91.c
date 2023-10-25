#include <stdio.h>

int f91(int N) {
    if (N >= 101) {
        return N - 10;
    } else {
        return f91(f91(N + 11));
    }
}

int main() {
    int N;

    while (1) {
        scanf("%d", &N);
        if (N == 0) {
            break;  // Fim da entrada
        }

        int M = f91(N);
        printf("f91(%d) = %d\n", N, M);
    }

    return 0;
}
