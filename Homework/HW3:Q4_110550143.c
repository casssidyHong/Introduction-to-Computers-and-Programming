#include<stdio.h>
int main(void)
{
    int n, j, i, k, h;
    scanf("%d", &n);
    int A[n], B[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &A[i], &B[i]);
    }
    for(i=0; i!=n; i++)
    {
        for(h=0; h<B[i]; h++)
        {
            for(k=1; k<A[i]+1; k++)
        {
            j=0;
            while(j<k) 
            {
                printf("%d", k);
                j++;
            }
            printf("\n");
        }
        for(k=A[i]-1; k>0; k--)
        {
            j=k;
            while(j>0)
            {
                printf("%d", k);
                j--;
            }
            printf("\n");
        }
        }
        printf("\n");
    }
    return 0;
}