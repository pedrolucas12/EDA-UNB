//Pedro Lucas Figueiredo Santana
//202017049

//Lista 10 - EDA

//Numero Proibido

#include <stdio.h>

void merge(int *vetor, int i, int final, int meia)
{
    int vetorAux[final - i + 1];
    int Ai = i, Bi = meia + 1, AUXi = 0, p;
    while (Ai <= meia && Bi <= final) //enquanto os dois vetores não estiverem vazios
    {
        if (vetor[Ai] <= vetor[Bi]) //se o valor do vetor A for menor que o valor do vetor B
        {
            vetorAux[AUXi++] = vetor[Ai++]; //o valor do vetor A é colocado no vetor auxiliar
        }
        else 
        {
            vetorAux[AUXi++] = vetor[Bi++];
        }
    }
    while (Ai <= meia) //enquanto o vetor A não estiver vazio
    {
        vetorAux[AUXi++] = vetor[Ai++]; //o valor do vetor A é colocado no vetor auxiliar
    }
    while (Bi <= final)
    {
        vetorAux[AUXi++] = vetor[Bi++];
    }
    int v = 0;
    for (p = i; p <= final; ++p) //o vetor auxiliar é colocado no vetor original
    {
        vetor[p] = vetorAux[v++]; //o vetor auxiliar é colocado no vetor original
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
    while (i + 1 < final) //enquanto o inicio for menor que o final
    {
        int metade = (final + i) / 2;
        if (busca >= vetor[metade]) //se o valor buscado for maior ou igual ao valor da metade
            i = metade;
        if (busca < vetor[metade])
            final = metade;
    }
    return vetor[i] == busca ? i : -1; //se o valor buscado for igual ao valor do vetor na posição i, retorna i, senão retorna -1
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