#include <stdlib.h>
#include <stdio.h>
int n, vec[1005];

void printNumbers(int cur)
{
    printf("%d", vec[0]);
    for (int i = 1; i <= cur; i++)
    {
        printf("+%d", vec[i]);
    }
    printf("\n");
}

void rec(int vec[1005], int num, int sum, int cur) 
{
    for (int i=num; i<=n; i++) 
    {
        if (sum+i>n)
        {
            return;
        }
        if (sum+i<n) 
        {
            vec[cur]=i;
            rec(vec, i, sum + i, cur+1);
        }
        if (sum+i==n) 
        {
            vec[cur]=i;
            printNumbers(cur);
            return;
        }
    }
    return;
}

int main() 
{
    scanf("%d", &n);
    for (int i=1; i<=n/2; i++) 
    {
        vec[0]=i;
        rec(vec, i, i, 1);
    }
    printf("%d\n", n);
    return 0;
}