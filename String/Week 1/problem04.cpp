

/*
Given a string of lowercase alphabets and a number k, the task is to find the minimum value of
the string after removal of ‘k’ characters. 
The value of a string is defined as the sum of squares of the count of each distinct character.
For example consider the string “geeks”, here frequencies of characters are 
g -> 1, e -> 2, k -> 1, s -> 1 and value of the string is 12 + 22 + 12 + 12 = 7

*/

#include<bits/stdc++.h>

using namespace std;

int MinValue(string str)
{
    unordered_map <char , int> m ; int frequency = 0;
    for( char i : str)
    {
        m[i] = m[i] + 1;
    }
    for(auto i : m)
    {
        cout<<i.first<<" "<<i.second<<endl;    
    }
    return 0;
}

int main()
{
    string str = "geeksforgeeks";
    MinValue(str);

    return 0;

}