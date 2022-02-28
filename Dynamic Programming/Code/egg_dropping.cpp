// recursion
#include <bits/stdc++.h>
using namespace std;

int solve(int e,int f){
    if(f == 0 || f == 1)
        return f;
    if(e == 0)
        return f;
    int mn = INT_MAX;
    for(int k=1;k<=f;k++){
        int temp = 1 + max(solve(e-1,k-1),solve(e,f-k));
        mn = min(temp,mn);
    }
    return mn;
}

int main(){
    int e,f;
    // cin >> e >> f;
    e = 2,f = 10;
    cout << solve(e,f) << endl;
    return 0;
}

// memorization
#include <bits/stdc++.h>
using namespace std;
static int dp[11][51];

int solve(int e,int f){
    if(f == 0 || f == 1)
        return f;
    if(e == 0)
        return f;
    if(dp[e][f] != -1)
        return dp[e][f];
    int mn = INT_MAX;
    for(int k=1;k<=f;k++){
        int temp = 1 + max(solve(e-1,k-1),solve(e,f-k));
        mn = min(temp,mn);
    }
    return dp[e][f] = mn;
}

int main(){
    int e,f;
    // cin >> e >> f;
    memset(dp,-1,sizeof dp);
    e = 2,f = 10;
    cout << solve(e,f) << endl;
    return 0;
}

// optimization (checking for subproblems of dp)
#include <bits/stdc++.h>
using namespace std;
static int dp[11][51];

int solve(int e,int f){
    if(f == 0 || f == 1)
        return f;
    if(e == 0)
        return f;
    if(dp[e][f] != -1)
        return dp[e][f];
    int mn = INT_MAX;
    for(int k=1;k<=f;k++){
        int l,r;
        if(dp[e-1][k-1] != -1)
            l = dp[e-1][k-1];
        else{
            l = solve(e-1,k-1);
            dp[e-1][k-1] = l;
        }
        if(dp[e][f-k] != -1)
            r = dp[e][f-k];
        else{
            r = solve(e,f-k);
            dp[e][f-k] = r;
        }
        int temp = 1 + max(l,r);
        mn = min(temp,mn);
    }
    return dp[e][f] = mn;
}

int main(){
    int e,f;
    // cin >> e >> f;
    memset(dp,-1,sizeof dp);
    e = 2,f = 10;
    cout << solve(e,f) << endl;
    return 0;
}