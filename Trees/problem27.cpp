class Solution {
    
    TreeNode * getNode(TreeNode * root , int val){    
        if(root == NULL)
            return NULL;
        if(root -> val == val)
            return root;
        else if(root -> val < val)
            return getNode(root->right , val);
        return getNode(root->left , val);
        
    }
    
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return getNode(root , val);
    }
};