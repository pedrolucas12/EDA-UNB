#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *v, int l, int r)
{
    int menor;
    for (int i = l; i < r; i++)
    {
        menor = i;

        for (int j = i + 1; j < r; j++)
            if (v[menor] > v[j])
                menor = j;

        if (i != menor)
        {
            int t = v[i];
            v[i] = v[menor];
            v[menor] = t;
        }
    }
}

int main()
{
    int *vetor = malloc(1001 * sizeof(int));
    int numero;
    int i;

    for (i = 0; scanf("%d", &numero) != EOF; i++)
        vetor[i] = numero;

    selection_sort(vetor, 0, i);

    printf("%d", vetor[0]);

    for (int j = 1; vetor[j] != '\0'; j++)
        printf(" %d", vetor[j]);

    printf("\n");

    return 0;
}