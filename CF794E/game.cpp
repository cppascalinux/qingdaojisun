#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,mx,pl,pr;
int v[300009],s1[300009],s2[300009];
int ans[300009];
void init()
{
	for(int i=2;i<=n-1;i++)
		s1[i]=min(v[i],max(v[i-1],v[i+1]));
	for(int i=1;i<=n-1;i++)
		s2[i]=max(v[i],v[i+1]);
}
void solve1(int x)
{
	int len=n-x,npl,npr;
	npl=(len+1)>>1;
	npr=n-(len>>1);
	while(pl>npl)
		mx=max(mx,s1[--pl]);
	while(pr<npr)
		mx=max(mx,s1[++pr]);
	ans[x]=mx;
}
void solve2(int x)
{
	int len=n-x,npl,npr;
	npl=len>>1;
	npr=n-(len>>1);
	while(pl>npl)
		mx=max(mx,s2[--pl]);
	while(pr<npr)
		mx=max(mx,s2[++pr]);
	ans[x]=mx;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
#endif
	scanf("%d",&n);
	int tmx=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",v+i);
		tmx=max(tmx,v[i]);
	}
	ans[n-1]=tmx;
	init();
	mx=0;
	pl=(n+1)>>1;
	pr=pl-1;
	for(int i=0;i<=n-2;i+=2)
		if((n-i)&1)
			solve1(i);
		else
			solve2(i);
	mx=0;
	pl=(n+1)>>1;
	pr=pl-1;
	for(int i=1;i<=n-2;i+=2)
		if((n-i)&1)
			solve1(i);
		else
			solve2(i);
	for(int i=0;i<=n-1;i++)
		printf("%d ",ans[i]);
	return 0;
}