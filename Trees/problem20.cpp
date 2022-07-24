class Solution {
     vector<vector<int>> levelOrder(TreeNode* root)
     {
        if (root == NULL)
            return {};
        
        queue <TreeNode *> Q;
        Q.push(root);
        vector <vector <int>> result;
        
        while(!Q.empty()){
            int count = Q.size();
            vector <int> level_order;
            for(int i = 0 ; i < count ; i++)
            {
               
                TreeNode * node = Q.front();
                Q.pop();
                if(node->left) 
                    Q.push(node->left);
                if(node->right)
                    Q.push(node->right);
                level_order.push_back(node->val);
            }
            result.push_back(level_order);
        }
        return result;
     }

    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> result = levelOrder(root);
        vector<int> res;
        
        for(auto x : result){
            res.push_back(x[x.size() - 1]);
        }
        
        return res;
    }
};