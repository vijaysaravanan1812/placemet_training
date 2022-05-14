

// find lowest common ancestor

#include<iostream>
#include"tree.cpp"

using namespace std;

node * MyLowestCommonAncestor(node * root , node * p , node * q){
    if(root == NULL)
        return NULL;

    if(root == p || root == q)
        return root;
    
    
    node *left = MyLowestCommonAncestor(root->left, p , q);
    node *right = MyLowestCommonAncestor(root->right , p , q);

    if(left != NULL && right != NULL)
        return root;
    if(left == NULL && right == NULL)
        return NULL;
    
    return (left != NULL)?left:right;



}

int main(){

    node *root = NULL;

    insert(root, 84);
    insert(root, 54);
    insert(root, 104);
    insert(root, 34);
    insert(root, 68);
    insert(root, 95);

    insert(root, 120);
    insert(root, 10);
    insert(root, 42);
    insert(root, 59);
    insert(root, 76);
    insert(root, 92);
    insert(root, 99);
    insert(root, 110);
    insert(root, 130);
    insert(root, 15);
    insert(root, 70);

    node * p = root->left->right->left->left;
    node * q = root->left->right->right;

    level_order(root);
    cout<<"\ncommon ancestor "<<MyLowestCommonAncestor(root , p , q )->data<<"\n";

    return 0;
}