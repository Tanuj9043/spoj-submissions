#include <iostream>
#include <stdio.h>
using namespace std;

long long dp[100005]={0};

void dpSolve(long long a[], int n)
{
    dp[1]=a[1];
    dp[2]=dp[1]+a[2];
    dp[3]=dp[2]+a[3];
    for(int i=4; i<=n; i++)
    {
        if(i==4) dp[i]=max(a[4]+dp[2],max(a[4]+a[3],a[4]+a[3]+a[2]));
        else if(i==5) dp[i]=max(a[i]+dp[i-2], max(a[i]+a[i-1]+dp[i-4],a[i]+a[i-1]+a[i-2]));
        else
        {
            dp[i] = max(a[i]+dp[i-2],max(a[i]+a[i-1]+dp[i-4],a[i]+a[i-1]+a[i-2]+dp[i-6]));
        }
    }
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        long long a[n+4]={0};
        for(int i=1; i<=n; i++) scanf("%lld",&a[n-i+1]);

        dpSolve(a,n);

        printf("%lld\n",dp[n]);
    }
    return 0;
}

