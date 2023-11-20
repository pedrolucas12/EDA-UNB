#include <stdio.h>
#include <stdlib.h>

typedef struct celula 
{
    int dado;
    struct celula *prox;
} celula;

void empilha(celula *p, int x)
{
    celula *nova = malloc(sizeof(celula));

    nova->dado = x;
    nova->prox = p->prox;
    p->prox = nova;
}

int desempilha(celula *p, int *y)
{
    celula *lixo = p->prox;
    if(lixo == NULL)
        return 0;
    p->prox = lixo->prox;
    *y = lixo->dado;

    free(lixo);
    return 1;
}