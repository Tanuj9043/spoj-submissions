#include<iostream>
#include<cstring>
using namespace std;

typedef long long int ll;

int primes[10000000]={0};
bool p[87000000]={0};
ll k=1;

void sieve()
{
    p[0]=0, p[1]=0;
    primes[0]=2;
    for(ll i=3; i<87000000; i+=2)
    {
        if(p[i]==0)
        {
            primes[k++]=i;
            for(ll j=i*i; j<87000000; j+=i) p[j]=1;
        }
    }
    return;
}

int main()
{
    sieve();
    int t,a;
    cin >> t;
    while(t--)
    {
        cin >> a;
        cout << primes[a-1] << endl;
    }
    return 0;
}

