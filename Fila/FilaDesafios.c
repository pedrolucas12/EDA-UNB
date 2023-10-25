//Escreva uma função que devolva o comprimento (ou seja, o número de elementos) da fila.
void comprimentoFila ( FilaDinamica * fila ) {
    if ( filaDinamicaVazia ( fila ) ) {
        return 0 ;
    }
    int cont = 0 ;
    No * aux = fila -> inicio ;
    while ( aux != NULL ) {
        cont ++ ;
        aux = aux -> prox ;
    }
    return cont ;
}

//Faça uma versão da função distancias que devolva a distância de uma cidade a a outra b.
void distanciaFila ( FilaDinamica * fila , int a , int b ) {
    if ( filaDinamicaVazia ( fila ) ) {
        return 0 ;
    }
    int cont = 0 ;
    No * aux = fila -> inicio ;
    while ( aux != NULL && aux -> info != a ) {
        cont ++ ;
        aux = aux -> prox ;
    }
    if ( aux == NULL ) {
        return ;
    }
    int dist = 0 ;
    while ( aux != NULL && aux -> info != b ) {
        dist ++ ;
        aux = aux -> prox ;
    }
    if ( aux == NULL ) {
        return ;
    }
    return dist ;
}

//Implemente uma fila em uma lista encadeada circular sem célula-cabeça.
void circularSemCabeca ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    while ( aux -> prox != lista -> inicio ) {
        printf ( "%d\n" , aux -> info ) ;
        aux = aux -> prox ;
    }
    printf ( "%d\n" , aux -> info ) ;
}


//Implemente uma fila em uma lista encadeada não circular com célula-cabeça
void naoCircularComCabeca ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio -> prox ;
    while ( aux != NULL ) {
        printf ( "%d\n" , aux -> info ) ;
        aux = aux -> prox ;
    }
}



//Implemente uma fila em uma lista encadeada não circular sem célula-cabeça.
void naoCircularSemCabeca ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    while ( aux != NULL ) {
        printf ( "%d\n" , aux -> info ) ;
        aux = aux -> prox ;
    }
}



//Implemente uma fila em uma lista duplamente encadeada sem célula-cabeça. Use um ponteiro p para a primeira célula e um ponteiro u para a última.
void duplaSemCabeca ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    while ( aux != NULL ) {
        printf ( "%d\n" , aux -> info ) ;
        aux = aux -> prox ;
    }
}