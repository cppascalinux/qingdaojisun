#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define mod 1000000007
using namespace std;
int m,k,s,smr,tp;
int st[200009];
int f[5][200009];
char buc[200000009];
void solve0()
{
	int st=s>>1;
	ll ans=0;
	for(int i=1,l,r;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		for(int j=l;j<=min(s,r);j++)
			if(j<=st)
				buc[j]=1;
			else /* if(s-j>=0&&s-j<=200000000) */
				ans+=buc[s-j];
	}
	printf("%lld",ans%mod);
}
void dp()
{
	// for(int i=1;i<=tp;i++)
	// 	printf("i:%d st:%d\n",i,st[i]);
	int sm=0;
	f[0][0]=1;
	for(int i=1;i<=tp;i++)
	{
		sm=min(sm+st[i],s);
		for(int j=k;j>=1;j--)
			for(int l=sm;l>=st[i];l--)
				f[j][l]=(f[j][l]+f[j-1][l-st[i]])%mod;
	}
	// for(int i=0;i<=k;i++)
	// {
	// 	for(int j=0;j<=s;j++)
	// 		printf("%d ",f[i][j]);
	// 	printf("\n");
	// }
	printf("%d",f[k][s]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%d%d%d",&m,&k,&s);
	if(k==2)
	{
		solve0();
		return 0;
	}
	for(int i=1,l,r;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++)
			st[++tp]=j;
	}
	for(int i=tp;i>=tp-k+1;i--)
		smr+=st[i];
	if(smr<s)
	{
		printf("0");
		return 0;
	}
	dp();
	return 0;
}