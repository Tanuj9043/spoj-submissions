#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int t,n;
    float res=0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        res=0;
        for(float i=0; i<n; i++)
        {
            res += (n/(n-i));
        }
        printf("%.2f\n",res);
    }
    return 0;
}

