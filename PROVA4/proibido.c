#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int r1, int r2){
    int* v2 = malloc(sizeof(int) * (r2 - l + 1)); 
    int k = 0;
    int i = l;
    int j = r1 + 1;
    while(i <= r1 && j <= r2){ //enquanto os dois vetores não estiverem vazios
        if(v[i] < v[j]){
            v2[k++] = v[i++];
        }else{
            v2[k++] = v[j++];
        }
    }
    while(i <= r1){ //enquanto o vetor A não estiver vazio
        v2[k++] = v[i++]; //o valor do vetor A é colocado no vetor auxiliar
    }
    while(j <= r2){ //enquanto o vetor B não estiver vazio
        v2[k++] = v[j++];
    }
    k = 0;
    for(int i = l; i <= r2; i++){ //o vetor auxiliar é colocado no vetor original
        v[i] = v2[k++];
    }
}

void mergeSort(int *v, int l, int r){
    if(l >= r) return;
    int m = (l + r) / 2;
    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);
    merge(v, l, m , r);
}

int binarySearch(int *v, int l, int r, int key){
    int m = (l + r) / 2;
    if(l > r) return -1;
    if(v[m] == key) return m;
    if(v[m] < key){
        return binarySearch(v, m + 1, r, key);
    }else{
        return binarySearch(v, l, m - 1, key);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int vet[n];
    for(int i = 0; i < n; i++){ //leitura do vetor
        scanf("%d", &vet[i]);
    }
    mergeSort(vet, 0, n - 1);
    int read;
    while(scanf("%d", &read) != EOF){ //leitura dos valores a serem buscados
        int resultado = binarySearch(vet, 0, n - 1, read);
        if(resultado == -1) printf("nao\n");
        else printf("sim\n");
    }
}