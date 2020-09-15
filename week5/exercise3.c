#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>

int full = 0, empty = 10, mutex = 1;


int wait() {
  return 0;
}

int wakeup() {
  return 1;
}

void produce() {
  mutex = wait();
  full++;
  empty--;
  mutex = wakeup();
}

void consume() {
  mutex = wait();
  full--;
  empty++;
  mutex = wakeup();
}

void* thread_action (int* k) {
  while (1) {
    int n = rand() % 2;
    //printf("1 to Produce\n2 to Consume\n");
    //scanf("%d", &n);
    if (n == 0) {
      if (empty != 0 && mutex == 1){
        produce();
      } else {
        printf("Buffer is full\n");
      }
    } else if (n == 1) {
      if (full != 0 && mutex == 1){
        consume();
      } else {
        printf("Buffer is empty\n");
      }
    } else {
      printf("Bad request!\n");
    }
  }
}

int main() {
  int n = 5;
  pthread_t * thread = malloc(sizeof(pthread_t)*n);

  for (int i=0; i<n; i++){
    pthread_create(&thread[i], NULL, thread_action, &i);
    pthread_join(thread[i], NULL);
  }
  exit(0);
}


