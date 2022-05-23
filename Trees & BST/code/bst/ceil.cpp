int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ceil = -1;
    while(node){
        if(node->data == x)
            return x;
        if(node->data < x)
            node = node->right;
        else
            ceil = node->data, node = node->left;
    }
    return ceil;
}