#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

typedef long long ll;

#define SIZE 200000 // ??
int que[SIZE], l, r;

signed main() 
{
    l = r = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        que[r++] = i+1; //初始化que 第幾項就是幾
    for(int i = 0; i < n; i++) 
    {
        printf("%d\n", que[l++]); //先印第一項
        if (l == SIZE) l = 0;
        que[r++] = que[l++]; //看懂
        if (l == SIZE) l = 0; 
        if (r == SIZE) r = 0;
    }
    return 0;
}
