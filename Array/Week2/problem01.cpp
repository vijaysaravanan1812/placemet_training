

/*
1) Search an element in a sorted and rotated array

An element in a sorted array can be found in O(log n) 
time via binary search. But suppose we rotate an ascendin
order sorted array at some pivot unknown to you beforehand. 
So for instance, 1 2 3 4 5 might become 3 4 5 1 2. Devise 
a way to find an element in the rotated array in O(log n) time.
*/

#include<bits/stdc++.h>

using namespace std;

int search(vector<int> &num, int l, int r, int key)
{
     int mid = (l + r)/2;
    if(l > r)
        return -1;
   

    if(num[mid] == key)
        return mid;
    
    //Check num[l] to num[mid] is sorted
    if(num[l] <= num[mid])
    {
        if(key >= num[l] && key <= num[mid] ){
            return search(num , l , mid - 1, key);
        }
        else{
            return search(num , mid + 1, r , key);
        }
    }
    else
    {
        if(key >= num[mid] && key <= num[r] ){
            return search(num , mid + 1, r ,  key);
        }
        else{
            return search(num , l , mid - 1,  key);
        }
    }

}

int main()
{
    vector <int> num;
    num = {12, 14, 15, 16, 1, 3, 5, 4 } ;

    cout<<"index of 3 is "<<search(num , 0 , num.size() -1, 3)<<"\n";

    return 0;


}