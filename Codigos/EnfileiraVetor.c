#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *v;  // Vetor que representa a fila
    int N;   // Tamanho da fila
    int inicio, fim;  // Indicadores de inicio e final da fila
} fila;

// Function to enqueue an element x in the circular queue f
int enfileira(fila *f, int x) {
    // Check if the queue is full
    if ((f->fim + 1) % f->N == f->inicio) {
        return 0;  // Queue is full
    }

    // Enqueue the element
    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->N;
    return 1;
}

// Function to dequeue an element from the circular queue
int desenfileira(fila *f, int *y) {
    // Check if the queue is empty
    if (f->inicio == f->fim) {
        return 0;  // Queue is empty
    }

    // Dequeue the element
    *y = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % f->N;
    return 1;
}
