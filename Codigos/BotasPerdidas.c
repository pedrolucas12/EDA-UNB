//Pedro Lucas Santana   
// 202017049
// Lista 12

//Botas perdidas

#include <stdio.h>
#include <stdlib.h>

typedef struct bota
{
    int e;
    int d;
} bota;

void solve(int n)
{
    int num, comb = 0, i;
    bota *bot = calloc(sizeof(bota), 66);

    while (n-- != 0)
    {
        char side;
        scanf("%d", &num);
        scanf("%c", &side);
        scanf("%c", &side);
        side == 'D' ? bot[num].d++ : bot[num].e++;
    }

    for (i = 0; i < 66; i++)
    {
        if (bot[i].d < bot[i].e)
            comb += bot[i].d;
        if (bot[i].d >= bot[i].e)
            comb += bot[i].e;
    }

    printf("%d\n", comb);
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
        solve(n);
    return 0;
}