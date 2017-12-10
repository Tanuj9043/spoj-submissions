#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t,n,x;
    int a[100010];
    cin >> t;

    while(t--)
    {
        int cnt=0;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> x;
            if(x==1) cnt++;
            else a[i-cnt]=x;
        }

        for(int i=0; i<cnt; i++) cout << "1 ";

        n-=cnt;
        sort(a,a+n);

        if(n==2 && a[0]==2 && a[1]==3)
        {
            cout << "2 3\n";
            continue;
        }
        else reverse(a,a+n);

        for(int i=0; i<n; i++) cout << a[i] << " ";

        cout << endl;
    }
    return 0;
}

