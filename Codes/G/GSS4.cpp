#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node
{
    int start,end;
    ll total;
    bool pendingUpdate;

    node():total(0),pendingUpdate(false){}

    void applyPendingUpdate()
    {
        total=(ll)sqrt(total);
        pendingUpdate=false;
    }
};

node st[400010];
long long arr[100010];

void build(int index, int i, int j)
{
    st[index].start=i, st[index].end=j;

    if(i==j)
    {
        st[index].total=arr[i];
        return;
    }

    int mid=(i+j)>>1;

    build(2*index, i, mid);
    build(2*index+1, mid+1, j);

    st[index].total = st[2*index].total+st[2*index+1].total;
}

node query(int index, int i, int j)
{
    if(st[index].start==i && st[index].end==j) return st[index];

    int mid = (st[index].start+st[index].end)>>1;

    node res;
    if(i>mid) {res = query(2*index+1, i, j);}
    else if(j<=mid) {res = query(2*index, i, j);}
    else
    {
        node left = query(2*index, i, mid);
        node right = query(2*index+1, mid+1, j);

        res.start = left.start;
        res.end = right.end;
        res.total = left.total+right.total;
    }
    return res;
}

void applyLazyProp(int index, bool val)
{
    st[index].pendingUpdate=true;
    if(st[index].total<=st[index].end-st[index].start+1)///all values in the range are 1
    {
        return;
    }

    if(st[index].start==st[index].end)
    {
        st[index].applyPendingUpdate();
        return;
    }

    bool pendingUpdate = st[index].pendingUpdate;
    st[index].pendingUpdate=false;

    int mid = (st[index].start+st[index].end)>>1;

    applyLazyProp(2*index, pendingUpdate);
    applyLazyProp(2*index+1, pendingUpdate);
    st[index].total = st[2*index].total+st[2*index+1].total;
}

void update(int index, int i, int j, bool val)
{
    if(st[index].start==i && st[index].end==j)
    {
        applyLazyProp(index,val);
        return;
    }

    int mid=(st[index].start+st[index].end)>>1;

    if(i>mid) update(2*index+1, i, j, val);
    else if(j<=mid) update(2*index, i, j, val);
    else
    {
        update(2*index, i, mid, val);
        update(2*index+1, mid+1, j, val);
    }
    st[index].total = st[2*index].total+st[2*index+1].total;
}

int main()
{
    int n,q,x,a,b,test=1;
    while(scanf("%d", &n)!=EOF)
    {
        for(int i=0; i<n; i++) scanf("%lld",&arr[i]);

        build(1,0,n-1);

        scanf("%d",&q);

        printf("Case #%d:\n", test++);
        while(q--)
        {
            scanf("%d %d %d",&x,&a,&b);
            if(a>b) swap(a,b);
            if(x==1) printf("%lld\n",query(1,a-1,b-1).total);
            else
            {
                update(1,a-1,b-1,true);
            }
        }
        printf("\n");
    }
    return 0;
}

