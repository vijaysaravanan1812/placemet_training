class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    int left ;
	    int right ;

		//Square the array
	    for(int i = 0; i < n ; i++)
	        arr[i] = arr[i] * arr[i];
	    
	    sort(arr , arr + n);
	    for(int i = n - 1 ; i >= 2 ; i--){
	        left = 0 ;
	        right  = i - 1;
	        while(left < right){
	            if(arr[left] + arr[right] == arr[i])
	                return true;
	           
	            (arr[left] + arr[right] < arr[i])? left++ : right--;
	        }
	    }
	    return false;
	}
};
