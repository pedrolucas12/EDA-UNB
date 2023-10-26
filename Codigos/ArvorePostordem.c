#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq;
    struct no *dir;
} no;

typedef no *raiz;

void pos_ordem(raiz raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq); // Visita a subarvore da esquerda
        pos_ordem(raiz->dir); // Visita a subarvore da direita
        printf("%d ", raiz->dado); // Visita a raiz
    }
}