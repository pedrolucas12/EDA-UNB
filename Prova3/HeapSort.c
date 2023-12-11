//Criacao da Binary Head
void binaryHead (int *A, int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int maior = i;
    int aux;
    if (l < n && A[l] > A[maior]){
        maior = l;
    }
    if (r < n && A[r] > A[maior]){
        maior = r;
    }
    if (maior != i){
        aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
        binaryHead(A, n, maior);
    }
}

//HeapSort
void HeapSort (int *A, int n){
    int i, aux;
    for (i = n/2-1; i >= 0; i--){
        binaryHead(A, n, i);
    }
    for (i = n-1; i >= 0; i--){
        aux = A[0];
        A[0] = A[i];
        A[i] = aux;
        binaryHead(A, i, 0);
    }
}

void fixUp(int k){ 
    while (k>1 && less(pq[k/2], pq[k])){
        exch(pq[k], pq[k/2]);
        k = k/2; //verifica o avô
    }
}

void PQinsert(Item v){
    pq[++N] = v;
    fixUp(N);
}

void fixDown(int k, int N){
    int j;
    while (2*k <= N){
        j = 2*k;
        if(j < N && less (pq[j] , pq[j+1])){
            j ++;
        }
        if (!less(pq[k],pq[j])) {
            break;
        }
        exch(pq[k], pq[j]);
        k = j;
    }
}

void PQchange(int k, int valor){
    v[k] = valor;

    if(v[k] < valor){
        fixUp(k);
    }
    else{
        fixDown(k, N);
    }
}

void PQinsert(int k){
    qp[k] = ++N; // data[k] na ultima posição da fila
    pq[N] = k; // inserir na ultima posição
    fixUp(N); // consertar a heap
}

void PQchange(int i){
    fixUp(qp[i]);
    fixDown(qp[i], N);
}

void exch(int a, int b){
    int k = qp[a];
    qp[a] = qp[b];
    qp[b] = k;
    pq[qp[a]] = a;
    pq[qp[b]] = b;
}
