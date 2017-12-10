#include <bits/stdc++.h>
using namespace std;

int arr[50010];

class node
{
public:
    int ps,ss,ts,ms;//prefix sum, suffix sum, total sum, maximum sum

    node()
    {
        ps=-10001,ss=-10001,ts=-10001,ms=-10001;
    }
};

node st[200010];

node build(int index, int l, int r)
{
    if(l==r)
    {
        st[index].ps=arr[l];
        st[index].ss=arr[l];
        st[index].ts=arr[l];
        st[index].ms=arr[l];
        return st[index];
    }
    int mid=(l+r)>>1;

    node left = build(2*index+1, l, mid);
    node right = build(2*index+2, mid+1, r);

    st[index].ps = max(left.ps, left.ts+right.ps);
    st[index].ss = max(right.ss, left.ss+right.ts);
    st[index].ts = left.ts + right.ts;
    st[index].ms = max(left.ss+right.ps,max(left.ms,right.ms));

    return st[index];
}

node query(int index, int l, int r, int i, int j)
{
    node d;
    if(l>j || r<i) return d;
    if(l>=i && r<=j) return st[index];

    int mid = (l+r)>>1;

    if(i>mid) return query(2*index+2, mid+1, r, i, j);
    else if(j<=mid) return query(2*index+1, l, mid, i, j);

    node left = query(2*index+1, l, mid, i, j);
    node right = query(2*index+2, mid+1, r, i, j);

    d.ps = max(left.ps, left.ts+right.ps);
    d.ss = max(right.ss, left.ss+right.ts);
    d.ts = left.ts + right.ts;
    d.ms = max(left.ss+right.ps,max(left.ms,right.ms));

    return d;
}

node update(int index, int l, int r, int idx, int val)
{
    if(l==r)
    {
        st[index].ms=val;
        st[index].ps=val;
        st[index].ss=val;
        st[index].ts=val;
        return st[index];
    }
    node d;
    int mid=(l+r)>>1;
    if(idx>mid) update(2*index+2, mid+1, r, idx, val);
    else update(2*index+1, l, mid, idx, val);

    node left = st[2*index+1];
    node right = st[2*index+2];

    st[index].ps = max(left.ps, left.ts+right.ps);
    st[index].ss = max(right.ss, left.ss+right.ts);
    st[index].ts = left.ts + right.ts;
    st[index].ms = max(left.ss+right.ps,max(left.ms,right.ms));
    return st[index];
}

int main()
{
    int n,a,b,q,c;
    char ch;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    build(0,0,n-1);

    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d %d",&c,&a,&b);
        if(c==1) printf("%d\n",query(0,0,n-1,a-1,b-1).ms);
        else update(0,0,n-1,a-1,b);
    }
    return 0;
}

