
class Solution
{
    public:
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        if(root == node_to_find){
            return {-1};
        }
        
        queue<Node *> q;
        q.push(root);

        bool found = false;
        int size;
        
        while(!q.empty() && !found)
        {
            size = q.size();
            while(size)
            {
                Node * parent = q.front();
                q.pop();
                if(parent->left == node_to_find || 
                   parent->right == node_to_find){
                       found = true;
                   }
                else{
                    if(parent->left){
                        //cout<<parent->left->data<<" ";
                        q.push(parent->left);
                    }
                    if(parent->right){
                      //  cout<<parent->right->data<<" ";
                        q.push(parent->right);
                    }
                  }
                size--;
            }
            
        }
       // cout<<q.front()->data<<" "<<found<<" ";
        if(found){
            if(size == 0)
                return {-1};
            
            vector<int> result;
            while(!q.empty()){
                Node * current = q.front();
              //  cout<<current->data<<" ";
                q.pop();
                result.push_back(current->data);
            }
        
            return result;
        }
        else{
            return {-1};
        }
    }
};