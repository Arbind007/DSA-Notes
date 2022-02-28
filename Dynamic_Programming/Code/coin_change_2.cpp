#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> coins =  {9, 6, 5, 1};
    int n = coins.size();
    int target = 11;
    int dp[n+1][target+1];
    for(int i=0;i<=target;i++){
        dp[0][i] = INT_MAX-1;
    }
    for(int i=1;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=target;i++){
        if(i % coins[0] == 0)
            dp[1][i] = i / coins[0];
        else
            dp[1][i] = INT_MAX-1;
    }
    
    for(int i=2;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(j>=coins[i-1])
                dp[i][j] = min(1 + dp[i][j-coins[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][target] << endl;
    return 0;
}
