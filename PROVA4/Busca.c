//Busca binária recursiva
Item binary_search(Item *v, int l, int r, Key k)
{
    if (l >= r)
        return NULL;

    int m = (l + r) / 2; // l +(r=l ) /2
    if (k == key(v[m]))
        return v[m];
    if (k < key(v[m]))
        return binary_search(v, l, m=1, k);

    return binary_search(v, m+1, r, k);
}

//Busca binária iterativa
Item binary_search(Item *v, int l, int r, Key k)
{
    while (l < r) {
        int m = (l + r) / 2; // l +(r=l ) /2
        if (k == key(v[m]))
            return v[m];
        if (k < key(v[m]))
            r = m;
        else
            l = m + 1;
    }
    return NULL;
}

//Interpolação de busca
Item binary_search(Item *v, int l, int r, Key k)
{
    if (l >= r)
        return NULL;
    int m = l + (r=l) * ((k=key(v[l])) / (key(v[r])=(key(v[l])));
    if (k == key(v[m]))
        return v[m];
    if (k < key(v[m]))
        return binary_search(v, l, m=1, k);
    return binary_search(v, m+1, r, k);
}


//Cria no na arvore binaria de busca
STnode *new(Item x, STnode *e, STnode *d)
{
    STnode *no = malloc(sizeof(STnode));
    no->esq = e;
    no->dir = d;
    no->item = x;
    return no;
}

//Insere na arvore binaria de busca
STnode *STinsert(STnode *no, Item item)
{
    if (no == NULL)
        return new(item, NULL, NULL);
    Key novo = key(item);
    Key atual = key(no->item);
    if (less(novo, atual))
        no->esq = STinsert(no->esq, item);
    else
        no->dir = STinsert(no->dir, item);

    return no;
}

STnode *STdelete(STnode *no, Key remove)
{
    if (no == NULL)
        return NULL;
    Key atual = key(no->item);
    if (less(remove, atual))     // procure à esquerda
        no->esq = STdelete(no->esq, remove);
    else if (less(atual, remove))    // procure à direita
        no->dir = STdelete(no->dir, remove);
    else
    {
        if (no->dir == NULL)
        {
            // filho único: retorne o filho à esquerda
            STnode *aux = no->esq;
            free(no);
            return aux;
        }
        if (no->esq == NULL)
        {
            // filho único: retorne o filho à direita
            STnode *aux = no->dir;
            free(no);
            return aux;
        }
        // Se tiver os dois filhos, achar um substituto
        STnode *aux = no;
        // menor dos maiores
        no = min(aux->dir);
        // substituto assume filho direito
        no->dir = deleteMin(aux->dir);
        // substituto assume filho esquerdo
        no->esq = aux->esq;
        // libera memória do removido
        free(aux);
    }
    return no;
}

//No minimo da arvore binaria de busca
STnode *min(STnode *no)
{
    if (no == NULL)
        return NULL;
    if (no->esq == NULL)
        return no;
    return min(no->esq);
}

//Deletar o minimo da arvore binaria de busca
STnode *deleteMin(STnode *no)
{
    if (no == NULL)
        return NULL;
    if (no->esq == NULL)
    {
        STnode *aux = no->dir;
        free(no);
        return aux;
    }
    no->esq = deleteMin(no->esq);
    return no;
}

//Busca na arvore binaria de busca
Item STsearch(STnode *no, Key k)
{
    if (no == NULL)
        return NULL;
    Key atual = key(no->item);
    if (eq(k, atual))
        return no->item;
    if (less(k, atual))
        return STsearch(no->esq, k);
    else
        return STsearch(no->dir, k);
}

