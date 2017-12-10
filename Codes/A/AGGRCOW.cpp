#include <bits/stdc++.h>
using namespace std;

int n,c;

int check(int num, int array[])
{
    int cows=1, pos=array[0];

    for(int i=1; i<n; i++)
    {
        if(array[i]-pos>=num)
        {
            cows++;
            if(cows==c) return 1;
            pos = array[i];
        }
    }
    return 0;
}

int binSearch(int array[])
{
    int s=0, e=array[n-1], mx=-1;
    while(e>s)
    {
        int mid = (s+e)/2;

        if(check(mid,array)==1)
        {
            mx=max(mx,mid);
            s=mid+1;
        }
        else e=mid;
    }
    return mx;
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&c);
        int array[n];
        for(int i=0; i<n; i++)
        {
            scanf("%d",&array[i]);
        }
        sort(array,array+n);

        int k=binSearch(array);

        printf("%d\n",k);
    }
    return 0;
}

