#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v = {2,3,7,8,10};
    int n = v.size();
    int sum = 11;
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0] = true;
    for(int i=1;i<=sum;i++)
        dp[0][i] = false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j >= v[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]]; 
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][sum] << endl;
    return 0;
}
