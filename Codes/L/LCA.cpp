#include <bits/stdc++.h>
using namespace std;

#define log 11

const int MAXN = 1030;
vector<int> adj[MAXN];
int pa[MAXN][log], P[MAXN], depth[MAXN], n;

void pre_process()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<log; j++)
            pa[i][j]=-1;
    }

    for(int i=0; i<n; i++) pa[i][0]=P[i];

    for(int i=0; i<n; i++)
    {
        for(int j=1; (1<<j)<n; j++)
        {
            if(pa[i][j-1]!=-1)
                pa[i][j]=pa[pa[i][j-1]][j-1];
        }
    }
    return;
}

void dfs(int cur, int prev, int d)
{
    P[cur]=prev;
    depth[cur]=d;
    for(int i=0; i<adj[cur].size(); i++)
    {
        int v=adj[cur][i];
        if(v!=prev) dfs(v,cur,d+1);
    }
    return;
}

int lca(int u, int v)
{
    if(depth[u]<depth[v]) swap(u,v);

    int diff=depth[u]-depth[v];

    for(int i=0; i<log; i++)
    {
        if((diff>>i)&1) u=pa[u][i];
    }

    if(u==v) return u;

    for(int i=log-1; i>=0; i--)
    {
        if(pa[u][i]!=pa[v][i])
        {
            u=pa[u][i];
            v=pa[v][i];
        }
    }
    return pa[u][0];
}

int main()
{
    int t,sz,u,v,ch,q,cnt=1;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&sz);
            for(int j=1; j<=sz; j++)
            {
                scanf("%d",&u);
                P[u-1]=i;
                adj[i].push_back(u-1);
                adj[u-1].push_back(i);
            }
        }
        dfs(0,-1,0);
        pre_process();
        scanf("%d",&q);
        printf("Case %d: \n",cnt++);
        for(int i=0; i<q; i++)
        {
            scanf("%d%d",&u,&v);
            printf("%d\n",(lca(u-1,v-1)+1));
        }
        for(int i=0; i<n; i++) adj[i].clear();
    }
    return 0;
}

