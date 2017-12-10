#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;
typedef long long int ll;
#define MOD 98765431

vector<vector<ll> > T(3,vector<ll>(3));

vector<vector<ll> > mul(vector<vector<ll> > A, vector<vector<ll> > B){
    vector<vector<ll> > C(3, vector<ll>(3));
    for(int i = 1;i<=2;i++){
        for(int j = 1;j<=2;j++){
            for(int x = 1;x<=2;x++)
                C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
        }
    }
    return C;
}

vector<vector<ll> > pow(vector<vector<ll> > A, ll p){
    if(p == 1)
        return A;
    if(p & 1)
        return mul(A,pow(A,p-1));
    vector<vector<ll> > X = pow(A,p/2);
    return mul(X,X);
}

int main(){
    ll n,t,a,sum=0,res;
    ll N[100005];
    scanf("%lld %lld",&n,&t);
    for(int i=0; i<n; i++)
    {
        scanf("%lld",&a);
        N[i]=a;
        sum = (sum+a)%MOD;
    }
    T[1][1]=0;
    T[1][2]=1;
    T[2][1]=n-1;
    T[2][2]=n-2;
    T = pow(T,t);
    for(ll i=0; i<n; i++)
    {
        res = ((T[1][1]*N[i])%MOD + (T[1][2]*(sum-N[i]))%MOD)%MOD;
        if(res<0) res+=MOD;
        printf("%lld\n",res);
    }
    return 0;
}

