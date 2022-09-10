

class Solution {
    
    pair <int , int > diameterOfBinaryTree_util(TreeNode * root){
        if(root == NULL)
            return make_pair(0, 0);
        
        pair<int , int > left = diameterOfBinaryTree_util(root->left);
        pair<int , int > right = diameterOfBinaryTree_util(root -> right);
        
        int internal_path = max(left.second , right.second);
        if(left.first + right.first + 1 > internal_path){
            internal_path = left.first  + right.first + 1; 
        }
        
         return make_pair(max(left.first , right.first) + 1 , internal_path);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        pair<int , int> result = diameterOfBinaryTree_util(root);
        return max(result.first , result.second) - 1;
    }
};