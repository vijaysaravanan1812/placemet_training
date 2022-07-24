class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
	//edge cases
        if(!head){
            return NULL;
        }
        if(!head->next){
            return new TreeNode(head->val);
        }
        // if(head->next->next==NULL){
        //      TreeNode* root=new TreeNode(head->val);
        //     root->right=new TreeNode(head->next->val);
        //     return root;
        // }
		//main code
        // finding mid element
        ListNode *fast,*slow,*mid;
        fast=head->next,slow=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        mid = slow->next;
        slow->next=NULL;
        
        // creating node for mid element 
        TreeNode* root=new TreeNode(mid->val);
        
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(mid->next);
        return root;
    }
};