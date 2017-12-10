#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct cow
{
	long long x;
	long long y;
	long long index;
};
cow a[50008];
bool operator <(const cow& x,const cow& y)
{
	return x.x<y.x;
}
long long modul(long long x)
{
	if(x<0)
		return -x;
	return x;
}
long long dist(long long x1,long long y1,long long x2,long long y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
	long long i,j,c,d,n,m,ansi,ansj;
	long long b,ans;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].index=i;
	}
	sort(a+1,a+n+1);
	ans=1000000*10000000;
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
		{
			if(modul(a[i].x-a[j].x)*modul(a[i].x-a[j].x)>ans)
				break;
			b=dist(a[i].x,a[i].y,a[j].x,a[j].y);
			if(b<ans)
			{
				ansi=a[i].index;
				ansj=a[j].index;
				ans=b;
			}
		}
	if(ansi>ansj)
		swap(ansi,ansj);
	printf("%lld %lld %.6f\n",ansi-1,ansj-1,sqrt((double)ans));
	return 0;
}

