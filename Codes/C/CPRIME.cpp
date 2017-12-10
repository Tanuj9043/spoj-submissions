#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define MAX 100000000
#define LMT 10000

unsigned flag[MAX/64];
int primes[5761466], total;

#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))

void sieve()
{
	int i, j, k;
	for(i=3;i<LMT;i+=2)
		if(!chkC(i))
			for(j=i*i,k=i<<1;j<MAX;j+=k)
				setC(j);
    primes[0] = -1;
	primes[1] = 2;
	j=2;
	for(i=3;i<MAX;i+=2)
		if(!chkC(i))
			primes[j++] = i;
	total = j;
}

int binSearch(int n, int s, int e)
{
    int mid;
    while(s<=e)
    {
        if(n < primes[s]) return s-1;
        if(n > primes[e]) return e;
        mid = (s+e) / 2;
        if(n == primes[mid]) return mid;
        else if(n < primes[mid]) e = mid-1;
        else s = mid+1;
    }
    return total-1;
}

int main()
{
	int n;
	double x,p,r;
	sieve();
	while(1)
    {
        scanf("%d", &n);
        if(n==0) break;

        p = binSearch(n, 0, total-1);
        x = n;
        r = ( fabs(p - x/log(x)) / p ) * 100.0;
        printf("%.1f\n", r);
    }
    return 0;
}

