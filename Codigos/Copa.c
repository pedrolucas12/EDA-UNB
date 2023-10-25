//Pedro Lucas Figueiredo Santana
//202017049
//Lista 3 - EDA

//Ideia para resolver o problema COPA
//Muito Completa

//Copa

#include <stdio.h>

int main(void){

    int T, N;

    printf("Digite o numero de times envolvidos na sua COPA: ");
    scanf("%i", &T);

    printf("Digite o numero de jogos que cada time ira jogar: ");
    scanf("%i", &N);

    int matriz[T][N];

    //nome do time
    char nome[T][50];


    for (int i = 0; i < T; i++){
        
    
        printf("Digite o nome do time %i: ", i+1);
        scanf("%s", nome[i]);
                printf("\n");

        for (int j = 0; j < N; j++){
            printf("Digite o numero de gols do time %i no jogo %i: ", i+1, j+1);
            scanf("%i", &matriz[i][j]);
                    printf("\n");

        }
    }

    for (int i = 0; i < T; i++){
        for (int j = 0; j < N; j++){
            printf("O time %i fez %i gols no jogo %i ", i+1, matriz[i][j], j+1);
                    printf("\n");


        }

    }
    
    for (int i = 0; i < T; i++){
        int soma = 0;
        for (int j = 0; j < N; j++){
            soma = soma + matriz[i][j];
        }
        printf("O time %s fez %i gols no total ", nome[i], soma);
                printf("\n");

        printf("O time %i fez %i gols no total ", i+1, soma);
    }

    for (int i = 0; i < T; i++){
        int soma = 0;
        for (int j = 0; j < N; j++){
            soma = soma + matriz[i][j];
        }
        if (soma > 0){
            printf("O time %s esta classificado ", nome[i]);
        printf("\n");

            printf("O time %i ganhou \n", i+1);
        }else{
            printf("O time %s esta eliminado ", nome[i]);
        printf("\n");

            printf("O time %i perdeu \n", i+1);
        }
    }

    return 0;

}