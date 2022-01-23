#include <bits/stdc++.h>
using namespace std; 

int binarysearch(vector <int> &v,int start,int end,int key){
    int mid;
    while(start <= end){
        mid = start + (end - start)/2;
        if(v[mid] == key)
            return mid;
        else if(v[mid] > key)
            end = mid - 1;
        else if(v[mid] < key)
            start = mid + 1;
    }
    return -1;
}

int norotated(vector <int> &arr,int n){
    int i = 0,j = n-1,mid,prev,next;
    while(i <= j){
        mid = i + (j - i)/2;
        prev = (mid + n - 1) % n;
        next = (mid + 1 ) % n;
        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next])
            return mid;
        else if(arr[mid] >= arr[0])
            i = mid + 1;
        else if(arr[mid] <= arr[n])
            j = mid - 1;
    }
    return 0;
}

int main(){
    int n,key;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cin >> key;
    int m = norotated(v,n);
    int a = binarysearch(v,0,m-1,key);
    int b = binarysearch(v,m,v.size()-1,key);
    if(a == -1 && b == -1){
        cout << -1 << endl;
        return 0;
    }
    if(a == -1){
        cout << b << endl;
        return 0;
    }
    cout << a << endl;
    return 0;
}

// 8
// 8 11 12 15 18 2 5 6