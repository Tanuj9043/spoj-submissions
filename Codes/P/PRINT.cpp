#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 2500000000
#define NN 50000

bool p[NN+10], pp[1000010];
vector<int> primes;

void sieve()
{
    for(ll i=0; i<=NN; i++) p[i]=1;

    for(ll i=2; i*i<=MAXN; i++)
    {
        if(p[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=NN; j+=i) p[j]=0;
        }
    }
    p[0]=0, p[1]=0;
    return;
}

void segmented_seive(ll a, ll b)
{
    for(ll i=0; i<=(b-a); i++) pp[i]=1;

    for(ll i=0; primes[i]*primes[i]<=b && i<primes.size(); i++)
    {
        ll start;
        a%primes[i]==0 ? start=a : start=a+(primes[i]-(a%primes[i]));

        for(ll j=start; j<=b; j+=primes[i])
        {
            if(primes[i]==j) continue;
            if(j%primes[i]==0) pp[j-a]=0;
        }
    }

    for(ll i=a; i<=b; i++)
    {
        if(i==1) continue;
        if(pp[i-a]) printf("%lld\n",i);
    }
    return;
}

int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll m,n;
        scanf("%lld %lld",&m,&n);
        segmented_seive(m,n);
    }
    return 0;
}

