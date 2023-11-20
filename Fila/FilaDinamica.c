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
    No *novo = (No*)malloc(sizeof(No)); //aloca memoria para o novo no
    if(novo == NULL){ 
        return 0;
    }   
    novo->valor = valor; //insere o valor no novo no
    novo->prox = NULL; //o proximo do novo no aponta para NULL
    if(filaDinamicaVazia(fila)){ //se a fila estiver vazia, o inicio aponta para o novo no
        fila->inicio = novo;
    }else{ //se nao, o proximo do ultimo no aponta para o novo no
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
    No *aux = fila->inicio; //aux aponta para o inicio da fila
    *valor = aux->valor; //o valor do inicio da fila e armazenado
    fila->inicio = aux->prox; //o inicio da fila aponta para o proximo do inicio
    free(aux); //libera a memoria do inicio da fila
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
