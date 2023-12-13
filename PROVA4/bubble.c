// Bubble sort
void bubble_sort(int v[], int l, int r) {
    for (; r > l; r--) {
        for (int j = l; j < r; j++) {
            if (v[j] > v[j + 1]) {
                exch(v[j], v[j + 1]);
            }
        }
    }
}
