#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> val = {10, 40, 50, 70};
    vector <int> wt = {1, 3, 4, 5};
    int n = val.size();
    int w = 8;
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=w;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i-1] <= j)
                dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i][j-wt[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}