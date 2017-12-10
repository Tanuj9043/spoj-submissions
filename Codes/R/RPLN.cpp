#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000001
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
    st[node]=min(st[2*node+1],st[2*node+2]);
}

int query_tree(int node, int l, int r, int i, int j)
{
    if(l>r || l>j || r<i) return MAX;

    if(l>=i && r<=j) return st[node];

    int mid = (l+r)>>1;
    return min(query_tree(2*node+1, l, mid, i, j),query_tree(2*node+2, mid+1, r, i, j));
}

int main()
{
    int t,n,q,i=1,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }
        build(0,0,n-1);
        bool f=0;
        while(q--)
        {
            scanf("%d %d",&a,&b);
            if(f==0)
            {
                printf("Scenario #%d:\n",i++);
                f=1;
            }
            printf("%d\n",query_tree(0,0,n-1,a-1,b-1));
        }
    }
    return 0;
}

