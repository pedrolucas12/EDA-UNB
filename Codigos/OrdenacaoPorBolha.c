//Pedro Lucas Figueiredo Santana    
//202017049
//Lista 9 - EDA

//BubbleSort

#include "stdio.h"
#define EXC(A, B) \
    int tt = A;   \
    A = B;        \
    B = tt

int main()
{
    int vetor[1000], i = 0, j, k, l;

    while (scanf("%d", &vetor[i]) != EOF)
        i++;

    for (j = 0; j < i; j++)
    {
        for (k = j + 1; k < i; k++)
        {
            if (vetor[j] > vetor[k])
            {
                EXC(vetor[k], vetor[j]);
            }
        }
    }

    for (l = 0; l < i; l++)
    {
        printf("%d ", vetor[l]);
    }
}