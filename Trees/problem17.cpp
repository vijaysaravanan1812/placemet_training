class Solution {
    int getIndex(vector<int> v, int K , int l , int r)
    {
        for(int i = l ; i <= r ; i++){
            if(v[i] == K)
                return i;
        }
        return -1;
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder , int l , int r)
    {
        if(l > r )
            return NULL;
        int n = postorder.size();
        TreeNode * cur = new TreeNode(postorder[n - 1]);
        postorder.resize(n - 1);
        
        int index;
        for(int i = l ; i <= r ; i++ )
            if(cur->val == inorder[i]){
                index = i;
                break;
            }
        
        cout<<cur->val<<" ";
        cur -> right = build(inorder , postorder , index + 1 , r);
        cur -> left = build(inorder, postorder , l , index - 1);
        
        
        return cur;
        
    }
    
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    
        int n = inorder.size();

        for(int i = 0 ; i < n ;i++)
            cout<<inorder[i]<<" ";
        cout<<"\n";
        return build(inorder , postorder , 0 , n - 1);
        
    }
};