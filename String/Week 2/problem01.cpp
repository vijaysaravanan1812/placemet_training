    bool isAnagram(string s, string t){
        
        map<char , int> freq; 
        
                 int m = s.length();
        int n = t.length();
        if(m != n )
            return false;
        
        for(int i = 0 ; i < s.length() ; i++)
            freq[s[i]]++;
        for(int i = 0 ; i < t.length() ; i++){
            if(freq.find(t[i]) != freq.end()){
                freq[t[i]]--;
            }
        }
            
        
        int sum = 0;
        for(auto x : freq){
            

            sum += x.second;
            if(x.second < 0)
                return false;
        }
        
        return (sum == 0);
    }
