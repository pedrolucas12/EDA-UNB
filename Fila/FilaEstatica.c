//Funcoes de uma Fila Estatica

//Inicializa a fila
void inicializaFilaEstatica(FilaEstatica *fila){
    fila->inicio = 0;
    fila->fim = 0;
}

//Verifica se a fila esta vazia
int filaEstaticaVazia(FilaEstatica *fila){
    if(fila->inicio == fila->fim){
        return 1;
    }
    return 0;
}

//Verifica se a fila esta cheia
int filaEstaticaCheia(FilaEstatica *fila){
    if(fila->fim == MAX){
        return 1;
    }
    return 0;
}

//Insere um novo elemento no fim da fila
int insereFilaEstatica(FilaEstatica *fila, int valor){
    if(filaEstaticaCheia(fila)){
        return 0;
    }
    fila->dados[fila->fim] = valor;
    fila->fim++;
    return 1;
}

//Remove um elemento do inicio da fila
int removeFilaEstatica(FilaEstatica *fila, int *valor){
    if(filaEstaticaVazia(fila)){
        return 0;
    }
    *valor = fila->dados[fila->inicio];
    int i;
    for(i = 0; i < fila->fim-1; i++){
        fila->dados[i] = fila->dados[i+1];
    }
    fila->fim--;
    return 1;
}

//Retorna o primeiro elemento da fila
int primeiroFilaEstatica(FilaEstatica *fila, int *valor){
    if(filaEstaticaVazia(fila)){
        return 0;
    }
    *valor = fila->dados[fila->inicio];
    return 1;
}



