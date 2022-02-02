#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater <pair<int,int>>> q;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(auto i=mp.begin();i!=mp.end();i++){
            q.push({i->second,i->first});
            if(q.size() > k)
                q.pop();
        }
        nums.clear();
        while(!q.empty()){
            nums.push_back(q.top().second);
            q.pop();
        }
        return nums;
    }
};

