#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
};

struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int solve(Node* root,int& res){
    if(root == NULL)
        return 0;
    int l = solve(root->left,res);
    int r = solve(root->right,res);
    int temp = max(l,r) + 1;
    int ans = max(temp,l+r+1);
    res = max(res,ans);
    return temp;
}

int diameter(Node* root){
    int res = INT_MIN;
    solve(root,res);
    return res;
}

int main(){
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << diameter(root) << endl;
}