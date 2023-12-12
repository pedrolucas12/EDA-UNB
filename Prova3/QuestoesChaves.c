

//Escreva uma função recursiva que receba um vetor de inteiros e ordene-o usando o algoritmo de ordenação por intercalação (merge sort). 
1 merge_sort(v, 0, 5) 
2 meio = (5+0)/2 = 2
3 merge_sort(v, 0, meio=2): esquerda
    m = (2+0)/2 = 1
    merge_sort(v, 0, 1) : esquerda
        m = (1+0)/2 = 0
        merge_sort(v, 0, 0) : esquerda
        merge_sort(v, 1, 1) : direita
        merge(v, 0, 0, 1)
        65312 4:56
        merge_sort(v, 2, 2): direita
        merge(v, 0, 1, 2) 56312 4:3
        563124:35
        563124:356


//Imprima os 100 menores números de um conjunto de 10^6 de números.
    #define less(A,B) (vetor[A]>vetor[B])
    int main(void){
        PQinit(101);
        for(int i = 0; i<100; i++){ //insere os 100 primeiros elementos
            int k;
            scanf("%d", &x);
            PQinsert(x);
        }
        while(scanf("%d",&x) == 1){ //enquanto tiver elementos
            PQinsert(x);
            PQdelmax();
        }
    }
    int PQespiamin(){ //retorna o menor elemento
        return vetor[pq[1]];
    }
    void PQinit(int maxN){ //inicializa a heap
        pq = malloc((maxN+1)*sizeof(int));
        N = 0;
    }
    void PQinsert(int v){ //insere um elemento na heap
        pq[++N] = v;
        fixUp(pq, N);
    }
    int PQdelmin(){ //remove o menor elemento
        exch(pq[1], pq[N]);
        fixDown(pq, 1, N-1);
        return pq[N--];
    }
    int PQdelmax(){ //remove o maior elemento
        exch(pq[1], pq[N]);
        fixDown(pq, 1, N-1);
        return pq[N--];
    }
    void PQchange(int k, int valor){ //troca o valor de uma chave
        v[k] = valor;
        if(v[k] < valor){ //se o valor for menor que o anterior
            fixUp(k);
        }
        else{
            fixDown(k, N);
        }
    }



