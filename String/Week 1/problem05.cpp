

/*
5)
Given a string of lowercase alphabets and a number k, the task is to find the minimum value of
the string after removal of ‘k’ characters. 
The value of a string is defined as the sum of squares of the count of each distinct character.
For example consider the string “geeks”, here frequencies of characters are 
g -> 1, e -> 2, k -> 1, s -> 1 and value of the string is 12 + 22 + 12 + 12 = 7
*/

#include<bits/stdc++.h>

using namespace std;

int MinValue(string s, int k)
{
    int h[26]; //index value as  alphabet and array value as frequency

    //set frequency as Zero
    for(int i = 0; i < 26; i++)
        h[i] = 0;


    //store frequency
    for(int i = 0 ; i < s.length(); ++i)
    {
        h[s[i] - 97]++;
    }
    

    priority_queue<int> q;
    
    printf("Push\t"); 
    for(int i = 0 ; i < 26 ; ++i)
    {
        if (h[i] != 0)
            q.push(h[i]);
     }
    printf("\n");

    int ans= 0;
    //removing k characters
    while (k)
    {
        int top = q.top();
        q.pop();
        top--; // if I decrease frequency then i remove that character
        k--;
        q.push(top);
    }

  

    while(q.size())
    {
        ans = ans + (q.top()* q.top());
     
        q.pop();
    }
    
    return ans;

}

int main()
{
    string s = "ac";
    cout<<"Minimum Value"<<MinValue(s , 2)<<"\n";

    return 0;
}