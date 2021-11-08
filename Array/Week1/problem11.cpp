
/*


11) Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to
the left of the index is equal to the sum of all the numbers strictly to 
the index's right.

If the index is on the left edge of the array, then the left sum is 0 because 
there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.


*/

#include<bits/stdc++.h>

using namespace std;

int find_pivot(vector <int> & num) 
{
    int total_sum = 0;
    int left_sum = 0;

    for(int i = 0 ; i < num.size(); i++)
    {
        total_sum += num[i];
        
    }

    for(int i = 0; i < num.size(); i++ )
    {
        if(i != 0){
            left_sum += num[i - 1];
        }
        if(total_sum - left_sum - num[i] == left_sum)
        {
            return i;
        }
    }

    return -1;
}


int main()
{
    vector <int> num;
    num = {1, 3, 5, 2, 2};

    cout<<"The pivot element is "<<find_pivot(num)<<"\n";
    return 0;

}
