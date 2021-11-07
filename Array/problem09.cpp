

/*

9) You are given a list of n-1 integers and
these integers are in the range of 1 to n.
There are no duplicates in the list. One of
the integers is missing in the list. Write 
an efficient code to find the missing integer.
Example: 

Input: arr[] = {1, 2, 4, 6, 3, 7, 8}
Output: 5
Explanation: The missing number from 1 to 8 is 5

Input: arr[] = {1, 2, 3, 5}
Output: 4
Explanation: The missing number from 1 to 5 is 4

Time complexity : O(n)
space complexity  : O(1)
*/

#include<bits/stdc++.h>

using namespace std;

int get_missing_number(vector<int> &num)
{
    int x1 = num[0];
    int x2 = 1;

    for(int i = 1; i < num.size(); i++ )
    {
        x1 = x1 ^ num[i];
    }

    for(int i = 2 ; i <= num.size() + 1; i++)
    {
        x2 = x2 ^ i;
    }

    return (x1 ^ x2);
}


int main()
{
    vector <int> num;

    num = {1, 3, 4, 5};

    for(int i = 0 ; i < num.size() ; i++)
    {
        cout<<num[i]<< " ";
    }
    cout<<"\n";
    cout<<"Missing number is "<<get_missing_number(num)<<"\n";

    return 0;
}