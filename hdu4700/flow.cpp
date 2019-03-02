#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F
using namespace std;
int n;
int mat[109][109];
int f[109][109],g[109][109];
int dis[109],vis[109],pre[109];
void prim()
{
	memset(dis,0x80,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(pre,0,sizeof(pre));
	memset(f,-1,sizeof(f));
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		int p=0;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dis[j]>dis[p])
				p=j;
		vis[p]=1;
		f[pre[p]][p]=f[p][pre[p]]=mat[p][pre[p]];
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dis[j]<mat[p][j])
			{
				dis[j]=mat[p][j];
				pre[j]=p;
			}
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 		printf("%d ",f[i][j]);
	// 	printf("\n");
	// }
}
void dfs(int x,int fa,int st,int mn)
{
	g[st][x]=x==st?-1:mn;
	for(int i=1;i<=n;i++)
		if(i!=fa&&f[x][i]>-1)
			dfs(i,x,st,min(mn,f[x][i]));
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("flow.in","r",stdin);
	freopen("flow.out","w",stdout);
#endif
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",mat[i]+j);
		prim();
		for(int i=1;i<=n;i++)
			dfs(i,0,i,inf);
		int fg=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(mat[i][j]!=g[i][j])
					fg=0;
		if(!fg)
			printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
					printf("%d ",i==j?-1:(f[i][j]==-1?0:f[i][j]));
				printf("\n");
			}
		}
	}
	return 0;
}