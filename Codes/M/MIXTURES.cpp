#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>
using namespace std;

#define INF 99999999
const int NN = 101;

long long dp[NN][NN], sum[NN], col[NN];

int minSmoke(int n){
    
    //Building the cummulative sum array
    sum[0] = col[0];
    for(int i = 1;i<n;i++)
        sum[i] = (sum[i-1] + col[i]);
    
    
    //dp[i][j] --> min smoke produced after mixing {color(i).....color(j)}
    //Note color after mixing {color(i).....color(j)} is sum[i...j] mod M
    //Building the dp in bottom up fashion
    for(int i = n-1;i>=0;i--){
        for(int j = 0;j<n;j++){
            
            //Base Case
            //if i and j are equal then we have a single mixture and 
            //hence no smoke is produced
            if(i == j){
                dp[i][i] = 0;
                continue;
            }
            
            dp[i][j] = LONG_MAX;
            
            for(int k = i;k<j;k++){
                int color_left = (sum[k] - sum[i-1]) % 100;
                int color_right = (sum[j] - sum[k]) % 100;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + (color_left * color_right));
            }
        }
    }
    
    //return the most optimal answer
    return dp[0][n-1];
}

int main() {
    int t,n;
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>col[i];
        cout<<minSmoke(n)<<endl;
    }
    return 0;
}
