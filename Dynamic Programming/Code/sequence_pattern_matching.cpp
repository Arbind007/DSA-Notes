#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1,str2;
    str1 = "AXY";
    str2 = "ADXCPY";
    int n = str1.length(),m = str2.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=m;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    if(dp[n][m] == min(n,m)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}