#include <bits/stdc++.h>
using namespace std;

int search(vector <int> &v,int m){
    int start = 0,end = v.size()-1,mid;
    while(start <= end){
        mid = start + (end - start)/2;
        if(v[mid] == m){
            return mid;
        }
        else if(v[mid] > m){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cin >> m;
    cout << search(v,m) << endl;
    return 0;
}

// 10
// 1 2 3 4 5 6 7 8 9 10