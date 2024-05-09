#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  int a, i, j;
  scanf("%d\n", &a);
  if(a<1 || a>105)
  {
    return 0;
  }
  int arr[a];
  for(i=0; i<a-1; i++)
  {
    scanf("%d ", &arr[i]);
    if(arr[i]<0 || arr[i]>105)
    {
      return 0;
    }
  }
  if(arr[0]==0)
  {
     printf("false");
     return 0;
  }
  for(j=1; ; j++) 
  {
    if(arr[a-1-j]!=0)
    {
      if(j-arr[a-1-j]<=0)
      {
         printf("true");
         break;
      }
    }
    else if(j==a)
    {
      printf("false");
      break;
    }
  }
  return 0;
}

