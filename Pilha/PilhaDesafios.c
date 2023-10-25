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

