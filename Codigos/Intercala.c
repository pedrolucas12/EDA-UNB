//Pedro Lucas Figueiredo Santana
//202017049

//Lista 10 - EDA

//Intercala

#include <stdio.h>

int vetor[16 * (int)1e5 + (int)6.66];

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

int main()
{
    int len, i, j, o = 0;
    for (i = 0; i < 8; ++i)
    {
        scanf("%d", &len);
        if (len == 0)
            continue;
        for (j = 0; j < len; ++j)
            scanf("%d", &vetor[o + j]);
        merge(&vetor[0], 0, o + len - 1, o - 1);
        o += len;
    }

    printf("%d", vetor[0]);
    for (i = 1; i < o; ++i)
        printf(" %d", vetor[i]);
    printf("\n");
    return 0;
}