
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

int palindrome(string sentence)
{
    string temp;

    cout<<sentence.size()<<"\n";
    if(sentence.size() == 0)
        return 0;

    for (int i = 0; i <= sentence.size(); i++)
    {
     
        if(!((int)sentence[i] >= 65 &&  (int)sentence[i] <= 92) && !((int)sentence[i] >= 97 &&  (int)sentence[i] <= 124 ))
         { 
    
            continue;
         }
        else if ((int)sentence[i] >= 65 &&  (int)sentence[i] <= 92)
        {
            sentence[i] = sentence[i] + 32;
            temp.push_back(sentence[i]);
        }
        else{
            temp.push_back(sentence[i]);
        }
    }
    cout<<temp<<"\n";

    int i = 0 , j = temp.size() -1 ;
    while (i < j)
    {
        if(temp[i++] == temp[j--])
            continue;
        else
            return 0; 
    }
    return 1;
    
}

int main()
{
    string sentence = "i.I";
    cout<<"At Main :"<<sentence<<"\n";
    cout<<palindrome(sentence)<<"\n";

    return 0;



}