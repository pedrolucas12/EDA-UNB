#include <stdio.h>
#include <stdlib.h>

int tam1, tam2;

void IniciaPagina(int *array);
void MovePagina(int *array, int numPage);
int VetorPagina(int *array, int numPage);


int main(int argc, char const *argv[]){
    
    int numPage, count = 0;

    scanf("%d", &tam1);
    scanf("%d", &tam2);

    int *fifo_array = malloc(tam1 * sizeof(int));

    IniciaPagina(fifo_array);

    while (tam2 >= 1) {

        scanf("%d", &numPage);
        if ( ! VetorPagina(fifo_array, numPage) ) {
            MovePagina(fifo_array, numPage);
            count++;
        }
        tam2--;
    }

    printf("%d\n", count);

    return 0;
}


void IniciaPagina(int *array) {

    for (int i=0; i<tam1; i++) {
        *(array + i) = -1;
    }

}

void MovePagina(int *array, int numPage){

    for (int i = 0; i < tam1-1; i++) {
        array[i] = array[i+1];
    }

    array[tam1-1] = numPage;

}

int VetorPagina(int *array, int numPage){

    int isElementPresent = 0;
     
    for (int i = 0; i < tam1; i++) {
        if (array[i] == numPage) {
            isElementPresent = 1;
            break;
        }
    }
    
    if (isElementPresent) return 1;
     
    return 0;
}

