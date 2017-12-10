#include<iostream>
#include<stdio.h>
using namespace std;

typedef long long int ll;

bool p[100000000]={0};
ll k=1;

void sieve()
{
    p[0]=0, p[1]=0;
    cout << 2 << endl;
    for(ll i=3; i<=100000000; i+=2)
    {
        if(p[i]==0)
        {
            if(k==100)
            {
                 printf("%lld\n",i);
                 k=0;
            }
            k++;
            for(ll j=i*i; j<=100000000; j+=i) p[j]=1;
        }
    }
    return;
}

int main()
{
    sieve();
    return 0;
}

