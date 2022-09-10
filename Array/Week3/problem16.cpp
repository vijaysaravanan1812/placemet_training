//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
    	string MaxZero(string a[],int n)
    	{
    	   
    	    int max = INT_MIN;
    	    string num = "";
    	    for(int i = 0 ; i < n ; i++){
    	         int count = 0;
    	        for(auto j : a[i]){
    	            if(j == '0'){
    	                count += 1;
    	            }
    	        }
    	        if(count > max){
    	            max = count;
    	            num = a[i];
    	        }
    	        if(max == count){
    	            if(a[i].size() > num.size())
                        num = a[i];
    	            if(a[i].size() == num.size() && a[i] > num){
    	                num = a[i];
    	            }
    	        }
    	        
    	    }
    	    
    	    if(max == 0){
    	        return "-1";
    	    }
    	    return num;
    	        
    	}
};
	 

//{ Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    string a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    

      

        Solution ob;
        cout << ob.MaxZero(a,n) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends