#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

class compare
{
public:
    bool operator()(pair<int,int> l, pair<int,int> r)
    {
        return l.second<r.second;
    }
};

int main()
{
    int t,n,s,e,res,fin;
    scanf("%d",&t);
    while(t--)
    {
        res=1;
        vector<pair<int,int> > a;
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&s,&e);
            a.push_back(make_pair(s,e));
        }

        sort(a.begin(),a.end(),compare());

        fin = a[0].second;

        for(int i=1; i<a.size(); i++)
        {
            if(a[i].first>=fin)
            {
                fin = a[i].second;
                res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

