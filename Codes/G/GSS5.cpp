#include <bits/stdc++.h>
using namespace std;

int arr[200010];

struct node
{
    int ps,ss,ts,bs;//prefix sum, suffix sum, total sum, best sum

    node()
    {
        ps=ss=ts=bs=0;
    }

    node(int val)
    {
        ps=ss=ts=bs=val;
    }
}st[800010];

node build(int index, int l, int r)
{
    if(l==r)
    {
        st[index] = node(arr[l]);
        return st[index];
    }
    int mid=(l+r)>>1;

    node left = build(2*index+1, l, mid);
    node right = build(2*index+2, mid+1, r);

    st[index] = node();
    st[index].ps = max(left.ps, left.ts+right.ps);
    st[index].ss = max(right.ss, left.ss+right.ts);
    st[index].ts = left.ts + right.ts;
    st[index].bs = max(left.bs,right.bs);
    st[index].bs = max(st[index].bs, left.ss+right.ps);

    return st[index];
}

node query(int index, int l, int r, int i, int j)
{
    if(l>j || r<i || i>j)
    {
        node d = node(-1000000);
        d.ts=0;
        return d;
    }
    if(l>=i && r<=j) return st[index];

    int mid = (l+r)>>1;

    /*if(i>mid) return query(2*index+2, mid+1, r, i, j);
    else if(j<=mid) return query(2*index+1, l, mid, i, j);*/

    node left = query(2*index+1, l, mid, i, j);
    node right = query(2*index+2, mid+1, r, i, j);

    node d = node();
    d.ps = max(left.ps, left.ts+right.ps);
    d.ss = max(right.ss, left.ss+right.ts);
    d.ts = left.ts + right.ts;
    d.bs = max(left.bs,right.bs);
    d.bs = max(d.bs, left.ss+right.ps);

    return d;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }
        for(int i=0; i<800010; i++) st[i]=node();

        build(0,0,n-1);

        int q;
        scanf("%d",&q);
        while(q--)
        {
            int x1,x2,y1,y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            x1--;
            x2--;
            y1--;
            y2--;
            int ans;

            if(y1<x2)
            {
                ans = query(0,0,n-1,x1,y1).ss + query(0,0,n-1,y1+1,x2-1).ts + query(0,0,n-1,x2,y2).ps;
            }
            else
            {
                ans = query(0,0,n-1,x1,x2-1).ss + query(0,0,n-1,x2,y2).ps;
				ans = max( ans , query(0,0,n-1,x2,y1).ss + query(0,0,n-1,y1+1,y2).ps);
				ans = max( ans , query(0,0,n-1,x2,y1).bs);
            }

            printf("%d\n",ans);
        }
    }
    return 0;
}

