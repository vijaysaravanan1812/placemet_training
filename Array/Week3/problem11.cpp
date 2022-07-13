vector<int> nextPermutation(int N, vector<int> arr){
        if(arr.size() == 1)
            return {arr[0]};
            
        int i = 1;
        int lastinc = -1;
        while(i < N )
        {
            if(arr[i] > arr[i - 1])
                lastinc = i;
            i++;
        }
        
        if(lastinc == -1){
    
                sort(arr.begin() , arr.end());
            return arr;
        }
         
        int index = lastinc;
        for( i = lastinc ; i < N; i++){
            if(arr[lastinc - 1] < arr[i] )
                index = i;
        }
        swap(arr[index] , arr[lastinc - 1]);
        sort(arr.begin() + lastinc , arr.end());
        
        return arr;
            
    }