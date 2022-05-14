// Boundary order traversal

#include <iostream>
#include <vector>
#include <stack>
#include "tree.cpp"

using namespace std;

void get_left_side(vector<int> &result, node *root)
{

    if (root == NULL)
        return;
    if (root->left)
    {
        result.push_back(root->data);
        
        get_left_side(result, root->left);
    }
    else if (root->right)
    {
        result.push_back(root->data);
        
        get_left_side(result, root->right);
    }
}

void get_right_side(vector<int> &result, node *root)
{

    if (root == NULL)
        return;
    if (root->right)
    {
        get_right_side(result, root->right);
        result.push_back(root->data);
        
    }
    else if (root->left)
    {
        get_right_side(result, root->left);
        result.push_back(root->data);
        
    }
}

void get_leaves(vector<int> &result, node *root)
{
    if (root == NULL)
        return;

    get_leaves(result, root->left);

    if (!root->left && !root->right)
    {
        result.push_back(root->data);
        return;
    }

    get_leaves(result, root->right);
}

vector<int> boundary(node *root)
{

    if(root == NULL)
        return {};
    vector<int> result;
    result.push_back(root ->data);
    get_left_side(result, root ->left);
    get_leaves(result, root ->left);
    get_leaves(result, root ->right);
    get_right_side(result, root->right);
    

    return result;
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

    vector<int> result = boundary(root);

    for (auto x : result)
    {

        cout << x << " ";
    }
    cout << "\n";

    return 0;
}