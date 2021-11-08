/*

4) Two pairs
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{

    public:
        int find_pairs(vector <int> & num, int value)
        {
             int l = 0 ,r = num.size() - 1;
            sort(num.begin(), num.end());
               
           

            while (l < r)
            {
                           
                if(num[l] + num[r]  == value)
                {
                    return 1;
                }
                else if (num[l] + num[r] < value)
                {
                    l++;
                }
                else{
                    r--;
                }
            }
            

            return 0;
        }
};

int main()
{
    vector<int> num;
    num.push_back(2);
    num.push_back(4);
    num.push_back(1);
    num.push_back(7);
    num.push_back(50);
    num.push_back(12);
    for (int i = 0; i < num.size(); i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<"\n";

    Solution s;
    cout<<s.find_pairs(num , 28);
    cout<<"\n";
    return 0 ;
}