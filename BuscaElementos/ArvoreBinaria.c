//Operacoes em arvores binarias de busca

//Define o no da arvore
typedef struct No {
    int dado;  
    struct No* esq;
    struct No* dir;
} No;

typedef No* raiz;

//Inicializa a arvore
raiz criar_arvore(int x, raiz esq, raiz dir) {
    raiz r = malloc(sizeof(No)); // Aloca memoria para o novo no
    r->dado = x; // Inicializa o dado
    r->esq = esq; // Inicializa o filho da esquerda
    r->dir = dir; // Inicializa o filho da direita
    return r; // Retorna o novo no
}

//Insere um novo elemento na arvore ( compara se for menor ou maior com a raiz )
int insereElementeIterativa ( raiz * raiz , int valor ) {
    raiz novo = ( raiz ) malloc ( sizeof ( No ) ) ;
    novo -> dado = valor ;
    novo -> esq = NULL ;
    novo -> dir = NULL ;
    if ( * raiz == NULL ) { // Ve se a arvore ta vazia
        * raiz = novo ; 
        return 1 ;
    }
    raiz temp = * raiz ; /
    while ( temp != NULL ) { 
        if ( valor < temp -> dado ) { // Insere na subarvore esquerda se for menor
            if ( temp -> esq == NULL ) { //Ve se tem elemento na esquerda
                temp -> esq = novo ; // Insere o novo elemento 
                return 1 ;
            }
            temp = temp -> esq ; // Se não tiver elemento na esquerda, vai para a esquerda
        } else if ( valor > temp -> dado ) { // Insere na subarvore direita se for maior
            if ( temp -> dir == NULL ) { //Ve se tem elemento na direita
                temp -> dir = novo ; // Insere o novo elemento
                return 1 ;
            }
            temp = temp -> dir ; // Se não tiver elemento na direita, vai para a direita
        } else {
            return 0 ;
        }
    }
    return 0 ;
}

//Verifica se a arvore esta vazia ( pega o elemento a ser buscado e vai comparando partindo da raiz )
raiz procuraElemento ( raiz raiz , int valor ) {
    if ( raiz == NULL ) { // Ve se a arvore ta vazia
        return NULL ;
    }
    raiz temp = raiz ; // Cria um no temporario
    while ( temp != NULL ) {
        if ( valor < temp -> dado ) { // Ve se o valor e menor que o elemento atual
            temp = temp -> esq ; // Se for menor, vai para a esquerda
        } else if ( valor > temp -> dado ) { // Ve se o valor e maior que o elemento atual
            temp = temp -> dir ; // Se for maior, vai para a direita
        } else {
            return temp ; // Se for igual, retorna o elemento
        }
    }
    return NULL ; // Se nao encontrar, retorna NULL
}

