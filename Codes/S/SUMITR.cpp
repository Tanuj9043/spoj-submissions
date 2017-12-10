#include<iostream>
using namespace std;main(){int t,n,i=1,j;int a[105][105];cin>>t;while(t--){cin>>n;for(;i<=n;i++)for(j=1;j<=i;cin>>a[i][j++]){}for(i=n-1;i>=1;i--){for(j=1;j<=i;j++){a[i][j]+=max(a[i+1][j],a[i+1][j+1]);}}cout<<a[1][1]<<"\n";}}

