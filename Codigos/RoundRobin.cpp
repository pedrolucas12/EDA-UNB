#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int execution_time;
    int remaining_time;
} Process;

void round_robin_scheduling(Process *processes, int n, int time_slice) {
    int current_time = 0;
    int *completion_times = (int *)malloc(n * sizeof(int));
    int *turnaround_times = (int *)malloc(n * sizeof(int));
    int completed_processes = 0;

    while (completed_processes < n) {
        for (int i = 0; i < n; i++) {
            Process *process = &processes[i];

            if (process->remaining_time > 0) {
                int execution_time = (process->remaining_time < time_slice) ? process->remaining_time : time_slice;
                current_time += execution_time;
                process->remaining_time -= execution_time;

                if (process->remaining_time == 0) {
                    completion_times[i] = current_time;
                    turnaround_times[i] = current_time - process->execution_time;
                    completed_processes++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d (%d)\n", processes[i].pid, completion_times[i] * 1000);
    }

    free(completion_times);
    free(turnaround_times);
}

int main() {
    int n, time_slice;
    scanf("%d", &n);
    scanf("%d", &time_slice);

    Process *processes = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        int pid, execution_time;
        scanf("%d %d", &pid, &execution_time);

        processes[i].pid = pid;
        processes[i].execution_time = execution_time;
        processes[i].remaining_time = execution_time;
    }

    round_robin_scheduling(processes, n, time_slice);

    free(processes);

    return 0;
}
