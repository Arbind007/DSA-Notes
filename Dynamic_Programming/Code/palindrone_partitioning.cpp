#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s ,int i,int j){
    if(i >= j)
        return true;
    while(i <= j){
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve(string s,int i,int j){
    if(i >= j)
        return 0;
    if(isPalindrome(s,i,j))
        return 0;
    int mn = INT_MAX;
    for(int k=i;k<j;k++){
        int tempans = solve(s,i,k) + solve(s,k+1,j) + 1;
        mn = min(tempans,mn);
    }
    return mn;
}

int main(){
    string s = "nitik";
    int n = s.size();
    cout << solve(s,0,n-1) << endl;
    return 0;
}

//memorization
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];

bool isPalindrome(string s ,int i,int j){
    if(i >= j)
        return true;
    while(i <= j){
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve(string s,int i,int j){
    if(i >= j)
        return 0;
    if(isPalindrome(s,i,j))
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;
    for(int k=i;k<j;k++){
        int tempans = solve(s,i,k) + solve(s,k+1,j) + 1;
        mn = min(tempans,mn);
    }
    return dp[i][j] = mn;
}

int main(){
    string s = "nitik";
    int n = s.size();
    memset(dp,-1,sizeof dp);
    cout << solve(s,0,n-1) << endl;
    return 0;
} 

//optimized
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];

bool isPalindrome(string s ,int i,int j){
    if(i >= j)
        return true;
    while(i <= j){
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve(string s,int i,int j){
    if(i >= j)
        return 0;
    if(isPalindrome(s,i,j))
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;
    int left,right;
    for(int k=i;k<j;k++){
        if(dp[i][k] != -1)
            left = dp[i][k];
        else{
            left = solve(s,i,k);
            dp[i][k] = left;
        }
        if(dp[k+1][j] != -1)
            right = dp[k+1][j];
        else{
            right = solve(s,k+1,j);
            dp[k+1][j] = right;
        }
        int tempans = left + right + 1;
        mn = min(tempans,mn);
    }
    return dp[i][j] = mn;
}

int main(){
    string s = "nitik";
    int n = s.size();
    memset(dp,-1,sizeof dp);
    cout << solve(s,0,n-1) << endl;
    return 0;
}