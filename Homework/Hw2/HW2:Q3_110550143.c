#include <stdio.h>
int main(void) 
{
	int n, i, j;
	scanf("%d", &n);
	if(n==0)
	{
		printf("NULL");
	}
	else
	{
		for(i=1; i<=n; i++) 
		{
			for(j=1; j<=i; j++)
			{
				if(i%2==1)
				{
					if(j%2==0)
					{
						printf("0");
					}
					else
					{
						printf("1");
					}
				}
				else
				{
					if(j%2==0)
					{
						printf("1");
					}
					else
					{
						printf("0");
					}
				}
			}
			printf("\n");
		}
	}
	return 0;
}