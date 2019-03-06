#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<random>
#include<set>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
mt19937 rnd(time(0));
set<pii> s;
set<pii>::iterator it;
int main()
{
	freopen("a.in","w",stdout);
	int n=1000,m=2000;
	printf("%d %d\n",n,m);
	for(int i=2;i<=n;i++)
	{
		int a=rnd()%(i-1)+1;
		int b=i;
		s.insert(pii(a,b));
	}
	int sm=m-n+1;
	while(sm)
	{
		int a=rnd()%n+1,b=rnd()%n+1;
		if(a>b)
			swap(a,b);
		if(a==b||(!s.insert(pii(a,b)).se))
			continue;
		sm--;
	}
	int s0=-1;
	for(it=s.begin();it!=s.end();it++)
		printf("%d %d %d\n",it->fi,it->se,s0=(s0+1)%101);
	return 0;
}