#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 1000000000000
#define NN 1000000

bool p[NN+10];
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
    return;
}

pair<ll,ll> answer(ll n, ll m)
{
    ll dim=0;
    ll dis=0;
    for(ll i=0; i!=-1; i++)
    {
        if(n==1 && m==1) break;
        bool flag=0;
        while(n%primes[i]==0 || m%primes[i]==0)
        {
            if((n%primes[i]==0 || m%primes[i]==0) && flag==0)
            {
                dim++;
                flag=1;
            }

            if(n%primes[i]==0 && m%primes[i]==0)
            {
                n/=primes[i];
                m/=primes[i];
            }
            else if(n%primes[i]==0 && m%primes[i]!=0)
            {
                dis++;
                n/=primes[i];
            }
            else if(n%primes[i]!=0 && m%primes[i]==0)
            {
                dis++;
                m/=primes[i];
            }
        }
    }
    return make_pair(dim,dis);
}

int main()
{
    sieve();
    ll n,m,i=1;
    while(1)
    {
        cin >> n >> m;
        if(n==0 && m==0) break;

        pair<ll,ll> p = answer(n,m);

        cout << i++ << ". " << p.first << ":" << p.second << endl;
    }
    return 0;
}

