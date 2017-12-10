#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	int a[105];
	a[0]=0;
	for(int i=1; i<=100; i++)
    {
        a[i]=a[i-1]+(i*i);
    }

	while(1)
    {
        scanf("%d",&n);
        if(n==0)
        {
            printf("\n");
            break;
        }

        printf("%d\n",a[n]);
    }
	return 0;
}

