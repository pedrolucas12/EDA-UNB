//Pedro Lucas Santana   
//202017049

//Desfazer no editor

/*
Você foi contratado para trabalhar na Fábrica de Geração de Aplicativos (FGA). Todos na FGA estão focados no
desenvolvimento de um novo editor de texto, versátil, que funciona como IDE, editor de linguagens de marcação e também
um editor de texto.
O gerente de projetos te deu a tarefa de desenvolver a Estrutura de Desfazer do Aplicativo (EDA). O objetivo da EDA é
prover, para o editor, o famoso ctrl+z, ou seja, a funcionalidade de desfazer certas ações.
A demanda é a seguinte: o editor de texto, de tempos em tempos, enviará ao seu módulo EDA o conteúdo que havia em
determinado trecho do texto antes das alterações mais recentes do usuário. Caso o usuário deseje desfazer alguma ação, o
editor enviará ao seu aplicativo o comando desfazer, e você deve devolver a alteração mais recente do usuário que você
tem armazenada.
Nessa primeira versão do módulo EDA, não há limite para a quantidade de desfazer que o usuário pode solicitar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO{
  char *WORD;
  struct NO *NEXT;
}NO;

NO *PILHA(){
 NO *TOPO;
 TOPO = malloc (sizeof(NO));
 TOPO->NEXT = NULL;
 return TOPO;
}

int EMPILHA(NO *TOPO, char *WORD){
  NO *NEW = malloc(sizeof(NO));

  if(NEW == NULL) return 1;

  NEW->WORD = WORD;
  NEW->NEXT = TOPO->NEXT;
  TOPO->NEXT = NEW;

  return 0;
}


int DESEMPILHA(NO *TOPO){
  NO *TRASH = TOPO->NEXT;
  if(TRASH==NULL){
    printf("NULL\n");
    return 1;
  }
  printf("%s\n",TRASH->WORD);
  TOPO->NEXT = TRASH->NEXT;
  free(TRASH);
  return 0;
}



int OPERATION(char *a){
    char *inserir = "inserir";
    char *desfazer = "desfazer";

    int eh_inserir;
    int eh_desfazer;

    eh_inserir = strcmp(a,inserir);
    eh_desfazer = strcmp(a,desfazer);

    if(eh_inserir==0){
        return 1;
    }

    else if(eh_desfazer==0){
        return 2;
    }
    else{
        return 0;
    }

}



int main() {
  NO *TOPO;
  TOPO = PILHA();
  char input[10]="";



  int operacao;
   while(scanf("%s",input)!=EOF){
        operacao = OPERATION(input);
        if(operacao==1){
            char *WORD = calloc(101,sizeof(char));

            scanf("%[^\n]s",WORD);
            EMPILHA(TOPO,WORD);


        }
        else if(operacao == 2){
            DESEMPILHA(TOPO);

        }
        else{
            printf("entrada invalida\n");
        }

    }


  return 0;
}