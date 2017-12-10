#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define M 1000000007

long long dp[505][505]={0};

int main()
{
	int n,m;
	int b[505][505]={0};
	int y[505][505]={0};
	while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0 && m==0) break;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&y[i][j]);
                y[i][j]+=y[i][j-1];
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&b[i][j]);
                b[i][j]+=b[i-1][j];
            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                dp[i][j]=max(dp[i-1][j]+y[i][j],dp[i][j-1]+b[i][j]);
            }
        }

        printf("%lld\n",dp[n][m]);
    }
	return 0;
}

