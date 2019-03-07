//2019.03.07
//aizu 2790 non-redundant drive 点分治
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,tot,rt,mn,tpst,tped,ans,cnt,sgrt;
int v[100009];
int hd[100009],eg[200009],nxt[200009],len[200009];
int vis[100009],sz[100009];
pii st[100009],ed[100009],pst[100009],ped[100009];
int lp[10000009],rp[10000009],mnst[10000009],mned[10000009],lzst[10000009],lzed[10000009];
void ins(int a,int b,int c)
{
	eg[++tot]=b;
	len[tot]=c;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
void down(int a,int *mn,int *lz)
{

}
void add(int &a,int l,int r,int ll,int rr,int x,int *mn,int *lz)
{
	if(l>rr||r<ll)
		return;
	if(!a)
	{
		a=++cnt;
		mn[a]=lz[a]=inf;
	}
	if(l>=ll&&r<=rr)
	{
		mn[a]=min(mn[a],x);
		lz[a]=min(lz[a],x);
		return;
	}
	down(a,mn,lz);
	int mid=(l+r)>>1;
	add(lp[a],l,mid,ll,rr,x,mn,lz);
	add(rp[a],mid+1,r,ll,rr,x,mn,lz);
	if(lp[a])
		mn[a]=min(mn[a],)
}
void getrt(int x,int fa,int siz)
{
	int mx=0;
	sz[x]=1;
	for(int i=hd[x];i;i=nxt[i])
		if(!vis[eg[i]]&&eg[i]!=fa)
		{
			getrt(eg[i],x,siz);
			sz[x]+=sz[eg[i]];
			mx=max(mx,sz[eg[i]]);
		}
	mx=max(mx,siz-sz[x]);
	if(mx<mn)
	{
		mn=mx;
		rt=x;
	}
}
void dfs(int x,int fa,int sdis,int scst,int mxcst,int mncst)
{
	ed[++tped]=pii(sdis,mncst);
	if(scst-mxcst>=0)
		st[++tpst]=pii(sdis,scst);
	for(int i=hd[x];i;i=nxt[i])
		if(!vis[eg[i]]&&eg[i]!=fa)
		{
			int ncst=scst+v[eg[i]]-len[i];
			dfs(eg[i],x,sdis+1,ncst,max(mxcst,ncst),min(mncst,ncst));
		}
}
void cal(int x)
{
	for(int i=hd[x];i;i=nxt[i])
		if(!vis[eg[i]])
		{
			tpst=tped=0;
			int ncst=v[eg[i]]-len[i];
			dfs(eg[i],0,1,ncst,ncst,ncst);

		}
}
void solve(int x,int siz)
{
	vis[x]=1;
	cal(x);
	for(int i=hd[x];i;i=nxt[i])
		if(!vis[i])
		{
			mn=inf;
			int nsz=sz[eg[i]]>sz[x]?siz-sz[x]:sz[eg[i]];
			getrt(eg[i],0,nsz);
			solve(rt,nsz);
		}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",v+i);
	for(int i=1,a,b,c;i<=n-1;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		ins(a,b,c);
		ins(b,a,c);
	}
	getrt(1,0,n);
	solve(rt,n);
	printf("%d",ans);
	return 0;
}