#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL ModularExponentiaion(LL x,LL n,LL p)
{
       LL ans=1,temp=x%p;
       while(n)
       {
              if(n&1) // to check if last bit is 1 or not
              {
                     ans=(ans*temp)%p;
              }
              n>>=1;
              temp=(temp*temp)%p;
       }
       return  ans;
}

int main() {
     int n;
     /*variables to store 1!*2!*...N!, mod p for pF and pS respectively*/
     LL ansF=1,ansS=1;

     /* variable to store Factorial till array_index mod pF and pS respectively*/

     LL tempFactF=1,tempFactS=1;
     LL pF=186583 ;// First Prime
     LL pS=587117 ;// Second Prime
     LL N=pF*pS;
     scanf("%d",&n);
     for(int i=1;i<=n;++i)
     {
          tempFactS=(tempFactS*i)%pS;
          ansS=(ansS*tempFactS)%pS;

          tempFactF=(tempFactF*i)%pF;
          ansF=(ansF*tempFactF)%pF;
     }
     LL xF=ModularExponentiaion(N/pF,pF-2,pF);
     LL xS=ModularExponentiaion(N/pS,pS-2,pS);

     LL FinalAns=(ansF*((N/pF)*xF)%N + ansS*((N/pS)*xS)%N)%N;
     printf("%lld\n",FinalAns);
     return 0;
}

