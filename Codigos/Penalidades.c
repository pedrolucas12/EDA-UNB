//Pedro Lucas Figueiredo Santana
//202017049
//Lista 8 - EDA

//COPA - PENALIDADES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{

    char *timeFirst, *timeSecund;
    int rodadas, i, equal = 0, linha = 0, primeiroTime = 0, segundoTime = 0, v1, v2;

    scanf("%d", &rodadas);
    timeFirst = malloc((rodadas * sizeof(char)) + 1);
    timeSecund = malloc((rodadas * sizeof(char)) + 1);
    v1 = rodadas;
    v2 = rodadas;
    scanf(" %s", timeFirst);
    scanf(" %s", timeSecund);

    for (i = 0; i < rodadas; i++)
    {
        linha++;
        if (timeFirst[i] == 'o')
        {
            primeiroTime++;
        }
        v1--;
        if (primeiroTime + v1 < segundoTime || segundoTime + v2 < primeiroTime)
        {
            break;
        }

        linha++;
        if (timeSecund[i] == 'o')
        {
            segundoTime++;
        }
        v2--;
        if (primeiroTime + v1 < segundoTime || segundoTime + v2 < primeiroTime)
        {
            break;
        }

    }


    if (primeiroTime == segundoTime)
    {
        printf("Empate\n");
    }
    else
    {
        printf("%d\n", linha);

    }

    return 0;
}