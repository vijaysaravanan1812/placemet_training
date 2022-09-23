//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int search(int arr[], int one  , int l , int r){
    int mid = (l + r)/2;
    if( l > r)
        return -1;
    
    if(arr[mid] == one){
        if(arr[l] == one)
            return l;
        for(int i = l + 1 ; i <= mid; i++)
        {
            if(arr[i] == one)
                return i;
        }
        
    }
    if(arr[mid] < one){
        return search(arr , one , mid + 1 , r );
    }
    
}


int transitionPoint(int arr[], int n) {
    // code here
    return search(arr , 1 , 0 , n - 1);
}