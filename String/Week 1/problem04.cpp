

/*
4)
Find the frequency of character
*/

#include<bits/stdc++.h>

using namespace std;

int Get_frequency(string str)
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
    Get_frequency(str);

    return 0;

}