#include <bits/stdc++.h>
using namespace std;

int arr[100010], st[400010];

void build(int node, int l, int r)
{
    if(l==r)
    {
        st[node]=arr[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*node+1, l, mid);
    build(2*node+2, mid+1, r);
    st[node]=max(st[2*node+1],st[2*node+2]);
}

int query_tree(int node, int l, int r, int i, int j)
{
    if(l>r || l>j || r<i) return -1;

    if(l>=i && r<=j) return st[node];

    int mid = (l+r)>>1;
    return max(query_tree(2*node+1, l, mid, i, j),query_tree(2*node+2, mid+1, r, i, j));
}

int main()
{
    int n,k;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    build(0,0,n-1);
    scanf("%d",&k);
    for(int i=0; i<=n-k; i++)
    {
        printf("%d ",query_tree(0,0,n-1,i,i+k-1));
    }
    return 0;
}

