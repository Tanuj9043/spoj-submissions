#include <iostream>
#include <set>
using	namespace	std;

int main()
{
    int n,k,a;
    long long int ans=0;
    cin >> n;
    multiset<int> m;
    for(int i=0; i<n; i++)
    {
        cin >> k;
        for(int i=0; i<k; i++)
        {
            cin >> a;
            m.insert(a);
        }
        auto it1 = m.begin();
        auto it2 = m.end();
        it2--;
        ans += (*it2 - *it1);
        m.erase(it1);
        m.erase(it2);
    }
    cout << ans << endl;
    return 0;
}

