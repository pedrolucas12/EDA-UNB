from collections import deque

# Function to read input and initialize data structures
def initialize():
    processes = []
    n = int(input())
    t = int(input())
    for i in range(n):
        pid, time = [int(x) for x in input().split()]
        processes.append((pid, time*1000)) # convert time to milliseconds
    processes.sort(key=lambda x: x[1]) # sort by arrival time
    queue = deque(processes) # initialize process queue
    return t, queue

# Function to implement round-robin scheduling
def schedule(t, queue):
    current_time = 0
    output = []
    while queue:
        pid, time = queue.popleft()
        if time <= t:
            output.append((pid, current_time + time))
            current_time += time
        else:
            output.append((pid, current_time + t))
            queue.append((pid, time - t))
            current_time += t
    return output

# Function to print output
def print_output(output):
   
