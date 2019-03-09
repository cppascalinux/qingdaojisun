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
int n,tot,rt,mn,tpst,tped,ans,cnt;
int v[100009];
int hd[100009],eg[200009],nxt[200009],len[200009];
int vis[100009],sz[100009];
pii st[100009],ed[100009],pst[100009],ped[100009];
int lp[30000009],rp[30000009],mxst[30000009],mxed[30000009],lz[30000009];
void ins(int a,int b,int c)
{
	eg[++tot]=b;
	len[tot]=c;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
void down(int a)
{
	lz[a]=0;
	int la=lp[a],ra=rp[a];
	mxst[la]=mxst[ra]=-inf;
	mxed[la]=mxed[ra]=-inf;
	lz[la]=lz[ra]=1;
}
void add(int a,int l,int r,int x,int val,int *mx)
{
	mx[a]=max(mx[a],val);
	if(l==r)
		return;
	if(!lp[a])
		lp[a]=++cnt;
	if(!rp[a])
		rp[a]=++cnt;
	if(lz[a])
		down(a);
	int mid=(l+r)>>1;
	if(x<=mid)
		add(lp[a],l,mid,x,val,mx);
	else
		add(rp[a],mid+1,r,x,val,mx);
}
int ask(int a,int l,int r,int ll,int rr,int *mx)
{
	if(!a||l>rr||r<ll)
		return -inf;
	if(l>=ll&&r<=rr)
		return mx[a];
	if(lz[a])
		down(a);
	int mid=(l+r)>>1;
	return max(ask(lp[a],l,mid,ll,rr,mx),ask(rp[a],mid+1,r,ll,rr,mx));
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
void dfs(int x,int fa,int dep,int scst,int mxcst,int mncst)
{
	ed[++tped]=pii(dep,mncst);
	if(scst-mxcst>=0)
		st[++tpst]=pii(dep,scst);
	for(int i=hd[x];i;i=nxt[i])
		if(!vis[eg[i]]&&eg[i]!=fa)
		{
			int ncst=scst+v[eg[i]]-len[i];
			dfs(eg[i],x,dep+1,ncst,max(mxcst,ncst),min(mncst,ncst-v[eg[i]]));
		}
}
void cal(int x)
{
	// printf("x:%d---------------------------\n",x);
	mxst[1]=mxed[1]=-inf;
	lz[1]=1;
	add(1,-1000000000,1000000000,v[x],1,mxst);
	add(1,-1000000000,1000000000,v[x],1,mxed);
	for(int i=hd[x];i;i=nxt[i])
		if(!vis[eg[i]])
		{
			tpst=tped=0;
			int ncst=v[eg[i]]-len[i];
			dfs(eg[i],0,1,ncst,max(ncst,0),-len[i]);
			// for(int j=1;j<=tpst;j++)
			// 	printf("stj:%d dep:%d cst:%d\n",j,st[j].fi,st[j].se);
			// for(int j=1;j<=tped;j++)
			// 	printf("edj:%d dep:%d cst:%d\n",j,ed[j].fi,ed[j].se);
			for(int j=1;j<=tpst;j++)
				ans=max(ans,st[j].fi+ask(1,-1000000000,1000000000,-st[j].se,1000000000,mxed));
			// printf("ans:%d\n",ans);
			for(int j=1;j<=tped;j++)
				ans=max(ans,ed[j].fi+ask(1,-1000000000,1000000000,-ed[j].se,1000000000,mxst));
			// printf("ans:%d\n",ans);
			for(int j=1;j<=tpst;j++)
				add(1,-1000000000,1000000000,st[j].se+v[x],st[j].fi+1,mxst);
			for(int j=1;j<=tped;j++)
				add(1,-1000000000,1000000000,ed[j].se+v[x],ed[j].fi+1,mxed);
		}
}
void solve(int x,int siz)
{
	// printf("x:%d sz:%d\n",x,siz);
	vis[x]=1;
	cal(x);
	for(int i=hd[x];i;i=nxt[i])
		if(!vis[eg[i]])
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
	cnt=1;
	mn=inf;
	getrt(1,0,n);
	solve(rt,n);
	ans=max(ans,1);
	printf("%d\n",ans);
	return 0;
}