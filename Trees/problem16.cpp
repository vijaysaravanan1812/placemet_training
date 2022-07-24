
class Solution {
public:
    Node* connect(Node* root) {
        Node * cur;
        Node * nxt;
        

        if(root == NULL || root ->left == NULL)
            nxt = NULL;
        else
        {
            cur = root;
            nxt = root->left ;
        }

        
        while(cur && nxt)
        {
            (cur->left)->next = cur->right;
            if(cur -> next){
                cur->right->next = cur->next->left;
            }
            cur = cur -> next;
            if(!cur)
            {
                cur = nxt;
                nxt = cur->left;
            }
        }
        
        return root;
    }
};
