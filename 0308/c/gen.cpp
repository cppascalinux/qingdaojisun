#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<random>
#include<ctime>
using namespace std;
mt19937 rnd(time(0));
int main()
{
	freopen("c.in","w",stdout);
	int n=1000,m=1000000000,q=500000;
	printf("%d %d %d\n",n,m,q);
	for(int i=1;i<=n;i++)
		printf("%d ",rnd()%m);
	for(int i=1;i<=q;i++)
		printf("\n%d %d",rnd()%m,rnd()%n+1);
	return 0;
}