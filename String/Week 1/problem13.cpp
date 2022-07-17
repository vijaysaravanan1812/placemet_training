
    string reverseWords(string s) 
    { 
        vector<string> temp ;string str;
        for(int i = 0 ; i < s.length(); i++ ){
            
            if(s[i] == '.'){
                temp.push_back(str);
                str = "";
            }
            else{
                str += s[i];
            }
        }
        temp.push_back(str);
        
        str = "";
        
        for(int i = temp.size() - 1 ; i >= 1  ; i--){
            str += temp[i];
            str += '.';
        }
        str += temp[0];
        
        return str;
    } 