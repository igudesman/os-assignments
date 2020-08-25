#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 40

int main()
{
  char str[MAX_LIMIT];
  fgets(str, MAX_LIMIT, stdin);
  int len = strlen(str);
  for (int i=len-1; i>=0; i--)
  {
    printf("%c", str[i]);
  }
  printf("\n");
  return 0;
}
