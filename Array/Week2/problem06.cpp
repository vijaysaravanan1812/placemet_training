
/*
You are given an array prices where prices[i] is the price of a given stock on the 
ith day.
You want to maximize your profit by choosing a single day to buy one stock and
choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot
achieve any profit, return 0.
*/

#include<bits/stdc++.h>

using namespace std;

int profit(vector <int> &num )
{
    int min = num[0],min_index = 0, max= 0;

    for(int i = 0; i < num.size(); i++)
    {
        if(min > num[i])
        {
            min = num[i];
            min_index++;
        }

    }
   
    for (int i = min_index; i < num.size(); i++)
    {
        if(max < num[i]){
            max = num[i];
        }

    }
    
    return max  - min;
}

int main()
{
    vector <int> num = {7, 1, 5, 3, 6, 4, 10};
    cout<<"profit is "<<profit(num)<<"\n";
    return 0;
}