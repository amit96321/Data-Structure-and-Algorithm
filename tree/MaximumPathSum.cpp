// C++ program to find maximum path sum between two leaves of 
// a binary tree 
#include <bits/stdc++.h> 
using namespace std; 

// A binary tree node 
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}; 

// Utility function to allocate memory for a new node 
struct Node* newNode(int data) 
{ 
	struct Node* node = new(struct Node); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

int maxPathSumUtil(struct Node *root, int &res) 
{ 
	if (root==NULL) return 0; 
	int ls = maxPathSumUtil(root->left, res); 
	int rs = maxPathSumUtil(root->right, res); 
	res = max(res, ls + rs + root->data);
	return max(ls, rs) + root->data;
} 

int maxPathSum(struct Node *root) 
{ 
	int res = INT_MIN; 
	maxPathSumUtil(root, res); 
	return res; 
} 

// driver program to test above function 
int main() 
{ 
	struct Node *root = newNode(-15); 
	root->left = newNode(5); 
	root->right = newNode(6); 
	root->left->left = newNode(-8); 
	root->left->right = newNode(1); 
	root->left->left->left = newNode(2); 
	root->left->left->right = newNode(6); 
	root->right->left = newNode(3); 
	root->right->right = newNode(9); 
	root->right->right->right= newNode(0); 
	root->right->right->right->left= newNode(4); 
	root->right->right->right->right= newNode(-1); 
	root->right->right->right->right->left= newNode(10); 
	cout << "Max pathSum of the given binary tree is "
		<< maxPathSum(root); 
	return 0; 
} 
