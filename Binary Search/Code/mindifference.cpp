#include <bits/stdc++.h>
using namespace std;

int mindiff(vector <int> &v,char key){
    int start = 0, end = v.size()-1,mid;
    char ans;
    while(start <= end){
        mid = start + (end - start)/2;
        if(v[mid] == key){
            return 0;
        }
        if(v[mid] > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return min(abs(key - v[start]),abs(v[end] - key));
}

int main(){
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int key;
    cin >> key;
    cout << mindiff(v,key) << endl;
    return 0;
}

// 3
// 4 6 10
// 7