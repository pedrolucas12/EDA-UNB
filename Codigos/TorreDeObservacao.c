//Pedro Lucas Santana
//202017049

//Torre de Observação

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 105
#define MAX_T 105

int n, m, t, h[MAX_T], ans;
char g[MAX_N][MAX_N];

int max(int a, int b) {
  return a > b ? a : b;
}

int min(int a, int b) {
  return a < b ? a : b;
}

void floodfill(int x, int y, int h) {
  if (x < 0 || x >= n || y < 0 || y >= m)
    return;
  if (g[x][y] == '#' && abs(x - h) <= h) {
    g[x][y] = '.';
    ans++;
    floodfill(x - 1, y, h);
    floodfill(x + 1, y, h);
    floodfill(x, y - 1, h);
    floodfill(x, y + 1, h);
  }
}

int main() {
  int i, j, k, x, y;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++)
    scanf("%s", g[i]);
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d", &h[i]);
    for (j = 0; j < n; j++)
      for (k = 0; k < m; k++)
        if (g[j][k] == 't') {
          x = j;
          y = k;
          break;
        }
    floodfill(x, y, h[i]);
  }
  printf("%d\n", ans);
  for (i = 0; i < n; i++)
    printf("%s\n", g[i]);
  return 0;
}