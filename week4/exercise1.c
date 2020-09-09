/*
The process ID (n) surpasses the parent's PID by one => getpid()-n=-1
*/

#include<stdio.h>

int main(){
  int n;
  n=fork();
  if (n==0){
    printf("Hello from child %d", getpid()-n);
  } else{
    printf("Hello from parent %d", getpid()-n);
  }
  printf("\n");
  return 0;

}
