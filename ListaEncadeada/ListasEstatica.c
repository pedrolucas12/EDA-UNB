//Funções da Lista Estatica

void inicializaListaEstatica(ListaEstatica *lista){
    lista->fim = -1;
}

int listaEstaticaVazia(ListaEstatica *lista){
    if(lista->fim == -1){
        return 1;
    }
    return 0;
}

int listaEstaticaCheia(ListaEstatica *lista){
    if(lista->fim == MAX-1){
        return 1;
    }
    return 0;
}

int insereInicioListaEstatica(ListaEstatica *lista, int valor){
    if(listaEstaticaCheia(lista)){
        return 0;
    }
    int i;
    for(i = lista->fim; i >= 0; i--){
        lista->dados[i+1] = lista->dados[i];
    }
    lista->dados[0] = valor;
    lista->fim++;
    return 1;
}

int insereFimListaEstatica(ListaEstatica *lista, int valor){
    if(listaEstaticaCheia(lista)){
        return 0;
    }
    lista->fim++;
    lista->dados[lista->fim] = valor;
    return 1;
}

int removeInicioListaEstatica(ListaEstatica *lista, int *valor){
    if(listaEstaticaVazia(lista)){
        return 0;
    }
    *valor = lista->dados[0];
    int i;
    for(i = 0; i < lista->fim; i++){
        lista->dados[i] = lista->dados[i+1];
    }
    lista->fim--;
    return 1;
}

int removeFimListaEstatica(ListaEstatica *lista, int *valor){
    if(listaEstaticaVazia(lista)){
        return 0;
    }
    *valor = lista->dados[lista->fim];
    lista->fim--;
    return 1;
}
