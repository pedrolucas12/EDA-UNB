#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *v, int l, int r)
{
    int flag = 1;
    for (; l < r && flag; r--)
    {
        flag = 0;
        for (int j = l; j < r; j++)
            if (v[j + 1] < v[j])
            {
                int t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
                flag = 1;
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

    bubble_sort(vetor, 0, i);

    printf("%d", vetor[1]);

    for (int j = 2; vetor[j] != '\0'; j++)
        printf(" %d", vetor[j]);

    printf("\n"); 

    return 0;
}