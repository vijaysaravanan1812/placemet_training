/*
1) Given a String S, reverse the string without reversing its individual words. 
Words are separated by dots.

*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverse_string(string sentence)
{
    stack <string> s; string temp;
    for (int i = 0; i < sentence.size(); i++)
    {
        if(sentence[i] != '.')
        {
            temp.push_back(sentence[i]);
        }
        else if(sentence[i] == '.')
        {
            s.push(temp);
            temp.clear();
        }
    }
    temp.clear();
    while (!s.empty())
    {
        temp.append(s.top());
        temp = temp + '.';
        s.pop();
    }
    
    return temp;

    
}



void main()
{

    string sentence;
    cout<<sentence<<" "<<"\n";
    sentence = reverse_string(sentence);
    cout<<sentence<<" "<<"\n";

       //return 0;

}
