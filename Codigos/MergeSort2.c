//Pedro Lucas Figueiredo Santana
//202017049

//Lista 10 - EDA

//Merge Sort 2 

#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int i, int f, int meia)
{
    int vetorAux[f - i + 1];
    int Ai = i, Bi = meia + 1, AUXi = 0, p;

    while (Ai <= meia && Bi <= f)
    {
        if (vetor[Ai] <= vetor[Bi])
        {
            vetorAux[AUXi++] = vetor[Ai++];
        }
        else
        {
            vetorAux[AUXi++] = vetor[Bi++];
        }
    }

    while (Ai <= meia)
    {
        vetorAux[AUXi++] = vetor[Ai++];
    }
    while (Bi <= f)
    {
        vetorAux[AUXi++] = vetor[Bi++];
    }

    int v = 0;
    for (p = i; p <= f; ++p)
    {
        vetor[p] = vetorAux[v++];
    }
}

void mergeSort(int *vetor, int i, int j)
{
    if (i >= j)
        return;

    int metade = i + (j - i) / 2;
    mergeSort(vetor, i, metade);
    mergeSort(vetor, metade + 1, j);
    merge(vetor, i, j, metade);
}

int main()
{
    int vetor[100000 + 66], i = 0, k;

    while (scanf("%d", &vetor[i++]) != EOF)
    {
    }

    --i;

    mergeSort(&vetor[0], 0, i - 1);

    printf("%d", vetor[0]);
    for (k = 1; k < i; ++k)
    {
        printf(" %d", vetor[k]);
    }
    printf("\n");
    return 0;
}