#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int,vector<int>,greater<int>> p;
        for(int i=0;i<nums.size();i++){
            p.push(nums[i]);
            if(p.size() > k)
                p.pop();
        }
        while(!p.empty()){
          cout << p.top() << " ";
          p.pop();
        }
    }
};