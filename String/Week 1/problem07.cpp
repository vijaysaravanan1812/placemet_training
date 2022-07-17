// C++ program for implementation of KMP pattern searching
// algorithm
#include <bits/stdc++.h>
using namespace std;

void Lps(string pat, vector<int> &lps ){
    
    int len = 0 ; 
    int i = 1, n = pat.length();

    lps[0] = 0;
    while(i < n)
    {

        if(pat[len] == pat[i]){
            len++;
            lps[i] = len;
             i++;
        }    
        else{
            if(len != 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }    
            
        }
    }
    
    return;

}


bool searchPattern(string str, string pat)
{
    int M = pat.length();
    int N = str.length();

    vector<int> lps(N, 0);
 
    Lps(pat , lps);
   
    
    int i = 0; // index for txt
    int j = 0; // index for pat
    while(i < N)
    {
        if(pat[j] == str[i]){
            i++;
            j++;
        }
        if(j == M)
            return true;
        else if( i < N && pat[j] != str[i]){
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return false;
    
    // Navive solution
    // int i = 0 , j = 0 , count = 0;
    // while(i < str.size()){
    //     int k = i; 
    //     j = 0;
    //     while( j < pat.size()){
    //         if(str[k] == pat[j]){
    //             count += 1;
    //             j++;
    //             k++;
    //         }
            
    //         if(count == pat.size())
    //             return true;
    //     }
    // }
    // return false;
    
    
}

// Driver program to test above function
int main()
{
	char txt[] = "ABABDABACDABABCABAB";
	char pat[] = "ABABCABAB";
	cout<<searchPattern(txt , pat)<<"\n";
	return 0;
}
