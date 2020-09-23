//First come, first served is the simplest scheduling algorithm. FIFO simply queues processes in the order that they arrive in the ready queue.
//PROS: It is quite easy to implement
//CONS: May be ineffective

//Shortest Job First executes the processes based upon their burst time in ascending order of their burst times. 
//PROS: The average waiting time for given set of processes is minimum.
//CONS: A long process may never get executed and the system may keep executing the short processes.

//Round-Robin executes the processes based upon the time quantum defined. Each process is executed for a fixed amount of time.
//PROS: The average waiting time for given set of processes is quite small and depends on the time quantum.
//CONS: If time quantum is shorter than needed, the number of times that CPU switches from one process to another process, increases. This leads to decrease in CPU efficiency.


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

struct Process {
  int burst_time;
  int arrival_time;
  int waiting_time;
  int completion_time;
  int turn_around_time;
};

void find_waiting_time(struct Process *arr, int size, int quantum) {
  int t = 0;

  int copies_of_burst_time[size]; 
  for (int i = 0 ; i < size ; i++) {
    copies_of_burst_time[i] =  (arr + i)->burst_time; 
  }

  while (1) { 
    bool done = true; 
    for (int i = 0 ; i < size; i++) { 
      if (copies_of_burst_time[i] > 0) { 
        done = false;
        if (copies_of_burst_time[i] > quantum) {
          t += quantum;
          copies_of_burst_time[i] -= quantum;
        } else {
          t += copies_of_burst_time[i];
          (arr + i)->waiting_time = t - (arr + i)->burst_time;
          printf("Waiting time of %d process: %d\n", i, (arr+i)->waiting_time);
          copies_of_burst_time[i] = 0;
        }
      }
    }
    if (done) {
      break;
    }
  }
} 

void completion_time(struct Process *arr, int size) {
  for (int i = 0; i < size; i++) {
    int temp = (arr + i)->waiting_time + (arr + i)->burst_time;
    printf("The completion time of %d process: %d\n", i, temp);
    (arr+i)->completion_time = temp;
  }
}

void turn_around_time(struct Process *arr, int size) {
  for (int i = 0; i < size; i++) {
    int temp = (arr+i)->waiting_time + (arr+i)->burst_time;
    printf("The turn around time of %d process: %d\n", i, temp);
    (arr+i)->turn_around_time = temp;
  }
}

void print_processes(struct Process *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("Burst: %d, Arrival: %d\n", (arr + i)->burst_time, (arr + i)->arrival_time);
  }
}

float average_turn_around_time(struct Process *arr, int size) {
  float total_time = 0;
  for (int i = 0; i < size; i++) {
    total_time += (arr+i)->turn_around_time;
  }
  printf("Average turn around time: %f\n", total_time/size);
  return total_time/size;
}

float average_waiting_time(struct Process *arr, int size) {
  float total_time = 0;
  for (int i = 0; i < size; i++) {
    total_time += (arr+i)->waiting_time;
  }
  printf("Average waiting time: %f\n", total_time/size);
  return total_time/size;
}

int main(void) {
  int quantum;
  int n; // number of processes
  printf("Indicate the number of processes: ");
  scanf("%d", &n);
  printf("\n");
  printf("Indicate the quantum: ");
  scanf("%d", &quantum);
  printf("\n");

  struct Process *processes = malloc(n * sizeof(struct Process));

  for (int i = 0; i < n; i++) {
    int burst_time;
    int arrival_time;
    printf("Indicate the burst time of %d process: ", i);
    scanf("%d", &burst_time);
    printf("Indicate the arrival time of %d process: ", i);
    scanf("%d", &arrival_time);
    printf("\n");
    
    processes[i].burst_time = burst_time;
    processes[i].arrival_time = arrival_time;
  }

  find_waiting_time(processes, n, quantum);
  completion_time(processes, n);
  turn_around_time(processes, n);

  average_turn_around_time(processes, n);
  average_waiting_time(processes, n);

  free(processes);
  return 0;
}
