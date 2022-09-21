//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
    int value(char R){
        if(R == 'I')
            return 1;
        if(R == 'V')
            return 5;
        if(R == 'X')
            return 10;
        if(R == 'L')
            return 50;
        if(R == 'C')
            return 100;
        if(R == 'D')
            return 500;
        if(R == 'M')
            return 1000;
    }
  public:
    int romanToDecimal(string &str) {
        // code here
        int res = 0;
        for(int i = 0 ; i < str.length() ; i++){
            int s1 = value(str[i]);
            
            if(i + 1 < str.length()){
                int s2 = value(str[i + 1]);
                if(s1 >= s2){
                    res = res + s1;
                }
                else{
                    res = res + s2 - s1;
                    i++;
                }
            }else{
                res = res + s1;
        
            }
        }
        return res;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends