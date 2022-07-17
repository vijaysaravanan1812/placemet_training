	string removeDuplicates(string str) {
	    // code here
	    string str1;
	    for(int i = 0 ; i < str.length() ; i++){
	            int found = str1.find(str[i]);
                if (!(found != string::npos))
                    str1 += str[i];
	    }
	    return str1;

  }
// 	    map<char , pair<int , int >> frequency;
// 	    string str1;
// 	    for(int i = 0 ; i < str.length(); i++ ){
// 	        if(frequency.find(str[i]) != frequency.end()){
// 	            frequency[str[i]].second++;
// 	        }
// 	        else{
// 	            frequency[str[i]] = make_pair( i , 1);
// 	        }
// 	    }
	    
// 	    vector <pair<char , pair<int , int >>> b;
// 	    for(auto x : frequency){
// 	        b.push_back(make_pair(x.first , x.second));
// 	       // cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<"\n";
// 	    }
	    
// 	    sort(b.begin() , b.end() , compare);
	    
// 	    for(int i = 0 ; i < b.size(); i++){
// 	        str1 += b[i].first;
// 	    }
	    
	    
	    
// 	    return str1;
 