#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, i, j; 
    long long int t, max=0;
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[i]>=arr[j])
            {
                t=arr[j]*(j-i);
            }
            else
            {
                t=arr[i]*(j-i);
            }
            if(t>max)
            {
                max=t;
            }
        }
    }
    printf("%lld", max);
    return 0;
}