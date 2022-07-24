
// Level order traversal

#include <iostream>
#include <vector>
#include <queue>
#include "tree.cpp"

using namespace std;

vector<vector<int>> MyLevelOrder(node *root)
{
    vector<vector<int>> result;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> LevelOrder;
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            node *current = q.front();
            LevelOrder.push_back(current->data);
            q.pop();
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }

        result.push_back(LevelOrder);
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
    result = MyLevelOrder(root);
    for (int i = 0; i < result.size(); i++)
    {
        for (auto itr = result[i].begin(); itr < result[i].end(); itr++)
        {
            cout << *itr << " ";
        }
        cout << "\n";
    }

    return 0;
}