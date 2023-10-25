#include <stdio.h>
#include <stdlib.h>

int tam1, tam2;

void IniciaPagina(int *array);
void InserePagina(int *array, int *CONTA_PAG, int NPagina);
int PaginaVetor(int *array, int *CONTA_PAG, int NPagina);
void PaginaMove(int *array, int *CONTA_PAG, int NPagina);


int main(int argc, char const *argv[]){
    
    int NPagina, count = 0, i=0;

    scanf("%d", &tam1);
    scanf("%d", &tam2);

    int *LRU_VETOR = malloc(tam1 * sizeof(int));
    int *CONTA_PAG = calloc(tam1, sizeof(int));

    IniciaPagina(LRU_VETOR);

    while ( i < tam2) {

        scanf("%d", &NPagina);

        if ( !PaginaVetor(LRU_VETOR, CONTA_PAG, NPagina) && i < tam1 ){
            PaginaMove(LRU_VETOR, CONTA_PAG,NPagina);
            count++;
            i++;
            continue;
        }

        if ( !PaginaVetor(LRU_VETOR, CONTA_PAG, NPagina) ) {
            InserePagina(LRU_VETOR, CONTA_PAG,NPagina);
            count++;
        }

        i++;
    }

    printf("%d\n", count);
    return 0;
}



int PaginaVetor(int *LRU_VETOR, int *CONTA_PAG, int NPagina){

    int isElementPresent = 0;
     
    for (int i = 0; i < tam1; i++) {
        if (LRU_VETOR[i] == NPagina) {
            isElementPresent = 1;
            CONTA_PAG[i] = 0;
        } else
            CONTA_PAG[i]++;
    }
    
    if (isElementPresent) return 1;
     
    return 0;
}


void IniciaPagina(int *array) {
    for (int i=0; i<tam1; i++) {
        *(array + i) = -1;
    }
}

void InserePagina(int *array, int *CONTA_PAG, int NPagina){

    int lru_pageCount = CONTA_PAG[0], index = 0;

    for (int i=1; i<tam1; i++){
        if (lru_pageCount < CONTA_PAG[i]){
            lru_pageCount = CONTA_PAG[i];
            index = i;
        } 
    } 

    for (int i=0; i<tam1; i++){
        if (i != index)
            CONTA_PAG[i]++;
    }

    array[index] = NPagina;
    CONTA_PAG[index] = 0;

}

void PaginaMove(int *array, int *CONTA_PAG, int NPagina){

    for (int i = 0; i < tam1-1; i++) {
        array[i] = array[i+1];
        CONTA_PAG[i] = CONTA_PAG[i+1] + 1;
    }

    array[tam1-1] = NPagina;
    CONTA_PAG[tam1-1] = 0;

}

