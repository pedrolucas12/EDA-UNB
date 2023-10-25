//Operções da Lista Encadeada

typedef struct no {
    int info ;
    struct no * prox ;
} No ;

typedef struct listaEncadeada {
    No * inicio ;
} ListaEncadeada ;


void inicializaLista ( ListaEncadeada * lista ) {
    lista -> inicio = NULL ;
}

int listaVazia ( ListaEncadeada * lista ) {
    if ( lista -> inicio == NULL ) {
        return 1 ;
    }
    return 0 ;
}

void novoElemento ( ListaEncadeada * lista , int valor ) {
    No * novo = ( No * ) malloc ( sizeof ( No ) ) ;
    novo -> prox = NULL ;
    novo -> info = valor ;
    if ( lista -> inicio == NULL ) {
        lista -> inicio = novo ;
    } else {
        No * aux = lista -> inicio ;
        while ( aux -> prox != NULL ) {
            aux = aux -> prox ;
        }
        aux -> prox = novo ;
    }
}

void removeElemento ( ListaEncadeada * lista , int valor ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    No * ant = NULL ;
    while ( aux != NULL && aux -> info != valor ) {
        ant = aux ;
        aux = aux -> prox ;
    }
    if ( aux == NULL ) {
        return ;
    }
    if ( ant == NULL ) {
        lista -> inicio = aux -> prox ;
    } else {
        ant -> prox = aux -> prox ;
    }
    free ( aux ) ;
}

void buscaElemento ( ListaEncadeada * lista , int valor ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    while ( aux != NULL && aux -> info != valor ) {
        aux = aux -> prox ;
    }
    if ( aux == NULL ) {
        return ;
    }
    printf ( "Valor encontrado: %d\n" , aux -> info ) ;
}

void IniciaInsere ( ListaEncadeada * lista , int valor ) {
    No * novo = ( No * ) malloc ( sizeof ( No ) ) ;
    novo -> prox = NULL ;
    novo -> info = valor ;
    lista -> inicio = novo ;
}