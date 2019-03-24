//Find a pair with given sum in a Balanced BST

void isPairPresent(struct node *root, int target) 
{ 
	struct Stack* s1 = createStack(MAX_SIZE); 
	struct Stack* s2 = createStack(MAX_SIZE);  
	bool done1 = true, done2 = true; 
	int val1 = 0, val2 = 0; 
	struct node *curr1 = root, *curr2 = root;
	while (1) 
	{ 
		if(done1 == true) 
		{ 
			while(curr1 != NULL) 
			{ 
				push(s1, curr1); 
				curr1 = curr1->left; 
			} 
			if (isEmpty(s1)) 
				done1 = false; 
			else
			{ 
				curr1 = pop(s1); 
				val1 = curr1->val; 
				curr1 = curr1->right; 
				done1 = false; 
			} 
		} 
		
		if(done2 == true) 
		{ 
			while (curr2 != NULL) 
			{ 
				push(s2, curr2); 
				curr2 = curr2->right; 
			} 
			if (isEmpty(s2)) 
				done2 = false; 
			else
			{ 
				curr2 = pop(s2); 
				val2 = curr2->val; 
				curr2 = curr2->left; 
				done2 = false; 
			} 
		}
		
		if ((val1 != val2) && (val1 + val2) == target) 
		{ 
			printf("\n Pair Found: %d + %d = %d\n", val1, val2, target); 
			return; 
		}
		else if ((val1 + val2) < target) 
			done1 = true;
		else if ((val1 + val2) > target) 
			done2 = true; 
		if (val1 >= val2){
		    cout<<"Pair not found\n";
		    return;
		}
	} 
} 
