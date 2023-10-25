//202017049
//Pedro Lucas Santana

//placas.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_PLACAS 100005

struct placa {
    int id;
    int num;
};

struct heap {
    struct placa placas[MAX_PLACAS];
    int size;
};

void push(struct heap *h, struct placa p) {
    h->placas[++h->size] = p;
    int i = h->size;
    while (i > 1 && h->placas[i].num < h->placas[i / 2].num) {
        struct placa temp = h->placas[i];
        h->placas[i] = h->placas[i / 2];
        h->placas[i / 2] = temp;
        i = i / 2;
    }
}

struct placa pop(struct heap *h) {
    struct placa ret = h->placas[1];
    h->placas[1] = h->placas[h->size--];
    int i = 1;
    while (i * 2 <= h->size) {
        int child = i * 2;
        if (child + 1 <= h->size && h->placas[child + 1].num < h->placas[child].num) {
            child++;
        }
        if (h->placas[child].num < h->placas[i].num) {
            struct placa temp = h->placas[i];
            h->placas[i] = h->placas[child];
            h->placas[child] = temp;
            i = child;
        } else {
            break;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    struct heap h;
    h.size = 0;
    int op, n, id = 0;
    while (scanf("%d", &op) != EOF) {
        if (op == 1) {
            scanf("%d", &n);
            struct placa p;
            p.id = ++id;
            p.num = n;
            push(&h, p);
        } else if (op == 2) {
            scanf("%d", &n);
            struct placa p;
            for (int i = 0; i < n; i++) {
                p = pop(&h);
                printf("%d ", p.num);
            }
            printf("\n");
            push(&h, p);
        }
    }
    return 0;
}