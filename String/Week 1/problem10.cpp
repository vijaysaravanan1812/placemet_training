	void binary_conversion(string &s, int m) {
        while (m) {
	       int tmp = m % 2;
	       s += tmp + '0';
	       m = m / 2;
        }
        reverse(s.begin(), s.end());
    }

// Function to find ith character

	
	char kthCharacter(int m, int n, int )
	{
	    
        string s;

        // Function to change decimal to binary
        binary_conversion(s, m);

        string s1 = "";
        for (int x = 0; x < n; x++) {
	        for (int y = 0; y < s.length(); y++) {
	            if (s[y] == '1')
		            s1 += "10";
	            else
		            s1 += "01";	
	        }

	// Assign s1 string in s string
	        s = s1;
	        s1 = "";
        }
        return s[i] - '0';
	    // Your code goes here
	}