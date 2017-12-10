#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

typedef long long int ll;

int primes[10000010]={0};

void sieve()
{
    for(ll i=2; i<=10000000; i++)
    {
        if(primes[i]==0)
        {
            for(ll j=i*2; j<=10000000; j+=i)
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

    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==1){printf("%d\n",n);continue;}
        else printf("1");

        if(primes[n]!=0)
        {

        while(n%primes[n]==0)
        {
            printf(" x %d",primes[n]);
            if(primes[n]==0)break;
            n/=primes[n];
            if(primes[n]==0)break;
        }
        }
        printf(" x %d",n);
        printf("\n");
    }
    return 0;
}

