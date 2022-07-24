class Solution {
    bool post_order(TreeNode * p , TreeNode * q)
    {
        
        if(!p && !q )
            return true;
        if(!p || !q)
            return false;
        if(p->val != q ->val )
            return false;
            
        return (post_order(p->left , q->left) && post_order(p->right , q->right));
    }
    
    
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return post_order(p ,q);
    }
};