//Funcoes de filas Dinamicas

//Inicializa a fila
void inicializaFilaDinamica(FilaDinamica *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

//Verifica se a fila esta vazia
int filaDinamicaVazia(FilaDinamica *fila){
    if(fila->inicio == NULL){
        return 1;
    }
    return 0;
}

//Insere um novo elemento no fim da fila
int insereFilaDinamica(FilaDinamica *fila, int valor){
    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        return 0;
    }
    novo->valor = valor;
    novo->prox = NULL;
    if(filaDinamicaVazia(fila)){
        fila->inicio = novo;
    }else{
        fila->fim->prox = novo;
    }
    fila->fim = novo;
    return 1;
}

//Remove um elemento do inicio da fila
int removeFilaDinamica(FilaDinamica *fila, int *valor){
    if(filaDinamicaVazia(fila)){
        return 0;
    }
    No *aux = fila->inicio;
    *valor = aux->valor;
    fila->inicio = aux->prox;
    free(aux);
    return 1;
}

//Retorna o primeiro elemento da fila
int primeiroFilaDinamica(FilaDinamica *fila, int *valor){
    if(filaDinamicaVazia(fila)){
        return 0;
    }
    *valor = fila->inicio->valor;
    return 1;
}

//Retorna o ultimo elemento da fila
void ultimoElemento ( ListaEncadeada * lista , int * valor ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    while ( aux -> prox != NULL ) {
        aux = aux -> prox ;
    }
    * valor = aux -> info ;
}
