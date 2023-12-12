void fixUp(int k){  
    while (k>1 && less(pq[k/2], pq[k])){ //enquanto tiver pai e o pai for menor que o filho
        exch(pq[k], pq[k/2]);
        k = k/2; //verifica o avô
    }
}

void fixUpRecursivo (int k){ //recursivo
    if (k>1 && less(pq[k/2], pq[k])){ //enquanto tiver pai e o pai for menor que o filho
        exch(pq[k], pq[k/2]);
        fixUpRecursivo(k/2);
    }
}

void PQinsert(int k){
    qp[k] = ++N; // data[k] na ultima posição da fila
    pq[N] = k; // inserir na ultima posição
    fixUp(N); // consertar a heap
}

Item top(Heap *h){
    return h-> pq[1];
}

void PQremove (int k){
    int aux = pq[k];
    exch(pq[k], pq[N--]); //troca o elemento a ser removido com o ultimo elemento
    fixDown(1, N); //conserta a heap
    qp[aux] = -1; //retira o elemento da fila
}

void fixDown(int k, int N){
    int j;
    while (2*k <= N){ //enquanto tiver filhos
        j = 2*k;  //filho 
        if(j < N && less (pq[j] , pq[j+1])){ //verifica qual filho é maior
            j ++;
        }
        if (!less(pq[k],pq[j])) { //se o pai for maior que o filho, para
            break;
        }
        exch(pq[k], pq[j]); //troca o pai com o filho
        k = j;
    }
}

void PQchange(int k, int valor){
    v[k] = valor;
    if(v[k] < valor){ //se o valor for menor que o anterior
        fixUp(k);
    }
    else{
        fixDown(k, N);
    }
}

void isEmpyt(Heap *h){
    if(h->N == 0){ //se a heap estiver vazia
        return 1;
    }
    else{
        return 0;
    }
}

void headSort (int *v, int l, int r){
    int i, aux;
    for (i = (r-l)/2; i >= 0; i--){ //cria a heap
        fixDown(v, i, r); //conserta a heap
    }
    for (i = r; i >= 0; i--){ //remove o maior elemento e conserta a heap
        aux = v[0]; //troca o maior elemento com o ultimo
        v[0] = v[i]; 
        v[i] = aux;
        fixDown(v, 0, i); //conserta a heap
    }
}


//HeapSort
void HeapSort (int *A, int n){ 
    int i, aux;
    for (i = n/2-1; i >= 0; i--){ //cria a heap
        binaryHead(A, n, i);
    }
    for (i = n-1; i >= 0; i--){ //remove o maior elemento e conserta a heap
        aux = A[0];
        A[0] = A[i];
        A[i] = aux;
        binaryHead(A, i, 0);
    }
}

//Criacao da Binary Head
void binaryHead (int *A, int n, int i){ 
    int l = 2*i+1;
    int r = 2*i+2;
    int maior = i;
    int aux;
    if (l < n && A[l] > A[maior]){ //verifica qual o maior elemento
        maior = l;
    }
    if (r < n && A[r] > A[maior]){ //verifica qual o maior elemento
        maior = r;
    }
    if (maior != i){ //se o maior elemento nao for o pai
        aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
        binaryHead(A, n, maior);
    }
}


//HeapSort Recursivo
void HeapSortRecursivo (int *A, int n){ 
    int i, aux;
    for (i = n/2-1; i >= 0; i--){ //cria a heap
        binaryHeadRecursivo(A, n, i);
    }
    for (i = n-1; i >= 0; i--){ //remove o maior elemento e conserta a heap
        aux = A[0];
        A[0] = A[i];
        A[i] = aux;
        binaryHeadRecursivo(A, i, 0);
    }
}

//Criacao da Binary Head Recursivo
void binaryHeadRecursivo (int *A, int n, int i){ 
    int l = 2*i+1;
    int r = 2*i+2;
    int maior = i;
    int aux;
    if (l < n && A[l] > A[maior]){ //verifica qual o maior elemento
        maior = l;
    }
    if (r < n && A[r] > A[maior]){ //verifica qual o maior elemento
        maior = r;
    }
    if (maior != i){ //se o maior elemento nao for o pai
        aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
        binaryHeadRecursivo(A, n, maior);
    }
}

