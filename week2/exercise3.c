#include <stdio.h>

int main()
{
  int height;
  int width;
  scanf("%d", &height);
  width = 2*height-1;
  for (int i=0; i<height; i++)
  {
    for (int k=1; k<=width; k++)
    {
      int temp = (width/2)+1;
      //printf("temp = %d\n", temp);
      int diff = (2*i+1)/2;
      //printf("diff = %d\n", diff);
      if (k >= temp-diff & k <= temp+diff)
      {
        printf("*");
      } else
      {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
