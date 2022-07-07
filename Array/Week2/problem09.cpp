class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {

        unordered_set<int> myset ;
        pair<int , int> mypair;
        vector<pair <int , int>> result;
        
        for(int i = 0 ; i < N ;i++){
            myset.insert(A[i]);
        }
        
        for(int i = 0 ; i < M; i++){
            int A = X - B[i];
            
            
            if((myset.find(A)) != myset.end() ){
                mypair.first = A;
                mypair.second = B[i];
                result.push_back(mypair);
            }
        }
                
        
        
        return result;
        
        // Your code goes here   
    }
};