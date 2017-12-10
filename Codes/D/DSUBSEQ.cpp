#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define M 1000000007

int main()
{
	int t;
    scanf("%d",&t);
	while(t--)
    {
        string s;
        cin >> s;
        int l = s.length();

        long long dp[100005]={1};
        int last[30]={0};
        for(int i=1; i<=l; i++)
        {
            dp[i]=(dp[i-1]*2)%M;
            if(last[s[i-1]-'A']!=0) dp[i] = (dp[i] - dp[last[s[i-1]-'A']-1] + M)%M;
            last[s[i-1]-'A']=i;
        }
        if(dp[l]<0) dp[l]+=M;
        printf("%lld\n",dp[l]);
    }
	return 0;
}

