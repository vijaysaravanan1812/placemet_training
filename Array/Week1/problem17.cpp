// C++ program to find equilibrium index of an array
#include <bits/stdc++.h>
using namespace std;

int equilibrium(int a[], int n)
{
	if (n == 1)
		return (0);
	int forward[n] = { 0 };
	int rev[n] = { 0 };

	// Taking the prefixsum from front end array
	for (int i = 0; i < n; i++) {
		if (i) {
			forward[i] = forward[i - 1] + a[i];
		}
		else {
			forward[i] = a[i];
		}
	}

	// Taking the prefixsum from back end of array
	for (int i = n - 1; i > 0; i--) {
		if (i <= n - 2) {
			rev[i] = rev[i + 1] + a[i];
		}
		else {
			rev[i] = a[i];
		}
	}

	// Checking if forward prefix sum
	// is equal to rev prefix
	// sum
	for (int i = 0; i < n; i++) {
		if (forward[i] == rev[i]) {
			return i;
		}
	}
	return -1;

	// If You want all the points
	// of equilibrium create
	// vector and push all equilibrium
	// points in it and
	// return the vector
}

// Driver code
int main()
{
	int arr[] = { -7, 1, 5, 2, -4, 3, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "First Point of equilibrium is at index "
		<< equilibrium(arr, n) << "\n";
	return 0;
}
