#include <stdio.h>
#include <stdlib.h>

// estrutura da lista encadeada simplesmente encadeada.
typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

// função imprime interativa da lista encadeada com nó cabeça.
void *imprime (celula *le) {
  celula *p = le -> prox;
  while (p != NULL){
    printf ("%d -> ", p -> dado);
    p = p -> prox;
  }
  printf("NULL\n");
}

// função imprime recursiva da lista encadeada com nó cabeça.
void *imprime_rec (celula *le) {
  if (le -> prox == NULL){
  printf("NULL\n");
  }
  else{
    printf ("%d ->", le -> prox -> dado);
    imprime_rec (le -> prox);
  }
}
/*
int main () {
  int x, y;
  celula *p, *novo1, *novo2, *novo3, *novo4;

  p = malloc(sizeof(celula));

  novo1 = malloc(sizeof(celula));
  novo2 = malloc(sizeof(celula));
  novo3 = malloc(sizeof(celula));
  novo4 = malloc(sizeof(celula));

  novo1 -> dado = 1;
  novo2 -> dado = 1;
  novo3 -> dado = 2;
  novo4 -> dado = 3;
  novo4 -> prox = NULL;
  novo3 -> prox = novo4;
  novo2 -> prox = novo3;
  novo1 -> prox = novo2;
  p -> prox = novo2;


  imprime(p );
  imprime_rec(p );

  free(novo1);
  free(novo2);
  free(novo3);
  free(novo4);

  free(p);
  return 0;
}
*/