#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue <pair<int,int>> p;
        for(int i=0;i<arr.size();i++){
            p.push({abs(arr[i] - x),arr[i]});
            if(p.size() > k){
                p.pop();
            }
        }
        arr.clear();
        while(!p.empty()){
            arr.push_back(p.top().second);
            p.pop();
        }
        sort(arr.begin(),arr.end());
        return arr;
    }
};