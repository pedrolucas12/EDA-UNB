

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




/*
Resolva o problem da contagem para o fluxo de chaves  17 21 19 4 26 30 37  usando hashing com sondagem linear.  A tabela de dispersão deve ter tamanho 13 e a função de espalhamento deve ser o resto da divisão da chave por 13.  Faça uma figura do estado final da tabela de dispersão.
*/
    void hash(int *v, int n){
        int i, j, h;
        int hash[13];
        for(i = 0; i < 13; i++){
            hash[i] = -1;
        }
        for(i = 0; i < n; i++){
            h = v[i]%13;
            if(hash[h] == -1){
                hash[h] = v[i];
            }
            else{
                j = h;
                while(hash[j] != -1){
                    j++;
                    if(j == 13){
                        j = 0;
                    }
                }
                hash[j] = v[i];
            }
        }
    }


    /* CERTO OU ERRADO
    Um vetor em ordem decrescente é um heap decrescente?  Um vetor em ordem crescente é um heap crescente? 
    */
    CERTO E CERTO

    /*
    Insira os itens  E A S Y Q U E S T I O N, nessa ordem, em um heap decrescente inicialmente vazio. Mostre o heap que resulta.
    */
    void insert(int *v, int n){
        int i, j, aux;
        for(i = 1; i < n; i++){
            j = i;
            while(j > 0 && v[j] > v[(j-1)/2]){
                aux = v[j];
                v[j] = v[(j-1)/2];
                v[(j-1)/2] = aux;
                j = (j-1)/2;
            }
        }
    }

    /*
    Desenhe todos os heaps que podem ser construídos com os itens  A B C D E .  Desenhe todos os heaps que podem ser construídos com os itens  A A A B B
    */
    A B C D E                 
    E D C B A
    E D C A B
    E D A C B
    E A D C B
    A E D C B
    A D E C B
    A D C E B
    A D C B E
    A B D C E
    A B C D E


    /*
    Encontre o mínimo. Acrescente um método min() à classe MaxPQ. Sua implementação deve usar tempo constante e uma quantidade constante de espaço adicional.
    */
    void min(int *v, int n){
        int i, min;
        min = v[0];
        for(i = 1; i < n; i++){
            if(v[i] < min){
                min = v[i];
            }
        }
        return min;
    }

    /*
    Suponha que sua aplicação terá um número enorme de operações insert e apenas algumas poucas operação delMax. Qual implementação de PQ devo usar: heap, vetor ordenado, ou vetor não ordenado?
    */
    vetor ordenado

    /*
    Suponha que sua aplicação terá um número enorme de operações max e apenas algumas poucas operação insert e delMax. Qual implementação de PQ devo usar: heap, vetor ordenado, ou vetor não ordenado?
    */
    heap

