#include<stdio.h>
int main(void)
{
    int n, x, i, j;
    long long int out=0;
    scanf("%d\n%d\n", &n, &x);
    if(n<0 || n>15 || x<-10 || x>10)
    {
        return 0;
    }
    int arr[n+1];
    for(i=0; i<n+1; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=1; i<n+1; i++)
    {
        long long int k=0;
        k=i*arr[i];
        for(j=0; j<i-1; j++)
        {
           k=k*x;
        }
        out+=k;
    }
    printf("%lld", out);
    return 0;
}