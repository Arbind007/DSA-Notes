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

int binarysearchasc(vector <int> &v,int start,int end,int key){
    int mid;
    while(start <= end){
        mid = start + (end - start)/2;
        if(v[mid] == key){
            return mid;
        }
        else if(v[mid] > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
}

int binarysearchdec(vector <int> &v,int start,int end,int key){
    int mid;
    while(start <= end){
        mid = start + (end - start)/2;
        if(v[mid] == key){
            return mid;
        }
        else if(v[mid] > key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
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
    int key;
    cin >> key;
    int high = n-1;
    int point = peak(v,low,high);
    int h1 = binarysearchasc(v,0,point-1,key);
    // cout << h1 << endl;
    int h2 = binarysearchdec(v,point,n-1,key);
    // cout << h2 << endl;
    if(h1 == -1 && h2 == -1){
        cout << "-1"  << endl;
        return 0;
    }
    if(h1 == -1){
        cout << h2 << endl;
        return 0; 
    }
    cout << h1 << endl;
    return 0;
}

// 6
// 1 3 8 12 4 2 