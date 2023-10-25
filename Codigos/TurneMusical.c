//Pedro Lucas Santana
//202017049

//Turne do Leo e Henrique

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NO{
    char *city;
    struct NO *prox;
}NO;


NO *FILA(){
    NO *p;
    p = malloc(sizeof(NO));
    p->prox = NULL;
    return p;
}

void ENFILA(NO *p){
    NO *novo;
    novo = malloc(sizeof(NO));
    p->prox = novo;
    novo->prox = NULL;
    novo->city = malloc(sizeof(char)*27);    
}

NO *CIDADE(NO *ptr){
    char nomeCidade[27];
    if(scanf(" %s", nomeCidade) != EOF){
        ENFILA(ptr);
        strcpy(ptr->prox->city, nomeCidade);
        CIDADE(ptr->prox);        
    }
    else{
        return ptr;
    }
}

NO *JOGAPARATRAS(NO *p, NO *u){

    if(p->prox->prox == NULL){
        return u;
    }
    else{
        u->prox = p->prox;
        p->prox = p->prox->prox;
        u->prox->prox = NULL; 
        return u->prox;
    }

}

void CHANGE(NO *mostra, NO *ultimo){

    printf("%s\n", mostra->city);
    if(mostra->prox == NULL){ return; }
    if((int)mostra->prox->city[0] + 32 == (int)mostra->city[strlen(mostra->city) - 1]){ 
        ultimo = JOGAPARATRAS(mostra, ultimo);
    }
    CHANGE(mostra->prox, ultimo); 
}

int main(){
    NO *mostra, *ultimo;
    mostra = FILA();
    ultimo = CIDADE(mostra);
    CHANGE(mostra->prox, ultimo);

    return 0;
}