
/*
3) 
Your task  is to implement the function atoi. 
The function takes a string(str) as argument 
and converts it to an integer and returns it.
*/

#include<bits/stdc++.h>

using namespace std; 


int ToInteger(string number)
{
    string temp ;int num = 0 ; 
    for (int j  = 1 , i = number.size() -1; i >= 0 ; i-- , j *= 10)
    {
        if (!((int)number[i] >= 48 && (int)number[i] <= 57))
        {
          
            return -1;
        }
        else{
            temp.push_back(number[i]);
        
           num = num + j*((int)number[i]  - 48);
        }
    }
    
    return num;
    
}

int main()
{
    string number = "1345096";
    cout<<"main " <<number<<"\n";
    cout<<"number is :"<<ToInteger(number)<<"\n";
   // cout<<ToInteger(number).size()<<"\n";
    return 0;
}
