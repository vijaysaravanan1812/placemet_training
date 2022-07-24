class Solution {
    
    void mark_parent(TreeNode * root , unordered_map<TreeNode * , TreeNode *> &parent_track,
                    TreeNode * target){
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode * current_node = q.front();
            q.pop();
            if(current_node->left){
                parent_track[current_node->left] = current_node;
                q.push(current_node->left);
            }
            if(current_node->right){

                parent_track[current_node->right] = current_node;
                q.push(current_node->right);
            }
        }
        
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
       
        unordered_map<TreeNode * , TreeNode *> parent_track;
        unordered_map<TreeNode * , bool > visited;
        
        mark_parent(root , parent_track , target);
        
        
        
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int current_level = 0;
            
        while(!q.empty())
        {
            int size = q.size();
        
            if(current_level++ == k){
                            
                break;                
            }
          
            for(int i = 0 ; i < size; i++)
            {
                TreeNode * current_node = q.front();
                q.pop();
             
                if(current_node->left && !visited[current_node->left])
                {
                    q.push(current_node -> left);
                    visited[current_node->left] = true;
                }
                if(current_node->right && !visited[current_node->right])
                {
                    q.push(current_node->right);
                    visited[current_node->right] = true;
                }
                if(parent_track[current_node] && !visited[parent_track[current_node]])
                {
                    q.push(parent_track[current_node]);
                    visited[parent_track[current_node]] = true;
                }                
            }

            
        }
                
        vector<int> result;
        while(!q.empty())
        {
            TreeNode * current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
        
        
    }
};