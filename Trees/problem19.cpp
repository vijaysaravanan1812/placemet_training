void getNoSibling(Node * node, vector<int> & result){
    if(node == NULL)
        return;
    if(node -> left && node ->right)
    {
        getNoSibling(node->left , result);
        getNoSibling(node -> right , result);
        
    }
    else if(node -> right){
        result.push_back((node->right)->data);
        getNoSibling(node->right , result);
    }
    else if(node -> left){
        result.push_back((node->left)->data);
        getNoSibling(node->left , result);
    }
        
}

vector<int> noSibling(Node* node)
{
    vector<int> result;
    getNoSibling(node , result);
    if(result.size() == 0)
        return {-1};
    return result;
}