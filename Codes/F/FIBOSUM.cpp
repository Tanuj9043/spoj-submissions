#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

typedef long long ll;
#define matrix vector<vector<ll> >

ll m,n,MOD=1000000007;
int k=2;
vector<ll> c;
vector<ll> b;

matrix mul(matrix A, matrix B){
    matrix C(k+2, vector<ll>(k+2));
    for(int i = 1;i<=k+1;i++){
        for(int j = 1;j<=k+1;j++){
            for(int x = 1;x<=k+1;x++)
                C[i][j] = (C[i][j] + A[i][x]*B[x][j]) % MOD;
        }
    }
    return C;
}

matrix pow(matrix A, ll p){
    if(p == 1)
        return A;
    if(p & 1)
        return mul(A, pow(A,p-1));
    matrix X = pow(A,p/2);
    return mul(X,X);
}

ll fib(ll n){
    if(!n)
        return 0;
    if(n <= k)
        return b[n-1];

    vector<ll> F1(k+2);
    for(int i = 2;i<=k+1;i++){
        F1[i] = (b[i-2]);
    }
    matrix T(k+2, vector<ll>(k+2));
    for(int i = 1;i<=k+1;i++){
        for(int j = 1;j<=k+1;j++){

            if(i == 1 && j == 1){
                T[i][j] = 1;
                continue;
            }
            if(i == k + 1 && j > 1){
                T[i][j] = c[k- j + 1];
                continue;
            }

            if(j == i+1){
                T[i][j] = 1;
                continue;
            }
            T[i][j] = 0;
        }
    }

    T = pow(T,n);

    ll res = 0;
    for(int i = 1;i<=k+1;i++){
        res = (res + T[1][i] * F1[i]) % MOD;
    }
    return res % MOD;
}

int main(){
    int t;
    ll a;
    scanf("%d",&t);
    while(t--){
        b.push_back(0);
        b.push_back(1);
        c.push_back(1);
        c.push_back(1);
        scanf("%lld %lld",&m,&n);
        ll tot = fib(n+1) - fib(m);
        if(tot < 0) tot += MOD;
        printf("%lld\n",tot);
        c.clear();
        b.clear();
    }
    return 0;
}

