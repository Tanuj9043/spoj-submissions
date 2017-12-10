#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

typedef long long LL;

const int N=1000010;
bool cube[1000010];
vector<pair<int,int> > vec(1000010);
LL k=2;
LL in=2;

void solve()
{
    vec[0].first=0;
    vec[0].second=0;
    vec[1].first=1;
    vec[1].second=1;
    bool flag=0;

    for(int i=0; i<=1000009; i++) cube[i]=1;

    for(int i=2;i<=1000000;i++)
    {
        if(flag==0)
        {
            if(i*i*i<=1000000)
            {
                cube[i*i*i]=0;
                for(LL j=2*i*i*i; j<=1000000; j+=i*i*i) cube[j]=0;
            }
            else flag=1;
        }
        if(cube[i]==1)
        {
            vec[k].first=i;
            vec[k].second=in;
            ::in++;
        }
        ::k++;
    }
    return;
}
int main()
{
    solve();
    int t,n,i=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(cube[n]==0) cout << "Case " << i++ << ": Not Cube Free\n";
        else  cout << "Case " << i++ << ": " << vec[n].second << "\n";
    }
    return 0;
}

