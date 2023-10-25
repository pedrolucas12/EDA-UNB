//Pedro Lucas Figueiredo Santana
//202017049
//Lista 9 - EDA

//SelectionSort

#include "stdio.h"
#define EXC(A, B) \
    int tt = A;   \
    A = B;        \
    B = tt

int main()
{
    int vetor[1000], i = 0, x, y, l, minimo;

    while (scanf("%d", &vetor[i]) != EOF)
        i++;

    for (x = 0; x < i; x++)
    {
        minimo = x;
        for (y = x + 1; y < i; y++)
        {
            if (vetor[y] < vetor[minimo])
            {
                minimo = y;
            }
        }
        EXC(vetor[x], vetor[minimo]);
    }

    for (l = 0; l < i; l++)
    {
        printf("%d ", vetor[l]);
    }
}