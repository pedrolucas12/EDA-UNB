//Criar pilha
int *pilha;
int t;
void criar(int N)
{
    pilha = malloc(N * sizeof(*pilha));
    t = 0;
}

//Desempilha
Item desempilha()
{
    return pilha[--t];
}

//Empilha
void empilha(Item y)
{
    pilha[t++] = y;
}

//Pilha cheia
Item espia() {
    return pilha[t-1];
}

//Pilha vazia
int vazia() {
    return t == 0;
}

//Cria pilha com lista encadeada
head∗ criar_pilha()
{
    head∗ le = malloc(sizeof(head));
    le−>num_itens = 0;
    le−>prox = NULL;
    le−>ultimo = NULL;
    return le;
}

//Cria no da lista encadeada
node criar_no(Item x)
{
    node* no = malloc(sizeof(node));
    no->prox = NULL;
    no->info = x;
    return no;
}

//Vazia com lista encadeada
int vazia(head* p)
{
    return (p->prox == NULL);
}

//Cheia com lista encadeada
Item espia(head* p)
{
    return (p->prox->info);
}

//Empilha com lista encadeada
void empilha(head* lista, Item x)
{
    node* novo = criar_no(x);
    if (novo) {
        if (vazia(lista))
        lista->ultimo = novo;
        novo->prox = lista->prox;
        lista->prox = novo;
        lista->num_itens++;
    }
}

//Desempilha com lista encadeada
Item desempilha(head* lista)
{
    node* topo = lista->prox;
    lista->prox = topo->prox;
    if (topo == lista->ultimo)
        lista->ultimo = NULL;
    lista->num_itens--;
    Item x = topo->info;
    free(topo);
    return x;
}


//Implemente um pilha em uma lista encadeada sem célula-cabeça. A pilha será dada pelo endereço da primeira célula da lista (que é o topo da pilha).
void pilhaSemCabeca ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    while ( aux != NULL ) {
        printf ( "%d\n" , aux -> info ) ;
        aux = aux -> prox ;
    }
}

//Implemente um pilha em uma lista encadeada com célula-cabeça. A pilha será dada pelo endereço da célula-cabeça.
void pilhaComCabeca ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio -> prox ;
    while ( aux != NULL ) {
        printf ( "%d\n" , aux -> info ) ;
        aux = aux -> prox ;
    }
}
