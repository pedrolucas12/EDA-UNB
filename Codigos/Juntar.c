#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

void mescla_listas(celula *l1, celula *l2, celula *l3)
{
    celula *aux_1=l1->prox, *aux_2=l2->prox, *aux_3=l3;

    while(aux_1 != NULL && aux_2 != NULL){
        if(aux_1->dado < aux_2->dado){
            aux_3->prox = aux_1;
            aux_1 = aux_1->prox;
        }
        else{
            aux_3->prox = aux_2;
            aux_2 = aux_2->prox;
        }
        aux_3 = aux_3->prox;
    }
    if(aux_1 == NULL)
        aux_3->prox = aux_2;
    else
        aux_3->prox = aux_1;
}