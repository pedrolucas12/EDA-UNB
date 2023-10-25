//Escreva uma função que conte o número de células de uma lista encadeada. Faça duas versões: uma iterativa e uma recursiva.
void contaCelulas ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return 0 ;
    }
    No * aux = lista -> inicio ;
    int cont = 0 ;
    while ( aux != NULL ) {
        cont ++ ;
        aux = aux -> prox ;
    }
    return cont ;
}
int contaCelulasRecursiva ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return 0 ;
    }
    return 1 + contaCelulasRecursiva ( lista -> inicio -> prox ) ;
}


//Altura.  A altura de uma célula c em uma lista encadeada é a distância entre c e o fim da lista. Escreva uma função que calcule a altura de uma dada célula.
void alturaLista ( ListaEncadeada * lista , int valor ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    int cont = 0 ;
    while ( aux != NULL && aux -> info != valor ) {
        cont ++ ;
        aux = aux -> prox ;
    }
    if ( aux == NULL ) {
        return ;
    }
    int altura = contaCelulas ( aux ) ;
    return altura ;
}


//Profundidade.  A profundidade de uma célula c em uma lista encadeada é o número de passos do único caminho que vai da primeira célula da lista até c. 
// Escreva uma função que calcule a profundidade de uma dada célula.
void profundidadeLista ( ListaEncadeada * lista , int valor ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    int cont = 0 ;
    while ( aux != NULL && aux -> info != valor ) {
        cont ++ ;
        aux = aux -> prox ;
    }
    if ( aux == NULL ) {
        return ;
    }
    return cont ;
}


//Escreva uma função que verifique se uma lista encadeada que contém números inteiros está em ordem crescente.
void verificaCrescente ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    while ( aux -> prox != NULL ) {
        if ( aux -> info > aux -> prox -> info ) {
            return 0 ;
        }
        aux = aux -> prox ;
    }
    return 1 ;
}


//Escreva uma função que faça uma busca em uma lista encadeada crescente. Faça versões recursiva e iterativa.
void buscaCrescente ( ListaEncadeada * lista , int valor ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    while ( aux != NULL && aux -> info != valor ) {
        aux = aux -> prox ;
    }
    if ( aux == NULL ) {
        return 0 ;
    }
    return 1 ;
}
void buscaCrescenteRecursiva ( ListaEncadeada * lista , int valor ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    if ( lista -> inicio -> info == valor ) {
        return 1 ;
    }
    return buscaCrescenteRecursiva ( lista -> inicio -> prox , valor ) ;
}


//Escreva uma função que encontre uma célula com conteúdo mínimo. Faça duas versões: uma iterativa e uma recursiva.
void minimoLista ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    int min = aux -> info ;
    while ( aux != NULL ) {
        if ( aux -> info < min ) {
            min = aux -> info ;
        }
        aux = aux -> prox ;
    }
    return min ;
}
void minimoListaRecursiva ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    if ( lista -> inicio -> prox == NULL ) {
        return lista -> inicio -> info ;
    }
    int min = minimoListaRecursiva ( lista -> inicio -> prox ) ;
    if ( lista -> inicio -> info < min ) {
        return lista -> inicio -> info ;
    }
    return min ;
}


//Escreva uma função que verifique se duas listas encadeadas são iguais, ou melhor, se têm o mesmo conteúdo. Faça duas versões: uma iterativa e uma recursiva
void verificaIgual ( ListaEncadeada * lista1 , ListaEncadeada * lista2 ) {
    if ( listaVazia ( lista1 ) || listaVazia ( lista2 ) ) {
        return ;
    }
    No * aux1 = lista1 -> inicio ;
    No * aux2 = lista2 -> inicio ;
    while ( aux1 != NULL && aux2 != NULL ) {
        if ( aux1 -> info != aux2 -> info ) {
            return 0 ;
        }
        aux1 = aux1 -> prox ;
        aux2 = aux2 -> prox ;
    }
    if ( aux1 != NULL || aux2 != NULL ) {
        return 0 ;
    }
    return 1 ;
}
void verificaIgualRecursiva ( ListaEncadeada * lista1 , ListaEncadeada * lista2 ) {
    if ( listaVazia ( lista1 ) || listaVazia ( lista2 ) ) {
        return ;
    }
    if ( lista1 -> inicio -> info != lista2 -> inicio -> info ) {
        return 0 ;
    }
    return verificaIgualRecursiva ( lista1 -> inicio -> prox , lista2 -> inicio -> prox ) ;
}


