// Criação de uma lista encadeada 
typedef struct node no ;
    struct node {
    Item info ;
    no *prox;
} ;

// Criação de uma lista encadeada com cabeça
struct head {
    int tam;
    no *prox;
    no *ultimo;
};

// Criação da lista duplamente encadeada
typedef struct node no ;
    struct node {
    Item info ;
    no *prox;
    no *ant;
} ;

// Criação da lista duplamente encadeada com cabeça
struct head {
    int tam;
    no *prox;
    no *ultimo;
};

// Operacao Percorrer na lista duplamente encadeada 
int Percorrer (no *lista) {
    no *aux;
    aux = lista->prox;
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

// Operacao Inserir no inicio na lista duplamente encadeada
void insere_inicio(cabeca *lista, no *novo) {
    if (vazia(lista))
        lista->ultimo = novo;
    else
        lista->prox->ant = novo;
    novo->ant = NULL;
    novo->prox = lista->prox;
    lista->prox = novo;
    lista->tam++;
}

// Operacao Inserir no final na lista duplamente encadeada
void insere_final(cabeca *lista, no *novo) {
    if (vazia(lista))
        lista->prox = novo;
    else
        lista->ultimo->prox = novo;
    novo->ant = lista->ultimo;
    novo->prox = NULL;
    lista->ultimo = novo;
    lista->tam++;
}

// Operacao Remover no inicio na lista duplamente encadeada
void remove_no(cabeca *lista, no *lixo)
{
    if (lista->prox == lixo)
        lista->prox = lixo->prox;
    else
        lixo->ant->prox = lixo->prox;
    if (lista->ultimo == lixo)
        lista->ultimo = lixo->ant;
    else
        lixo->prox->ant = lixo->ant;
    lista->tam--;
}
