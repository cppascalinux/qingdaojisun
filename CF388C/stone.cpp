#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int s[109];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
#endif
	scanf("%d",&n);
	int ans1=0,ans2=0,tp=0;
	for(int i=1;i<=n;i++)
	{
		int sm;
		scanf("%d",&sm);
		for(int j=1;j<=sm;j++)
		{
			int p;
			scanf("%d",&p);
			if((sm&1)&&(j==sm/2+1))
				s[++tp]=p;
			else if(j<=sm/2)
				ans1+=p;
			else
				ans2+=p;
		}
	}
	// printf("ans1:%d ans2:%d\n",ans1,ans2);
	sort(s+1,s+tp+1);
	int inv=0;
	for(int i=tp;i>=1;i--)
	{
		if(!inv)
			ans1+=s[i];
		else
			ans2+=s[i];
		inv^=1;
	}
	printf("%d %d",ans1,ans2);
	return 0;
}