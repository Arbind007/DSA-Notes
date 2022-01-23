#include <bits/stdc++.h>
using namespace std; 

int binarysearch(vector <int> &v,int start,int end,int key){
    int mid;
    while(start <= end){
        mid = start + (end - start)/2;
        if(v[mid] == key){
            return mid;
        }
        else if(v[mid] > key){
            end = mid - 1;
        }
        else if(v[mid] < key){
            start = mid + 1;
        }
    }
    return -1;
}


int main(){
    int n,m,key;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cin >> key;
    int low=0,high=1;
    while(key>v[high]){
        low = high;
        high = high * 2;
    }
    cout << binarysearch(v,low,high,key);
    return 0;
}

// 9
// 1 2 3 4 8 10 10 12 19
// 8