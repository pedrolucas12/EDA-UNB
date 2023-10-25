//Pedro Lucas Santana
//202017049

//Adaqueu

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

struct Deque {
    int front, back, size;
    int arr[MAX];
};

void init(struct Deque *dq) {
    dq->front = dq->size = 0;
    dq->back = MAX - 1;
}

void push_front(struct Deque *dq, int item) {
    if (dq->size == MAX) return;
    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->arr[dq->front] = item;
    dq->size++;
}

void push_back(struct Deque *dq, int item) {
    if (dq->size == MAX) return;
    dq->back = (dq->back + 1) % MAX;
    dq->arr[dq->back] = item;
    dq->size++;
}

void pop_front(struct Deque *dq) {
    if (dq->size == 0) return;
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
}

void pop_back(struct Deque *dq) {
    if (dq->size == 0) return;
    dq->back = (dq->back - 1 + MAX) % MAX;
    dq->size--;
}

int front(struct Deque *dq) {
    if (dq->size == 0) return -1;
    return dq->arr[dq->front];
}

int back(struct Deque *dq) {
    if (dq->size == 0) return -1;
    return dq->arr[dq->back];
}

void reverse(struct Deque *dq) {
    int i, j, temp;
    for (i = 0, j = dq->size - 1; i < j; i++, j--) {
        temp = dq->arr[i];
        dq->arr[i] = dq->arr[j];
        dq->arr[j] = temp;
    }
}

int main() {
    int q, i;
    char command[10];
    int item;
    struct Deque dq;

    scanf("%d", &q);
    init(&dq);

    for (i = 0; i < q; i++) {
        scanf("%s", command);
        if (strcmp(command, "back") == 0) {
            item = back(&dq);
            if (item == -1) {
                printf("No job for Ada?\n");
            } else {
                pop_back(&dq);
                printf("%d\n", item);
            }
        } else if (strcmp(command, "front") == 0) {
            item = front(&dq);
            if (item == -1) {
                printf("No job for Ada?\n");
            } else {
                pop_front(&dq);
                printf("%d\n", item);
            }
        } else if (strcmp(command, "reverse") == 0) {
reverse(&dq);
} else if (strcmp(command, "push_back") == 0) {
scanf("%d", &item);
push_back(&dq, item);
} else if (strcmp(command, "toFront") == 0) {
scanf("%d", &item);
push_front(&dq, item);
}
}
return 0;
}