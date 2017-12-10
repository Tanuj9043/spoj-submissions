#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, a[50], x;
    scanf("%d", &t);
    while(t--)
    {
        x=0;
        scanf("%d", &n);
        int cnt = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
            x=(x^a[i]);
            if(a[i]==1)
                cnt++;
        }
        if(cnt==n)
        {
            if(n&1) printf("Brother\n");
            else printf("John\n");
        }
        else
        {
            if(x==0) printf("Brother\n");
            else printf("John\n");
        }
    }
    return 0;
}

