int minManipulation (int N, string S1, string S2)
{
    // your code here
    map<char , int > freq;
    for(int i = 0 ; i < S1.length() ; i++){
        if(freq.find(S1[i]) != freq.end()){
            freq[S1[i]]++;
        }
        else{
            freq[S1[i]] = 1;
        }
    }
    
    for(int i = 0 ; i < S2.length() ; i++){
            freq[S2[i]]--;
    }
    int count = 0;
    for(auto x : freq){
        count += abs(x.second);
    }
    
    return count/2;
    
    
}