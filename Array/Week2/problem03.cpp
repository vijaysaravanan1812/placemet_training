
/*
3) sort the array that containing 0, 1, 2

Dutch  National flag Algorithm

Algorithm: 
Keep three indices low = 1, mid = 1 and high = N and there are four ranges, 1 to low (the range containing 0), low to mid (the range containing 1), mid to high (the range containing unknown elements) and high to N (the range containing 2).
Traverse the array from start to end and mid is less than high. (Loop counter is i)
If the element is 0 then swap the element with the element at index low and update low = low + 1 and mid = mid + 1
If the element is 1 then update mid = mid + 1
If the element is 2 then swap the element with the element at index high and update high = high – 1 and update i = i – 1. As the swapped element is not processed
Print the output array.

Time complexity O(n)
Space complexity O(10)
*/

#include<bits/stdc++.h>

using namespace std;


void sort(vector<int> &num)
{
    int low = 0;
    int high = num.size() - 1;
    int mid = 0;
    while (mid <= high)
    {
        if(num[mid] == 0)
        {
            swap(num[low++],num[mid++]);
        }
        else if(num[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(num[mid], num[high--]);
        }
    }
}

int main()
{
    vector<int> num = {1,0,2,0,1,0,1,2};

    for(int i= 0; i < num.size(); i++)
    {
        cout<<num[i]<<" ";
    }
    printf("\n");

    sort(num);

    for(int i =0 ; i < num.size(); i++ )
    {
        cout<<num[i]<<" ";
    }
    printf("\n");

    return 0;
}
