// C/C++ program to find maximum path sum in Binary Tree 
#include<bits/stdc++.h> 
using namespace std; 

// A binary tree node 
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}; 

// A utility function to allocate a new node 
struct Node* newNode(int data) 
{ 
	struct Node* newNode = new Node; 
	newNode->data = data; 
	newNode->left = newNode->right = NULL; 
	return (newNode); 
} 

int findMaxSumUtil(Node *root){
    if(root==NULL) return 0;
    return root->data+max(findMaxSumUtil(root->left),findMaxSumUtil(root->right));
}
 
int findMaxSum(Node *root) { 
	if(root==NULL) return 0;
	return max(root->data + findMaxSumUtil(root->left) + findMaxSumUtil(root->right),
	    max(findMaxSum(root->left),findMaxSum(root->right))
	);
} 

int main(void) 
{ 
	struct Node *root = newNode(10); 
	root->left	 = newNode(2); 
	root->right	 = newNode(10); 
	root->left->left = newNode(20); 
	root->left->right = newNode(1); 
	root->right->right = newNode(-25); 
	root->right->right->left = newNode(3); 
	root->right->right->right = newNode(4); 
	int mx=INT_MIN;
	cout << "Max path sum is " << findMaxSum(root); 
	return 0; 
} 
