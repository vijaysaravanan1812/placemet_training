
class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        vector<int> moves(35 , -1);
        vector<bool> visited(35 , false);
        
        for(int i = 0;i < 2*N;i += 2)
            moves[arr[i]] = arr[i+1];
            
        queue<pair<int ,int>> q;
        pair<int , int> p ;
        q.push({1 , 0});
        visited[1] =  true;
        while(!q.empty()){
            p = q.front();
            int index = p.first;
            int distance = p.second;
            q.pop();
            if(index == 30){
                break;
            }
            
            
            for(int i = index + 1 ; i <= index + 6 && i <= 30 ; i++){
                pair<int , int> pp;
                if(!visited[i]){
                    pp.second = distance + 1;
                    visited[i] = true;
                    if(moves[i] != -1)
                        pp.first = moves[i];
                    else
                        pp.first = i;
                        
                    q.push(pp);
                }
                
            }
        }
        return p.second;
        
        
    }
};