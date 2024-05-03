#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    int arr[60];
    char c;
    scanf("%d\n", &n);
    for(int i=1; i<=n; i++)
    {
        int k=0;
        int j=0;
        int a=0, e=0, i=0, o=0, u=0;
        char letter[100];
        gets(letter);
        for(j=0; letter[j] != EOF && j<100; j++)
        {
            if(letter[j]=='A')
                a++;
            else if(letter[j]=='E')
                e++;
            else if(letter[j]=='I')
                i++;
            else if(letter[j]=='O')
                o++;
            else if(letter[j]=='U')
                u++;
        }
        if(j==1)
            k=0;
        else if(a>=e && a>=i && a>=o && a>=u)
            k=j-a;
        else if(e>=a && e>=i && e>=o && e>=u)
            k=j-e;
        else if(i>=a && i>=e && i>=o && i>=u)
            k=j-i;
        else if(o>=a && o>=e && o>=i && o>=u)
            k=j-o;
        else
            k=j-u;
        arr[i]=k;
        printf("j=%d\n", j);
    }
    /*for(int i=1; i<=n; i++)
    {
        printf("Case #%d: %d\n", i, arr[i]);
    }
    return 0;*/
}
