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
       cout<<sentence.size()<<" "<<"\n";
    s.push("0");

    for (int i = 0; i < sentence.size(); i++)
    {
        if(sentence[i] != '.')
        {
            temp.push_back(sentence[i]);
        }   
        else if(sentence[i] == '.' )
        {
            cout<<"else temp :"<<temp<<"\n";
            s.push(temp);
            temp.clear();   
        }       
    }
   
    s.push(temp);
    cout<<"\n\n";
    temp.clear();
   
    while (!s.empty())
    {
        if(s.top() != "0")
        {
            if(temp.size() == 0)
            {
                temp.append(s.top());
            }
            else{
                    temp = temp + '.';
                    cout<<"size :"<<temp.size()<<" "<<temp<<"\n";
                    temp.append(s.top());
            }
        
     
        }
        
          s.pop();
         
        

        
    }
    
    return temp;

    
}



int main()
{

    string sentence = "yyy.ggg";
    cout<<sentence<<" "<<"\n";
    sentence = reverse_string(sentence);
    cout<<sentence<<" "<<"\n";

    return 0;

}
