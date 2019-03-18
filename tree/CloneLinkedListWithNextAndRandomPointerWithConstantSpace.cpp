// C++ program to clone a linked list with next 
// and arbit pointers in O(n) time 
#include <bits/stdc++.h> 
using namespace std; 

// Structure of linked list Node 
struct Node { 
	int data; 
	Node *next,*random; 
	Node(int x) 
	{ 
		data = x; 
		next = random = NULL; 
	} 
};  

// Utility function to print the list. 
void print(Node *start) 
{ 
    int c=0;
	Node *ptr = start; 
	while (ptr) 
	{ 
		cout << "Data = " << ptr->data << ", Random = "
			<< ptr->random->data <<", Addr = "<<ptr<< endl; 
		ptr = ptr->next; 
	} 
} 

// This function clones a given linked list 
// in O(1) space 
Node* clone(Node *start){ 
    Node *res,*temp=start,*temp1;
    //this loop inserts a newly created node just after each node whose value is same as previos node 
    while(temp!=NULL){  
        temp1=new Node(temp->data);
        temp1->next=temp->next;
        temp->next=temp1;
        temp=temp1->next;
    }
    
    //this loop is used to create random pointer of inserted node
    temp=start;
    while(temp!=NULL){
        temp1=temp->next;
        temp1->random=temp->random->next;
        temp=temp->next->next;
    }
    
    
    //this loop is used to seperate the inserted and Original list
    temp=start;
    res=start->next;
    temp1=res;
    while(temp!=NULL){
        temp1=temp->next;
        temp->next=temp1->next;
        temp=temp->next;
        if(temp==NULL) temp1->next=NULL;
        else temp1->next=temp1->next->next;
    }
    return res;
} 

int main() 
{ 
	Node* start = new Node(1); 
	start->next = new Node(2); 
	start->next->next = new Node(3); 
	start->next->next->next = new Node(4); 
	start->next->next->next->next = new Node(5); 

	// 1's random points to 3 
	start->random = start->next->next; 

	// 2's random points to 1 
	start->next->random = start; 

	// 3's and 4's random points to 5 
	start->next->next->random = start->next->next->next->next; 
	start->next->next->next->random = start->next->next->next->next; 

	// 5's random points to 2 
	start->next->next->next->next->random = 
									start->next; 
    cout << "Original list : \n"; 
	print(start); 
	
	cout << "\nCloned list : \n"; 
	Node *cloned_list = clone(start); 
	print(cloned_list); 
  
    cout << "\nOriginal list : \n"; 
	print(start); 

	return 0; 
} 