//Escreva uma função que faça uma cópia de uma lista encadeada. Faça duas versões da função: uma iterativa e uma recursiva.
void copiaLista ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    ListaEncadeada * copia = ( ListaEncadeada * ) malloc ( sizeof ( ListaEncadeada ) ) ;
    No * aux = lista -> inicio ;
    while ( aux != NULL ) {
        novoElemento ( copia , aux -> info ) ;
        aux = aux -> prox ;
    }
    return copia ;
}
void copiaListaRecursiva ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    ListaEncadeada * copia = ( ListaEncadeada * ) malloc ( sizeof ( ListaEncadeada ) ) ;
    copia -> inicio = NULL ;
    copiaListaRecursivaAux ( lista -> inicio , copia ) ;
    return copia ;
}


//Escreva uma função que concatene duas listas encadeadas (isto é, engate a segunda no fim da primeira). Faça duas versões: uma iterativa e uma recursiva.
void juntaLista ( ListaEncadeada * lista1 , ListaEncadeada * lista2 ) {
    if ( listaVazia ( lista1 ) || listaVazia ( lista2 ) ) {
        return ;
    }
    No * aux = lista1 -> inicio ;
    while ( aux -> prox != NULL ) {
        aux = aux -> prox ;
    }
    aux -> prox = lista2 -> inicio ;
    return lista1 ;
}
void juntaListaRecursiva ( ListaEncadeada * lista1 , ListaEncadeada * lista2 ) {
    if ( listaVazia ( lista1 ) || listaVazia ( lista2 ) ) {
        return ;
    }
    if ( lista1 -> inicio -> prox == NULL ) {
        lista1 -> inicio -> prox = lista2 -> inicio ;
        return lista1 ;
    }
    return juntaListaRecursiva ( lista1 -> inicio -> prox , lista2 ) ;
}



//Escreva uma função que troque de posição duas células de uma mesma lista encadeada.
void trocaPosicao ( ListaEncadeada * lista , int valor1 , int valor2 ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux1 = lista -> inicio ;
    No * aux2 = lista -> inicio ;
    while ( aux1 != NULL && aux1 -> info != valor1 ) {
        aux1 = aux1 -> prox ;
    }
    while ( aux2 != NULL && aux2 -> info != valor2 ) {
        aux2 = aux2 -> prox ;
    }
    if ( aux1 == NULL || aux2 == NULL ) {
        return ;
    }
    int aux = aux1 -> info ;
    aux1 -> info = aux2 -> info ;
    aux2 -> info = aux ;
}



//Escreva uma função que inverta a ordem das células de uma lista encadeada. Faça isso sem usar espaço auxiliar, apenas alterando ponteiros. Dê duas soluções: uma iterativa e uma recursiva.
void inverteOrdem ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    No * ant = NULL ;
    No * prox = NULL ;
    while ( aux != NULL ) {
        prox = aux -> prox ;
        aux -> prox = ant ;
        ant = aux ;
        aux = prox ;
    }
    lista -> inicio = ant ;
}
void inverteOrdemRecursiva ( ListaEncadeada * lista ) {
    if ( listaVazia ( lista ) ) {
        return ;
    }
    No * aux = lista -> inicio ;
    No * ant = NULL ;
    No * prox = NULL ;
    inverteOrdemRecursivaAux ( aux , ant , prox ) ;
    lista -> inicio = ant ;
}