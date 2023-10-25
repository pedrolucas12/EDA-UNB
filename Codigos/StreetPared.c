#include <stdio.h>

#define MAX_N 1000

int n, order[MAX_N + 1];

int main() {
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &order[i]);
    }

    int i = 0, j = n - 1;
    while (i < n && order[i] == i + 1) {
      i++;
    }
    while (j >= 0 && order[j] == j + 1) {
      j--;
    }

    printf("%s\n", (i >= j) ? "yes" : "no");
  }

  return 0;
}