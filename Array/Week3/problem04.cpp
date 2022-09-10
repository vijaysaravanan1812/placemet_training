class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> result;
        int i;
        for(int i = 0 ; i < k ; i++){
            while(!q.empty() && nums[i] >= nums[q.back()] ){
                q.pop_back();
            }
            q.push_back(i);
        }
        result.push_back(nums[q.front()]);
        for(i = k ; i < nums.size() ; i++){

            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            
            if(!q.empty() && q.front() <= i - k){
                q.pop_front();
            }
            
            result.push_back(nums[q.front()]);
        }
    
        return result;
    }
};