#include <stdio.h>
#include <stdlib.h>

int menor_indice(int *v, int i, int j)
{
    //Chegou ao fim do vetor
    if(i == j)
        return i;

    //Encontra o menor indice recursivamente
    int menor = menor_indice(v, i + 1, j);

    //Faz o retorno do menor indice
    if (v[i] < v[menor])
        return i;
    else
        return menor;
}

void selection_sort_recursivo(int *v, int n, int i)
{
    //Chegou ao fim do vetor
    if(n == i)
        return;

    //Encontra o menor indice
    int menor = menor_indice(v, i, n - 1);

    //Checa se é o menor e troca
    if(i != menor)
    {
        int t = v[i];
        v[i] = v[menor];
        v[menor] = t;
    }

    //Faz chamada recursiva
    selection_sort_recursivo(v, n, i + 1);
}

//Função ordena chama a função selection_sort_recursivo
void ordena(int *v, int n)
{
    selection_sort_recursivo(v, n, 0);
}