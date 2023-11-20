#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int Item;

typedef struct Pilha
{
    Item *v;
    int size;
    int elem;
} Pilha;

int criaPilha(Pilha *pilha, int s)
{
    pilha->v = malloc(sizeof(Item) * s);
    if (pilha->v == NULL)
        return 1;

    pilha->size = s;
    pilha->elem = -1;
    return 0;
}

int estaVazia(Pilha *pilha)
{
    return pilha->elem == -1;
}

Item espia(Pilha *pilha)
{
    return pilha->v[pilha->elem];
}

int estaCheia(Pilha *pilha)
{
    return pilha->elem == pilha->size;
}

int empilha(Pilha *pilha, Item e)
{
    if (estaCheia(pilha))
        return 1;

    pilha->elem++;
    pilha->v[pilha->elem] = e;
    return 0;
}

int desempilha(Pilha *pilha)
{
    if (estaVazia(pilha))
    {
        return 1;
    }
    pilha->elem--;
    return 0;
}

void desalocaPilha(Pilha *pilha)
{
    free(pilha->v);
    return;
}

int sS[1000];
int solve(Pilha *pilha, int c)
{
    // k++ significa que o k já passou e agora o proximo a passar é k+1
    // 0 sai mais rapido , cars = carros que atravessaram, k = ultimo que saiu
    // empilhar entrar na rua de lado
    int k = 0, cars = 0, flag = 0;
    while (cars < c)
    {
        // verifica stack
        while (espia(pilha) == k + 1 && !estaVazia(pilha))
        {
            k++;
            desempilha(pilha);
        }

        // se nao tem empilha
        if (sS[cars] != k + 1)
        {
            empilha(pilha, sS[cars]);
        }
        else
        {
            k++;
        }
        // soma a carros
        cars++;
    }

    // remove todos os carros da pilha
    while (espia(pilha) == k + 1 && !estaVazia(pilha))
    {
        desempilha(pilha);
        k++;
    }
    // retorna a relação entre carros que conseguiram passar
    // e carrost totais
    return k - c;
}

int main()
{

    // extrai informações
    int c, i;
    while (scanf("%d", &c))
    {
        // cria pilha
        Pilha pilha;
        criaPilha(&pilha, 1000);
        // se o c equivaler a zero, fecha o programa
        if (c == 0)
        {
            break;
        }
        for (i = 0; i < c; i++)
        {
            scanf("%d", &sS[i]);
        }

        // resolve o problema, se retornar 0 printa sim , senão printa não
        solve(&pilha, c) == 0 ? printf("yes\n") : printf("no\n");
        desalocaPilha(&pilha);
    }

    return 0;
}