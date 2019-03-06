#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int num[400009],pos[200009];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("h.in","r",stdin);
	freopen("h.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		num[i+200000]=i;
		pos[i]=i+200000;
	}
	int top=200000;
	for(int i=1,a;i<=m;i++)
	{
		scanf("%d",&a);
		num[pos[a]]=0;
		pos[a]=--top;
		num[pos[a]]=a;
	}
	for(int i=1;i<=400000;i++)
		if(num[i])
			printf("%d\n",num[i]);
	return 0;
}