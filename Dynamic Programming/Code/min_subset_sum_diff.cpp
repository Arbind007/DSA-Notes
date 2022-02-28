#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v = {1,2,7};
    int n = 3;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += v[i];
    }
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j >= v[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    // int mn = INT_MAX;                      //NOT EFFICIENT
    // for(int i=0;i<=sum/2;i++){
    //     cout << dp[n][i] << " ";
    //     if(dp[n][i])
    //         mn = min(mn,sum - 2 * i);
    // }
    // cout << mn << endl;
    int ans;
    for(int i=sum/2;i>=0;i--){
        if(dp[n][i]){
            ans = sum - 2 * i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}