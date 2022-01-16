#include <bits/stdc++.h>
using namespace std;

int MAH(vector <int> v,int n){
    vector <int> right,left,ans(n);
    stack <pair<int,int>> s;
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
    return maxno;
}

int main(){
    int n,m;
    cin >> m >> n;
    vector <vector<int>> v(n, vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    
    cout << endl;
    
    vector <int> temp;
    for(int j=0;j<m;j++){
        temp.push_back(v[0][j]);
    }
    int mx = MAH(temp,m);    
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == 0)
                temp[j] = 0;
            else
                temp[j] += v[i][j];
        }
        mx = max(mx,MAH(temp,m));
    }
    
    cout << mx;
    return 0;
}

// 4 4 
// 0 1 1 0
// 1 1 1 1
// 1 1 1 1
// 1 1 0 0