// what i thought
/*
#include <bits/stdc++.h>
using namespace std;

bool equalSum(vector <int> v,int a,int b,int n){
    if(n < 0){
        if(a == b)
            return true;
        else
            return false;
    }
    return equalSum(v,a+v[n],b,n-1) || equalSum(v,a,b+v[n],n-1);
}

int main(){
    vector <int> v = {1,5,11,5};
    int n = v.size()-1;
    int a=0,b=0;
    cout << equalSum(v,a,b,n);
    return 0;
}
*/

// solution
#include <bits/stdc++.h>
using namespace std;

bool subset(vector <int> v,int n,int sum){
    bool arr[n+1][sum+1];
    for(int i=0;i<=n;i++)
        arr[i][0] = true;
    for(int i=1;i<=sum;i++)
        arr[0][i] = false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j >= v[i-1])
                arr[i][j] = arr[i-1][j] || arr[i-1][j-v[i-1]];
            else
                arr[i][j] = arr[i-1][j];
        }
    }
    return arr[n][sum];
}

int main(){
    vector <int> v = {1,5,11,5};
    int n = v.size();
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += v[i];
    }
    if(sum % 2)
        cout << 0 << endl;
    else
        cout << subset(v,n,sum/2) << endl;
    return 0;
}
