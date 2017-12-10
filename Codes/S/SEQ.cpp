#include<iostream>
#include<vector>
using	namespace	std;

typedef long long ll;
#define MOD 1000000000

ll k;
vector<ll> a;
vector<ll> b;
vector<ll> c;

vector<vector<ll> > mul(vector<vector<ll> > A, vector<vector<ll> > B)
{
    vector<vector<ll> > C(k+1, vector<ll>(k+1));
    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=k; j++)
        {
            for(int x=1; x<=k; x++)
            {
                C[i][j] = (C[i][j] + A[i][x]*B[x][j])%MOD;
            }
        }
    }
    return C;
}

vector<vector<ll> > pow(vector<vector<ll> > A, ll p)
{
    if(p==1) return A;

    if(p&1) return mul(A,pow(A,p-1));
    vector<vector<ll> > X = pow(A,p/2);
    return mul(X,X);
}

ll fib(ll n)
{
    if(n==0) return 0;
    if(n<=k) return b[n-1];

    vector<ll> F1(k+1);
    for(int i=1; i<=k; i++) F1[i]=b[i-1];

    vector<vector<ll> > T(k+1, vector<ll>(k+1));
    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(i<k)
            {
                if(j==i+1) T[i][j]=1;
                else T[i][j]=0;
                continue;
            }
            T[i][j]=c[k-j];
        }
    }

    T = pow(T,n-1);

    ll res=0;
    for(int i=1; i<=k; i++)
    {
        res = (res + T[1][i]*F1[i])%MOD;
    }

    return res%MOD;
}

int main()
{
    ll t,n,a;
    cin >> t;
    while(t--)
    {
        cin >> k;
        for(int i=0; i<k; i++)
        {
            cin >> a;
            b.push_back(a);
        }
        for(int i=0; i<k; i++)
        {
            cin >> a;
            c.push_back(a);
        }
        cin >> n;
        cout << fib(n) << endl;
        b.clear();
        c.clear();
    }
    return 0;
}

