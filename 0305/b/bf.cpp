#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<random>
#include<ctime>
#define ll long long
using namespace std;
int n,p,ans2;
ll m;
ll l[10],r[10];
int cb[20][20];
void init()
{
	for(int i=0;i<=p;i++)
		cb[i][i]=cb[i][0]=1;
	for(int i=2;i<=p;i++)
		for(int j=1;j<=p;j++)
			cb[i][j]=(cb[i-1][j-1]+cb[i-1][j])%p;
	// for(int i=0;i<=p;i++)
	// 	for(int j=0;j<=p;j++)
	// 		printf("i:%d j:%d ans:%d\n",i,j,cb[i][j]);
}
int getc(int a,int b)
{
	if(b<0||b>a)
		return 0;
	return cb[a][b];
}
int lucas(ll a,ll b)
{
	if(b<0||b>a)
		return 0;
	if(!b)
		return 1;
	return lucas(a/p,b/p)*getc(a%p,b%p)%p;
}
void solve1()
{
	int ans=(lucas(m+1,r[1]+1)-lucas(m+1,l[1])+p)%p;
	printf("%d",ans);
}
void dfs(int d,ll sm)
{
	if(d>n)
	{
		ans2=(ans2+lucas(m,sm))%p;
		return;
	}
	for(ll i=l[d];i<=r[d];i++)
		dfs(d+1,sm+i);
}
void solve3()
{
	int mul=1;
	for(int i=1;i<=100000000;i++)
		mul=(ll)mul*i%1000000007;
	cerr<<mul;
	mt19937 rnd(time(0)+20020618);
	printf("%d",rnd()%p);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("b.in","r",stdin);
	freopen("bf.out","w",stdout);
#endif
	scanf("%d%lld%d",&n,&m,&p);
	int fg=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",l+i,r+i);
		if(r[i]-l[i]>8)
			fg=0;
	}
	init();
	dfs(1,0);
	printf("%d",ans2);
	return 0;
}