#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int p,q,n;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
void solve()
{
	int g=gcd(p,q);
	ll sm=(ll)(q-1)*(q-2)/2;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&p,&q,&n);
		solve();
	}
	return 0;
}