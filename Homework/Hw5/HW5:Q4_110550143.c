#include <stdio.h>

int main()
{
    int w, h, a;
    int ans=60;
    int arr[55][205]={{0},{0}};
    scanf("%d %d", &w, &h);
    for(int i=1; i<=h; i++) //看有幾列就輸幾個陣列
    {
        for(int sum=0; sum<w; ) //橫的陣列如果剛好=sum
        {
            scanf("%d", &a);
            sum+=a;
            arr[i][sum]=1;
        }
    }
    /*for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }*/
    for(int i=1; i<w; i++)
    {
        int n=0;
        for(int j=1; j<=h; j++)
        {
            if(arr[j][i] == 0)
                n++;
        }
        if(ans>n)
        {
            ans=n;
        }
    }
    printf("%d", ans);
    return 0;
}
