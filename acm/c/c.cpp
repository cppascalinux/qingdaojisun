#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
int n;
int pos,lst;
map<int,int> mp;
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&n);
	int stop=0;
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		if(stop||pos>x||(pos==x&&x!=lst))
		{
			printf("No\n");
			continue;
		}
		if(pos==x&&lst==x)
		{
			printf("Yes\n");
			stop=1;
			continue;
		}
		printf("Yes\n");
		lst=max(lst,x);
		mp[x]++;
		while(mp[x]>=2)
		{
			mp[x]=0;
			mp[x-1]++;
			if(lst==x)
				lst--;
			x--;
		}
		while(mp[pos+1]==1)
			pos++;
		// printf("i:%d pos:%d\n",i,pos);
	}
	return 0;
}