//Pedro Lucas Figueiredo Santana
//202017049

//Lista 10 - EDA

//Dados de Degustação

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int tam;
    char caractere;
    int pos;
} Drink;

void merge(Drink *bebida, int i, int f, int m)
{
    Drink vetorAux[f - i + 1];
    int Ai = i, Bi = m + 1, AUXi = 0, p;

    while (Ai <= m && Bi <= f)
    {
        if (bebida[Ai].tam >= bebida[Bi].tam)
        {
            vetorAux[AUXi++] = bebida[Ai++];
        }
        else
        {
            vetorAux[AUXi++] = bebida[Bi++];
        }
    }

    while (Ai <= m)
    {
        vetorAux[AUXi++] = bebida[Ai++];
    }
    while (Bi <= f)
    {
        vetorAux[AUXi++] = bebida[Bi++];
    }

    int v = 0;
    for (p = i; p <= f; ++p)
    {
        bebida[p] = vetorAux[v++];
    }
}

void mergeSort(Drink *bebida, int i, int j)
{
    if (i >= j)
        return;

    int meio = i + (j - i) / 2;
    mergeSort(bebida, i, meio);
    mergeSort(bebida, meio + 1, j);
    merge(bebida, i, j, meio);
}

int main()
{
    Drink bebida[100000];
    int i = 0, sent = 0, j;
    char input[100001];
    scanf("%s", input);

    int z = strlen(input);
    for (i = 0; i < z; i++)
    {

        bebida[sent].caractere = input[i];
        bebida[sent].pos = i;

        while (input[i] == bebida[sent].caractere)
        {
            bebida[sent].tam++;
            i++;
        }
        i--;
        sent++;
    }

    mergeSort(&bebida[0], 0, sent);

    for (j = 0; j < sent; j++)
    {
        printf("%d %c %d\n", bebida[j].tam, bebida[j].caractere, bebida[j].pos);
    }

    return 0;
}