#include <bits/stdc++.h>
using namespace std;

int arr[100010];
pair<int,int> st[400010];

void build(int node, int l, int r)
{
    if(l==r)
    {
        st[node].first=arr[l];
        st[node].second=-100;
        return;
    }
    int mid=(l+r)>>1;
    build(2*node+1, l, mid);
    build(2*node+2, mid+1, r);
    st[node].first=max(st[2*node+1].first,st[2*node+2].first);
    st[node].second=min(max(st[2*node+1].first,st[2*node+2].second),max(st[2*node+2].first,st[2*node+1].second));
}

pair<int,int> query_tree(int node, int l, int r, int i, int j)
{
    if(l>j || r<i) return make_pair(-100,-100);
    if(l>=i && r<=j) return st[node];

    int mid = (l+r)>>1;
    if(i>mid) return query_tree(2*node+2, mid+1, r, i, j);
    if(j<=mid) return query_tree(2*node+1, l, mid, i, j);

    pair<int,int> p1,p2,res;
    p1 = query_tree(2*node+1, l, mid, i, j);
    p2 = query_tree(2*node+2, mid+1, r, i, j);

    res.first = max(p1.first,p2.first);
    res.second = min(max(p1.first,p2.second),max(p2.first,p1.second));
    return res;
}

void update(int node, int l, int r, int idx, int val)
{
    if(l==r)
    {
        st[node].first=val;
        st[node].second=-100;
    }
    else
    {
        int mid=(l+r)>>1;
        if(idx<=mid) update(2*node+1, l, mid, idx, val);
        else update(2*node+2, mid+1, r, idx, val);

        st[node].first = max(st[2*node+1].first,st[2*node+2].first);
        st[node].second = min(max(st[2*node+1].first,st[2*node+2].second),max(st[2*node+2].first,st[2*node+1].second));
    }
}

int main()
{
    int n,a,b,q;
    char ch;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    build(0,0,n-1);
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        cin >> ch;
        scanf("%d %d",&a,&b);
        if(ch=='Q')
        {
            pair<int,int> p = query_tree(0,0,n-1,a-1,b-1);
            printf("%d\n",(p.first+p.second));
        }
        else update(0,0,n-1,a-1,b);
    }
    return 0;
}

