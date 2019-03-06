#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
pii v[200009];
int ans1[200009],ans2[200009];
int fn[200009],sm[200009];
int mx[200009],mn[200009];
int fnd(int x)
{
	return x==fn[x]?x:fn[x]=fnd(fn[x]);
}
void solve()
{
	sort(v+1,v+m+1);
	for(int i=1;i<=n;i++)
		mx[i]=mn[i]=i;
	for(int i=1;i<=m;i++)
	{
		int y=v[i].se;
		mx[y]=max(mx[y],mx[y+1]);
		mn[y+1]=min(mn[y],mn[y+1]);
	}
	for(int i=1;i<=n-1;i++)
		printf("%d ",mx[i]-mn[i]+1);
	printf("%d",mx[n]-mn[n]+1);
	puts("");
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		v[i]=pii(a,b);
	}
	solve();
	return 0;
}