#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define mod 1000000007
using namespace std;
int n,k;
char f[21][1050000];
void dp(int x,int s)
{
	int sm=0;
	for(int i=1;i<=n;i++)
		if(s&(1<<(i-1)))
			sm++;
	if(x>sm)
		return;
	if(x==1)
	{
		f[x][s]=1;
		return;
	}
	f[x][s]=1;
	int top=0;
	for(int i=n;i>=1;i--)
		if(s&(1<<(i-1)))
		{
			top=i;
			break;
		}
	f[x][s]&=f[x-1][s^(1<<(top-1))];
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(s&(1<<(i-1)))
		{
			cur=i;
			continue;
		}
		if(!cur)
			continue;
		f[x][s]&=f[x][(s^(1<<(cur-1)))|(1<<(i-1))];
	}
	f[x][s]^=1;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int s=(1<<n)-1;s>=1;s--)
			dp(i,s);
	for(int s=1;s<1<<n;s++)
	{
		int sm=0;
		for(int i=1;i<=n;i++)
			if(s&(1<<(i-1)))
				sm++;
		for(int i=n;i>=1;i--)
			if(s&(1<<(i-1)))
				printf("1");
			else
				printf("0");
		printf(" sm:%d \n",sm);
		for(int i=1;i<=sm;i++)
		{
			printf("i:%d f:%d\n",i,f[i][s]);
			// if((sm&1)&&!f[i][s])
			// 	cerr<<"q";
		}
	}
	ll ans=0;
	for(int s=1;s<1<<n;s++)
	{
		int sm=0;
		for(int i=1;i<=n;i++)
			if(s&(1<<(i-1)))
				sm++;
		if(sm==k+1)
			for(int i=1;i<=sm;i++)
				ans+=f[i][s];
	}
	printf("%lld",ans%mod);
	return 0;
}