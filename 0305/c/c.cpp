#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F
using namespace std;
int n,m;
char s[50009];
int v[50009];
int f[1009][1009],g[1009][1009],mx[1009][1009];
void init()
{
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			int k=0;
			while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k])
				k++;
			f[i][j]=f[j][i]=k;
		}
	// for(int i=1;i<=n;i++)
	// 	for(int j=1;j<=n;j++)
	// 		printf("i:%d j:%d f:%d\n",i,j,f[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			mx[i][j]=max(mx[i][j-1],v[j]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			for(int k=i;k<=j;k++)
				for(int l=k+1;l<=j;l++)
					g[i][j]=max(g[i][j],min(f[k][l],j-l+1));
}
void solve(int l,int r,int x)
{
	int ans=inf;
	for(int i=l;i<=r;i++)
		for(int j=i;j<=r;j++)
		{
			int t=g[i][j];
			if(t>=x)
				ans=min(ans,mx[i][j]);
		}
	printf("%d\n",ans<inf?ans:-1);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",v+i);
	init();
	for(int i=1,a,b,c;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		solve(a,b,c);
	}
	return 0;
}