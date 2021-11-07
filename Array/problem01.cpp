
/* 
1) Array rotation 

Time complexity : O(n)
Space complexity : O(1)

*/


#include <bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public:
    void rotate(vector<int> & num, int k);

};

void Solution::rotate(vector<int> &num, int k)
{
    reverse(num.begin(), num.end());
    k = k % num.size();
    reverse(num.begin(), num.begin() + k);
    reverse(num.begin() + k, num.end()); 
}

int main()
{
    vector<int> num;
    num.push_back(2);
    num.push_back(4);
    num.push_back(6);
    num.push_back(8);
    num.push_back(10);
    num.push_back(12);
    for (int i = 0; i < num.size(); i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<"\n";
    Solution s;
    s.rotate(num,3);

    for (int i = 0; i < num.size(); i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<"\n";

    
    return 0 ;
}