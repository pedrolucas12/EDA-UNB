//Pedro Lucas Figueiredo Santana
//202017049

//Lista 10 - EDA

//Numero Proibido

#include <stdio.h>

void merge(int *vetor, int i, int final, int meia)
{
    int vetorAux[final - i + 1];
    int Ai = i, Bi = meia + 1, AUXi = 0, p;

    while (Ai <= meia && Bi <= final)
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

int buscaBin(int *vetor, int i, int final, int busca)
{
    while (i + 1 < final)
    {
        int metade = (final + i) / 2;
        if (busca >= vetor[metade])
            i = metade;
        if (busca < vetor[metade])
            final = metade;
    }
    return vetor[i] == busca ? i : -1;
}

int main()
{
    int *vetor, nums, input, i;
    scanf("%d", &nums);
    vetor = malloc(nums * sizeof(int));

    for (i = 0; i < nums; i++)
        scanf("%d", &vetor[i]);

    mergeSort(vetor, 0, nums - 1);

    while (scanf("%d", &input) != EOF)
        buscaBin(vetor, 0, nums - 1, input) == -1 ? printf("nao\n") : printf("sim\n");

    return 0;
}