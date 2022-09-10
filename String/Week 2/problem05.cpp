#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    static int compare(pair<string , int> a , pair<string , int> b){
        return (a.second > b.second);
    }
    
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        map<string , int> mymap;
        for(int i = 0 ; i < n ; i++)
            mymap[arr[i]]++;
            
        vector <pair<string , int>> b;
        for(auto x : mymap)
            b.push_back(make_pair(x.first , x.second));
            
        sort(b.begin() , b.end() , compare);
        
        return b[1].first;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends