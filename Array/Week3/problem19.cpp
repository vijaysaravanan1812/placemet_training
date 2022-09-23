//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    int search(int arr[] , int l , int r ,int n){
        int mid =  (l + r) / 2;
            
         if (l == r) return arr[l];

	    /* If there are two elements and first is greater then
	        the first element is maximum */
	    if ((r == l + 1) && arr[l] >= arr[r]) return arr[l];

	    /* If there are two elements and second is greater then
	        the second element is maximum */
	    if ((r == l + 1) && arr[l] < arr[r]) return arr[r];
	    
         if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) return arr[mid];
         
        if(arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1] )
        {
            return search(arr , l , mid - 1 , n);
        }
        else 
        {
            return search(arr , mid + 1 , r , n);
        }
        
    }
    
    
    
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    return search(arr , 0 , n - 1 , n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends