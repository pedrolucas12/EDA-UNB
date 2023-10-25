//Funcoes para manipulacao de listas duplamente encadeadas

//Inicializa a lista
void inicializaListaDupla(ListaDupla *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}

//Verifica se a lista esta vazia
int listaDuplaVazia(ListaDupla *lista){
    if(lista->inicio == NULL){
        return 1;
    }
    return 0;
}

//Insere um novo elemento no inicio da lista
int insereInicioListaDupla(ListaDupla *lista, int valor){
    NoDuplo *novo = (NoDuplo*)malloc(sizeof(NoDuplo));
    if(novo == NULL){
        return 0;
    }
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = lista->inicio;
    if(listaDuplaVazia(lista)){
        lista->fim = novo;
    }else{
        lista->inicio->ant = novo;
    }
    lista->inicio = novo;
    return 1;
}

//Insere um novo elemento no fim da lista
int insereFimListaDupla(ListaDupla *lista, int valor){
    NoDuplo *novo = (NoDuplo*)malloc(sizeof(NoDuplo));
    if(novo == NULL){
        return 0;
    }
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = lista->fim;
    if(listaDuplaVazia(lista)){
        lista->inicio = novo;
    }else{
        lista->fim->prox = novo;
    }
    lista->fim = novo;
    return 1;
}

//Remove um elemento do inicio da lista
int removeInicioListaDupla(ListaDupla *lista, int *valor){
    if(listaDuplaVazia(lista)){
        return 0;
    }
    NoDuplo *aux = lista->inicio;
    *valor = aux->valor;
    lista->inicio = aux->prox;
    if(lista->inicio == NULL){
        lista->fim = NULL;
    }else{
        lista->inicio->ant = NULL;
    }
    free(aux);
    return 1;
}

//Remove um elemento do fim da lista
int removeFimListaDupla(ListaDupla *lista, int *valor){
    if(listaDuplaVazia(lista)){
        return 0;
    }
    NoDuplo *aux = lista->fim;
    *valor = aux->valor;
    lista->fim = aux->ant;
    if(lista->fim == NULL){
        lista->inicio = NULL;
    }else{
        lista->fim->prox = NULL;
    }
    free(aux);
    return 1;
}

//Insere apos um nó 
int insereAposListaDupla(ListaDupla *lista, int valor, int pos){
    if(listaDuplaVazia(lista)){
        return 0;
    }
    NoDuplo *aux = lista->inicio;
    while(aux != NULL && aux->valor != pos){
        aux = aux->prox;
    }
    if(aux == NULL){
        return 0;
    }
    NoDuplo *novo = (NoDuplo*)malloc(sizeof(NoDuplo));
    if(novo == NULL){
        return 0;
    }
    novo->valor = valor;
    novo->prox = aux->prox;
    novo->ant = aux;
    if(aux->prox == NULL){
        lista->fim = novo;
    }else{
        aux->prox->ant = novo;
    }
    aux->prox = novo;
    return 1;
}

//Insere Antes de um nó
int insereAntesListaDupla(ListaDupla *lista, int valor, int pos){
    if(listaDuplaVazia(lista)){
        return 0;
    }
    NoDuplo *aux = lista->inicio;
    while(aux != NULL && aux->valor != pos){
        aux = aux->prox;
    }
    if(aux == NULL){
        return 0;
    }
    NoDuplo *novo = (NoDuplo*)malloc(sizeof(NoDuplo));
    if(novo == NULL){
        return 0;
    }
    novo->valor = valor;
    novo->prox = aux;
    novo->ant = aux->ant;
    if(aux->ant == NULL){
        lista->inicio = novo;
    }else{
        aux->ant->prox = novo;
    }
    aux->ant = novo;
    return 1;
}

//Remove um nó da lista
int removeListaDupla(ListaDupla *lista, int valor){
    if(listaDuplaVazia(lista)){
        return 0;
    }
    NoDuplo *aux = lista->inicio;
    while(aux != NULL && aux->valor != valor){
        aux = aux->prox;
    }
    if(aux == NULL){
        return 0;
    }
    if(aux->ant == NULL){
        lista->inicio = aux->prox;
    }else{
        aux->ant->prox = aux->prox;
    }
    if(aux->prox == NULL){
        lista->fim = aux->ant;
    }else{
        aux->prox->ant = aux->ant;
    }
    free(aux);
    return 1;
}



