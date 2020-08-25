#include <stdio.h>
#include <limits.h>
#include <float.h>
int main()
{
  int a = INT_MAX;
  float b = FLT_MAX;
  double c = DBL_MAX;
  printf("The size of integer: %lu\n", sizeof(a));
  printf("The size of float: %lu\n", sizeof(b));
  printf("The size of double: %lu\n", sizeof(c));
  return 0;
}
