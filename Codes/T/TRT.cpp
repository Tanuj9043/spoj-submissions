#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

int dp[2002][2002] = {0}, price[2002];

int maxPrice(int start,int end,int N){

    //Initialize the dp array
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++)
            dp[i][j] = 0;
    }

    //Outer loop denotes the starting index for our solution
    for(int i = N-1;i>=0;i--){
        //Inner loop denotes the ending index
        for(int j = 0;j<N;j++){
            //if (start > end), return 0
            if(i > j)
                dp[i][j] = 0;
            else{
                //find the current year
                int year = N - (j - i);
                //using bottom up dp to solve the problem for smaller sub problems
                //and using it to solve the larger problem i.e. dp[i][j]
                dp[i][j] = max(year * price[i] + dp[i+1][j], year * price[j] + dp[i][j-1]);
            }
        }
    }
    //return the final answer where starting index is start = 0 and ending index is end = n-1
    return dp[0][N-1];
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&price[i]);
    }
    printf("%d\n",maxPrice(0,n-1,n));
    return 0;
}

