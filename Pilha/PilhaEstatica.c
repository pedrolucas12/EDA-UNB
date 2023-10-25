//Todas as funcoes de pilha

//Pilha Estatica

void inicializaPilhaEstatica(PilhaEstatica *pilha){
    pilha->topo = -1;
}

int pilhaEstaticaVazia(PilhaEstatica *pilha){
    if(pilha->topo == -1){
        return 1;
    }
    return 0;
}

int pilhaEstaticaCheia(PilhaEstatica *pilha){
    if(pilha->topo == MAX-1){
        return 1;
    }
    return 0;
}

int empilhaEstatica(PilhaEstatica *pilha, int valor){
    if(pilhaEstaticaCheia(pilha)){
        return 0;
    }
    pilha->topo++;
    pilha->dados[pilha->topo] = valor;
    return 1;
}

int desempilhaEstatica(PilhaEstatica *pilha, int *valor){
    if(pilhaEstaticaVazia(pilha)){
        return 0;
    }
    *valor = pilha->dados[pilha->topo];
    pilha->topo--;
    return 1;
}

int topoEstatica(PilhaEstatica *pilha, int *valor){
    if(pilhaEstaticaVazia(pilha)){
        return 0;
    }
    *valor = pilha->dados[pilha->topo];
    return 1;
}

void imprimePilhaEstatica(PilhaEstatica *pilha){
    int i;
    printf("\n");
    for(i = pilha->topo; i >= 0; i--){
        printf("%d\n", pilha->dados[i]);
    }
}

