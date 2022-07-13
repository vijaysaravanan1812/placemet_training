class Solution 
{
    int knows(int A  ,int B , vector<vector<int> >& M){
        return M[A][B];
    }
    public:

    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack <int> s;
        for(int i = 0 ; i < n ;i++){
            s.push(i);
        }
        
        int count = 0 ;
        while(count < n -1 ){
            
            int A = s.top();
            s.pop();
            int B = s.top();
            s.pop();
            
            if(knows(A , B , M)){
                s.push(B);
            }
            else{
                s.push(A);
            }
            
            count++;
        }
        int celebrity = s.top();
        int check = 1 ;
        for(int i = 0 ; i < n ; i++){
            if(i == celebrity)
                continue;
            if((M[i][celebrity] == 0) || (M[celebrity][i] == 1))
                check = 0;
        }
        
        if(check)
            return celebrity;
        else
            return -1;
    }
        
        
    };