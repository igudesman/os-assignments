#include <stdio.h>
#include <stdlib.h>
int main(){
  int child;
  int maxLen = 1024;
  char input[maxLen];

  child = fork();
  while (1){
    if (child == 0){
      printf("CHILD >> ");
      fgets(input, maxLen, stdin);
      system(input);
    }
  }
  return 0;
}
