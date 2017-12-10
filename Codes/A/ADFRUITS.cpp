#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

void lcs(string s1, string s2, int m, int n)
{
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0) dp[i][j]=0;

            else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;

            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int i=m, j=n, index=dp[m][n];

    string lcsStr;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            lcsStr+=s1[i-1];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }

    i=m-1, j=n-1;

    int l=0;
    index = dp[m][n];
    string ans="";
    while(i>=0 || j>=0)
    {
        if(l<index)
        {
            while(i>=0 && s1[i]!=lcsStr[l])
                ans+=s1[i--];
            while(j>=0 && s2[j]!=lcsStr[l])
                ans+=s2[j--];
            ans+=lcsStr[l++];
            j--;
            i--;
        }
        else
        {
            while(i>=0) ans+=s1[i--];
            while(j>=0) ans+=s2[j--];
        }
    }
    for(int i=ans.length()-1; i>=0; i--)
        cout << ans[i];
    cout << endl;
}

int main()
{
    string s1,s2;
    while(cin >> s1)
    {
        cin >> s2;
        lcs(s1,s2,s1.length(),s2.length());
    }
	return 0;
}

