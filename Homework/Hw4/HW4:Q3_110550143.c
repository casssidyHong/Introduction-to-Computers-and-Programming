#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, i, num=0;
    scanf("%d\n", &n);
    int arr[n];
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            num++;
        }
        else
            printf("%d ", arr[i]);
    }
    for(i=0; i<num; i++)
    {
        printf("0 ");
    }
    return 0;
}