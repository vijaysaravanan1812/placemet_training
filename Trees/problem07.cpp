
// Traverse the tree in diagonally

#include<iostream>
#include<vector>
#include<queue>
#include"tree.cpp"

using namespace std;

vector<int> diagonal_traversal(node *root){
    if(root == nullptr)
        return {};
    
    queue <node *> q;
    q.push(root);
    vector <int> answer;

    while(!q.empty()){
        int size = q.size();
        while(size--){
            node * tmp = q.front();
            q.pop();
            while(tmp){
                answer.push_back(tmp->data);
                if(tmp ->left)
                    q.push(tmp->left);
                tmp = tmp ->right;
            }

        }
    }

    return answer;
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

    vector<int> result = diagonal_traversal(root);

    for (auto x : result)
    {

        cout << x << " ";
    }
    cout << "\n";

    return 0;
}