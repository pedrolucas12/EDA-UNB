

// Radix sort LSD (Least Significant Digit)
void radix_sortLSD(int *v, int l, int r) {
    int i, w;
    int aux[r - l + 1], count[R + 1];
    for (w = 0; w < bytesword; w++) {
        memset(count, 0, sizeof(int) * (R + 1));
        for (i = l; i <= r; i++) count[digit(v[i], w) + 1]++;
        for (i = 1; i <= R; i++) count[i] += count[i - 1];
        for (i = l; i <= r; i++) {
            aux[count[digit(v[i], w)]] = v[i];
            count[digit(v[i], w)]++;
        }
        for (i = l; i <= r; i++) v[i] = aux[i - l];
    }
}


// Radix sort MSD (Most Significant Digit) - Strings
int charAt(char s[], int d) {
    if (d < strlen(s))
        return s[d]; // d-é simo caractere
    else
        return -1; // count [-1 + 1] = count [0]
}
// Strings: ordena para o d-é simo caractere
void radixMSD(char a[][maxstring], int l, int r, int d) {
    if (r <= l) return;
    char aux[r - l + 1][maxstring];
    int count[R + 1];
    memset(count, 0, sizeof(int) * (R + 1));    // for (int i = 0; i <= R; i++) count[i] = 0;    // frequencia dos d-é simos caracteres
    for (int i = l; i <= r; i++)
        count[charAt(a[i], d) + 1]++;    // tabela de índices: calculando as posições
    for (int i = 1; i <= R; i++)
        count[i] += count[i - 1];    // redistribui as chaves: ordena em aux
    for (int i = l; i <= r; i++)
        strcpy(aux[count[charAt(a[i], d)]++], a[i]);  // copia para o original
    for (int i = l; i <= r; i++)
        strcpy(a[i], aux[i - l]);   // ordenar por subconjunto: count[0] = já ordenadas
    for (int i = 1; i <= R; i++) {       // count[i-1] posição da primeira chave com o caractere i
        radixMSD(a, l + count[i - 1], l + count[i] - 1, d + 1);
    }
}

// Radix sort MSD (Most Significant Digit) - Inteiros
void radix_sortMSD(int *v, int l, int r, int w) {
    if (r <= l || w < 0) return;
    int i, aux[r - l + 1], count[R + 1];
    memset(count, 0, sizeof(int) * (R + 1));
    for (i = l; i <= r; i++)
        count[digit(v[i], w) + 1]++;
    for (i = 1; i <= R; i++)
        count[i] += count[i - 1];
    for (i = l; i <= r; i++)
        aux[count[digit(v[i], w)]] = v[i];
    for (i = l; i <= r; i++)
        v[i] = aux[i - l];
    radix_sortMSD(v, l, l + count[0] - 1, w - 1);
    for (i = 1; i <= R; i++)
        radix_sortMSD(v, l + count[i - 1], l + count[i] - 1, w - 1);
}
