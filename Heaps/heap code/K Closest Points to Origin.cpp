#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair<int,pair<int,int>>> p;
        for(int i=0;i<points.size();i++){
            p.push({points[i][0] * points[i][0]+points[i][1] * points[i][1],{points[i][0],points[i][1]}});
            if(p.size() > k)
                p.pop();
        }
        points.clear();
        vector <int> v;
        while(!p.empty()){
            v.push_back(p.top().second.first);
            v.push_back(p.top().second.second);
            points.push_back(v);
            v.clear();
            p.pop();
        }
        return points;
    }
};