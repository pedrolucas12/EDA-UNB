#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;
/*
void insere (celula *p, int x) {
  celula *novo = malloc (sizeof(celula));
  if (novo == NULL)
  exit(EXIT_FAILURE);
  novo -> dado = x;
  novo -> prox = p -> prox;
  p -> prox = novo;
}*/

void insere_inicio (celula *p, int x) {
  celula *novo = malloc (sizeof(celula));
  if (novo == NULL)
  exit(EXIT_FAILURE);
  novo -> dado = x;
  novo -> prox = p -> prox;
  p -> prox = novo;
}

void insere_antes (celula *p, int x, int y) {
  celula *novo = malloc (sizeof(celula));
  celula *percor;
  if (novo == NULL)
  exit(EXIT_FAILURE);
  novo -> dado = x;
  for (percor = p; percor -> prox != NULL && percor -> prox -> dado != y; percor = percor -> prox);
    novo -> prox = percor -> prox;
    percor -> prox = novo;

}
/*
void *imprime_rec (celula *le) {
  if (le -> prox == NULL){
  printf("NULL\n");
  }
  else{
    printf ("%d - > ", le -> prox -> dado);
    imprime_rec (le -> prox);
  }
}

int main () {
  int dado;
  scanf("%d",&dado);

  celula *p = malloc (sizeof(celula));
  celula *x = malloc (sizeof(celula));

  p -> prox = x;
  x -> prox = NULL;

  x -> dado = 2;

  imprime_rec(p);

  insere_inicio(p,dado);
  imprime_rec(p);
  insere_antes(p, 23, 2);
  imprime_rec(p);
  free(p);

  return 0;
}
*/