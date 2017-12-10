#include<iostream>
#include<map>
#include <stdio.h>
#include <string>
using	namespace	std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        map<string, int> m;
        int n;
        scanf("%d",&n);
        string a,b,c,d,e,f;
        for(int i=0; i<n; i++)
        {
            cin >> a >> b >> c >> d >> e >> f;
            string x = a+" "+b+" "+c+" "+d+" "+e+" "+f;
            auto it = m.find(x);
            if(it!=m.end())
            {
                it->second++;
            }
            else m.insert(make_pair(x,1));
        }
        for(auto it=m.begin(); it!=m.end(); it++)
        {
            cout << it->first << " " << it->second <<  endl;
        }
        cout << endl;
    }
    return 0;
}

