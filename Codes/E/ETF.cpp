#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

const int N=1000010;
int phi[N];

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
    return;
}
int main()
{
    solve();
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",phi[n]);
    }
    return 0;
}

