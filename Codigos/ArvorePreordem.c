#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq;
    struct no *dir;
} no;

typedef no *raiz;

void pre_ordem(raiz raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado); // Visita a raiz
        pre_ordem(raiz->esq); // Visita a subarvore da esquerda
        pre_ordem(raiz->dir); // Visita a subarvore da direita
    }
}