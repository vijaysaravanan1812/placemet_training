class Solution
{
    public:
    //Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2) 
    { 
        
        set<char> myset1, myset2;
        for(int i = 0 ; i < s1.length() ; i++ )
            myset1.insert(s1[i]);
            
        for(int i = 0 ; i < s2.length() ; i++)
            myset2.insert(s2[i]);
            
        string str = "";
        int i = 0 ;
        while(i < s1.length() || i < s2.length()){
            if(i == s1.length())
                break;
            char c = s1[i];
            if(!(myset2.find(s1[i]) != myset2.end()))
                str += c;
            i++;
        }
        
        i = 0;
        
        while(i < s1.length() || i < s2.length()){
            if(i == s2.length())
                break;
            
            char c = s2[i];
            if(!(myset1.find(s2[i]) != myset1.end()))
                str += c;
            i++;
        }
        if(s1 == s2)
            return "-1";
        
        return str;
        // Your code here
    }

};