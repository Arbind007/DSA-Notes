#include <bits/stdc++.h>
using namespace std;

int subset(vector <int> v,int n,int sum){
    int arr[n+1][sum+1];
    for(int i=0;i<=n;i++)
        arr[i][0] = 1;
    for(int i=1;i<=sum;i++)
        arr[0][i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j >= v[i-1])
                arr[i][j] = arr[i-1][j] + arr[i-1][j-v[i-1]];
            else
                arr[i][j] = arr[i-1][j];
        }
    }
    return arr[n][sum];
}

int main(){
    vector <int> v = {2,3,5,6,8,10};
    int n = v.size();
    int sum = 10;
    cout << subset(v,n,sum) << endl;
    return 0;
}
