

// implementation of tree

#include <iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void level_order(node* root)
{
    if (root == NULL)
    {
        printf("No list here to print\n");
        return;
    }
    queue <node *> q;
    q.push(root);
    
    while (!q.empty())
    {
        node* current = q.front();
        q.pop();
        printf("%d ",current->data);
        if (current->left != NULL)
            q.push(current->left);
        if (current ->right != NULL)
            q.push(current->right);
    }
}

void pre_order(node *&root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(node *&root)
{
    if (root == NULL)
        return;
    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

void post_order(node *&root)
{
    if (root == NULL)
        return;
    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
}

node *get_node(node *&tmp, int x)
{
    tmp = (node *)malloc(sizeof(node));
    tmp->data = x;
    tmp->left = tmp->right = NULL;
    //  return tmp;
}

node *find_min(node *root)
{
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    return find_min(root->left);
}

void insert(node *&root, int data)
{
    if (root == NULL)
    {
        get_node(root, data);
    }
    else if (data <= root->data)
    {
        insert(root->left, data);
    }
    else
    {
        insert(root->right, data);
    }
}

void delete_node(node *&root, int data)
{
    if (root == NULL)
        return;
    else if (data < root->data)
        delete_node(root->left, data);
    else if (data > root->data)
        delete_node(root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            node *tmp = root;
            root = root->right;
            free(tmp);
        }
        else if (root->right == NULL)
        {
            node *tmp = root;
            root = root->left;
            free(tmp);
        }
        else
        {
            node *tmp = find_min(root->right);
            root->data = tmp->data;
            delete_node(root->right, tmp->data);
        }
    }
}

