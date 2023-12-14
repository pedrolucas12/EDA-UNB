#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lesseq(a, b) (a <= b)
struct Item {
    int len;
    char c;
    int pos;
};
void merge(struct Item *v, int l, int m, int r) {
	struct Item *v2 = malloc(sizeof(struct Item) * (r - l + 1));
	int k = 0, i = l, j = m+1;
    while (lesseq(i, m) && lesseq(j, r)) { //enquanto os dois vetores não estiverem vazios
		if (lesseq(v[j].len, v[i].len)) //se o valor do vetor A for menor que o valor do vetor B
			v2[k++] = v[j++];
        else
	        v2[k++] = v[i++];
    }
    while (lesseq(i, m)) //enquanto o vetor A não estiver vazio
        v2[k++] = v[i++]; //o valor do vetor A é colocado no vetor auxiliar
    while (lesseq(j, r)) 
        v2[k++] = v[j++];
    k = l;
    for(int i = 0; i <= r - l; i++) 
        v[k++] = v2[i];
}

void mergesort(struct Item *v, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergesort(v, l, m);
    mergesort(v, m+1, r);
    merge(v, l, m, r);
}

int main() {
    char s[100000];
    struct Item drink[100000];
    scanf("%s", s);
    int index = strlen(s);
    int index_drink = 0;
    for (int i = 0; i < index; i++) {
        char tocmp = s[i];
        drink[index_drink].c = s[i]; 
        drink[index_drink].pos = i;
        int j = 0;
        while (tocmp == s[i]) {
            i++;
            j++;
        }
        i--;
        drink[index_drink].len = j;
        index_drink++;
    }
    mergesort(drink, 0, index_drink);
    for (int i = index_drink; i > 0; i--) //imprime o vetor ordenado
        printf("%d %c %d\n", drink[i].len, drink[i].c, drink[i].pos);
    return 0;
}