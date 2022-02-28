#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1,str2;
    str1 = "bacbcf";
    str2 = "abcdaf";
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
    int i=n,j=m;
    string ans = "";
    while(i>0 && j>0){
        if(str1[i-1] == str2[j-1]){
            ans+=str1[i-1];
            i--,j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                ans+=str1[i-1];
                i--;
            }
            else{
                ans+=str2[j-1];
                j--;
            }
        }
    }
    while(i>0){
      ans.push_back(str1[--i]);
    }
    while(j>0){
      ans.push_back(str2[--j]);
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
    return 0;
}