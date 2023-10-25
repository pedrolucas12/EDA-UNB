//Pedro Lucas Figueiredo Santana
//202017049

//Lista 10 - EDA

//Merge Sort

#include <stdio.h>

void merge(int *vetor, int i, int final, int medio)
{
    int vetorAux[final - i + 1];
    int Ai = i, Bi = medio + 1, AUXi = 0, p;

    while (Ai <= medio && Bi <= final)
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

    while (Ai <= medio)
    {
        vetorAux[AUXi++] = vetor[Ai++];
    }
    while (Bi <= final)
    {
        vetorAux[AUXi++] = vetor[Bi++];
    }

    int v = 0;
    for (p = i; p <= final; ++p)
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
    int i, len, k;
    scanf("%d", &len);
    int vetor[len];

    for (i = 0; i < len; i++)
    {
        scanf("%d", &vetor[i]);
    }

    mergeSort(&vetor[0], 0, len - 1);

    printf("%d", vetor[0]);
    for (k = 1; k < len; k++)
    {
        printf(" %d", vetor[k]);
    }
    printf("\n");

    return 0;
}