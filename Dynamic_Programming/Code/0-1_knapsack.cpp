//recursive
#include <bits/stdc++.h>
using namespace std;

int knashap(vector <int> wt,vector <int> val,int n,int w){
    if(w == 0 || n == 0)
        return 0;
    if(wt[n-1] <= w)
        return max(knashap(wt,val,n-1,w), val[n-1] + knashap(wt,val,n-1,w-wt[n-1]));
    else
        return knashap(wt,val,n-1,w);
}

int main(){
    vector <int> val = {60, 100, 120};
    vector <int> wt = {10, 20, 30};
    int w = 50,n = wt.size();
    cout << knashap(wt,val,n,w);
    return 0;
}

//memorization
#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int knashap(vector <int> wt,vector <int> val,int n,int w){
    if(w == 0 || n == 0)
        return 0;
    if(dp[n][w] != -1)
        return dp[n][w];
    if(wt[n-1] <= w)
        return dp[n][w] = max(knashap(wt,val,n-1,w), val[n-1] + knashap(wt,val,n-1,w-wt[n-1]));
    else
        return dp[n][w] = knashap(wt,val,n-1,w);
}

int main(){
    vector <int> val = {60, 100, 120};
    vector <int> wt = {10, 20, 30};
    int w = 50,n = wt.size();
    memset(dp,-1,sizeof dp);
    cout << knashap(wt,val,n,w);
    return 0;
}

/*top down*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> val = {60, 100, 120};
    vector <int> wt = {10, 20, 30};
    int w = 50,n = wt.size();
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j]; 
        }
    }
    cout << dp[n][w];
    return 0;
}