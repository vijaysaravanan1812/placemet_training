
/*
12)    Given a sorted array arr[] of distinct integers.
Sort the array into a wave-like array and return it
In other words, arrange the elements into a sequence
such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....

Example 1:

Input:
n = 5
arr[] = {1,2,3,4,5}
Output: 2 1 4 3 5
Explanation: Array elements after 
sorting it in wave form are 
2 1 4 3 5.

*/


#include<bits/stdc++.h>

using namespace std;

void sort_in_wave(vector<int> &num)
{
    for (int i = 0; i < num.size(); i += 2)
    {
        if(num[i] < num[i + 1])
            swap(num[i], num[i + 1]);
    }
    
}


int main()
{
    vector<int> num;

    num = {10, 90, 49, 2, 1, 5, 23};


    for (int i = 0; i < num.size(); i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<"\n";

    sort_in_wave(num);

    for (int i = 0; i < num.size(); i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<"\n";
    
}