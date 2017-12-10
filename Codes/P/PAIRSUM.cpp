#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n,m,l,r;
    scanf("%d",&n);

    long long a[n+1];
    long long as[n+1];
    long long as2[n+1];
    long long x=0,y=0;
    a[0]=0,as[0]=0,as2[0]=0;

    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
        y+=a[i]*a[i];
        x+=a[i];
        as[i]=x;
        as2[i]=y;
    }

    long long sum;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d %d",&l,&r);
        l++;
        r++;

        sum = as[r]-as[l-1];
        long long ans = ((sum*sum)+(as2[r]-as2[l-1]))/2;

        printf("%lld\n",ans);
    }
	return 0;
}

