class Solution{
  public:
    // your task is tp complete this function
    // function should return the length of the longestConsecutive
    // sequence
    void longestConsecutiveUtil(Node* root, int curLength,
                              int expected, int& res)
    {
        if (root == NULL)
            return;
  
        // if root data has one more than its parent
        // then increase current length
        if (root->data == expected)
            curLength++;
        else
            curLength = 1;
  
        //  update the maximum by current length
        res = max(res, curLength);
        
        // recursively call left and right subtree with
        // expected value 1 more than root data
        longestConsecutiveUtil(root->left, curLength, root->data + 1, res);
        longestConsecutiveUtil(root->right, curLength, root->data + 1, res);
    }
  
    // method returns length of longest consecutive
    // sequence rooted at node root
    int longestConsecutive(Node* root)
    {
        if (root == NULL)
            return -1;
  
        int res = 0;
  
        //  call utility method with current length 0
    //  longestConsecutiveUtil(root , current_length , expected, max_res)
        longestConsecutiveUtil(root, 0, root->data, res);
  
        if(res == 1)
            return -1;
        return res;
    }
};