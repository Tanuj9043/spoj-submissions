#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

const int N = 200010;
const int MAX=1000010;
const int LN=15;
vector<int> adj[N],costs[N], ind[N];
int n,sz,arr[N],tree[N],depth[N],pa[N][20],otherEnd[N],subsz[N];
int chainNo,chainHead[N],chainInd[N],posInBase[N];
int st[4*N];

void build(int node, int l, int r)
{
    if(l==r)
    {
        st[node]=arr[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    st[node]=st[2*node]+st[2*node+1];
}

int query_tree(int node, int l, int r, int i, int j)
{
    if(l>r || l>j || r<i) return 0;

    if(l>=i && r<=j) return st[node];

    int mid = (l+r)>>1;
    return query_tree(2*node, l, mid, i, j)+query_tree(2*node+1, mid+1, r, i, j);
}

int query_up(int u, int v)
{
    if(u==v) return 0;

    int uchain, vchain=chainInd[v], ans=0;

    while(1)
    {
        uchain=chainInd[u];
        if(uchain==vchain)
        {
            if(u==v) break;
            ans+=query_tree(1,0,sz,posInBase[v]+1,posInBase[u]);
            break;
        }
        ans+=query_tree(1,0,sz,posInBase[chainHead[uchain]],posInBase[u]);
        u=chainHead[uchain];
        u=pa[u][0];
    }
    return ans;
}

int lca(int p, int q)
{
    if(depth[p]<depth[q]) swap(p,q);

    int diff = depth[p]-depth[q];

    for(int i=0; i<LN; i++)
    {
        if((diff>>i)&1) p = pa[p][i];
    }
    if(p==q) return p;

    for(int i=LN-1; i>=0; i--)
    {
        if(pa[p][i]!=-1 && pa[p][i]!=pa[q][i])
        {
            p=pa[p][i];
            q=pa[q][i];
        }
    }
    return pa[p][0];
}

int query(int p, int q)
{
    int l = lca(p,q);
    int ans = query_up(p,l);
    ans+=query_up(q,l);
    return ans;
}

void hld(int cur, int prev, int cost)
{
    if(chainHead[chainNo]==-1) chainHead[chainNo]=cur;

    chainInd[cur] = chainNo;
    posInBase[cur] = sz;
    arr[sz++] = cost;

    int sc=-1, sc_cost;
    for(int i=0; i<adj[cur].size(); i++)
    {
        if(adj[cur][i]!=prev)
        {
            if(sc==-1 || subsz[sc]<subsz[adj[cur][i]])
            {
                sc=adj[cur][i];
                sc_cost=costs[cur][i];
            }
        }
    }

    if(sc!=-1) hld(sc,cur,sc_cost);

    for(int i=0; i<adj[cur].size(); i++)
    {
        if(adj[cur][i]!=prev && sc!=adj[cur][i])
        {
            chainNo++;
            hld(adj[cur][i],cur,costs[cur][i]);
        }
    }
    return;
}

void dfs(int cur, int prev, int level)
{
    pa[cur][0]=prev;
    depth[cur]=level;
    subsz[cur]=1;
    for(int i=0; i<adj[cur].size(); i++)
    {
        if(adj[cur][i]!=prev)
        {
            otherEnd[ind[cur][i]] = adj[cur][i];
            dfs(adj[cur][i], cur, level+1);
            subsz[cur]+=subsz[adj[cur][i]];
        }
    }
}

int getkth(int p, int q, int k)
{
    int l = lca(p,q);
    int d;

    if(l==p)
    {
        d=depth[q]-depth[p]+1;
        swap(p,q);
        k=d-k+1;
    }
    else if(l==q);
    else
    {
        d=depth[p]+depth[q]-(2*depth[l])+1;
        if(k>depth[p]-depth[l]+1)
        {
            k=d-k+1;
            swap(p,q);
        }
    }

    k--;
    for(int i=LN-1; i>=0; i--)
    {
        if(k>=(1<<i))
        {
            p=pa[p][i];
            k-=(1<<i);
        }
    }
    return p;
}

int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        sz=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            adj[i].clear();
            costs[i].clear();
            ind[i].clear();
            chainHead[i]=-1;
            for(int j=0; j<LN; j++) pa[i][j]=-1;
        }

        for(int i=1; i<n; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            --a,--b;

            adj[a].push_back(b);
            adj[b].push_back(a);
            ind[a].push_back(i-1);
            ind[b].push_back(i-1);
            costs[a].push_back(c);
            costs[b].push_back(c);
        }
        chainNo=0;

        dfs(0,-1,0);
        hld(0,-1,-1);
        build(1,0,sz);

        for(int j=1; j<LN; j++)
        {
            for(int i=0; i<n; i++)
                if(pa[i][j-1]!=-1) pa[i][j]=pa[pa[i][j-1]][j-1];
        }

        char ch[20];
        while(1)
        {
            scanf("%s",ch);
            if(ch[1]=='O')break;
            if(ch[0]=='D')
            {
                scanf("%d %d",&a,&b);
                printf("%d\n",query(a-1,b-1));
            }
            else if(ch[0]=='K')
            {
                scanf("%d %d %d",&a,&b,&c);
                printf("%d\n",getkth(a-1,b-1,c)+1);
            }
        }
    }
    return 0;
}

