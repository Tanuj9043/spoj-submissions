#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
const int NN = 1e5+2;

vector<int> adj[NN];
vector<int> w[NN];

int cnt[100010];
bool vis[100010];

int n;

void dfs(int v)
{
    vis[v]=1;

    for(int i=0; i<adj[v].size(); i++)
    {
        int u = adj[v][i];

        if(vis[u]) continue;

        dfs(u);
        cnt[v] += cnt[u];
    }
    return;
}

long long sol(int v)
{
    vis[v]=1;
    long long res=0;
    for(int i=0; i<adj[v].size(); i++)
    {
        int u=adj[v][i];
        if(vis[u]) continue;

        res += min(cnt[u],n-cnt[u])*2*w[v][i] + sol(u);
    }
    return res;
}

int main()
{
    int t,a,x,y,in=1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            adj[i].clear();
            w[i].clear();
            cnt[i]=1;
            vis[i]=0;
        }
        for(int i=0; i<n-1; i++)
        {
            cin >> x >> y >> a;
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
            w[x].push_back(a);
            w[y].push_back(a);
        }
        dfs(0);
        memset(vis,0,sizeof vis);
        cout << "Case #" << in << ": " << sol(0) << endl;
        in++;
    }
    return 0;
}

