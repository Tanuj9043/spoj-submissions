#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a>b;
}

int dp[1005][1005]={0};

int main()
{
	int t,n,a,b;
	int x[1005],y[1005];
    scanf("%d",&t);
	while(t--)
    {
        scanf("%d %d",&a,&b);
        for(int i=1; i<=a-1; i++) scanf("%d",&x[i]);
        for(int i=1; i<=b-1; i++) scanf("%d",&y[i]);

        sort(x+1,x+a,compare);
        sort(y+1,y+b,compare);


        for(int i=0; i<=a-1; i++)
        {
            for(int j=0; j<=b-1; j++)
            {
                if(i==0 && j==0) continue;
                if(i==0) dp[i][j]=dp[i][j-1]+y[j];
                else if(j==0) dp[i][j]=dp[i-1][j]+x[i];
                else
                {
                    int l = dp[i-1][j] + (j+1)*x[i];
                    int r = dp[i][j-1] + (i+1)*y[j];
                    dp[i][j] = min(l,r);
                }
            }
        }

        printf("%d\n",dp[a-1][b-1]);
    }
	return 0;
}

