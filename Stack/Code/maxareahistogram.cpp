#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> v(n);
    vector <int> right,left,ans(n);
    stack <pair<int,int>> s;
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    for(int i=0;i<n;i++){
        if(s.empty())
            left.push_back(-1);
        else if(!s.empty() && s.top().first < v[i])
            left.push_back(s.top().second);
        else if(!s.empty() && s.top().first >= v[i]){
            while(!s.empty() && s.top().first >= v[i]){
                s.pop();
            }
            if(s.empty()){
                left.push_back(-1);
            }
            else{
                left.push_back(s.top().second);
            }
        }
        s.push({v[i],i});
    }
    
    s = stack <pair<int,int>>();
    for(int i=n-1;i>=0;i--){
      if(s.empty()){
          right.push_back(n);
      }
      else if(!s.empty() && s.top().first < v[i]){
          right.push_back(s.top().second);
      }
      else if(!s.empty() && s.top().first >= v[i]){
        while(!s.empty() && s.top().first >= v[i]){
          s.pop();
        }
        if(s.empty()){
            right.push_back(n);
        }
        else{
            right.push_back(s.top().second);
        }
      }
      s.push({v[i],i});
    }
    reverse(right.begin(), right.end());
    for(int i=0;i<n;i++){
         ans[i] = right[i] - left[i] - 1;
         ans[i] = v[i] * ans[i];
    }
    int maxno = 0;
    for(int i=0;i<n;i++){
      maxno = max(maxno,ans[i]);
    }
    cout << maxno << endl;
    return 0;
}

// 7
// 6 2 5 4 5 1 6