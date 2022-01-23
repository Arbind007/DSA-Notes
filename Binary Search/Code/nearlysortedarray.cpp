#include <bits/stdc++.h>
using namespace std; 

int binarysearch(vector <int> &v,int start,int end,int key){
    int mid;
    while(start <= end){
        mid = start + (end - start)/2;
        if(v[mid] == key)
            return mid;
        else if(mid - 1 >= 0 && v[mid - 1] == key)
            return mid - 1;
        else if(mid + 1 <= v.size() - 1 && v[mid + 1] == key)
            return mid + 1;
        else if(v[mid] > key)
            end = mid - 2;
        else if(v[mid] < key)
            start = mid + 2;
    }
    return -1;
}


int main(){
    int n,key;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cin >> key;
    cout << binarysearch(v,0,n,key);
    return 0;
}

// 5
// 5 10 30 20 40