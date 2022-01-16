#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> v(n);
    stack <int> s;
    vector <int> ans;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<n;i++){
        if(s.empty())
            ans.push_back(-1);
        else if(s.size() > 0 && s.top() < v[i])
            ans.push_back(s.top());
        else if(s.size() > 0 && s.top() >= v[i]){
            while(!s.empty() && s.top() >= v[i])
                s.pop();
            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(v[i]);
    }
    for(int i=0;i<n;i++)
        cout << ans[i] << " ";
    return 0;
}