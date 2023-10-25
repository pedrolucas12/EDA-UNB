//Todas as funcoes de pilha

//Pilha Dinamica

void inicializaPilhaDinamica(PilhaDinamica *pilha){
    pilha->topo = NULL;
}

int pilhaDinamicaVazia(PilhaDinamica *pilha){
    if(pilha->topo == NULL){
        return 1;
    }
    return 0;
}

int empilhaDinamica(PilhaDinamica *pilha, int valor){
    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        return 0;
    }
    novo->valor = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    return 1;
}

int desempilhaDinamica(PilhaDinamica *pilha, int *valor){
    if(pilhaDinamicaVazia(pilha)){
        return 0;
    }
    No *aux = pilha->topo;
    *valor = aux->valor;
    pilha->topo = aux->prox;
    free(aux);
    return 1;
}

int topoDinamica(PilhaDinamica *pilha, int *valor){
    if(pilhaDinamicaVazia(pilha)){
        return 0;
    }
    *valor = pilha->topo->valor;
    return 1;
}

void imprimePilhaDinamica(PilhaDinamica *pilha){
    No *aux = pilha->topo;
    printf("\n");
    while(aux != NULL){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

