class Solution {
public:
    bool isValidBST(TreeNode * root , int minval , int maxval){
        if(root == NULL)
            return true;
        if(root->val >= maxval || root->val <= minval)
            return false;
        return ( 
            isValidBST(root->left , minval , root->val)
            && isValidBST(root->right ,root->val ,  maxval ) 
               );
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        if(!root ->left && !root ->right)
            return true;
        return isValidBST(root , -9147483647, 9147483647);
    }
};