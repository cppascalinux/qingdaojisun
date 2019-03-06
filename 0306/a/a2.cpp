#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<ctime>
#define pii pair<int,int>
#define fi first
#define se second
#define gc() (p1==p2&&(p2=(p1=buffer)+fread(buffer,1,10000000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char *p1,*p2,buffer[10000009];
int n,m,mx,ed;
int fn[1000009],h[1000009];
int l[400009],r[400009];
vector<pii> v[100009],s[400009],tmp;
int bkx[23][1000009];
pii bky[23][1000009];
int ans[100009];
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
	return x==fn[x]?x:fnd(fn[x]);
}
void build(int a,int ll,int rr)
{
	l[a]=ll;
	r[a]=rr;
	if(ll==rr)
		return;
	int mid=(ll+rr)>>1;
	build(a<<1,ll,mid);
	build(a<<1|1,mid+1,rr);
}
void add(int a,int ll,int rr,int id)
{
	if(l[a]>rr||r[a]<ll)
		return;
	if(l[a]>=ll&&r[a]<=rr)
	{
		for(int i=0;i<(int)v[id].size();i++)
			s[a].push_back(v[id][i]);
		return;
	}
	add(a<<1,ll,rr,id);
	add(a<<1|1,ll,rr,id);
}
void init()
{
	build(1,0,mx);
	for(int i=0;i<=mx;i++)
	{
		// tmp=v[i];
		if(i>0)
			add(1,0,i-1,i);
		if(i<mx)
			add(1,i+1,mx,i);
	}
	for(int i=1;i<=n;i++)
	{
		fn[i]=i;
		h[i]=1;
	}
}
void dfs(int a,int d,int sm)
{
	int tp=0;
	for(int i=0;i<(int)s[a].size();i++)
	{
		int fx=fnd(s[a][i].fi),fy=fnd(s[a][i].se);
		if(fx==fy)
			continue;
		if(h[fx]>h[fy])
			swap(fx,fy);
		bkx[d][++tp]=fx;
		bky[d][tp]=pii(fy,h[fy]);
		fn[fx]=fy;
		h[fy]=max(h[fy],h[fx]+1);
	}
	sm+=tp;
	// printf("a:%d l:%d r:%d sm:%d\n",a,l[a],r[a],sm);
	if(l[a]==r[a])
	{
		if(sm==n-1)
		{
			ans[l[a]]=1;
			ed=1;
			return;
		}
	}
	else
	{
		dfs(a<<1,d+1,sm);
		if(ed)
			return;
		dfs(a<<1|1,d+1,sm);
		if(ed)
			return;
	}
	sm-=tp;
	for(int i=tp;i>=1;i--)
	{
		fn[bkx[d][i]]=bkx[d][i];
		h[bky[d][i].fi]=bky[d][i].se;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a1.out","w",stdout);
#endif
	rd(n),rd(m);
	for(int i=1,a,b,c;i<=m;i++)
	{
		rd(a),rd(b),rd(c);
		if(a==b)
			continue;
		mx=max(mx,c);
		v[c].push_back(pii(a,b));
	}
	init();
	dfs(1,1,0);
	for(int i=0;i<=mx;i++)
		if(ans[i])
		{
			printf("%d",i);
			cerr<<clock();
			return 0;
		}
	printf("%d",mx+1);
	cerr<<clock();
	return 0;
}