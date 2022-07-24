class Solution
{
    int minDiff(Node * root , int k , int min_diff , int min_diff_key){
        if(root == NULL)
            return min_diff;
        
        
        if(root->data == k){
            return 0;
        }
        if(min_diff > abs(root->data - k)){
            min_diff = abs(root->data - k);
            min_diff_key = root->data;
        }
        
        if(k < root->data){
            return minDiff(root->left , k , min_diff ,min_diff_key);
        }
        else{
            return minDiff(root->right , k, min_diff , min_diff_key);
        }
        
        
    }
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        int min_diff = INT_MAX;
        int min_diff_key = -1;
        return minDiff(root , K , min_diff, min_diff_key);
        
        
    }
};