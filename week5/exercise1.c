#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_action(int* k) {
  printf("Printing from thread: %d\n", *k);
}

int main() {
  int n = 10;
  pthread_t * thread = malloc(sizeof(pthread_t)*n);

  for (int i=0; i<n; i++){
    printf("%d thread has been created\n", i);
    pthread_create(&thread[i], NULL, thread_action, &i);
    pthread_join(thread[i], NULL);
    printf("%d thread has been terminated\n\n", i);
  }
  exit(0);
}

