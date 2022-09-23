//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    static int compare(pair<int , int> a , pair<int , int> b){
        return a.first < b.first;
    }
    
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
           if (intervals.size() <= 0)
                return {};
         vector<pair<int , int>> interval;
         for(auto x : intervals){
             interval.push_back(make_pair(x[0] , x[1]));
         }
         
         sort(interval.begin() , interval.end() , compare);
        
         
         stack<pair<int , int>> s;
         
         s.push(interval[0]);
         for(int i = 1 ; i < interval.size() ;i++){
         

             pair<int , int> top = s.top();
            if(top.second < interval[i].first){
                s.push(interval[i]);
             }
             else if(top.second < interval[i].second){
              
              
                 top.second = interval[i].second;
                 s.pop();
                 s.push(top);
             }
             
         }
         intervals.clear();
         
         while(!s.empty()){
            auto top = s.top();
            intervals.push_back({top.first , top.second});
            s.pop(); 
        
        }   
        reverse(intervals.begin(), intervals.end());
         return intervals;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
