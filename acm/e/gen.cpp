#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<random>
using namespace std;
int main()
{
	mt19937 rnd(time(0));
	int t=0;
	while(1)
	{
		freopen("e.in","w",stderr);
		int n=1000;
		fprintf(stderr,"%d\n",n);
		for(int i=1;i<=n;i++)
			fprintf(stderr,"%d ",rnd()%100+1);
		for(int i=2;i<=n;i++)
			fprintf(stderr,"\n%d %d %d",i,rnd()%(i-1)+1,rnd()%100+1);
		fclose(stderr);
		system("./e;./bf");
		if(system("diff e.out bf.out"))
		{
			printf("WA %d\n",++t);
			break;
		}
		else
		printf("AC %d\n",++t);
	}
	return 0;
}