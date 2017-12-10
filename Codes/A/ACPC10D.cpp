#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,i=1;
    int a[100005][3];
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        scanf("%d %d %d",&a[0][0],&a[0][1],&a[0][2]);
        scanf("%d %d %d",&a[1][0],&a[1][1],&a[1][2]);

        a[0][2]+=a[0][1];
        a[1][0]+=a[0][1];
        a[1][1]+=min(a[0][1],min(a[0][2],a[1][0]));
        a[1][2]+=min(a[0][1],min(a[0][2],a[1][1]));

        for(int i=2; i<n; i++)
        {
            scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
            a[i][0] += min(a[i-1][0],a[i-1][1]);
            a[i][1] += min(a[i][0],min(a[i-1][0],min(a[i-1][1],a[i-1][2])));
            a[i][2] += min(a[i][1],min(a[i-1][1],a[i-1][2]));
        }

        printf("%d. %d\n",i++,a[n-1][1]);
    }
    return 0;
}

