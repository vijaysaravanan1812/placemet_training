class solution
{
    
    vector<string> result;
	public:
	
	    vector<string>find_permutation(string a){
	            permute(a , 0 , a.length() - 1 );
	            set<string> b;
	            for(auto x : result){
	                b.insert(x);
	            }
	            result.clear();
	            for(auto x : b){
	                result.push_back(x);
	            }
	            
	            
	            return result;
	    }
	    void permute(string a, int l, int r)  
        {  
            // Base case  
            if (l == r)  
                result.push_back(a);  
            else
            {  
                // Permutations made  
                for (int i = l; i <= r; i++)  
                {  
  
                    // Swapping done  
                    swap(a[l], a[i]);  
  
                    // Recursion called  
                    permute(a, l+1, r);  
  
                     //backtrack  
                    swap(a[l], a[i]);  
                }  
            }  
        }  
};