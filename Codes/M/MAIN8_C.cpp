#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

int box[50005];

bool distribute_candies(int x, int n, int k)
{
    int res=0;
    for(int i=0; i<n ;i++)
    {
        res+=(box[i]/x);
        if(res>=k) return true;
    }
    return false;
}

int main()
{
    int t,n,k,x=-1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);

        for(int i=0; i<n; i++)
        {
            scanf("%d",&box[i]);
            x = max(x,box[i]);
        }

        int lo = 0, hi = x;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (distribute_candies(mid, n, k)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        printf("%d\n",lo);
    }
    return 0;
}

