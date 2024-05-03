#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MOD 1000

int main()
{
    int n;
    int arr[35]={0};
    scanf("%d\n", &n);
    for(int i=0; i<n; i++)
    {
        long long int total=0;
        char s[3];
        scanf("%3s", s);
        getchar();
        if(s=='sum') //～～為什麼不能這樣打～～
        {
            while(getchar()!= EOF)
            {
                total=total+getchar();
                total=total%MOD;
                getchar();
            }
            arr[i]=total;
        }
        else if(s=='sub')
        {
            getchar()=total; //第一個字是初始值 ～～為什麼不能這樣打～～
            getchar(); //吃掉空白鍵
            while(getchar()!= EOF) //有字元存在
            {
                total=total-getchar();
                total=total%MOD;
                getchar(); //吃掉空白鍵
            }
            arr[i]=total;
        }
        else if(s=='pow')
        {
            getchar()=total;
            getchar();
            while(getchar()!= EOF)
            {
                for(int j=1; j<getchar(); j++)
                {
                    total=total*total;
                    total=total%MOD;
                }
                getchar();
            }
            arr[i]=total;
        }
    }
    for(int i=0; i<n; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
