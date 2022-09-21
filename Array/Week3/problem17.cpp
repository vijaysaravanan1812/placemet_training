//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    unordered_map <char , int> Nuts , Order;
	    char order[] = {'!', '#','$',  '%','&','*','@','^' ,'~' };
	    int size = sizeof(order)/sizeof(order[0]);
	    
	    
	    for(int i = 0 ; i < n ; i ++){
	        Nuts[nuts[i]] = i;
	    }
	    for(int i = 0 ; i < size; i++){
	        Order[order[i]] = i;
	    }
	    
	    
	    for(int i = 0 ; i < n ; i++){
	        if(Nuts.find(bolts[i]) != Nuts.end()){
	            nuts[i] = bolts[i];
	        }
	    }
	    
	    int j = 0;
	    for(int i = 0; i < size ; i++){
	        if(Nuts.find(order[i]) != Nuts.end()){
	            nuts[j] = bolts[j] = order[i];
	            j++;
	        }
	    }
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends