#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

typedef unsigned long long int ll;
typedef pair<ll, ll> pair_int;
typedef set<pair_int> set_int;
typedef map<string, pair_int> map_int;

map_int m;
set_int s;

int main()
{
    int M;
    ll S,P,total=0;
    char n[21];
    char a;

    cin >> M;
    for(int i=0; i<M; i++)
    {
        cin >> a;
        cin >> n;
        bool has_prev=false,has_next=false;

        if(a=='A')
        {
            cin >> S >> P;
            auto pointer = s.insert(make_pair(S,P));
            auto x = pointer.first;
            auto y = pointer.first;

            if(x != s.begin())
            {
                has_prev=true;
                x--;
            }
            if(y != s.end())
            {
                has_next=true;
                y++;
            }

            if (has_prev && has_next) {
                total -= x->second * y->second;
            }

            m[n] = make_pair(S,P);

            if (has_prev) {
                total += x->second * P;
            }
            if (has_next) {
                total += y->second * P;
            }
        }
        else
        {
            auto res = m.find(n);

            if(res!=m.end())
            {
                S = res->second.first;
                P = res->second.second;

                auto it = s.find(make_pair(S,P));
                auto x = it;
                auto y = it;

                if (x != s.begin()) {
                    x--;
                    has_prev = true;
                }
                y++;
                if (y!= s.end()) {
                    has_next = true;
                }

                if (has_prev) {
                    total -= P * x->second;
                }
                if (has_next) {
                    total -= P * y->second;
                }
                if (has_prev && has_next) {
                    total += x->second * y->second;
                }

                s.erase(it);
                m.erase(n);
            }
        }
        cout << total << endl;
    }
    return 0;
}

