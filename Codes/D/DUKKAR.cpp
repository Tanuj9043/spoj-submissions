#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 

/*
This problem can be solved using Luca's theorem which states that number of
binomial coefficients C(n,k) which are not divisible by prime p, is (a1+1)*(a2+1)*..(am+1),
where ai is ith digit of n when n is written in base-p.
*/

int main()
{
	int t;
	ll n,res,p,total;
	scanf("%d",&t);
	while(t--)
	{
		res=1;
		scanf("%lld %lld",&n,&p);
		total=n;
		while(n)
		{
			res=(res)*(n%p+1);
			n/=p;
		}
		printf("%lld\n",1+total-res);
	}
	return 0;
}
