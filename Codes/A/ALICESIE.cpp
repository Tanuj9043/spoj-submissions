#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t,n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);

        if(n%2) printf("%d\n",(n+1)/2);

        else printf("%d\n",n/2);
    }
    return 0;
}

