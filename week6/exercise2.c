#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

struct Process {
  int id;
  int burst_time;
  int arrival_time;
  int waiting_time;
  int completion_time;
  int turn_around_time;
  bool is_finished;
};

void find_waiting_time(struct Process *arr, int size) {
  (arr)->waiting_time = 0;   
  for (int i = 1; i < size; i++) {
    (arr+i)->waiting_time = abs((arr+i-1)->burst_time + (arr+i-1)->waiting_time + (arr+i-1)->arrival_time - (arr+i)->arrival_time);
  }

  for (int i = 0; i < size; i++) {
    printf("Waiting time of %d process: %d\n", arr[i].id, (arr+i)->waiting_time);
  }
}

void completion_time(struct Process *arr, int size) {
  (arr)->completion_time = arr->arrival_time + arr->burst_time;
  printf("The completion time of 0 process: %d\n", arr->completion_time);
  for (int i = 1; i < size; i++) {
    int temp = MAX((arr+i-1)->completion_time + (arr+i)->burst_time, (arr+i)->arrival_time + (arr+i)->burst_time);
    printf("The completion time of %d process: %d\n", arr[i].id, temp);
    (arr+i)->completion_time = temp;
  }
}

void sort_jobs(struct Process *arr, int size) {
  int current_time = 0;
  struct Process next;
  for (int i = 0; i < size - 1; i++) {
    bool is_init = false;
    struct Process next; 
    struct Process with_min_arrival_time;
    int temp_index;
    int index = i;
    bool is_found = false;
    for (int j = i; j < size; j++) {
      if ((arr + j)->arrival_time <= current_time) {
        is_found = true;
        if (!is_init) {
          next = arr[j];
          index = j;
          is_init = true;
        } else if (arr[j].burst_time < next.burst_time) {
          next = arr[j];
          index = j;
        }
      } else {
        if (arr[j].arrival_time < with_min_arrival_time.arrival_time) {
          with_min_arrival_time = arr[j];
          temp_index = j;
        }
      }
    }
    if (!is_found) {
      next = with_min_arrival_time;
      index = temp_index;
      current_time += with_min_arrival_time.arrival_time - current_time;
    }
    struct Process temp = arr[i];
    arr[i] = arr[index];
    arr[index] = temp;
    current_time += (arr + i)->burst_time;
  }
}

void turn_around_time(struct Process *arr, int size) {
  for (int i = 0; i < size; i++) {
    int temp = (arr+i)->waiting_time + (arr+i)->burst_time;
    printf("The turn around time of %d process: %d\n", arr[i].id, temp);
    (arr+i)->turn_around_time = temp;
  }
}

void print_processes(struct Process *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("id: %d\n", (arr + i)->id);
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
  int n; // number of processes
  printf("Indicate the number of processes: ");
  scanf("%d", &n);
  printf("\n");

  struct Process *processes = malloc(n * sizeof(struct Process));

  for (int i = 0; i < n; i++) {
    int burst_time;
    int arrival_time;
    printf("Indicate the arrival time of %d process: ", i);
    scanf("%d", &arrival_time);
    printf("Indicate the burst time of %d process: ", i);
    scanf("%d", &burst_time);
    printf("\n");
    
    processes[i].burst_time = burst_time;
    processes[i].arrival_time = arrival_time;
    processes[i].id = i;
  }

  sort_jobs(processes, n);

  find_waiting_time(processes, n);
  completion_time(processes, n);
  turn_around_time(processes, n);

  average_turn_around_time(processes, n);
  average_waiting_time(processes, n);

  free(processes);
  return 0;
}
