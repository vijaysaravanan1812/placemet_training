
class Solution {
    
    vector<vector<Node *>> levelOrder(Node* root)
    {
        queue<Node *> q;
        q.push(root);
        int size = q.size();
        vector<vector<Node *>> result;
        
        while(!q.empty())
        {
            size = q.size();
            vector<Node *> ans;
            for(int i = 0 ; i < size; i++)
            {
                Node * current = q.front();
                q.pop();
                
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
                ans.push_back(current);
            }
            result.push_back(ans);
        }
        for(auto m1 : result)
        {
            for(auto m2 : m1 ){
             cout<<m2<<" ";
            } 
            cout<<"\n";

        }
        
        return result;
    }
    
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        
        vector<vector<Node *>> result = levelOrder(root);
        
        
        for(auto m1 : result)
        {
            Node * prev = NULL;
            for(int i = 0 ; i < m1.size() ; i++){
                if(prev != NULL)
                    prev->next = m1[i];
                prev = m1[i];
            }
            
          
        }
        
        return root;
        
    }
};