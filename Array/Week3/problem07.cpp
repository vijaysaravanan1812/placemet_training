    int maxLen(int arr[], int N)
    {
        unordered_map <int , int > mymap;
        int longest_subarray = 0;
        int i = 0 ;
        int sum = 0 ;
        
        for(int i =  0 ;  i < N ; i ++){
            
            sum += arr[i] == 0? -1 : 1;
            
            if(sum == 0){
                if(longest_subarray < i + 1){
                    longest_subarray = i + 1;
                }
            }
            else if(mymap.find(sum) != mymap.end()){
                if(longest_subarray < i  - mymap[sum] ){
                    longest_subarray = i - mymap[sum];
                }
            }
            else{
                mymap[sum ] = i;
            }
             
        }
        
        return longest_subarray;
    }
};