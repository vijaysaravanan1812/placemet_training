class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long sum)
    {
int curr_sum = arr[0], start = 0, i;
 
    /* Add elements one by one to curr_sum and
    if the curr_sum exceeds the sum,
    then remove starting element */
    for (i = 1; i <= n; i++) {
        // If curr_sum exceeds the sum,
        // then remove the starting elements
        while (curr_sum > sum && start < i - 1) {
            curr_sum = curr_sum - arr[start];
            start++;
        }
 
        // If curr_sum becomes equal to sum,
        // then return true
        if (curr_sum == sum) {
            return {start + 1 , i };
            
        }
 
        // Add this element to curr_sum
        if (i < n)
            curr_sum = curr_sum + arr[i];
    }
 
    // If we reach here, then no subarray
    
    return {-1};
    }
};