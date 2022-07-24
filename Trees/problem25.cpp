// C++ program to find Sum Of All Elements larger
// than or equal to Kth Largest Element In BST
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

// utility function new Node of BST
struct Node* cNode(int data)
{
	Node* node = new Node;
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	return node;
}

// A utility function to insert a new Node
// with given key in BST
struct Node* add(Node* root, int key)
{
	// If the tree is empty, return a new Node
	if (root == NULL)
		return cNode(key);

	// Otherwise, recur down the tree
	if (root->data > key)
		root->left = add(root->left, key);

	else if (root->data < key)
		root->right = add(root->right, key);

	// return the (unchanged) Node pointer
	return root;
}

// function to return sum of all elements larger than
// and equal to Kth largest element
int klargestElementSumUtil(Node* root, int k, int& c)
{
	// Base cases
	if (root == NULL)
		return 0;
	if (c > k)
		return 0;

	// Compute sum of elements in right subtree
	int ans = klargestElementSumUtil(root->right, k, c);
	if (c >= k)
		return ans;

	// Add root's data
	ans += root->data;

	// Add current Node
	c++;
	if (c >= k)
		return ans;

	// If c is less than k, return left subtree Nodes
	return ans + klargestElementSumUtil(root->left, k, c);
}

// Wrapper over klargestElementSumRec()
int klargestElementSum(struct Node* root, int k)
{
	int c = 0;
	klargestElementSumUtil(root, k, c);
}

// Drivers code
int main()
{
	/* 19
		/ \
	7	 21
	/ \
	3	 11
		/ \
		9 13
		*/

	Node* root = NULL;
	root = add(root, 19);
	root = add(root, 7);
	root = add(root, 3);
	root = add(root, 11);
	root = add(root, 9);
	root = add(root, 13);
	root = add(root, 21);

	int k = 2;
	cout << klargestElementSum(root, k) << endl;
	return 0;
}
