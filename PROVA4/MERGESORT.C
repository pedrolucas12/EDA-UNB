void merge(long long *v, long long l, long long m, long long r) {
    long long *auxiliar = malloc(sizeof(long long) * (r - l + 1));

    long long i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
        auxiliar[k++] = v[i] <= v[j] ? v[i++] : v[j++];

    while (i <= m)
        auxiliar[k++] = v[i++];
    while (j <= r)
        auxiliar[k++] = v[j++];

    k = 0;

    for (i = l; i <= r; i++)
        v[i] = auxiliar[k++];

    free(auxiliar);
}

void merge_sort(long long *v, long long l, long long r) {
    if (r <= l)
        return;

    long long meio = (l + r) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio + 1, r);
    merge(v, l, meio, r);
}