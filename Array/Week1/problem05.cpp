
/*
05) Maximum Subarray
Kadane's Algorithm Approach
This problem is using dynamic programming approach


Time complexity O(n)

*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int max_sum_subarray(vector<int> &num)
        {
            int max_sum = num[0];
            int current_sum = max_sum;
            for(int i = 1; i < num.size();i++){
                current_sum = max(num[i] + current_sum , num[i]);
                max_sum = max(current_sum , max_sum);
            }
            return max_sum;
        }
};

int main()
{
    vector<int> num;
    Solution s;
    num.push_back(-2);
    num.push_back(2);
    num.push_back(5);
    num.push_back(-11);
    num.push_back(6);
    

    cout<<s.max_sum_subarray(num)<<" "<<"\n";

    return 0 ;
}