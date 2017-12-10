#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[9010],n,i,val,diff;
    while(1)
    {
        diff=0;
        int max_load=0, load=0;
        cin >> n;

        if(n==-1) break;

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
            load+=arr[i];
        }

        if(load%n)
        {
            cout << -1 << endl;
            continue;
        }

        load/=n;

        for(int i=0; i<n; i++)
        {
            diff += (arr[i]-load);

            if(diff<0) max_load = max(max_load, (-1*diff));
            else  max_load = max(max_load, diff);
        }
        cout << max_load << endl;
    }
    return 0;
}

