#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> coin = {1, 2, 3};
    int n = coin.size();
    int sum = 5;
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coin[i-1] <= j)
                dp[i][j] = dp[i-1][j]+dp[i][j-coin[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][sum] << endl;
    return 0;
}