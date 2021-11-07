

/*
10) valid parameters

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

*/


#include<bits/stdc++.h>

using namespace std;

bool check_valid_parameter(string s)
{
    stack <char> str;
    for(int i = 0 ; i < s.length(); i++)
    {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            str.push(s[i]);
        }
        else{
            if(str.empty()) 
                return false;
            if (s[i] == '}')
            {
                if(str.top() == '{'){
                   // cout<<"{ poped \n";
                    str.pop();
                }
                else 
                    return false;
            }
            else if(s[i] == ']')
            {
                if(str.top() == '[')
                {
                    //cout<<"[ poped \n";
                    str.pop();
                }
                else 
                    return false;
            }
            else if(s[i] == ')')
            {
            
                if(str.top() == '(')
                {
                    //cout<<"( poped\n";
                    
                    str.pop();
                }
                else
                    return false;
            }

        }
    }

    if(str.empty()){
       // cout<<"valid\n";
        return true;
    }
    return false;
}

int main()
{
    string s = "{}[]()";

    if (check_valid_parameter(s))
    {
        cout<<s<<" is valid\n"; 
    }
    else{
        cout<<s<<" is invalid\n";
    }
    
    return 0 ;
}