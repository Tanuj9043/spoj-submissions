#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;

void number()
{
    int primes[3000]={0};
    for(int i=2; i<3000; i++)
    {
        if(primes[i]==0)
        {
            primes[i]=1;
            for(int j=i*2; j<3000; j+=i)
            {
                primes[j]--;
                if(primes[j]==-3)
                {
                    num.push_back(j);
                }
            }
        }
    }
    return;
}

int main()
{
    number();
    sort(num.begin(),num.end());
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << num[n-1] << endl;
    }
    return 0;
}

