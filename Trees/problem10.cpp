
// Path sum ii

//      1   
//     / \
//    2   4
//   / \    \ 
//  2   3    1

//  target sum 6 
//  than path is
//  1->2->3
//  1->4->1

#include<iostream>
#include"tree.cpp"

using namespace std;

node* PathSum(node * root , int sum, int TargetSum , vector<int> &path , vector<vector<int>> & result ){
    if(root == NULL)
        return NULL;
    if(root ->data + sum == TargetSum && root->left == NULL && root->right == NULL){
        path.push_back(root->data);
        result.push_back(path);
        path.pop_back();
        return;
    }

    path.push_back(root->data);
    PathSum(root->left , sum + root->data , TargetSum , path , result);
    PathSum(root->right , sum + root->data , TargetSum , path, result );
    path.pop_back();
    return;
}

vector<vector<int>> PathSum(node * root, int targetsum){
    vector<int> path;
    vector<vector<int>> result;
    PathSum(root , 0 , targetsum , path , result);
    return result;
}
