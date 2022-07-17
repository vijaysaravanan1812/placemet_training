class Solution
{
    static int compare(pair<char , pair<int , int >> a,
                        pair<char , pair<int , int >>b){
            
        return ((a.second.first < b.second.first));            
                            
                            
                            
    }
    
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code he
       map<char , pair<int , int>> mymap;
       for(int i = 0 ; i < S.length() ; i++){
           if(mymap.find(S[i]) != mymap.end()){
               mymap[S[i]].second++;    
           }   
           else{
               mymap[S[i]] = make_pair(i , 1);
           }
       }
       vector<pair<char , pair<int , int >>>b;
       for(auto x : mymap){
           b.push_back(make_pair(x.first , x.second));
       }
       
       sort(b.begin() , b.end() , compare);
       
       for(auto x : b){
            if(x.second.second == 1)
                return x.first;
       }
       
       return '$';
       
    }

};