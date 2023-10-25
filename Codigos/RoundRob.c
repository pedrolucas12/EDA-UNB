#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int pid;
    int remaining_time;
    struct Node* next;
} Node;

Node* createNode(int pid, int remaining_time) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->pid = pid;
    newNode->remaining_time = remaining_time;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        Node* last = (*head)->next;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
}

void deleteNode(Node** head, Node* target) {
    if (*head == NULL) {
        return;
    }

    if (*head == target) {
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        if (*head == (*head)->next) {
            *head = NULL;
        } else {
            *head = (*head)->next;
            last->next = *head;
        }
    } else {
        Node* current = *head;
        while (current->next != *head && current->next != target) {
            current = current->next;
        }
        if (current->next == *head) {
            return;
        }
        current->next = target->next;
    }

    free(target);
}

void roundRobinScheduling(int num_processes, int time_quantum, int* pids, int* execution_times) {
    Node* head = NULL;

    for (int i = 0; i < num_processes; i++) {
        Node* newNode = createNode(pids[i], execution_times[i] * 1000);
        insertNode(&head, newNode);
    }

    Node* current = head;
    int current_time = 0;

    while (head != NULL) {
        if (current->remaining_time > time_quantum) {
            current_time += time_quantum;
            current->remaining_time -= time_quantum;
            current = current->next;
        } else {
            Node* nextProcess = current->next;
            current_time += current->remaining_time;
            printf("%d (%d)\n", current->pid, current_time);

            deleteNode(&head, current);
            current = nextProcess;
        }
    }
}

int main() {
    int num_processes;
    int time_quantum;

    scanf("%d", &num_processes);
    scanf("%d", &time_quantum);

    int* pids = (int*)malloc(num_processes * sizeof(int));
    int* execution_times = (int*)malloc(num_processes * sizeof(int));

    for (int i = 0; i < num_processes; i++) {
        scanf("%d", &pids[i]);
        scanf("%d", &execution_times[i]);
    }

    roundRobinScheduling(num_processes, time_quantum, pids, execution_times);

    free(pids);
    free(execution_times);

    return 0;
}
