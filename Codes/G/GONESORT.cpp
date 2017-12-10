#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
using namespace std;

#define INF 99999999
const int NN = 10000010;

int t, n, lis[NN], arr[NN], temp[NN];

/*
In order to get the minimum number of remove and place operations, we must make sure that we do not modify the longest consecutive increasing subsequence(like 1-2-3, 4-5-6-7 etc) of books. All the non-lcis books then needs to be placed either at the start or ebd depending whether its serial number is more then the largest lcis book or less then the lowest lcis book.
*/

int LCIS(int n)
{
    for(int i = 0;i<n;i++)
        temp[i] = arr[i];
    
    sort(arr+0, arr+n);
    
    for(int i = 0;i<n;i++)
        lis[arr[i]] = i;
    
    for(int i = 0;i<n;i++)
        arr[i] = lis[temp[i]];
    
    int largest = 0;
    for(int start = 0;start < n;start++){
        int cnt = 0, curr = start;
        for(int i = 0;i<n;i++){
            if(arr[i] == curr){
                curr++;
                cnt++;
            }
        }
        largest = max(cnt,largest);
    }
    return largest;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0;i<n;i++)
            cin>>arr[i];
        
        //Find the max number of books that needs to be kept fixed!
        int fixed = LCIS(n);
        
        //Output the number of books that needs to be shifted to start or end.
        cout<<n-fixed<<endl;       
    }
    return 0;
}
