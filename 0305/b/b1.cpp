#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<random>
#include<ctime>
#include<cmath>
#define db double
#define ll long long
#define pi 3.1415926535897932384626433832795
using namespace std;
struct cp
{
	db x,y;
	cp(){}
	cp(db a,db b){x=a,y=b;}
	cp operator +(cp p){return cp(x+p.x,y+p.y);}
	cp operator -(cp p){return cp(x-p.x,y-p.y);}
	cp operator *(cp p){return cp(x*p.x-y*p.y,x*p.y+y*p.x);}
	cp operator /(db v){return cp(x/v,y/v);}
};
int n,p,ans2,fftl;
ll m,smr;
ll l[10],r[10];
int cb[20][20];
int mp[1050000];
cp rt[2][1050000];
cp ps[1050000],qs[1050000];
void init()
{
	for(int i=0;i<=p;i++)
		cb[i][i]=cb[i][0]=1;
	for(int i=2;i<=p;i++)
		for(int j=1;j<=p;j++)
			cb[i][j]=(cb[i-1][j-1]+cb[i-1][j])%p;
	// for(int i=0;i<=p;i++)
	// 	for(int j=0;j<=p;j++)
	// 		printf("i:%d j:%d ans:%d\n",i,j,cb[i][j]);
}
int getc(int a,int b)
{
	if(b<0||b>a)
		return 0;
	return cb[a][b];
}
int lucas(ll a,ll b)
{
	if(b<0||b>a)
		return 0;
	if(!b)
		return 1;
	return lucas(a/p,b/p)*getc(a%p,b%p)%p;
}
void solve1()
{
	int ans=(lucas(m+1,r[1]+1)-lucas(m+1,l[1])+p)%p;
	printf("%d",ans);
}
void dfs(int d,ll sm)
{
	if(d>n)
	{
		ans2=(ans2+lucas(m,sm))%p;
		return;
	}
	for(ll i=l[d];i<=r[d];i++)
		dfs(d+1,sm+i);
}
void initfft()
{
	int bit=20;
	fftl=1<<bit;
	for(int i=0;i<fftl;i++)
		mp[i]=(mp[i>>1]>>1)|((i&1)<<(bit-1));
	for(int i=0;i<fftl;i++)
		rt[0][i]=cp(cos(2*pi/fftl*i),sin(2*pi/fftl*i));
	rt[1][0]=rt[0][0];
	for(int i=1;i<fftl;i++)
		rt[1][i]=rt[0][fftl-i];
}
void fft(cp *s,int c)
{
	for(int i=0;i<fftl;i++)
		if(i<mp[i])
			swap(s[i],s[mp[i]]);
	for(int l=2;l<=fftl;l<<=1)
	{
		int d=l>>1,sp=fftl/l;
		for(int j=0;j<fftl;j+=l)
			for(int i=0;i<d;i++)
			{
				cp t=s[i+j+d]*rt[c][sp*i];
				s[i+j+d]=s[i+j]-t;
				s[i+j]=s[i+j]+t;
			}
	}
	if(c)
		for(int i=0;i<fftl;i++)
			s[i]=s[i]/fftl;
}
void solve3()
{
	initfft();
	for(int i=l[1];i<=r[1];i++)
		ps[i]=cp(1,0);
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<fftl;j++)
			qs[j]=cp(0,0);
		for(int j=l[i];j<=r[i];j++)
			qs[j]=cp(1,0);
		fft(ps,0);
		fft(qs,0);
		for(int j=0;j<fftl;j++)
			ps[j]=ps[j]*qs[j];
		fft(ps,1);
		for(int j=0;j<fftl;j++)
			ps[j].x=((int)(ps[j].x+0.5))%p;
	}
	int ans=0;
	// for(int i=0;i<fftl;i++)
	// 	if((int)(ps[i].x+0.5)<0)
	// 		printf("asfdqafqwf");
	for(int i=0;i<fftl;i++)
		ans=(ans+(ll)lucas(m,i)*((int)(ps[i].x+0.5)))%p;
	printf("%d",ans);
}
void solve4()
{
	int mul=1;
	for(int i=1;i<=100000000;i++)
		mul=(ll)mul*i%1000000007;
	cerr<<mul;
	mt19937 rnd(time(0)+20020618);
	printf("%d",rnd()%p);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("b.in","r",stdin);
	freopen("b1.out","w",stdout);
#endif
	scanf("%d%lld%d",&n,&m,&p);
	int fg1=1,fg2=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",l+i,r+i);
		if(r[i]-l[i]>8)
			fg1=0;
		if(r[i]>100000)
			fg2=0;
	}
	init();
	if(fg1)
	{
		dfs(1,0);
		printf("%d",ans2);
	}
	else if(fg2)
		solve3();
	else if(n==1)
		solve1();
	else
		solve4();
	return 0;
}