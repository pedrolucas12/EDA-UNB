//Cria pilha
int fila[N];
int p, u;
void criar_fila()
{
    p = u = 0;
}

//Verifica se a pilha está vazia
int fila_vazia()
{
    if (p == u)
        return 1;
    else
        return 0;
}

//DesemFILEIRA
int desenFILEIRA(int *t)
{
    if (fila_vazia())
        return 0; // Erro: fila vazia
    *t = fila[p];
    p++;
    return 1;
}

//EnFILEIRA
int enFILEIRA(int t)
{
    if (u == N)
        return 0; // Erro: fila cheia
    fila[u] = t;
    u++;
    return 1;
}

//Fila cheia
int fila_cheia()
{
    if (u == N)
        return 1;
    else
        return 0;
}

//ENFILEIRA COM LISTA ENCADEADA
void enfileira(cabeca* lista, Item x) {
    no* novo = criar_no(x);
    if (novo) {
        novo->prox = NULL;
        if (!vazia(lista))
            lista->ultimo->prox = novo;
        else
            lista->prox = novo;
        lista->ultimo = novo;
        lista->tam++;
    }
}

//DESENFILEIRA COM LISTA ENCADEADA
Item desenFILEIRA(cabeca* lista)
{
    no* lixo = primeiro(lista);
    lista->prox = lista->prox->prox; // novo primeiro
    if (lixo == lista->ultimo)
        lista->ultimo = NULL;
    lista->tam--;
    Item x = lixo->info;
    free(lixo);
    return x;
}


//EXERC DISTANCIA ENTRE CIDADES
void distancias_do_inicio(int mapa[][N], head* fila_cidades, int inicio, int* distancia)
{
    for (int cidade = 0; cidade < N; cidade++)
        distancia[cidade] = N;
    enfileira(fila_cidades, inicio);
    distancia[inicio] = 0;
    while (!vazia(fila_cidades))
    {
        inicio = desenfileira(fila_cidades);
        for (int cidade = 0; cidade < N; cidade++)
        {
            if (mapa[inicio][cidade] == 1 && distancia[cidade] >= N)
            {
                distancia[cidade] = distancia[inicio] + 1;
                enfileira(fila_cidades, cidade);
}}}}
