#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=0;
    cin >> n;
    vector <int> v(n),mxl(n),mxr(n),water(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    mxl[0] = v[0];
    for(int i=1;i<n;i++){
        mxl[i] = max(mxl[i-1],v[i]);
    }
    mxr[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--)
        mxr[i] = max(mxr[i+1],v[i]);
    for(int i=0;i<n;i++)
        water[i] = min(mxl[i],mxr[i]) - v[i];
    for(int i=0;i<n;i++)
        ans += water[i];
    cout << ans << endl;
    return 0;
}

// 6
// 3 0 0 2 0 4