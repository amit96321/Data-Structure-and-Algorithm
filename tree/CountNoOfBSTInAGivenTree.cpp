// C++ program to count number of Binary search trees 
// in a given Binary Tree 
// each node individually is also a bst so if a subtree is bst and not leaf then increment the counter by 2(one for node itself being bst
// and one along with left and right child being bst), else increment the noOfBST by 1
#include <bits/stdc++.h> 
using namespace std; 

// Binary tree node 
typedef struct Node { 
	struct Node* left; 
	struct Node* right; 
	int data; 

	Node(int data) 
	{ 
		this->data = data; 
		this->left = NULL; 
		this->right = NULL; 
	} 
}Node; 


//used to store maximum value in subtree
map<Node*,int> mnv;
int maxValue(Node *root){
    if(root==NULL) return INT_MIN;
    if(mnv[root]) return mnv[root];
    if(root->left==NULL && root->right==NULL) mnv[root]= root->data;
    if(root->left!=NULL && root->right==NULL) mnv[root]= max(root->data,maxValue(root->left));
    if(root->right!=NULL && root->left==NULL) mnv[root]= max(root->data,maxValue(root->right));
    else mnv[root]= max(root->data,max(maxValue(root->left),maxValue(root->right)));
    return mnv[root];
}

//used to store minimum value in subtree
map<Node*,int> mxv;
int minValue(Node *root){
    if(root==NULL) return INT_MAX;
    if(mxv[root]) return mxv[root];
    if(root->left==NULL && root->right==NULL) mxv[root]= root->data;
    if(root->left!=NULL && root->right==NULL) mxv[root]= min(root->data,minValue(root->left));
    if(root->right!=NULL && root->left==NULL) mxv[root]= min(root->data,minValue(root->right));
    else mxv[root]= min(root->data,min(minValue(root->left),minValue(root->right)));
    return mxv[root];
}

//used to find weather a subtree is bst or not
map<Node*,bool> m1;
bool isBST(Node *root){
    if(root==NULL) return true;
    if(m1[root]) return m1[root];
    if(isBST(root->left) && isBST(root->right) && maxValue(root->left)<root->data && minValue(root->right)>root->data){
        m1[root]=true;
        return m1[root];
    }
    m1[root]=false;
    return m1[root];
}

map<Node*,int> m;
int NumberOfBST(Node *root){
    if(root==NULL) return 0;
    if(m[root]) return m[root];
    if(isBST(root) && !(root->left==NULL && root->right==NULL)){
        m[root]=NumberOfBST(root->left) + NumberOfBST(root->right) +2;
    }
    else m[root]=NumberOfBST(root->left) + NumberOfBST(root->right) +1;
    return m[root];
}

int main() 
{ 
	struct Node* root = new Node(5); 
	root->left = new Node(3); 
	root->right = new Node(9); 
	/*root->left->left = new Node(6); 
	root->right->right = new Node(4); 
	root->left->left->left = new Node(8); 
	root->left->left->right = new Node(7);*/

	cout << NumberOfBST(root); 

	return 0; 
} 
