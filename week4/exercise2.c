/*
Fork #1 creates an additional processes. You now have two processes.
Fork #2 is executed by two processes, creating two processes, for a total of four.
Fork #3 is executed by four processes, creating four processes, for a total of 8.
*/
#include <stdio.h> 

int main(){
  int k;
  for (int i=0; i<5; i++){
    k=fork();
    sleep(5);
  }
}
