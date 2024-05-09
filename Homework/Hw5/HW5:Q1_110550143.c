#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, j;
    char s[11];
    char ans='T';
    int key[15]={0};
    int arr[15][15];
     for(int i=0; i<10; i++)
     {
         key[i]=1;
         scanf("%1c", &s[i]);
         if(s[i]=='A')
             arr[i][1]=10;
         else if(s[i]=='B')
             arr[i][1]=11;
         else if(s[i]=='C')
             arr[i][1]=12;
         else if(s[i]=='D')
             arr[i][1]=13;
         else if(s[i]=='E')
             arr[i][1]=14;
         else if(s[i]=='F')
             arr[i][1]=15;
         else if(s[i]=='G')
             arr[i][1]=16;
         else if(s[i]=='H')
             arr[i][1]=17;
         else if(s[i]=='I')
             arr[i][1]=34;
         else if(s[i]=='J')
             arr[i][1]=18;
         else if(s[i]=='K')
             arr[i][1]=19;
         else if(s[i]=='L')
             arr[i][1]=20;
         else if(s[i]=='M')
             arr[i][1]=21;
         else if(s[i]=='N')
             arr[i][1]=22;
         else if(s[i]=='O')
             arr[i][1]=35;
         else if(s[i]=='P')
             arr[i][1]=23;
         else if(s[i]=='Q')
             arr[i][1]=24;
         else if(s[i]=='R')
             arr[i][1]=25;
         else if(s[i]=='S')
             arr[i][1]=26;
         else if(s[i]=='T')
             arr[i][1]=27;
         else if(s[i]=='U')
             arr[i][1]=28;
         else if(s[i]=='V')
             arr[i][1]=29;
         else if(s[i]=='W')
             arr[i][1]=32;
         else if(s[i]=='X')
             arr[i][1]=30;
         else if(s[i]=='Y')
             arr[i][1]=31;
         else if(s[i]=='Z')
             arr[i][1]=33;
         else {
             key[i] = 0;
         }

         for(int j=2; j<11; j++)
         {
             scanf("%1d", &arr[i][j]);
             if(arr[i][2] != 1 && arr[i][2] != 2) {
                 key[i] = 0;
             }
             if(arr[i][j] < 0) {
                 key[i] = 0;
             }
         }
         getchar();
     }

     int play[15]={0};
     for(int i=0; i<10; i++)
     {
         int num=1;
         if(play[i]==1)
            continue;
         for(int h=i+1; h<11; h++) 
         {

                int k=1;
                while(k<11 && arr[i][k]==arr[h][k]) 
                {
                    k++;
                }
                if(k==11)
                {
                    num++;
                    play[h]=1;
                }
         }
         int sum=arr[i][1]/10+arr[i][1]%10*9; 
         for(int p=2; p<10; p++)
         {
            sum+=(10-p)*arr[i][p];
         }
         sum+=arr[i][10];
         if(sum%10 != 0) {
             key[i] = 0;
         }
         if(play[i] == 0)
         {
             printf("%c", s[i]);
             for(int q=2; q<11; q++) 
                 printf("%d", arr[i][q]);
             if(key[i] == 0)
                 ans='F';
             else if(key[i] == 1)
                 ans='T';
             printf(" (%c, %d)\n", ans, num);
         }
     }
    return 0;
}