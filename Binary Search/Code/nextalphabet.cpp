#include <bits/stdc++.h>
using namespace std;

char nextletter(vector <char> &v,char key){
    int start = 0, end = v.size()-1,mid;
    char ans;
    while(start <= end){
        mid = start + (end - start)/2;
        if(v[mid] > key){
            ans = v[mid];
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector <char> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    char key;
    cin >> key;
    cout << nextletter(v,key) << endl;
    return 0;
}