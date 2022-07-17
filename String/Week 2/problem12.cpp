    string printMinNumberForPattern(string S){
        // code here 
        stack <int> st;
        string result = "";
        for(int i = 0 ; i <= S.length(); i++ ){
            st.push(i + 1);
            if(i == S.length()  || S[i] =='I'){
                while(!st.empty()){
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }
        return result;
        
        
    }