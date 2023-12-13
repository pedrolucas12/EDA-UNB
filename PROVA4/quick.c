//QUICKSORT
void quick_sort(int *v, int l, int r)
{
    if (r <= l)
        return; // vetor de tamanho 1
    int p = partition(v, l, r);
    quick_sort(v, l, p - 1);
    quick_sort(v, p + 1, r);
}

// Partition
int partition(int *v, int l, int r)
{
    int i = l - 1;
    int j = r;
    int pivot = v[r];
    while (i < j) // i e j se cruzam ?
    {
        while (v[++i] < pivot)
            ;
        while (v[--j] >= pivot && j > l)
            ; // pivot <v[ - -j]
        if (i < j)
            exch(v[i], v[j]); // troca v[i] com v[j]
    }
    exch(v[i], v[r]); // troca v[i] com v[r]
    return i;
}

//Partion Cornem
int partitionCORMEM(int *v, int l, int r)
{
    int pivot = v[r];
    int j = l;
    int i = l;
    while (i < r)
    {
        if (less(v[i], pivot))
        {
            exch(v[i], v[j]);
            j++;
        }
        i++;
    }
    exch(v[r], v[j]);
    return j;
}
