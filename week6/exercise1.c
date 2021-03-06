#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

struct Process {
  int burst_time;
  int arrival_time;
  int waiting_time;
  int completion_time;
  int turn_around_time;
};

void find_waiting_time(struct Process *arr, int size) {
  (arr)->waiting_time = 0;   
  for (int i = 1; i < size; i++) {
    (arr+i)->waiting_time = abs((arr+i-1)->burst_time + (arr+i-1)->waiting_time + (arr+i-1)->arrival_time - (arr+i)->arrival_time);
  }

  for (int i = 0; i < size; i++) {
    printf("Waiting time of %d process: %d\n", i, (arr+i)->waiting_time);
  }
}

void completion_time(struct Process *arr, int size) {
  (arr)->completion_time = arr->arrival_time + arr->burst_time;
  printf("The completion time of 0 process: %d\n", arr->completion_time);
  for (int i = 1; i < size; i++) {
    int temp = MAX((arr+i-1)->completion_time + (arr+i)->burst_time, (arr+i)->arrival_time + (arr+i)->burst_time);
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

float average_turn_around_time(struct Process *arr, int size) {
  float total_time = 0;
  for (int i = 0; i < size; i++) {
    total_time += (arr+i)->turn_around_time;
  }
  return total_time/size;
}

float average_waiting_time(struct Process *arr, int size) {
  float total_time = 0;
  for (int i = 0; i < size; i++) {
    total_time += (arr+i)->waiting_time;
  }
  return total_time/size;
}



int main(void) {
  int n; // number of processes
  printf("Indicate the number of processes: ");
  scanf("%d", &n);
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

  find_waiting_time(processes, n);
  completion_time(processes, n);
  turn_around_time(processes, n);

  printf("Average turn around time: %f\n", average_turn_around_time(processes, n));
  printf("Average waiting time: %f\n", average_waiting_time(processes, n));

  free(processes);
  return 0;
}