#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t,n,m,D,x;
    long long cnt;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d %d %d",&n,&m,&D);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&x);
            if(x>D)
            {
                cnt += (x/D);
                if(x%D==0) cnt--;
            }
        }
        if(cnt>=m)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

