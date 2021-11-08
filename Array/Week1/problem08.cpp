
/*
8) Moore's voting algorithm

Time Complexity : O(n)
space Complexity : O(1)

*/

#include<bits/stdc++.h>
using namespace std;


int find_majority(vector<int> &num )
{
    int major = 0, count = 1;
    for(int i = 1; i < num.size(); i++)
    {
        if(num[major] == num[i])
            count++;
        else
            count--;
        
        if(count == 0)
        {
            major = i;
            count = 1;
        }
    } 

    int majority = num[major];count = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if(majority == num[i])

            count++;
    }
    

    if(count <= (num.size()/2) ){

        return -1;
    }
    else
    {
        return majority;
    }
    

    
}


int main()
{
    vector<int> num = {13, 12, 12, 13, 13, 22, 22, 22 , 13};

    cout<<"Majority is "<<find_majority(num)<<endl;

    return 0;
}