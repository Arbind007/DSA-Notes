#include <bits/stdc++.h>
using namespace std;

int searchfirst(vector <int> &v,int m){
    int start = 0,end = v.size()-1,mid;
    int ans = -1;
    while(start <= end){
        mid = start + ( end - start ) / 2;
        if(v[mid] == m)
            ans = mid,end = mid - 1;
        else if (v[mid] > m)
            end = mid - 1;
        else 
            start = mid + 1;
    }
    if (ans == -1)
        return -1;
    return ans;
}

int searchlast(vector <int> v,int m){
    int start = 0,end = v.size() - 1,mid,ans = -1;
    while(start <= end){
        mid = start + ( end - start ) / 2;
        if(v[mid] == m)
            ans = mid,start = mid + 1;
        else if(v[mid] > m)
            end = mid - 1;
        else
            start = mid + 1;
    }
    if (ans == -1)
        return -1;
    return ans;
}

int main(){
    int n,m;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cin >> m;
    cout << searchfirst(v,m) << " " << searchlast(v,m) << endl;
    return 0;
}

// 7
// 2 4 10 10 10 18 20
// 10