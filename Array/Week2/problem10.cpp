Example 1:

Input: 
N = 5
Arr[] = {3, 30, 34, 5, 9}
Output: 9534330
Explanation: Given numbers are {3, 30, 34,
5, 9}, the arrangement 9534330 gives the
largest value.



class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	
	static int myCompare(string x , string y){
	    
	    string xy = x.append(y);
	    string yx = y.append(x);
	    
	    return xy.compare(yx) > 0? 1 : 0;
	}
	
	string printLargest(vector<string> &arr) {
	    // code here
	    
	    sort(arr.begin() , arr.end() , myCompare);
	    
	    string result;
	    for(int i = 0 ; i < arr.size() ; i++ ){
	        result.append(arr[i]);
	    }
	    
	    return result;
	    
	    
	}
};