#include <bits/stdc++.h>
using namespace std;

int searchdec(vector <int> &v,int m){
    int start = 0,end = v.size()-1,mid;
    while(start <= end){
        mid = start + ( end - start ) / 2;
        if(v[mid] == m)
            return mid;
        else if (v[mid] > m)
            start = mid + 1;
        else 
            end = mid - 1;
    }
    return -1;
}

int searchasc(vector <int> v,int m){
    int start = 0,end = v.size() - 1,mid;
    while(start <= end){
        mid = start + ( end - start ) / 2;
        if(v[mid] == m)
            return mid;
        else if(v[mid] > m)
            end = mid - 1;
        else
            start = mid + 1;
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
    if(n == 0){
        cout << -1 << endl;
    }
    else if(n == 1){
        if(v[0] == m)
            cout << 0 << endl;
        else
            cout << - 1 << endl;
    }
    else{
        if(v[0] > v[1]){
            cout << searchdec(v,m) << endl;
        }
        else if(v[0] < v[1]){
            cout << searchasc(v,m) << endl;
        }
    }
    return 0;
}

// 10
// 20 17 15 14 13 12 10 9 8 4
// 4
// 1 2 3 5