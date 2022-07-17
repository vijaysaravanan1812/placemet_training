class Solution{
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

public:
	int search(string pat, string txt) {
	    int N = pat.length();
	    int M = txt.length();
	   
	    int i = 0 , k;
	    int j = 0, res = 0;
	    string str;
	    for(i = 0; i < M - N + 1; i++ ){
	  
	        j = i; 
            str = txt.substr(j , N);
            

            if(isAnagram(pat , str)){
                res++;
            }
            str="";
	    }
	  

	    
	    return res;
	}

};