#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n;
    int arr[1005]={0};
    scanf("%d\n", &n);
    for(int i=0; i<n; i++)
    {
        char a[105];
        char b[105];
        gets(a);
        getchar();
        gets(b);
        if(a==b)
        {
            arr[i]=1;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]==1)
            printf("PASS\n");
        else
            printf("FAIL\n");
    }
    return 0;
}

// gets哪裡不對
// 可不可以直接a==b下去比