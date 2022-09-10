 vector<long long int> productExceptSelf(vector<long long int>& nums, int N) {
       
        vector <long long int> output;
        int product = 1;
        int n = nums.size();
        if(n < 1)
            return output;
        
        for(int i = 0 ; i < n ; i++){
            product = product*nums[i];
            output.push_back(product);
        }
        
        product = 1;
        for(int i = n -1 ; i > 0  ; i--){
            output[i] = output[i - 1] * product;
            product = product* nums[i];
        }
        output[0]  = product;
        
        return output;
         
    }  