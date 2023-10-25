#include <stdio.h>

int main(void)
{

    int num1,num2, e;
    
    printf("\n Escolha entre par(p) e impar(i), ou seja, digite '1' para par ou '2' para impar : ");
    scanf("%i", &e);

    printf("\nInforme o numero da Alice e o numero do Beto: ");
    scanf ("%i""%i",&num1,&num2);

    if (num1 % 2 == 0){
        printf ("\nO número %i da Alice é par e",num1);
    }else {
        printf("\nO número %i do Alice é ímpar",num1);
    }
    

    if (num2 % 2 == 0){
        printf("\nO número %i do Beto é par e",num2);
    }else {
        printf("\nO número %i do Beto é impar ",num2); 
    }

    if ( e == 1 ){
        if ( num1 % 2 == 0){ 
            printf( "\n Alice ganhou com o numero %i", num1);
        }else{
            printf( "\n Beto ganhou com o numero %i ", num2);
        }
    }
    
    if ( e == 2){
        if ( num1 % 2 == 0){
            printf( "\n Alice perdeu com o numero %i", num1);
        }else{
            printf( "\n Beto perdeu com o numero %i", num2);
        }
    }

    return 0;
}