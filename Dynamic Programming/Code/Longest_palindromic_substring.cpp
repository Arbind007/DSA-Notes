#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1;
    str1 = "aaaabbaa";
    int n = str1.length(),start = 0,length = 0;
    int dp[n][n];
    memset(dp,0,sizeof dp);
    for(int i=0;i<n;i++)
        dp[i][i] = 1;
    for(int i=0;i<n-1;i++){
        if(str1[i] == str1[i+1]){
            dp[i][i+1] = true;
            start = i;
            length = 2;
        }
    }
    // k -> length of string
    for(int k=3;k<=n;k++){
        // i -> starting index
        for(int i=0;i<n-k+1;i++){
            // j -> ending index
            int j=i+k-1; 
            if(dp[i+1][j-1] && str1[i] == str1[j]){
                dp[i][j] = true;
                if(k > length){
                    start = i;
                    length = k;
                }
            }
        }
    }
    cout << length << endl;
    return 0;
}