#include <stdio.h>

void bubble_sort(int* a, int size){
  for (int i=0; i<size; i++){
    for (int j=1; j<size-i; j++){
      if (a[j] < a[j-1]){
        int temp = a[j];
        a[j] = a[j-1];
        a[j-1] = temp;
      }
    }
  }
}

void print_array(int* a, int size){
  for (int i=0; i<size; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main(){
  int size = 10;
  int b[] = {23, 1, 2, 3, 4, 5, 6, 1, 1, 1};
  bubble_sort(b, size);
  print_array(b, size);
  return 0;
}
