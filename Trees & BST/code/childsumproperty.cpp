void changeTree(BinaryTreeNode < int > * root) {
        if(!root)
            return;
        int val=0;
        if(root->left)
            val += root->left->data;
        if(root->right)
            val += root->right->data;
        if(root->data <= val){
            root->data = val;
        }
        else{
            if(root->left)
                root->left->data = root->data;
            else if(root->right)
                root->right->data = root->data;
        }
        changeTree(root->left);
        changeTree(root->right);
        
        val = 0;
        if(root->left)
            val += root->left->data;
        if(root->right)
            val += root->right->data;
        if(root->left || root->right)
            root->data = val;
}  