#include <stdio.h>
#include <stdlib.h>

int n =0;

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

typedef struct pilha{
    celula *topo;
}pilha;


void criarpilha(pilha *p){
    p->topo = NULL;

}

void inserir( pilha *p, int x){
    celula *new;
    new = (celula*)malloc(sizeof(celula));
    new->prox = p->topo;
    p->topo = new;
    new->dado = x;
}

void mover(pilha *p){
    celula *new;
    celula *fim;

    fim = p->topo;
    new = p->topo;
    if(fim->prox){
        while(fim->prox){
            fim = fim->prox;
        }
        p->topo = p->topo->prox;
        new->prox = fim->prox;
        fim->prox = new;
    }
}


void retirar( pilha *p, int *descarta){
    celula *new;
    if(!p->topo->prox){
        return;
    }do{
        new = p->topo;
        descarta[n++] = new->dado;
        p->topo = p->topo->prox;
        free(new);
        mover(p);
    }while(p->topo->prox);
}


int main(){
    int entrada;
    int *descarta;
    
    struct pilha p;
    
    criarpilha(&p);
    
    scanf("%d",&entrada);
    descarta = malloc(entrada*sizeof(int));

    for(int i = entrada; i>0;i--){
        inserir(&p,i);
    }
    retirar(&p,descarta);
    printf("Cartas descartadas:");
    for(int i=0; i<n; i++){
        printf(" %d", descarta[i]);
        if(i !=n-1){
            printf(",");
        }
    }
    printf("\n");
    printf("Carta restante: %d\n", p.topo->dado);
    free(descarta);




    return 0;
}