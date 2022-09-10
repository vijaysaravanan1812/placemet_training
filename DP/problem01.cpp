class Solution {
    int climeStairs(int n , vector<int> &dp){
  
        if(n == 0 || n == 1)
                return dp[n] = 1;
        if(dp[n] != -1){
            return dp[n];
        }
        else 
        {

            dp[n] = climeStairs(n - 1, dp) + climeStairs(n - 2 , dp);
            return dp[n];
        }
    }
public:
    int climbStairs(int n) {
  
        vector<int> dp(n + 1, -1);
        return climeStairs(n , dp);
        
    }
};