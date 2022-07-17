
/*

2) Jarvis is weak in computing palindromes for Alphanumeric characters.
While Ironman is busy fighting Thanos, he needs to activate sonic 
punch but Jarvis is stuck in computing palindromes.
You are given a string S containing alphanumeric characters. 
Find out whether the string is a palindrome or not.
If you are unable to solve it then it may result in the death of Iron Man.
*/

#include<bits/stdc++.h>


using namespace std;


bool saveIronman(string ch)
{
    string str1;
    for(int i = 0 ; i < ch.length() ; i++){
        if(isupper(ch[i])){
            ch[i] = tolower(ch[i]);
        }
        if(isalpha(ch[i]) || isdigit(ch[i]))
        {
            str1 += ch[i];
        }
    }
    
    
    string str = str1;
    reverse(str.begin() , str.end());
    return (str1 == str);
    
}
