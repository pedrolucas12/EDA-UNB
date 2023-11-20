#include <stdio.h>
#include <stdlib.h>

int min_apertar(int f, int s, int g, int u, int d)
{
    int *visitados = malloc(sizeof(int) * (f + 1));

    for (int i = 1; i <= f; i++)
        visitados[i] = 0;

    int *fila = malloc(sizeof(int) * (f + 1));
    int inicio = 0;
    int fim = 0;

    fila[fim++] = s;
    visitados[s] = 1;

    int apertos = 0;
    int quantidade = 1;

    while (inicio < fim)
    {
        int quantidade_nova = 0;

        for (int i = 0; i < quantidade; i++)
        {
            int atual = fila[inicio++];

            if (atual == g)
            {
                free(visitados);
                free(fila);
                return apertos;
            }

            int andar_acima = atual + u;
            int andar_abaixo = atual - d;

            if (andar_acima <= f && visitados[andar_acima] == 0)
            {
                visitados[andar_acima] = 1;
                fila[fim++] = andar_acima;
                quantidade_nova++;
            }

            if (andar_abaixo >= 1 && visitados[andar_abaixo] == 0)
            {
                visitados[andar_abaixo] = 1;
                fila[fim++] = andar_abaixo;
                quantidade_nova++;
            }

        }
        apertos++;
        quantidade = quantidade_nova;
    }

    free(visitados);
    free(fila);

    return -1;
}

int main()
{
    int f, s, g, u, d;

    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    int apertos = min_apertar(f, s, g, u, d);

    if(apertos  == -1)
        printf("use the stairs\n");

    else
        printf("%d\n", apertos);

    return 0;
}