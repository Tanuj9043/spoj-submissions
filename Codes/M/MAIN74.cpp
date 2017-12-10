#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

typedef long long ll;
#define matrix vector<vector<ll> >

ll n,MOD=1000000007;
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
    if(n==0)
        return 0;
    if(n==1 || n==2)
        return 1;

    vector<ll> F1(k+2);
    F1[1]=0;
    F1[2]=1;
    F1[3]=1;

    matrix T(k+2, vector<ll>(k+2));
    for(int i = 1;i<=3;i++){
        for(int j = 1;j<=3;j++){

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
    for(int i = 1;i<=k;i++){
        res = (res + T[1][i] * F1[i]) % MOD;
    }
    return res % MOD;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        b.push_back(0);
        b.push_back(1);
        c.push_back(1);
        c.push_back(1);
        scanf("%lld",&n);
        ll tot=0;
        if(n==0) tot=0;
        else if(n==1) tot=2;
        else if(n>=2)
        {
            tot = ((fib(n+1)%MOD)+(fib(n+2)%MOD))%MOD;
            if(tot < 0) tot += MOD;
        }
        printf("%lld\n",tot);
        c.clear();
        b.clear();
    }
    return 0;
}

