#include<bits/stdc++.h>
using namespace std;

int LHS(string s1,string s2,int n,int m){
    if(!n || !m)
        return 0;
    if(s1[n] == s2[m])
        return 1 + LHS(s1,s2,n-1,m-1);
    return max(LHS(s1,s2,n-1,m),LHS(s1,s2,n,m-1));
}

int main()
{
    string str1,str2;
    str1 = "abcdgh";
    str2 = "abedfhr";
    cout << LHS(str1,str2,str1.length(),str2.length()) << endl;
    return 0;
}

//top down 
#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int LHS(string s1,string s2,int n,int m){
    if(!n || !m)
        return 0;
    if(dp[n][m] != -1)
        return dp[n][m];
    if(s1[n] == s2[m])
        return dp[n][m] = 1 + LHS(s1,s2,n-1,m-1);
    return dp[n][m] = max(LHS(s1,s2,n-1,m),LHS(s1,s2,n,m-1));
}

int main()
{
    string str1,str2;
    str1 = "abcdgh";
    str2 = "abedfhr";
    memset(dp,-1,sizeof dp);
    cout << LHS(str1,str2,str1.length(),str2.length()) << endl;
    return 0;
}

//Bottom Up
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1,str2;
    str1 = "acbcf";
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
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[n][m] << endl;
    return 0;
}