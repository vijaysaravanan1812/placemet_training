class Solution
{
    public:
    int findSubString(string s)
    {
        // Your code goes here   
            // your code here
         int count = 0;
        
         
        unordered_map <char , int > mymap;
        for(int i = 0 ; i < s.length(); i++){
            mymap[s[i]]++;
        }
        
        string p = "";
        for(auto x : mymap){
            p += x.first;
        }
        mymap.clear();
        
        
        for(int i = 0 ; i < p.length(); i++){
            if(mymap[p[i]] == 0)
                count++;
            mymap[p[i]]++;
        }
        
        int i = 0, start = 0; 
        int j = 0;
        int len = INT_MAX;
        while(j < s.length()){
            mymap[s[j]]--;
            if(mymap[s[j]] == 0)
                count--;
            if(count == 0){
                while(count == 0){
                    if(j - i + 1 < len){
                        len = j - i + 1;
                        start = i;
                        // cout<<"start -->"<<s[start]<<" ";
                    }
                    mymap[s[i]]++;
                    if(mymap[s[i]] == 1) 
                        count++;
                    // cout<<"i --> "<<s[i]<<" ";
                    i++;
                }
            }
            // cout<<"j --> "<<s[j]<<" ";
            j++;
        }
        if(len != INT_MAX){
            return (len);
        }
        
        
        
    }
}