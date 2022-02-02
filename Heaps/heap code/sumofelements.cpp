#include <bits/stdc++.h>
using namespace std;

int minkthsum(vector <int> &v,int k1,int k2){
    int n = v.size();
    if(n < k1 || n < k2)
        return -1;
    if(k2 > k1)
        swap(k1,k2);
    priority_queue <int> p;
    for(int i=0;i<n;i++){
        p.push(v[i]);
        if(n < k1)
            p.pop();
    }
    int first = p.top();
    for(int i=0;i<k1-k2;i++)
        p.pop();
    return first+p.top();
}

int main(){
    vector <int> v = {1,3,12,5,15,11};
    int k1=3,k2=6;
    cout << minkthsum(v,k1,k2) << endl;
    return 0;
}