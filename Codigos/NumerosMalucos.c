//Pedro Lucas Figueiredo Santana
//202017049

//Lista 10 - EDA

//Numeros Malucos

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

int searchNumber(int *vetor, int procura, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (vetor[i] == procura)
            return i;
    }
    return -1;
}

void removeRep(int *vetor, int f, int i)
{
    int vetAux[f - i + 1], p, auxI = 0, h, k;

    for (p = 0; p <= f; p++)
    {
        if (p == 0)
            vetAux[auxI++] = vetor[p];

        if (searchNumber(vetAux, vetor[p], auxI) == -1)
            vetAux[auxI++] = vetor[p];
    }

    for (h = 0; h < f - 1; h++)
    {
        vetor[h] = vetAux[h];
    }
}

int main()
{
    int i, tamanho;
    int *vetor;

    scanf("%d", &tamanho);
    vetor = (int *)malloc(tamanho * sizeof(int));

    for (i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    mergeSort(vetor, 0, tamanho - 1);
    removeRep(vetor, tamanho - 1, 0);

    return 0;
}