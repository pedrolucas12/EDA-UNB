 #include <stdio.h>
 #include <stdlib.h>

 typedef struct celula {
   int dado;
   struct celula *prox;
 } celula;

 typedef struct fila {
  celula *inicio;
  celula *fim;
 } fila;

 fila *cria_fila() {
   fila *filaCriada = (fila*) malloc(sizeof(fila));
   filaCriada->inicio = NULL;
   filaCriada->fim = NULL;

   return filaCriada;
 }

 void *adiciona_carta_na_fila(fila *p, int carta){
   celula *novo = (celula*) malloc(sizeof(celula));
   novo->dado = carta;
   novo->prox = NULL;

   if(p->inicio == NULL){
     p->inicio = novo;
     p->fim = novo;
   } else {
     p->fim->prox = novo;
     p->fim = novo;
   }
 }
int getCarta(fila *p){
  int carta;
  celula *celCarta;

  celCarta = p->inicio;
  carta = celCarta->dado;

  p->inicio = celCarta->prox;

  if(p->inicio == NULL) {
    p->fim = NULL;
  }

  free(celCarta);
  return carta;
}

int vazio(fila *p){
  return p->inicio == NULL;
}

 int main() {
   int n, i, carta, cont = 0;
   fila *fila;

   fila = cria_fila();

   scanf("%d", &n);

   if (n) {
     cont = n;

     for(i=1; i<=n; i++) {
       adiciona_carta_na_fila(fila, i);
     }
   }

   printf("Cartas descartadas:");

   while(cont != 1) {
     printf(" %d", getCarta(fila));
     adiciona_carta_na_fila(fila, getCarta(fila));

     if(cont != 2) {
       printf(",");
     }

     cont--;
   }

   if(!vazio(fila)) {
     printf("\nCarta restante: %d\n", getCarta(fila));
  }

   return 0;
}