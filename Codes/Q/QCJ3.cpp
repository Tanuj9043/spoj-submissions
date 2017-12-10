#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a, x;
    scanf("%d", &t);
    while(t--)
    {
        x=0;
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a);
            if(a&1) x=(x^i);
        }

        if(x==0) printf("Hanks Wins\n");
        else printf("Tom Wins\n");
    }
    return 0;
}

