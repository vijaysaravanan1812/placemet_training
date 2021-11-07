

/*

Kth smallest element 
Time complexity : O(n)
Space complexity : O(1)

*/

#include<bits/stdc++.h>

using namespace std;



int partition(vector<int> &num , int l , int r, int k)
{
    int pindex = l;
    int pivot = num[r], temp;
    for(int i = l ; i < r ; i++)
    {
        if(num[i] <= pivot)
        {
            //swap (num[pindex] , num[i])
            temp = num[pindex];
            num[pindex] = num[i];
            num[i] = temp;
            pindex = pindex + 1;
        }
    }
    //swap (num[r] , num[pindex]);
    temp = num[pindex];
    num[pindex] = num[r];
    num[r] = temp;


    if(pindex == k - 1 ) return num[pindex];
    else if(pindex < k - 1) return partition(num, pindex + 1, r, k);
    else return partition(num , l , pindex - 1 , k);

}


int main()
{
    vector <int> num = {21, 45, 63 , 34, 12, 47, 20 };
    for (int i = 0; i < num.size(); i++)
    {
        cout<<num[i] <<" ";
    }
    cout<<"\n";
    
    cout<<"Kth smallest element is "<<partition(num, 0, num.size() - 1, 4);

    return 0 ;
}