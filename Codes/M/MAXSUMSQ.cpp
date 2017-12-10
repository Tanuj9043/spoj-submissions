#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;
int a[100005];

int main()
{
	int t, i, n, maxsum, sum, mn;
	long long cnt, rct;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		maxsum = -INF;
		sum = mn = rct = 0;
		cnt = 1;
		for(i = 0; i < n; i++) {
			sum += a[i];
			if(sum - mn > maxsum) {
				maxsum = sum - mn;
				rct = cnt;
			}
			else if(sum - mn == maxsum) {
				rct += cnt;
			}
			if(sum < mn) {
				mn = sum;
				cnt = 1;
			}
			else if(sum == mn) {
				cnt++;
			}
		}
		printf("%d %lld\n", maxsum, rct);
	}
    return 0;
}
