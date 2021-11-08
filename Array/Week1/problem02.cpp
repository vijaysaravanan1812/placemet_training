
/*
2) Remove Elements from array



*/


#include<bits/stdc++.h>

using namespace std;

class Solution{

public:
    int remove(vector<int> &num , int value )
    {
        int i = 0 , n = num.size();
        
        while(i < n)
        {
            if(num[i] == value){
                num[i] = num[n -1];
                //num[n -1] = 0;
                n--;
            }
            else{
                i++;
            }
        }

          cout<<i<<" "<<n<<"\n";
        return n;
    }
  
};


int main()
{
    vector<int> num;
    num.push_back(10);
    num.push_back(2);
    num.push_back(19);
    num.push_back(10);
    num.push_back(10);
    num.push_back(12);
    num.push_back(13);
    num.push_back(10);
    
    Solution s;
       for(int i = 0; i < num.size(); i++ )
    {
        cout<<num[i]<<" ";
    }
    cout<<"\n";
    int n = s.remove(num , 10);
    
    for(int i = 0; i <= n; i++ )
    {
        cout<<num[i]<<" ";
    }
    cout<<"\n";
}


