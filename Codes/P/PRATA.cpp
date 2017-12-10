#include <iostream>
#include <stdio.h>
using namespace std;

int R[1000];
int N,C;

bool checkPrata(int k)
{
    int p=0,j,tmp;
    for(int i=0; i<C; i++)
    {
        j=1,tmp=k;
        while(tmp>0)
        {
            tmp-=((j++)*R[i]);
            if(tmp>=0) p++;
            if(p>=N) return true;
        }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&N,&C);

        for(int i=0; i<C; i++) scanf("%d",&R[i]);

        int lo=0, hi=2147483647, mi;

        while(lo < hi)
        {
            mi = (lo+hi)/2;

            if(checkPrata(mi)) hi=mi;
            else lo=mi+1;
        }

        printf("%d\n",lo);
    }
	return 0;
}

