#include <stdio.h>

int main(void)
{
    long long int n, k;
    long long int arr[100000];
    scanf("%lld", &n);
    k=n;
    for(int i=0; ; i++)
    {
        long long int sum=0;
        while(k != 0)
        {
            int a=0;
            a=k%10;
            sum+=a*a;
            k=k/10;
        }
        arr[i]=sum;
        k=sum;
        if(sum == 1)
        {
            printf("1");
            return 0;
        }
        else
        {
            for(int j=0; j<i; j++)
            {
                if(sum == arr[j])
                {
                    printf("0");
                    return 0;
                }
            }
        }
    }
}