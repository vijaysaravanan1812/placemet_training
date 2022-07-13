class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> result ;
        
        int i ;
        deque<int> q(k);
            
            
        for(i = 0 ; i < k ; i++){
            while((!q.empty()) && arr[i] >= arr[q.back() ])
                  q.pop_back();
            q.push_back(i);
        }
        
        for(;i < arr.size(); i++  ){
            
            result.push_back(arr[q.front()]);
            //check there is element which is not belong to current window
            while((!q.empty()) && q.front() <= i - k)
                q.pop_back();
            
            
            //maintain useful element
            while((!q.empty()) && arr[i] >= arr[q.back()])
                q.pop_back();
            q.push_back(i);
            
        }
                  
        result.push_back(arr[q.front()]);
        
        
        return result;
                
        
    }
};