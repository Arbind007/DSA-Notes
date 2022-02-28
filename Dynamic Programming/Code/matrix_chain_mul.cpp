#include <bits/stdc++.h>
using namespace std;

int solve(int arr[],int i,int j){
    if(i >= j)
        return 0;
    int mn = INT_MAX;
    for(int k=i;k<j;k++){
        int tempans = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];
        if (tempans < mn)
            mn = tempans;
    }
    return mn;
}

int main(){
    int arr[] = {40,20,30,10,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << solve(arr,1,n-1) << endl;
    return 0;
}

//memorization

#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int solve(int arr[],int i,int j){
    if(i >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;
    for(int k=i;k<j;k++){
        int tempans = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];
        mn = min(tempans,mn);
    }
    return dp[i][j] = mn;
}

int main(){
    int arr[] = {40,20,30,10,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    memset(dp,-1,sizeof(dp));
    cout << solve(arr,1,n-1) << endl;
    return 0;
}