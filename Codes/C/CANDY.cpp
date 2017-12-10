#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,sum,cnt;
    int arr[10010];
    while(1)
    {
        cin >> n;
        if(n==-1) break;
        sum=0;
        cnt=0;

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        if(sum%n!=0)
        {
            cout << -1 << endl;
            continue;
        }

        sum/=n;
        for(int i=0; i<n; i++)
        {
            if(arr[i]<sum) cnt+=(sum-arr[i]);
        }
        cout << cnt << endl;
    }
    return 0;
}

