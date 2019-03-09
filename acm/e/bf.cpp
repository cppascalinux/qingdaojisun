#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F
using namespace std;
int n,tot,ans;
int v[100009];
int hd[100009],eg[200009],nxt[200009],len[200009];
void ins(int a,int b,int c)
{
	eg[++tot]=b;
	len[tot]=c;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
void dfs(int x,int fa,int dis,int sml)
{
	ans=max(ans,dis);
	for(int i=hd[x];i;i=nxt[i])
		if(eg[i]!=fa)
		{
			int nsml=sml-len[i];
			if(nsml>=0)
				dfs(eg[i],x,dis+1,nsml+v[eg[i]]);
		}
}
int main()
{
#ifndef ONNLINE_JUDGE
	freopen("e.in","r",stdin);
	freopen("bf.out","w",stdout);
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
	for(int i=1;i<=n;i++)
		dfs(i,0,1,v[i]);
	printf("%d\n",ans);
	return 0;
}