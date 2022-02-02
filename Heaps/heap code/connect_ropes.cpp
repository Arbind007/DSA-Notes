#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        priority_queue <int,vector<int>,greater <int>> q;
        for(int i=0;i<stones.size();i++){
            q.push(stones[i]);
        }
        int temp = 0,ans=0;
        while(q.size() != 1){
            for(int i=0;i<2;i++){
                temp += q.top();
                q.pop();
            }
            q.push(temp);
            ans += temp;
            temp = 0;
        }
        return ans;
    }
};

