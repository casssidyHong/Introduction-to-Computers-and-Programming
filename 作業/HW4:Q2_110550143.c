#include<stdio.h>
int main(void)
{
    int n, target, i, j;
    long long int time=0, k;
    scanf("%d\n%d\n", &n, &target);
    int arr[n];
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    if(target==0)
    {
        printf("0");
        return 0;
    }
    for(i=0; i<n; i++)
    {
        j=i+1;
        k=arr[i];
        while(k<target)
        {
            time++;
            k=k*arr[j];
            if(j>=n)
                break;
            j++;
        }
    }
    printf("%lld", time);
    return 0;
}