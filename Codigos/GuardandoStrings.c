//Pedro Lucas Santana
//202017049

//Guardando Strings

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100005

int q, n, x;
char s[15];
int a[MAX];
int f, b;

int main()
{
    scanf("%d", &q);

    f = 0;
    b = -1;

    while (q--) {
        scanf("%s", s);

        if (!strcmp(s, "toFront")) {
            scanf("%d", &n);
            if (b == -1) {
                a[++b] = n;
            } else {
                for (int i = b; i >= 0; i--) {
                    a[i+1] = a[i];
                }
                a[0] = n;
                b++;
            }
        } else if (!strcmp(s, "push_back")) {
            scanf("%d", &n);
            a[++b] = n;
        } else if (!strcmp(s, "front")) {
            if (b == -1) {
                printf("No job for Ada?\n");
            } else {
                printf("%d\n", a[f]);
                f++;
                b--;
            }
        } else if (!strcmp(s, "back")) {
            if (b == -1) {
                printf("No job for Ada?\n");
            } else {
                printf("%d\n", a[b]);
                b--;
            }
        } else {
            if (f <= b) {
                int mid = (f+b)/2;
                for (int i = f; i <= mid; i++) {
                    int t = a[i];
                    a[i] = a[b-(i-f)];
                    a[b-(i-f)] = t;
                }
            }
        }
    }
    return 0;
}