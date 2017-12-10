#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n,t,x,d,f,D,F,prev=0;
    scanf("%d",&t);
    while(t--)
    {
        int flag=0,ans=0;
        vector<pair<int,int> > v;
        priority_queue<int> pq;

        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&d,&f);
            v.push_back(make_pair(d,f));
        }

        scanf("%d %d",&D,&F);

        for(int	i=0; i<n; i++)
        {
            v[i].first=D-v[i].first;
        }

        sort(v.begin(),v.end());
        prev=0;
        x=0;

        while(x<n)
        {
            if(F>=(v[x].first-prev))
            {
                F -= (v[x].first-prev);
                pq.push(v[x].second);
                prev = v[x].first;
            }
            else
            {
                if(pq.empty())
                {
                    flag=1;
                    break;
                }
                F+=pq.top();
                pq.pop();
                ans++;
                continue;
            }
            x++;
        }

        if(flag)
        {
            printf("-1\n");
            continue;
        }
        D = D-v[n-1].first;
        if(F>=D)
        {
            printf("%d\n",ans);
            continue;
        }
        while(F<D)
        {
            if(pq.empty())
            {
                flag=1;
                break;
            }
            F+=pq.top();
            pq.pop();
            ans++;
        }
        if(flag)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",ans);
    }
    return 0;
}

