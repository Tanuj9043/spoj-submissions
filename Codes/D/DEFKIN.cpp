#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int  point_x[40010], point_y[40010];

int main()
{
    int t,w,h,n,x,y,dx,dy;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&w,&h,&n);

        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&point_x[i],&point_y[i]);
        }

        sort(point_x, point_x+n);
        sort(point_y, point_y+n);

        dx = point_x[0];
        dy = point_y[0];

        for(int i=1; i<n; i++)
        {
            dx = max(dx,point_x[i]-point_x[i-1]);
            dy = max(dy,point_y[i]-point_y[i-1]);
        }

        dx = max(dx,w+1-point_x[n-1]);
        dy = max(dy,h+1-point_y[n-1]);
        printf("%d\n",((dx-1)*(dy-1)));
    }
    return 0;
}

