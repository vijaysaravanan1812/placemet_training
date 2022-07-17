
//Check if string is rotated by two places 

bool isRotated(string str1, string str2)
    {
        string temp1="";
        for(int i=2;i<str2.size();i++){
            temp1.push_back(str2[i]);
            
        }
        temp1.push_back(str2[0]);
        
        temp1.push_back(str2[1]);
    
        if(str1==temp1)
            return true;
        string temp = "";
        temp += str2[str2.size() - 2];
        temp += str2[str2.size() - 1];
        for(int i = 0 ; i < str2.size() - 2 ; i++){
            temp += str2[i];
        }
        
        return temp == str1;
    }
