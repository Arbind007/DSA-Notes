#include <bits/stdc++.h>
using namespace std; 

int norotated(vector <int> &arr,int n){
    int start = 0,end = n - 1,mid,prev,next;
    //edge condition
    if(n == 0 || n == 1 || arr[0] <= arr[n]){
        return 0;
    }
    
    while(start <= end){
        mid = start + (end - start)/2;
        prev = (mid + n - 1) % n;
        next = (mid + 1) % n; 
        if(arr[prev] >= arr[mid] && arr[next] >= arr[mid])
            return mid;
        else if(arr[mid] >= arr[0])
            start = mid + 1;
        else if(arr[mid] <= arr[n-1])
            end = mid - 1;
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cout << norotated(v,n) << endl;
    return 0;
}

// 8
// 8 11 12 15 18 2 5 6