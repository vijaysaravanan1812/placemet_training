int longestSubstrDistinctChars (string S)
{
    // your code here
    int right = 0 , left = 0;
    int length = 0 ;
    unordered_map<char , int> mymap;
    int n = S.length();
    while(right < n){
        if(mymap.find(S[right]) != mymap.end()){
            left = max(left , mymap[S[right]] + 1);
         
        }
        
        
        mymap[S[right]] = right;
        length = max(length , right - left + 1);
        right++;
    }
    
    return length;

}