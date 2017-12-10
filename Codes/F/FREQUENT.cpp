#include <bits/stdc++.h>
using namespace std;

int arr[100010];

class node
{
public:
    int lfreq,rfreq,mfreq;//frequency of left most value, right most value and maximum frequency
};

node st[400010];

void build(int index, int l, int r)
{
    if(l==r)
    {
        st[index].lfreq=st[index].rfreq=st[index].mfreq=1;
        return;
    }

    int mid=(l+r)>>1;

    build(2*index+1, l, mid);
    build(2*index+2, mid+1, r);

    if(arr[mid]==arr[mid+1])
    {
        st[index].lfreq = st[2*index+1].lfreq + (arr[l]==arr[mid])*st[2*index+2].lfreq;
        st[index].rfreq = st[2*index+2].rfreq + (arr[r]==arr[mid+1])*st[2*index+1].rfreq;
        int temp = st[2*index+1].rfreq + st[2*index+2].lfreq;
        st[index].mfreq = max(temp, max(st[2*index+1].mfreq,st[2*index+2].mfreq));
    }
    else
    {
        st[index].lfreq = st[2*index+1].lfreq;
        st[index].rfreq = st[2*index+2].rfreq;
        st[index].mfreq = max(st[2*index+1].mfreq,st[2*index+2].mfreq);
    }
    return;
}

int query(int index, int l, int r, int i, int j)
{
    if(l==i && r==j) return st[index].mfreq;

    int mid = (l+r)>>1;

    if(j<=mid) return query(2*index+1, l, mid, i, j);
    if(i>mid) return query(2*index+2, mid+1, r, i, j);

    int left = query(2*index+1, l, mid, i, mid);
    int right = query(2*index+2, mid+1, r, mid+1, j);

    if(arr[mid]==arr[mid+1])
    {
        int temp = min(st[2*index+1].rfreq, mid+1-i) + min(st[2*index+2].lfreq, j-mid);
        return max(temp, max(left,right));
    }
    else return max(left,right);
}

int main()
{
    int n,q,x,y;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        scanf("%d",&q);

        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }

        build(0,0,n-1);

        while(q--)
        {
            scanf("%d %d",&x,&y);
            if(x==y) printf("1\n");
            else printf("%d\n",query(0,0,n-1,x-1,y-1));
        }
    }
    return 0;
}

