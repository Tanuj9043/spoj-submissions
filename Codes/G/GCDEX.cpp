#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

const int N=1000001;
int phi[N];
LL res[N],cum[N];
void solve()
{
    for(int i=1;i<N;i++) phi[i]=i;

    for(int i=2;i<N;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<N;j+=i)
            {
                phi[j]/=i;
                phi[j]*=i-1;
            }
        }
    }

    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
        {
            res[j]=res[j]+1LL*i*phi[j/i];
        }
    }

    for(int i=1;i<N;i++) res[i]-=i;
    cum[0]=0;

    for(int i=1;i<N;i++)
    {
        cum[i]=cum[i-1]+res[i];
    }
}
int main()
{
    solve();
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        printf("%lld\n",cum[n]);
        scanf("%d",&n);
    }
    return 0;
}

