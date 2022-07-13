     int closestToZero(int arr[], int n)
        {
            sort(arr, arr + n);
            
            if(n == 1)
                return arr[0]*2;
            else if(arr[0] < 0)
                return arr[n-1] + arr[n -2 ];
            else if(arr[0] > 0)
                return arr[0] + arr[1];
                
            int  min_sum = INT_MAX , low  = 0, high = n -1;
            while(low < high){
                int sum = arr[low] + arr[high];
                if(abs(sum) < abs(min_sum)){
                    min_sum = sum;
                    
                }
                
                if(abs(sum) == abs(min_sum))
                    min_sum = max(min_sum , sum);
                
                if(sum < 0 )
                    low++;
                else
                    high--;
            }
            
            return min_sum;
            // your code here 
        }