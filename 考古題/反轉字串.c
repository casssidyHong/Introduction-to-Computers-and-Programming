#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    int n;
    scanf("%d\n", &n);
    char arr[1005][105];
    int k;
    for(int i=0; i<n; i++)
    {
        scanf("%d\n", &k);
        for(int j=0; j<k; j++)
        {
            scanf("%s ", arr[j]); // ～～這樣打問題出在哪裡～～
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=k-1; j>-1; j--)
        {
            printf("%s ", arr[j]);
        }
    }
    return 0;
}

// int 的 array 不能輸入符號 只能存數字
/*
單一字串表示

char s[105];
scanf(“%s”, s);

就是只能一行*/