    map <int , map<int ,set<int>>> mymap;
    void solve(Node * cur , int col , int row){
        if(!cur)
            return;
        mymap[col][row].insert(cur->data);
        solve(cur->left , col - 1 , row +1);
        solve(cur->right , col + 1 , row + 1);
        
    }
    
    vector<vector<int>> verticalTraversal(Node* root) {
        solve(root , 0 , 0);
        vector<vector<int>> ans;
        for(auto m1 : mymap){
            // ans.push_back(vector<int>());
            vector<int> temp;
            for(auto m2 : m1.second){
                for(auto m3 : m2.second){
                    temp.push_back(m3);
                }
               // sort(m2.second.begin(), m2.second.end());
            }
            ans.push_back(temp);
            
        }
        return ans;
    }


    void topView(Node * root) {
        vector<vector<int>> result;
        result = verticalTraversal(root);
        for(auto x : result){
            cout<<x[0]<<" ";
        }
    }
