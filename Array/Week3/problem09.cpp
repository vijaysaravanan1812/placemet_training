class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    	    long long  start=1,end=1;
	    long long ans=INT_MIN;
	    int i=0,j=n-1;
	    while(i<n && j>=0){
	        start*=arr[i];
	       // cout<<"start "<<start<<" ";
	        end*=arr[j];
	       // cout<<"end " << end<<"  ";
	        
	        ans=max(ans,max(start,end));
	       // cout<<"Ans " <<ans<<" \n";
	        if(arr[i]==0){
	            start=1;
	        }
	        if(arr[j]==0){
	            end=1;
	        }
	        i++;
	        j--;
	    }
	    return ans;
	 
	}
};