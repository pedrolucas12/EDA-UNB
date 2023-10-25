#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100000

struct node {
    unsigned long long address;
    unsigned long long next;
    unsigned long long prev;
};

struct node memory[MAX];
int count = 0;

int get_index(unsigned long long address) {
    for (int i = 0; i < count; i++) {
        if (memory[i].address == address) {
            return i;
        }
    }
    return -1;
}

bool is_sane(unsigned long long ptr1, unsigned long long ptr2) {
    int index1 = get_index(ptr1);
    int index2 = get_index(ptr2);
    while (index1 != -1 && index2 != -1 && memory[index1].next != memory[index2].address) {
        index1 = get_index(memory[index1].next);
        index2 = get_index(memory[index2].prev);
    }
    return index1 != -1 && index2 != -1 && memory[index1].next == memory[index2].address;
}

int main() {
    unsigned long long ptr1, ptr2;
    scanf("%llx %llx %llx", &ptr1, &ptr1, &ptr2);
    scanf("%llx %llx %llx", &ptr2, &ptr2, &ptr2);
    while (scanf("%llx %llx %llx", &memory[count].address, &memory[count].prev, &memory[count].next) != EOF) {
        count++;
    }
    if (is_sane(ptr1, ptr2)) {
        printf("sana\n");
    } else {
        printf("insana\n");
    }
    return 0;
}