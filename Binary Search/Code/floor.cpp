#include <bits/stdc++.h>
using namespace std; 

int floorele(vector <int> &v,int start,int end,int key){
    int mid,ans(-1);
    while(start <= end){
        mid = start + (end - start)/2;
        if(v[mid] == key){
            return v[mid];
        }
        else if(v[mid] > key){
            end = mid - 1;
        }
        else if(v[mid] < key){
            ans = v[mid];
            start = mid + 1;
        }
    }
    return ans;
}


int main(){
    int n,key;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cin >> key;
    cout << floorele(v,0,n,key);
    return 0;
}

// 9
// 1 2 3 4 8 10 10 12 19
// 5