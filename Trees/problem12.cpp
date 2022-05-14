
// binary tree maximum sum path 
#include<iostream>
#include"tree.cpp"

using namespace std;

int MaxSum(node *root , int &result){
    if(root == NULL)
        return 0;
    int left = MaxSum(root->left , result);
    int right = MaxSum(root->right , result);

    int max_straight = max(max(left , right)  + root->data , root->data);
    int max_caseVal = max(max_straight  , left + right + root->data);
    result = max(max_caseVal , result);
}

int MaxSumPath(node *root ){
    int result = -3322234;
    MaxSum(root , result);
    return result;
}