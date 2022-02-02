#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int,vector<int>,greater<int>> p;
        int i;
        for(i=0;i<k;i++){
            p.push(nums[i]);
        }
        while(i < nums.size()){
            p.push(nums[i++]);
            cout <<  p.top() << " "; 
            p.pop();
        }
        while(!p.empty()){
            cout << p.top() << " "; 
            p.pop();
        }
        return 0;
    }
};