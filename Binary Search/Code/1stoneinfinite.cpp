#include <bits/stdc++.h>
using namespace std; 

int binarysearch(vector <int> &v,int start,int end,int key){
    int mid,ans=-1 ;
    while(start <= end){
        mid = start + (end - start)/2;
        if(v[mid] == key){
            ans = mid;
            end = mid - 1;
        }
        else if(v[mid] > key){
            end = mid - 1;
        }
        else if(v[mid] < key){
            start = mid + 1;
        }
    }
    return ans;
}


int main(){
    int n,m,key=1;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int low=0,high=1;
    while(key>v[high]){
        low = high;
        high = high * 2;
    }
    cout << binarysearch(v,low,high,key);
    return 0;
}

// 9
// 0 0 0 0 0 1 1 1 1