#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define MAX 1000005

long long in[MAX], psum, sum, res1, res;
int N;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		res = res1=sum=0;

		scanf("%d",&N);
		for(int i=N-1;i>=0;i--) scanf("%lld",&in[i]);

		for(int i=0;i<N-1;i++) // N-1 is left
		{
			//psum = sum;
			sum = sum + in[i];
			res1= res1 + in[i] + sum;
			if(sum < 0){
				res = res  + res1;
				sum = 0;
				res1=0;
			}
			//cout << res <<' '<< res1 << ' ' << sum << endl;
		}
		res = res + res1 + in[N-1];
		printf("%lld\n",res);
	}
	return 0;
}

