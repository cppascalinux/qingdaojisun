#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int f[1009][1009];
int v[1000009];
void dp()
{
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(j-i<1&&j+i>n)
			{
				f[i][j]=0;
				continue;
			}
			f[i][j]=1;
			if(j-i>=1)
				f[i][j]&=f[i+1][j-i];
			if(j+i<=n)
				f[i][j]&=f[i+1][j+i];
			f[i][j]^=1;
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
	freopen("c1.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",v+i);
	dp();
	for(int i=1;i<=m;i++)
		printf("%d",f[1][v[i]]);
	return 0;
}