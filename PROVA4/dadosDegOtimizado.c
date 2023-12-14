#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lesseq(a, b) (a <= b)

struct Item {
    int len;
    char c;
    int pos;
};

void insertionSort(struct Item *v, int tamanho) {
    int i, j;
    struct Item chave;
    for (i = 1; i < tamanho; i++) {
        chave = v[i];
        j = i - 1;

        while (j >= 0 && v[j].len > chave.len) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = chave;
    }
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

    insertionSort(drink, index_drink);

    for (int i = 0; i < index_drink; i++)
        printf("%d %c %d\n", drink[i].len, drink[i].c, drink[i].pos);

    return 0;
}
