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
	Node *ptr = start; 
	while (ptr) 
	{ 
		cout << "Data = " << ptr->data << ", Random = "
			<< ptr->random->data <<", Addr = "<<ptr<< endl; 
		ptr = ptr->next; 
	} 
} 

// This function clones a given linked list 
// in O(n) space 
Node* clone(Node *start){ 
	map<Node*, Node*> m;
	Node *temp=start;
	//next node of original list is stored in map as it will help to rebuild the original array
	while(temp!=NULL){      
	    m[temp]=temp->next;
	    temp=temp->next;
	}
	Node *res,*prev=NULL;
	Node *temp1,*x;
	temp=start;
	while(temp!=NULL){
	    res=new Node(temp->data);   //new note is created with same value as in original list
	    res->random=temp;           //random pointer is set to corrosponding node in original list
	    if(prev==NULL){
	      prev=res;
	      temp1=res;
	    } 
	    else {
	        prev->next=res;
	        prev=res;
	    }
	    x=temp->next;       
	    temp->next=res;   //next pointer of original list is modified to current pointer of new list
	    temp=x;        
	}
	
	res=temp1;
	//this loop is used to set random pointer in new list
	while(res!=NULL){       
	    res->random=res->random->random->next;
	    res=res->next;
	}
	
	res=temp1;
	temp=start;
	//this loop is used to restore the next pointer 
	while(temp!=NULL){
	    temp->next=m[temp];
	    temp=temp->next;
	}
	return res;
} 

// Driver code 
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
