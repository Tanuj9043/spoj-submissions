#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int t,n,m,k;
    cin >> t;

    while(t--)
    {
        vector<int> v;
        char ch;
        int ans=0;
        cin >> n >> m >> k;

        for(int i=0; i<n; i++)
        {
            int temp=0;
            for(int j=0; j<m; j++)
            {
                cin >> ch;
                if(ch=='*') temp++;
            }
            v.push_back(temp);
            ans+=temp;
        }

        while(k--)
        {
            sort(v.begin(),v.end());
            ans -= v[0];
            v[0] = m-v[0];
            ans+=v[0];
        }
        cout << ans << endl;
    }
    return 0;
}

