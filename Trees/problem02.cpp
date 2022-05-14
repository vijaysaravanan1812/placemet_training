 
//Reverse Level order traversal
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
#include "tree.cpp"

vector<vector<int>> MySpiralLevelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    vector<vector<int>> result;
    while (!q.empty())
    {
        vector<int> Reverselevel_order;
        
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            node *current = q.front();
            Reverselevel_order.push_back(current->data);
        
            
            q.pop();
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
            
        }

        result.push_back(Reverselevel_order);

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
    reverse(result.begin(), result.end());
    for (int i = 0; i < result.size() ; i++)
    {
        
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j]<< " ";
        }
        cout << "\n";


    }

    return 0;
}
