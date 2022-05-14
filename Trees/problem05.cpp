
// zig zag Level order traversal
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
#include "tree.cpp"

vector<vector<int>> MySpiralLevelOrder(node *root)
{
    stack<node *> s1;
    stack<node *> s2;
    s1.push(root);

    vector<vector<int>> result;
    vector<int> Spiral;
            
    while(!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {

            node * tmp = s1.top(); 
            s1.pop();
            Spiral.push_back(tmp->data);
            if(tmp->left)
                s2.push(tmp->left);
            if(tmp->right)
                s2.push(tmp->right);
            if(s1.empty())
            {
                result.push_back(Spiral);
                Spiral.clear();
            }
        }

        while(!s2.empty())
        {
            node * tmp = s2.top();
            Spiral.push_back(tmp->data) ; 
            s2.pop();

            if(tmp ->right)
                s1.push(tmp ->right);
            if(tmp ->left)
                s1.push(tmp->left);

            if(s2.empty())
            {
                result.push_back(Spiral);
                Spiral.clear();
            }

        }
        
    }

    
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

    vector<vector<int>> result;
    result = MySpiralLevelOrder(root);

    // vector <vector<int>> res (result.rbegin(), result.rend());
    //  reverse(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {

        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
