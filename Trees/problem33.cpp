// A Better Solution is to create an auxiliary array and store Inorder
// traversal of BST in the array. The array will be sorted as Inorder 
// traversal of BST always produces sorted data. Once we have the 
// Inorder traversal, we can use method 2 of this post to find the 
// triplet with sum equals to 0. This solution works in O(n^2) time,
// but requires O(n) auxiliary space.



// C++ program to find a triplet
#include <bits/stdc++.h>
using namespace std;

// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
bool find3Numbers(int A[], int arr_size, int sum)
{
	int l, r;
	/* Sort the elements */
	sort(A, A + arr_size);
	/* Now fix the first element one by one and find the
	other two elements */
	for (int i = 0; i < arr_size - 2; i++) {

		// To find the other two elements, start two index
		// variables from two corners of the array and move
		// them toward each other
		l = i + 1; // index of the first element in the
		// remaining elements
		r = arr_size - 1; // index of the last element
		while (l < r) {
			if (A[i] + A[l] + A[r] == sum) {
				printf("Triplet is %d, %d, %d", A[i], A[l],A[r]);
				return true;
			}
			else if (A[i] + A[l] + A[r] < sum)
				l++;
			else // A[i] + A[l] + A[r] > sum
				r--;
		}
	}
	// If we reach here, then no triplet was found
	return false;
}

