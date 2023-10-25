//Pedro Lucas Figueiredo Santana
//202017049
//Lista 9 - EDA

//Pesquisa de Instrução


#include <stdio.h>
#define EXC(A, B)        \
    Instructions tt = A; \
    A = B;               \
    B = tt

typedef struct
{
    char name[16];
    int code;
} Instructions;

int binarySearch(Instructions *vetor, int inicio, int final, int procura)
{
    while (inicio + 1 < final)
    {
        int middle = (inicio + final) / 2;
        if (vetor[middle].code <= procura)
            inicio = middle;
        if (vetor[middle].code > procura)
            final = middle;
    }
    return vetor[inicio].code == procura ? inicio : -1;
}

void selectionSort(Instructions *vetor, int i)
{
    int x, minimo, k;

    for (x = 0; x < i; x++)
    {
        minimo = x;
        for (k = x + 1; k < i; k++)
        {
            if (vetor[k].code < vetor[minimo].code)
            {
                minimo = k;
            }
        }
        EXC(vetor[x], vetor[minimo]);
    }
}

int main()
{
    int num, repeticao1, entrada;
    scanf("%d", &num);
    Instructions rel[num];

    for (repeticao1 = 0; repeticao1 < num; repeticao1++)
    {
        scanf("%d %s", &rel[repeticao1].code, rel[repeticao1].name);
    }

    selectionSort(&rel, num);

    while (scanf("%d", &entrada) != EOF)
    {
        int returned = binarySearch(rel, 0, num, entrada);
        printf("%s\n", returned == -1 ? "undefined" : rel[returned].name);
    }

    return 0;
}