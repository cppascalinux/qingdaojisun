#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,q,d;
int v[1009],s[1009],ts[1009];
int sa[1009],c[1009],t1[1009],t2[1009];
void lsh()
{
	memcpy(ts,s,(n+1)<<2);
	sort(ts+1,ts+n+1);
	d=unique(ts+1,ts+n+1)-ts-1;
	for(int i=1;i<=n;i++)
		s[i]=lower_bound(ts+1,ts+d+1,s[i])-ts;
}
void getsa()
{
	lsh();
	// for(int i=1;i<=n;i++)
	// 	printf("%d ",s[i]);
	// printf("\n");
	int *x=t1,*y=t2;
	memset(c,0,(d+1)<<2);
	for(int i=1;i<=n;i++)
		c[x[i]=s[i]]++;
	for(int i=1;i<=d;i++)
		c[i]+=c[i-1];
	for(int i=1;i<=n;i++)
		sa[c[x[i]]--]=i;
	for(int k=1;k<=n;k<<=1)
	{
		int p=0;
		for(int i=n-k+1;i<=n;i++)
			y[++p]=i;
		for(int i=1;i<=n;i++)
			if(sa[i]>=k+1)
				y[++p]=sa[i]-k;
		memset(c,0,(d+1)<<2);
		for(int i=1;i<=n;i++)
			c[x[i]]++;
		for(int i=1;i<=d;i++)
			c[i]+=c[i-1];
		for(int i=n;i>=1;i--)
			sa[c[x[y[i]]]--]=y[i];
		p=0;
		for(int i=1;i<=n;i++)
			y[sa[i]]=x[sa[i]]==x[sa[i-1]]&&x[sa[i]+k]==x[sa[i-1]+k]?p:++p;
		swap(x,y);
		d=p;
		if(d>=n)
			return;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",v+i);
	for(int i=1,a,b;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		for(int j=1;j<=n;j++)
			s[j]=(v[j]+a)%m;
		getsa();
		printf("%d\n",sa[b]);
	}
	return 0;
}