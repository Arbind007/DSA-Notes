#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

bool isleaf(Node* root){
    if(!root->left && !root->right){
        return true;
    }
    return false;
}
 
void addleftBoundary(Node* root,vector <int> &ans){
    Node* temp = root->left;
    while(temp){
        if(!isleaf(temp))
            ans.push_back(temp->data);
        if(temp->left)
            temp = temp->left;
        else
            temp = temp->right;
    }
}

void addrightBoundary(Node* root,vector <int> &ans){
    Node* temp = root->right;
    vector <int> tmp;
    while(temp){
        if(!isleaf(temp))
            tmp.push_back(temp->data);
        if(temp->right)
            temp = temp->right;
        else
            temp = temp->left;
    }
    for(int i = tmp.size() - 1; i >= 0;i--){
        ans.push_back(tmp[i]);
    }
}

void addLeaf(Node* root,vector <int> &ans){
    if(isleaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left)
        addLeaf(root->left,ans);
    if(root->right)
        addLeaf(root->right,ans);
}


void performBoundaryTraversal(Node* root)
{
    vector <int> ans;
    if(!root){
        cout << 0 << endl;
        return ;
    }
    if(!isleaf(root))
        ans.push_back(root->data);
    addleftBoundary(root,ans);
    addLeaf(root,ans);
    addrightBoundary(root,ans);
    for(auto &it:ans){
        cout << it << " ";
    }
    cout << endl;
}
 
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->right = new Node(10);
    root->right->right->left = new Node(11);
    root->left->left->right->left = new Node(12);
    root->left->left->right->right = new Node(13);
    root->right->right->left->left = new Node(14);
    performBoundaryTraversal(root);
    return 0;
}

// 1 2 4 8 12 13 10 6 14 11 7 3