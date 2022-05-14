
// sum root to leaf numbers
#include<iostream>
#include"tree.cpp"

using namespace std;

void RootToLeaf(node * root , int &sum , int num)
{
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL){
        num = num*10 + root->data;
        sum = sum + num;
        return;
    }

    RootToLeaf(root->left , sum , num*10 + root->data);
    RootToLeaf(root->right , sum , num*10 + root->data);

}

int sumNumber(node * root){
    int sum = 0 , num = 0;
    RootToLeaf(root , sum , num);
    return sum;
}
