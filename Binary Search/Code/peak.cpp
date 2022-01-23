#include <bits/stdc++.h>
using namespace std; 

int peak(vector <int> &v,int low,int high){
    int mid;
    while(low <= high){
    int mid = low + (high-low)/2;
    if(mid > 0 && mid < v.size()-1){
        if(v[mid] > v[mid+1] && v[mid] > v[mid - 1]){
            return mid;
        }
        else if(v[mid - 1] > v[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    else if(mid == 0){
        if(v[0] > v[1]){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if(mid == v.size() - 1){
        if(v[v.size() - 1] > v[v.size() -1]){
            return v.size() - 1;
        }
        else{
            return v.size() - 2;
        }
    }
    }
    return -1;
}


int main(){
    int n,low=0;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int high = n-1;
    cout << peak(v,low,high);
    return 0;
}

// 7
// 10 20 15 2 23 90 67