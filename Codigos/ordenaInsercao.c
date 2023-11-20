#include <stdio.h>
#include <stdlib.h>

// void insertion_sort(int *v, int l, int r)
// {
//     for (int i = l + 1; i < r; i++)
//     {
//         for (int j = i; j > l && v[j] < v[j - 1]; j--)
//         {
//             int t = v[j];
//             v[j] = v[j - 1];
//             v[j - 1] = t;
//         }
//     }
// }

void shell_sort(int *v, int l, int r)
{
    int h = 1;

    while (h < (r - l + 1) / 3)
        h = 3 * h + 1;

    while (h >= 1)
        for (int i = l + h; i <= r; i++)
        {
            for (int j = i; j >= i + h && v[j] < v[j - h]; j -= h)
            {
                int t = v[j];
                v[j] = v[j - h];
                v[j - h] = t;
            }
            h /= 3;
        }
}

int main()
{
    int *vetor = malloc(50001 * sizeof(int));
    int numero;
    int i;

    for (i = 0; scanf("%d", &numero) != EOF; i++)
        vetor[i] = numero;

    shell_sort(vetor, 0, i);

    printf("%d", vetor[0]);

    for (int j = 1; j < i; j++)
        printf(" %d", vetor[j]);

    printf("\n");

    return 0;
}