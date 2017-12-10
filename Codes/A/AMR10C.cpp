#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long int ll;

int primes[1000010]={0};

void sieve()
{
    primes[1]=1;
    primes[2]=2;
    for(ll i=4; i<=1000000; i+=2)
    {
    	primes[i]=2;
    }
    for(ll i=3; i<=1000000; i+=2)
    {
        if(primes[i]==0)
        {
            primes[i]=i;
            for(ll j=i*i; j<=1000000; j+=i)
            {
                if(primes[j]==0) primes[j]=i;
            }
        }
    }
    return;
}

int main()
{
    sieve();

    int t,n,temp,m=-1,cnt=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        m=-1;
        cnt=0;
        while(n!=1)
        {
            temp = primes[n];
            while(n%temp==0)
            {
                n/=temp;
                cnt++;
            }
            m=max(m,cnt);
            cnt=0;
        }
        printf("%d\n",m);
    }
    return 0;
}

