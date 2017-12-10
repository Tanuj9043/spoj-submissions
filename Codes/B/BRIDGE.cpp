#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int maxBridge(pair<int,int> p[], int n)
{
    if(n==1) return 1;

    int i,j,res=0;

    int lis[n];

    for(int i=0; i<n; i++) lis[i]=1;

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(p[i].second>=p[j].second && lis[i] < lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    for(int i=0; i<n; i++) res = max(res,lis[i]);
    return res;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        pair<int,int> p[n];
        for(int i=0; i<n; i++) scanf("%d",&p[i].first);
        for(int i=0; i<n; i++) scanf("%d",&p[i].second);

        sort(p,p+n);

        printf("%d\n",maxBridge(p,n));
    }
	return 0;
}

