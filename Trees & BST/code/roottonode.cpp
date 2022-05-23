#include <bits/stdc++.h>
using namespace std;

bool helper(TreeNode* A,vector <int> &ans,int B){
    if(!A)
        return false;

    ans.push_back(A->val);
    if(A->val == B){
        return true;
    }
    if(helper(A->left,ans,B) || helper(A->right,ans,B))
        return true;
    ans.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector <int> ans;
    if(!A)
        return ans;
    helper(A,ans,B);
    return ans;
}