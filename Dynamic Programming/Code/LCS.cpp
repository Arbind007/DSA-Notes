#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1,str2;
    str1 = "GeeksforGeeks";
    str2 = "GeeksQuiz";
    int n = str1.length(),m = str2.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=m;i++){
        dp[0][i] = 0;
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
            }
            mx = max(mx,dp[i][j]);
        }
    }
    cout << mx << endl;
    return 0;
}