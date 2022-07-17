	
//Minimize string value
    
    int minValue(string S, int K)
	{
	    unordered_map <char , int > frequency;
	    
	    if(K > S.length())
	        return 0;
	    
	    for(char x : S){
	        if(frequency.find(x) != frequency.end()){
	            frequency[x]++;
	        }
	        else{
	            frequency[x] = 1;
	        }
	    }
	    
	    
	    priority_queue<int> q;
	    for(auto x : frequency){
	       // cout<<x.first<<" "<<x.second<<" "<<K<<"\n";
	        q.push(frequency[x.first]);
	    }
	    
	    
	    while(K--){
	        int temp = q.top();
	       
	        q.pop();
	        temp = temp - 1;
	        q.push(temp);
	    }
	    
	    int result = 0;
	    while(!q.empty()){
	        int temp = q.top();
	        result += temp * temp;
	        q.pop();
	    }
	    
	    return result;
	    
	    
	}