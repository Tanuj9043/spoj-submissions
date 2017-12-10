#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

typedef long long int ll;

int ans[1000010][11]={0};
int pr[1000010]={0};
bool p[1000010]={0};
int cnt[11]={0};

void sieve()
{
    p[0]=0, p[1]=0;
    for(ll i=2; i<=1000000; i++)
    {
        if(p[i]==0)
        {
            pr[i]=1;
            cnt[1]++;
            for(int k=0; k<=10; k++) ans[i][k]=ans[i-1][k];
            ans[i][1]=cnt[1];
            for(ll j=i*2; j<=1000000; j+=i)
            {
                p[j]=1;
                pr[j]++;
            }
        }
        else
        {
            for(int k=0; k<=10; k++) ans[i][k]=ans[i-1][k];
            cnt[pr[i]]++;
            ans[i][pr[i]]=cnt[pr[i]];
        }
    }
    return;
}

int main()
{
    ans[1][0]=1;
    cnt[0]=1;
    sieve();
    int t,n,a,b,res;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&n);
        res = ans[b][n]-ans[a-1][n];
        printf("%d\n",res);
    }
    return 0;
}

