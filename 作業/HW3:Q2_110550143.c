#include<stdio.h>
int main(void)
{
  int n, t, m, i;
  m=0;
  scanf("%d\n%d", &n, &t);
  if(n<0 || n>1000)
  {
    ;
  }
  int arr[n];
  for(i=0; i<n; i++) 
  {
    scanf("%d ", &arr[i]);
  }
  for(i=0; i<n-1; i++) 
  {
    if(arr[i]<arr[i+1])
    {
      m=m+arr[i+1]-arr[i];
    }
    else
    {
      m=m;
    }
  }
  printf("%d", m);
  return 0;
}