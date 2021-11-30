

/*
4) Sort the binary array 
*/

#include<bits/stdc++.h>

using namespace std;

void sort(vector<int> &num)
{
    int j = -1;
    for(int i = 0; i < num.size() ; i++)
    {
        if(num[i] < 1)
        {
            j++;
            swap(num[i], num[j]);
        }
    }
    
}
 
int main()
{
    vector <int> num = {0,1,0,1,0,1};
    sort(num);
    for (int i = 0; i < num.size(); i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}