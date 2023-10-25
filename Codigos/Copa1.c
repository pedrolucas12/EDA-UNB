//Pedro Lucas Figueiredo Santana
//202017049
//Lista 7 - EDA

//COPA - OITAVAS DE FINAL

#include <stdio.h>

int main()
{
    char times1[8], times2[4], times3[2], winner;
    int t1, t2, i;

    for (i = 0; i < 8; i++)
    {
        scanf("%d %d", &t1, &t2);
        if (t1 > t2)
        {
            times1[i] = (char)65 + (2 * i);
        }
        else
        {
            times1[i] = (char)65 + (2 * i) + 1;
        }
    }

    for (i = 0; i < 4; i++)
    {
        scanf("%d %d", &t1, &t2);
        if (t1 > t2)
        {
            times2[i] = times1[2 * i];
        }
        else
        {
            times2[i] = times1[2 * i + 1];
        }
    }

    for (i = 0; i < 2; i++)
    {
        scanf("%d %d", &t1, &t2);
        if (t1 > t2)
        {
            times3[i] = times2[2 * i];
        }
        else
        {
            times3[i] = times2[2 * i + 1];
        }
    }

    scanf("%d %d", &t1, &t2);
    if (t1 > t2)
    {
        winner = times3[0];
    }
    else
    {
        winner = times3[1];
    }
    printf("%c", winner);
    return 0;
}