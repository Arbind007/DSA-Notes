int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int floor = 0;
    while(root){
        if(root->val == X)
            return X;
        if(X > root->val){
            floor = root->val;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return floor;
}