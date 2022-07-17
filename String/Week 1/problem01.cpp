/*
1) Given a String S, reverse the string without reversing its individual words. 
Words are separated by dots.

*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        vector<string> temp ;string str;
        for(int i = 0 ; i < s.length(); i++ ){
            
            if(s[i] == '.'){
                temp.push_back(str);
                str = "";
            }
            else{
                str += s[i];
            }
        }
        temp.push_back(str);
        
        str = "";
        
        for(int i = temp.size() - 1 ; i >= 1  ; i--){
            str += temp[i];
            str += '.';
        }
        str += temp[0];
        
        return str;
    } 
};