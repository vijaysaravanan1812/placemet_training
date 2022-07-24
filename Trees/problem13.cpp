class Codec {
    
    void post_order(TreeNode * root , string &str ){
        if(root == NULL){
            str += "*";
            return;
        }
        str.append(to_string(root->val) + ",");
        post_order(root->left , str);
        post_order(root->right , str);
        
    }

    TreeNode * decode(string &str){
        if(str.size() == 0)
            return NULL;
        if(str[0] == '*'){
            str = str.substr(1);
            return NULL;
        }
        
        int pos = 0;
        string no;
        while(str[pos] != ','){
            no += str[pos++];
        }
        
        TreeNode *Cur = new TreeNode(stoi(no));
        str = str.substr(pos + 1);
        Cur->left = decode(str);
        Cur->right = decode(str);
        return Cur;
        
        
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        post_order(root , str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return decode(data);
    }
};