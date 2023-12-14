long long busca_binaria(long long *v, long long n, long long dado) {
    long long l = 0, h = n;

    while (l < h) {
        long long  meio = l + (h - l) / 2;

        if(dado == v[meio])
            return meio;
        else if (dado < v[meio])
            h = meio;
        else
            l = meio + 1;
    }

    return -1;
}