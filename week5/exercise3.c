// Critical region happens when Producer and Consumer appeal the same cell of memory (in array)
/* 
Array should look like this (1 1 1 .. 1 0 0 0 ... 0), 
every 100~10seconds iterations array is printed (so if it does not satisfy the template => raise condition occured)
*/
#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 10
int full = 0, empty = BUFFER_SIZE;
int arr[BUFFER_SIZE];

void produce() {
  arr[full] = 1;
  full++;
  empty--;
  //printf("Produce operation has been completed\n");
}

void consume() {
  full--;
  empty++;
  arr[full] = 0/arr[full];
  //printf("Consume operation has been completed\n");
}

void* thread_action (int* k) {
  int n = *k % 2;
  if (n == 0) {
    int count = 0;
    while (1) {
      count++;
      if (empty != 0){
        produce();
      }
      if (count == 100) {
        for (int i=0; i<BUFFER_SIZE; i++) {
          printf("%d ", arr[i]);
        }
        printf("\n");
      }
    }
  } else {
    while (1) {
      if (full != 0){
        consume();
      }      
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