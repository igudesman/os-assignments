// Critical region happens when Producer and Consumer appeal the same cell of memory (in array)

#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>

int full = 0, empty = 3, mutex = 1;
int arr[empty];


int wait() {
  return 0;
}

int wakeup() {
  return 1;
}

void produce() {
  mutex = wait();
  arr[full] = 1;
  full++;
  empty--;
  sleep(0.1);
  mutex = wakeup();
  printf("Produce operation has been completed\n");
}

void consume() {
  mutex = wait();
  full--;
  empty++;
  arr[full] = 0;
  sleep(0.1);
  mutex = wakeup();
  printf("Consume operation has been completed\n");
}

void* thread_action (int* k) {
  while (1) {
    int n = *k % 2;
    if (n == 0) {
      if (empty != 0 && mutex == 1){
        produce();
      } else {
        while (empty == 0 || mutex == 0) {
          printf("I am waiting\n");
        }
        produce();
        //printf("Buffer is full\n");
      }
    } else if (n == 1) {
      if (full != 0 && mutex == 1){
        consume();
      } else {
        while (full == 0 || mutex == 0) {
          printf("I am waiting\n");
        }
        consume();
        //printf("Buffer is empty\n");
      }
    } else {
      printf("Bad request!\n");
    }
  }
  return NULL;
}

int main() {
  int n = 2;
  pthread_t * thread = malloc(sizeof(pthread_t)*n);
  int a = 0, b = 1;
  
  pthread_create(&thread[0], NULL, thread_action, &a);
  pthread_create(&thread[1], NULL, thread_action, &b);
  pthread_join(thread[0], NULL);
  pthread_join(thread[1], NULL);
  

  return 0;
}