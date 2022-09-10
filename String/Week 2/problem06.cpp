//{ Driver Code Starts
// C++ program Find concatenated string with 
// uncommon characters of given strings 
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends


class Solution
{
    public:
    //Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2) 
    { 
        // Your code here
        map<char,int> mp1;
        map<char,int> mp2;
        for(int i  = 0; i<s1.size(); i++) mp1[s1[i]]++;
        for(int i  = 0; i<s2.size(); i++) mp2[s2[i]]++;
        
        string result = "";
        
        for(int i =0; i<s1.size(); i++) if(mp2.find(s1[i]) == mp2.end()) result += s1[i]; 
        for(int i =0; i<s2.size(); i++) if(mp1.find(s2[i]) == mp1.end()) result += s2[i];
        
        if(result.size() == 0) return "-1";
        return result;
    }

};

//{ Driver Code Starts.

/* Driver program to test above function */
int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	Solution obj;
    	string res = obj.concatenatedString(s1, s2);
    	cout<<res<<endl;
	}
	return 0; 
}

// } Driver Code Ends