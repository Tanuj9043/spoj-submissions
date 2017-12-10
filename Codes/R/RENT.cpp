#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define M 1000000007

long long dp[505][505]={0};

int main()
{
	int t,n,st,d,p;
	long long dp[10005]={0};
	scanf("%d",&t);
	while(t--)
    {
        scanf("%d",&n);
        vector<pair<int,pair<int,int> > > v;

        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d",&st,&d,&p);
            v.push_back(make_pair(st,make_pair(d+st,p)));
        }

        sort(v.begin(),v.end());

        long long ans=-1;
        dp[n]=v[n-1].second.second;
        ans = max(ans,dp[n]);
        for(int i=n-1; i>=1; i--)
        {
            int j=i+1;

            while(v[i-1].second.first>v[j-1].first)
            {
                j++;
                if(j>n) break;
            }
            if(j<=n) dp[i]=max((v[i-1].second.second + dp[j]),dp[i+1]);
            else dp[i]=max((long long)v[i-1].second.second,dp[i+1]);
            ans = max(dp[i],ans);
        }

        printf("%lld\n",ans);
    }
	return 0;
}

