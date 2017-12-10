#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define abs(a,b) a>b ? a-b : b-a

int  arr[100010];

int main()
{
    int t,n,temp;
    scanf("%d",&t);
    while(t--)
    {
        memset(arr,0,sizeof arr);
        string name;
        ll sum=0;

        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            cin >> name;
            cin >> temp;
            arr[temp]++;
        }
        int pos=1;

        for(int i=1; i<=n; i++)
        {
            while(arr[i])
            {
                sum += abs(pos,i);
                arr[i]--;
                pos++;
            }
        }

        printf("%lld\n",sum);
    }
    return 0;
}

