
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq;
    struct no *dir;
} no;

typedef no *raiz;

void em_ordem(raiz raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esq); // Visita a subarvore da esquerda
        printf("%d ", raiz->dado); // Visita a raiz
        em_ordem(raiz->dir); // Visita a subarvore da direita
    }
}