//Remove um elemento da arvore ( Caso 1 - No folha, sem filho | Caso 2 - No com um filho | Caso 3 - No com dois filhos )
int removeElemento ( raiz * raiz , int valor ) {
    if ( * raiz == NULL ) { // Ve se a arvore ta vazia
        return 0 ;
    }
    raiz temp = * raiz ; // Cria um no temporario
    raiz ant = NULL ; // Cria um no anterior
    while ( temp != NULL ) {
        if ( valor < temp -> dado ) { // Ve se o valor e menor que o elemento atual
           removerBusca ( & ( temp -> esq ) , valor ) ; // Se for menor, vai para a esquerda
        } else if ( valor > temp -> dado ) { // Ve se o valor e maior que o elemento atual
            removerBusca ( & ( temp -> dir ) , valor ) ; // Se for maior, vai para a direita
        } else {
            deletarNo ( raiz , temp ) ; // Se for igual, deleta o no
        }
    }
    return 0 ;
}
//Busca normal ate achar o elemento que vai ser excluido
int removerBusca ( raiz * raiz , int valor ) {
    if ( * raiz == NULL ) { // Ve se a arvore ta vazia
        return 0 ;
    }
    raiz temp = * raiz ; // Cria um no temporario
    raiz ant = NULL ; // Cria um no anterior
    while ( temp != NULL ) {
        if ( valor < temp -> dado ) { // Ve se o valor e menor que o elemento atual
           removerBusca ( & ( temp -> esq ) , valor ) ; // Se for menor, vai para a esquerda
        } else if ( valor > temp -> dado ) { // Ve se o valor e maior que o elemento atual
            removerBusca ( & ( temp -> dir ) , valor ) ; // Se for maior, vai para a direita
        } else {
            deletarNo ( raiz , temp ) ; // Se for igual, deleta o no
        }
    }
    return 0 ;
}
//Verifica se o no a ser deletado tem 0 - ponteiro aponta pra null, 1 - ponteiro aponta para o filho do deletado, ou 2 filhos - acha sucessor
int deletarNo ( raiz * raiz , raiz no ) {
    if ( no -> esq == NULL ) { // Caso 1 - No folha, sem filho
        if ( no -> dir == NULL ) { // Caso 1 - No folha, sem filho
            if ( * raiz == no ) { // Ve se o no e a raiz
                * raiz = NULL ; // Se for, a arvore fica vazia
            } else if ( ( * raiz ) -> esq == no ) { // Ve se o no e igual ao no atual
                ( * raiz ) -> esq = NULL ; // Se for, o no anterior a esquerda fica nulo
            } else {
                ( * raiz ) -> dir = NULL ; // Se nao for, o no anterior a direita fica nulo
            }
        } else { // Caso 2 - No com um filho
            if ( * raiz == no ) { // Ve se o no e a raiz
                * raiz = no -> dir ; // Se for, a raiz recebe o no atual a direita
            } else if ( ( * raiz ) -> esq == no ) { // Ve se o no e igual ao no atual
                ( * raiz ) -> esq = no -> dir ; // Se for, o no anterior a esquerda recebe o no atual a direita
            } else {
                ( * raiz ) -> dir = no -> dir ; // Se nao for, o no anterior a direita recebe o no atual a direita
            }
        }
    } else if ( no -> dir == NULL ) { // Caso 2 - No com um filho
        if ( * raiz == no ) { // Ve se o no e a raiz
            * raiz = no -> esq ; // Se for, a raiz recebe o no atual a esquerda
        } else if ( ( * raiz ) -> esq == no ) { // Ve se o no e igual ao no atual
            ( * raiz ) -> esq = no -> esq ; // Se for, o no anterior a esquerda
        } else {
            ( * raiz ) -> dir = no -> esq ; // Se nao for, o no anterior a direita recebe o no atual a esquerda
        }
    } else { // Caso 3 - No com dois filhos
        raiz sucessor = obterSucessor ( no ) ; // Obtem o sucessor do no atual
        no -> dado = sucessor -> dado ; // O no atual recebe o valor do sucessor
        removeElemento ( & ( no -> dir ) , sucessor -> dado ) ; // Remove o sucessor
    }
    free ( no ) ; // Libera o no atual
    return 1 ;
}
//Vai 1 vez para a direita e depois tudo a esquerda para achar o sucessor 
int obterSucessor ( raiz raiz ) {
    raiz temp = raiz -> dir ; // Vai para a direita
    while ( temp -> esq != NULL ) { // Vai para a esquerda
        temp = temp -> esq ;
    }
    return temp ; // Retorna o sucessor
}



//Percursos
//Pre-ordem
void pre_ordem(raiz raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado); // Visita a raiz
        pre_ordem(raiz->esq); // Visita a subarvore da esquerda
        pre_ordem(raiz->dir); // Visita a subarvore da direita
    }
}

//Em-ordem
void em_ordem(raiz raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esq); // Visita a subarvore da esquerda
        printf("%d ", raiz->dado); // Visita a raiz
        em_ordem(raiz->dir); // Visita a subarvore da direita
    }
}

//Pos-ordem
void pos_ordem(raiz raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq); // Visita a subarvore da esquerda
        pos_ordem(raiz->dir); // Visita a subarvore da direita
        printf("%d ", raiz->dado); // Visita a raiz
    }
}


//Deletar Arvore Completa
void deletarArvore(raiz raiz) {
    if (raiz == NULL) { 
        return; 
    }
    deletarArvore(raiz->esq); // Deleta a subarvore da esquerda
    deletarArvore(raiz->dir); // Deleta a subarvore da direita
    free(raiz);
}
