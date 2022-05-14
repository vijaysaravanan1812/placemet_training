
//invert the binary tree 
#include<iostream>
#include"tree.cpp"

using namespace std;

void invert(node *& root ){
    if(!root)
        return ;

    invert(root->left);
    invert(root->right);

    node *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
}


int main()
{
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

    cout<<"Before invert\n";
    level_order(root);

    cout<<"\n";
    invert(root);

    cout<<"After invert\n";
    level_order(root);

    cout<<"\n";

    return 0;
}

