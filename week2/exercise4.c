#include <stdio.h>

void separate_function(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

int main()
{
  int a;
  int b;
  scanf("%d", &a);
  scanf("%d", &b);
  separate_function(&a, &b);
  printf("%d\n", a);
  printf("%d\n", b);
}
