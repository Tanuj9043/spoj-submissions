#include<iostream>
#include<queue>
#include <stdio.h>
using	namespace	std;

class compare
{
public:

    bool operator()(const pair<int,int> p1, const pair<int,int> p2)
    {
        return p1.first<p2.first;
    }
};

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d",&n);
        scanf("%d",&m);
        int a;
        priority_queue<pair<int,int>, vector<pair<int,int> >, compare > pq;
        queue<pair<int,int> > q;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a);
            if(i==m)
            {
                pq.push(make_pair(a,1));
                q.push(make_pair(a,1));
            }
            else
            {
                pq.push(make_pair(a,0));
                q.push(make_pair(a,0));
            }
        }
        int ans=1;
        auto it=q.front();
        auto itv = pq.top();
        while(!q.empty())
        {
            if(it.first<itv.first)
            {
                q.push(it);
                q.pop();
                it=q.front();
            }
            else if(it.first==itv.first)
            {
                if(it.second==1)
                {
                    cout << ans << endl;
                    break;
                }
                else
                {
                    q.pop();
                    it=q.front();
                    pq.pop();
                    itv=pq.top();
                    ans++;
                }
            }
        }
    }
    return 0;
}

