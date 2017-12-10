#include<iostream>
#include<cstring>
using namespace std;

typedef long long int ll;

int main()
{
    ll t,a,m;
    cin >> t;
    while(t--)
    {
        char z[255];
        int b[255];

        cin >> a >> z >> m;

        int d=0;
        ll prev[300];
        for(int i=strlen(z)-1; i>=0; i--) b[d++]=z[i]-'0';

        ll res = 1;

        for(int i=0; i<strlen(z); i++)
        {
            if(i==0)
            {
                prev[i]=a;
                if(b[i]==0) res=1;
                else if(b[i]==1) res=(a%m);
                else if(b[i]==2) res=((a%m)*(a%m))%m;
            }
            else
            {
                ll x = prev[i-1];
                ll y = ((((x%m)*(x%m))%m)*x)%m;
                prev[i]=y;
                if(b[i]==0) res = res*1;
                else if(b[i]==1) res = (res*y)%m;
                else if(b[i]==2) res = (((y*y)%m)*res)%m;
            }
        }

        if(res<0) res+=m;
        cout << res << endl;
    }
    return 0;
}

