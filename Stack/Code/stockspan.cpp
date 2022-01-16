#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> v(n);
    vector <int> ans;
    stack <pair<int,int>> s;
    for(int i=0;i<n;i++)
        cin >> v[i];
    for(int i=0;i<n;i++){
        if(s.empty())
            ans.push_back(-1); 
        else if(s.size() > 0 && s.top().first > v[i])
            ans.push_back(s.top().second); 
        else if(s.size() > 0 && s.top().first <= v[i]){
            while(s.size() > 0 && s.top().first <= v[i])
                s.pop();
            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top().second);
        }
        s.push({v[i],i});
    }
    for(int i=0;i<n;i++){
        cout << i - ans[i] << " ";
    }
    return 0;
}

// 7
// 100 80 60 70 60 75 85