//INSERTION SORT
void insertion_sort(int v[], int l, int r)
{
    int elem, i, j;
    for (i = l + 1; i <= r; i++)
    {
        elem = v[i];
        for (j = i; j > l && elem < v[j - 1]; j--)
            v[j] = v[j - 1]; // puxando o maior

        v[j] = elem; // encaixando o elemento
    }
}


// SHELL SORT
void shell_sort(int v[], int l, int r)
{
    int h = 1;
    while (h < (r - l + 1) / 3)
        h = 3 * h + 1;

    while (h >= 1)
    {
        for (int i = l + h; i <= r; i++)
        {
            for (int j = i; j >= l + h && v[j] < v[j - h]; j -= h)
            {
                exch(v[j], v[j - h]);
            }
        }
        h = h / 3;
    }
}
