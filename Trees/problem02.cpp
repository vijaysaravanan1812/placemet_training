

vector<int> reverseLevelOrder(Node *root)
{
    vector <int> Reverse_level_order;
    queue <Node *> q;
    stack <Node *> s;
    q.push(root);
    while(q.empty() == false)
    {
        Node * tmp = q.front();
        q.pop();
        s.push(tmp);
        if(tmp->right)
            q.push(tmp->right);
        if(tmp->left)
            q.push(tmp->left);
        
    }
    
    while(s.empty() == false)
    {
        Reverse_level_order.push_back(s.top()->data);
        s.pop();
    }
    return Reverse_level_order;
}