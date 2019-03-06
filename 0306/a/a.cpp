#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define gc() (p1==p2&&(p2=(p1=buffer)+fread(buffer,1,10000000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char *p1,*p2,buffer[10000009];
struct node
{
	int u,v,w;
	bool operator <(const node &p) const
	{
		return w>p.w;
	}
};
int n,m;
node e[2000009];
int fn[1000009],vis[100009];
void rd(int &x)
{
	char ch=0;
	x=0;
	while(ch<'0'||ch>'9')
		ch=gc();
	while(ch>='0'&&ch<='9')
		x=x*10+(ch&15),ch=gc();
}
int fnd(int x)
{
	return x==fn[x]?x:fn[x]=fnd(fn[x]);
}
void solve0()
{
	for(int i=1;i<=n;i++)
		fn[i]=i;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++)
	{
		int fa=fnd(e[i].u),fb=fnd(e[i].v);
		if(fa!=fb)
		{
			fn[fa]=fb;
			vis[e[i].w]=1;
			// printf("i:%d\n",i);
		}
	}
	for(int i=0;i<=100001;i++)
		if(!vis[i])
		{
			printf("%d",i);
			break;
		}
}
void solve1()
{
	int mx=0;
	for(int i=1;i<=m;i++)
		mx=max(mx,e[i].w);
	for(int i=0;i<=mx+1;i++)
	{
		for(int j=1;j<=n;j++)
			fn[j]=j;
		int sm=0;
		for(int j=1;j<=m;j++)
			if(e[j].w!=i)
			{
				int fa=fnd(e[j].u),fb=fnd(e[j].v);
				if(fa!=fb)
				{
					fn[fa]=fb;
					sm++;
					if(sm==n-1)
						break;
				}
			}
		// printf("i:%d sm:%d\n",i,sm);
		if(sm==n-1)
		{
			printf("%d",i);
			return;
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	rd(n),rd(m);
	for(int i=1;i<=m;i++)
		rd(e[i].u),rd(e[i].v),rd(e[i].w);
	solve1();
	return 0;
}