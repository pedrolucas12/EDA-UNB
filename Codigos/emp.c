#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void empilha(celula *p, int x) {
    celula *novaCelula = (celula *)malloc(sizeof(celula));
    novaCelula->dado = x;
    novaCelula->prox = p->prox;
    p->prox = novaCelula;
}

int desempilha(celula *p, int *y) {
    if (p->prox == NULL) {
        // Pilha vazia, não é possível desempilhar
        return 0;
    }

    celula *topo = p->prox;
    *y = topo->dado;
    p->prox = topo->prox;
    free(topo);

    return 1;
}

int main() {
    celula *pilha = (celula *)malloc(sizeof(celula));

    pilha->prox = NULL;

    empilha(pilha, 1);
    empilha(pilha, 2);
    empilha(pilha, 3);

    int elemento;
    while (desempilha(pilha, &elemento)) {
        printf("Elemento desempilhado: %d\n", elemento);
    }

    free(pilha);

    

    return 0;
}
