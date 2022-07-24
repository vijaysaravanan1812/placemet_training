class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->left || root->right)
            return root;
        if(root->val == 0){
            delete root;
            return NULL;
        }
        return root;
    }
};