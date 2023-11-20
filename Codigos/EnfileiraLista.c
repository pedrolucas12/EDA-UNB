#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void enfileira (celula **f, int x)
{
    celula *nova = malloc(sizeof(celula));
    nova->prox = (*f)->prox;
    (*f)->prox = nova;
    (*f)->dado = x;
    (*f) = nova;
}


int desenfileira(celula *f, int *y)
{
    celula *celula_removida = f->prox;
    *y = celula_removida->dado;

    if (f->prox == f)
        return 0;
    else
        f->prox = celula_removida->prox;

    return 1;
}