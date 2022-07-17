
    vector<vector<string> > Anagrams(vector<string>& str) {
        //code here
        unordered_map<string , vector<string>> mymap;
        int n = str.size();
        for(int i = 0 ; i < n ; i++){
            string temp = str[i];
            sort(temp.begin() , temp.end());
            mymap[temp].push_back(str[i]);
        }
        
        vector<vector<string>> result;
        for(auto  x : mymap){
            //sort((x.second).begin() , (x.second).end());
            result.push_back(x.second);
        }
        
        return result;
        
    }