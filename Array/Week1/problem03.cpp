/*

3) Removing duplicates from sorted array

Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element
appears only once. The relative order of the elements should 
be kept the same.

Since it is impossible to change the length of the array in 
some languages, you must instead have the result be placed 
in the first part of the array nums. More formally, if there 
are k elements after removing the duplicates, then the first 
k elements of nums should hold the final result. It does not
matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by 
modifying the input array in-place with O(1) extra memory.

*/


#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
        int remove(vector<int> &num)
        {
            int j = 0;
            for(int i = 0 ; i < (num.size() - 1 ); i ++ ){
                if(num[i] != num[ i+ 1]){
                    num[j]  = num[i];
                    j++;
                }
            }
            num[j] = num[num.size()-1];
            j++;
            return j;

        }
};


int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(3);
    num.push_back(3);
    num.push_back(3);
    num.push_back(4);
    num.push_back(8);
    Solution s;

    for (int i = 0; i < num.size(); i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<"\n";
    int n = s.remove(num);

    for (int i = 0; i < n; i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<"\n";
    
}