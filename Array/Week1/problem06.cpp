

/*
6) Maximum sum such that no two elements are adjacent

This problem is using dynamic programming approach
Time complexity : O(n)
Space complexity : O(1)

*/

#include<bits/stdc++.h>

using namespace std;

class Solution {


    public:
    int maximum_sum(vector<int> &num)
   
    {
        int inclusive = num[0];
        int exclusive = 0, old_inclusive ;
        for(int i = 1 ; i < num.size(); i++){
            old_inclusive = inclusive;
            inclusive = max(exclusive + num[i], inclusive);
            exclusive = old_inclusive;
        }

        return max(inclusive , exclusive);

    }

};


int main(){
    vector <int> num ; 
    num = {4, 1, 1, 4, 2 , 1, 6};
    Solution s;
    cout<<"Maximum sum is "<<s.maximum_sum(num)<<"\n";

    return 0;
}