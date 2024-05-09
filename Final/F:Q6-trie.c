#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define int long long

int akari[43210][128],size[43210],sagiri[43210];
bool flag[43210],hikari[43210];
char s[999];
int root=1,pp=2;
bool nono[43210];

char ans[999];

void dfs(int cur,int dd)
{
	
	if(flag[cur] && dd)
	{
		printf("D %s %lld\n",ans,sagiri[akari[cur]['/']]);
	}
	if(hikari[cur])
	{
		printf("F %s %lld\n",ans,size[cur]);
	}
	for(int i=0;i<128 && !(nono[cur] && dd);i++)
	{
		if(akari[cur][i])
		{
			ans[dd]=i;
			
			dfs(akari[cur][i],dd+1);
			ans[dd]='\0';
		}
	}
}

ddfs(int cur)
{
	sagiri[cur]=size[cur];
	for(int i=0;i<128;i++)
	{
		if(akari[cur][i])
		{
			ddfs(akari[cur][i]);
			sagiri[cur]+=sagiri[akari[cur][i]];
		}
	}
}

signed main()
{
	int T;
	int a,i,n,cur,last;
	
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%s%lld",s,&a);
		n=strlen(s);
		cur=root;
		last=0;
		for(i=0;i<n;i++)
		{
			if(!akari[cur][s[i]])
			{
				akari[cur][s[i]]=pp++;
			}
			cur=akari[cur][s[i]];
			if(s[i]=='/')
			{
				flag[last]=1;
				nono[cur]=1;
			}
			last=cur;
		}
//		sagiri[last]+=a;
		size[cur]=a;
		hikari[cur]=1;
	}
	ddfs(root);
	
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%s",s);
		n=strlen(s);
		if(s[n-1]!='/')
		{
			s[n++]='/';
		}
		
		cur=root;
		for(i=0;i<n;i++)
		{
			cur=akari[cur][s[i]];
		}
		if(!cur)
		{
			puts("invalid path\n");
			continue;
		}
		
		dfs(cur,0);
		puts("");
	}
}
