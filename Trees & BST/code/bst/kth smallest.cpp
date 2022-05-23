/* method 1 */

class Solution {
private:
    int count = 0,ans;
    void inOrder(TreeNode* root,int K){
        if(root == NULL) 
            return;        
        inOrder(root->left,K);
        count++;
        if(count == K)
            ans = root->val;
        inOrder(root->right,K);
    }
public:
    int kthSmallest(TreeNode *root, int K){
        inOrder(root,K);
        return ans;
    }  
};

/* method 2 */