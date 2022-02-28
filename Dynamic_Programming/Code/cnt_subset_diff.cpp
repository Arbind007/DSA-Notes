#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v = {1,1,2,3};
    int n = 4;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += v[i];
    }
    int diff = 1;
    sum = (sum + diff)/2; // s1 - s2 = diff =>  s1 - sum + s1 = diff => 2*s1 = diff + sum  
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j >= v[i-1])
                dp[i][j] = dp[i-1][j] + dp[i-1][j-v[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][sum] << endl;
    return 0;
}