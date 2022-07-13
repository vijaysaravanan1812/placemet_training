class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> myset;
        for(int num : nums)
            myset.insert(num);
        
        int longstreak = 0 ;
    
        for(int num : nums){
            if(!(myset.count(num - 1))){
                int currentNum = num;
                int currentstreak = 1;
                
                while(myset.count(currentNum + 1))
                {
                    currentNum += 1;
                    currentstreak += 1;
                }
                
                longstreak = max(longstreak , currentstreak);
                
            }
               
        }
        return longstreak;
    }
    
};