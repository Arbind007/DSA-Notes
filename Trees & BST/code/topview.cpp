#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};
 

TreeNode* newNode(int key)
{
    TreeNode* root = new TreeNode();
    root->left = root->right = NULL;
    root->val = key;
}

void getTopView(TreeNode *root) {
    // Write your code here.
    vector <int> ans;
    if(!root){
        cout << 0 << endl;
        return;
    }
    map <int,int> mp;
    queue <pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        TreeNode* tp = temp.first; 
        int x = temp.second;
        if(mp.find(x) == mp.end()){
            mp[x] = tp->val;
        }
        if(tp->left){
            q.push({tp->left,x-1});
        }
        if(tp->right){
            q.push({tp->right,x+1});
        }
    }
    
    for(auto &it:mp){
        cout << it.second << " ";   
    }
}

int main(){
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary "
            "Tree\n";
    getTopView(root);
    return 0;
}