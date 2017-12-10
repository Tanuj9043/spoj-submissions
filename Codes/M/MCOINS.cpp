#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
#define MX 1000005
int main(){
  int l,m,n,i,j,k;
  bool gt[MX];
     
  gt[0] = false;
  scanf("%d %d %d",&k,&l,&m);
   
  for(i=1;i<MX;i++){
        gt[i] = false;
        if( i-1 >=0 && gt[i-1]==false) gt[i]=true;
        else if( i-k >=0 && gt[i-k]==false) gt[i]=true;
        else if( i-l >=0 && gt[i-l]==false) gt[i]=true;
  }
  for(i=0;i<m;i++){
        scanf("%d",&n);
        if(gt[n]) printf("A");
        else printf("B");
  }
  printf("\n");
  return 0;
}
