#include <stdio.h>
#include <stdlib.h>
int main(){
  int child;
  int maxLen = 1024;
  char input[maxLen];
  fgets(input, maxLen, stdin);
  child = fork();
  if (child == 0){
    system(input);
  }
  return 0;
}
