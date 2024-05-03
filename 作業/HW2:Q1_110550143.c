#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  int a, b, x, y, i, j, k, l, t;
  scanf("%d,%d", &a, &b);
  int A[a][b];
  for(i=0; i<a; i++)
  {
    for(j=0; j<b; j++)
    {
      scanf("%d,", &A[i][j]);
    }
  }
  scanf("%d,%d", &x, &y);
  int B[x][y];
  for(i=0; i<x; i++)
  {
    for(j=0; j<y; j++)
    {
      scanf("%d,", &B[i][j]);
    }
  }
  if(b!=x)
  {
    printf("Wrong dimensions!");
    return 0;
  }
  for(i=0; i<a; i++)
  {
    for(j=0; j<y; j++)
    {
        t=0; 
        for(k=0, l=0; k<b, l<x; k++, l++)
        {
         t+=A[i][l]*B[k][j];
        }
        printf("%d,", t);
    }
    printf("\n");
  }
  return 0;
}