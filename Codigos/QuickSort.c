#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SW(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int QUICK(int arr[], int low, int high) {
    srand(time(0));
    int random = low + rand() % (high - low);
    SW(&arr[random], &arr[high]);
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            SW(&arr[i], &arr[j]);
        }
    }
    SW(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = QUICK(arr, low, high);

        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i != n-1) printf(" ");
    }
    printf("\n");
    return 0;
}





